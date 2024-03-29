<?php

/**
 * @file
 *
 * CTools content type to render a fielded panel pane.
 */

/**
 * Small hook implementation of plugin.
 *
 * We have to use this because the form here can be loaded via form
 * caching and if this .inc file is loaded before the plugin is
 * requested, the $plugin = array() notation doesn't work.
 */
function fieldable_panels_panes_fieldable_panels_pane_ctools_content_types() {
  return array(
    'title' => t('Fielded custom content'),
    'no title override' => TRUE,
    'description' => t('Create custom panels pane with fields'),
    'category' => t('Fielded panes'),
    'all contexts' => TRUE,
    'defaults' => array(
      'view_mode' => 'full',
    ),
    'edit form' => 'fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form',
    'edit text' => t('Edit'),
  );
}
// --------------------------------------------------------------------------
// Callbacks, many of them automatically named, for rendering content.

/**
 * Callback to return the custom content types with the specified $subtype_name.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_content_type($subtype_name) {
  $types = _fieldable_panels_panes_default_content_type();
  if (isset($types[$subtype_name])) {
    return $types[$subtype_name];
  }
  else {
    $entity = fieldable_panels_panes_load_entity($subtype_name);
    if ($entity) {
      return _fieldable_panels_panes_custom_content_type($entity);
    }
  }
}

/**
 * Callback to return all custom content types available.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_content_types() {
  $types = _fieldable_panels_panes_default_content_type();

  $ids = db_query('SELECT fpid FROM {fieldable_panels_panes} WHERE reusable = 1')->fetchCol();
  if ($ids) {
    $entities = fieldable_panels_panes_load_multiple($ids);
    foreach ($entities as $entity) {
      $subtype = _fieldable_panels_panes_custom_content_type($entity);
      $types[$subtype['name']] = $subtype;
    }
  }

  return $types;
}

/**
 * Callback to render our content type.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_render($subtype, $conf, $panel_args = array(), $context = array()) {
  $entity = fieldable_panels_panes_load_entity($subtype);
  $view_mode = isset($conf['view_mode']) ? $conf['view_mode'] : 'full';
  if ($entity && !empty($entity->fpid) && fieldable_panels_panes_access('view', $entity)) {
    $settings = field_bundle_settings('fieldable_panels_pane', $entity->bundle);
    $block = new stdClass();
    $block->title = '';
    if (empty($settings['extra_fields']['display']) || !empty($settings['extra_fields']['display']['title']['default']['visible'])) {
      $block->title = !empty($entity->title) ? filter_xss_admin($entity->title) : '';
    }
    $block->content = fieldable_panels_panes_view($entity, $view_mode);
    return $block;
  }
}

/**
 * Callback to provide the administrative title of the custom content.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_admin_title($subtype, $conf) {
  $entity = fieldable_panels_panes_load_entity($subtype);

  $output = t('Deleted/removed entity pane');
  if (isset($entity) && is_object($entity)) {
    $title = !empty($entity->admin_title) ? $entity->admin_title : (!empty($entity->title) ? $entity->title : t('No title'));

    $output = $title;
  }

  return $output;
}

/**
 * Callback to provide administrative information for a fieldable panels pane.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_admin_info($subtype, $conf) {
  return fieldable_panels_panes_fieldable_panels_pane_content_type_render($subtype, $conf);
}

/**
 * Form used to edit our content type.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form($form, &$form_state) {
  $conf = &$form_state['conf'];
  $subtype_name = $form_state['subtype_name'];

  if (!isset($form_state['entity'])) {
    $form_state['entity'] = fieldable_panels_panes_load_entity($subtype_name);
  }
  $entity = $form_state['entity'];

  // It's possible that we have a reference to an entity that is no longer valid.
  // If so, bail, because otherwise field API will whitescreen.
  if (!$entity) {
    $form['error'] = array(
      '#markup' => t('The pane entity referenced does not appear to be valid. It was probably deleted and you should remove this pane.'),
    );
    return $form;
  }

  ctools_form_include_file($form_state, $form_state['plugin']['path'] . '/' . $form_state['plugin']['file']);

  $entity_info = entity_get_info('fieldable_panels_pane');
  $view_mode_options = array();
  foreach ($entity_info['view modes'] as $mode => $option) {
    $view_mode_options[$mode] = $option['label'];
  }
  $form['view_mode'] = array(
    '#title' => t('View mode'),
    '#type' => 'select',
    '#description' => t('Select a view mode for this pane.'),
    '#options' => $view_mode_options,
    '#default_value' => $conf['view_mode'],
  );

  // If we're adding a reusable type, the only thing we want on the form is
  // the view mode, so skip the rest.
  if ($form_state['op'] == 'add' && !empty($form_state['subtype']['entity_id'])) {
    $form_state['no update entity'] = TRUE;
    return $form;
  }

  $form = fieldable_panels_panes_entity_edit_form($form, $form_state);

  $form['reusable']['warning'] = array(
    '#markup' => '<div class="description">' . t('Note: Editing any value on a reusable pane will change the value everywhere this pane is used.') . '</div>',
  );

  return $form;
}

/**
 * Validate submission of our content type edit form.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form_validate($form, &$form_state) {
  if (!empty($form_state['no update entity'])) {
    return;
  }

  if ($form_state['entity']) {
    fieldable_panels_panes_entity_edit_form_validate($form, $form_state);
  }
}

/**
 * Submit our content type edit form.
 */
function fieldable_panels_panes_fieldable_panels_pane_content_type_edit_form_submit($form, &$form_state) {
  $form_state['conf']['view_mode'] = $form_state['values']['view_mode'];

  if (!empty($form_state['no update entity'])) {
    return;
  }

  $entity = $form_state['entity'];
  if (!$entity) {
    return;
  }

  fieldable_panels_panes_entity_edit_form_submit($form, $form_state);
  if (!empty($entity->is_new)) {
    if (module_exists('uuid') && isset($entity->uuid)) {
      $entity_id = 'uuid:' . $entity->uuid;
    }
    else {
      $entity_id = 'fpid:' . $entity->fpid;
    }

    // @todo -- this won't work if $form_state does not contain
    // 'pane' which could theoretically happen in a non-Panels
    // use case. Not that anybody uses this outside of Panels.
    $form_state['pane']->subtype = $entity_id;
  }
}

// --------------------------------------------------------------------------
// Internal methods used by the above callbacks.

/**
 * Provide the default content types.
 *
 * These are all visible in the UI as the content types that allow a user
 * to add new panel pane entities that will then be stored in the database.
 */
function _fieldable_panels_panes_default_content_type() {
  $types = array();

  $entity_info = entity_get_info('fieldable_panels_pane');

  foreach ($entity_info['bundles'] as $bundle => $info) {
    $types[$bundle] = array(
      'name' => $bundle,
      'title' => $info['label'],
      'category' => !empty($info['pane category']) ? $info['pane category'] : t('Fielded panes'),
      'top level' => !empty($info['pane top level']) ? $info['pane top level'] : FALSE,
      'icon' => !empty($info['pane icon']) ? $info ['pane icon'] : NULL,
      'description' => t('Create a new custom entity.'),
      'all contexts' => TRUE,
      'bundle' => $bundle,
      'create content access' => 'fieldable_panels_panes_content_type_create_access',
    );
  }

  return $types;
}

/**
 * Return an info array for a specific custom content type.
 */
function _fieldable_panels_panes_custom_content_type($entity) {
  $info = array(
    'title' => check_plain($entity->admin_title),
    'description' => check_plain($entity->admin_description),
    'category' => $entity->category ? check_plain($entity->category) : t('Miscellaneous'),
    'all contexts' => TRUE,
    'icon' => 'icon_block_custom.png',
  );

  if (module_exists('uuid') && isset($entity->uuid)) {
    $info['name'] = 'uuid:' . $entity->uuid;
  }
  else {
    $info['name'] = 'fpid:' . $entity->fpid;
  }

  $info['entity_id'] = $info['name'];
  return $info;
}

/**
 * Properly load the entity the subtype.
 */
function fieldable_panels_panes_load_entity($subtype_name) {
  ctools_include('content');
  $plugin = ctools_get_content_type('fieldable_panels_pane');

  // Next, check to see how the subtype is configured.
  $subtype_info = ctools_content_get_subtype($plugin, $subtype_name);

  // This means we're probably in the process of creating a new one.
  if (isset($subtype_info['bundle'])) {
    $values = array(
      'bundle' => $subtype_info['bundle'],
      'category' => isset($subtype_info['category']) ? $subtype_info['category'] : '',
    );
    return fieldable_panels_panes_create($values);
  }

  // And try it this way.
  if (isset($subtype_info['entity_id'])) {
    return _fieldable_panels_panes_load_entity($subtype_info['entity_id']);
  }

  // Finally, try this:
  return _fieldable_panels_panes_load_entity($subtype_name);
}

/**
 * Properly load the entity via $subtype_name
 */
function _fieldable_panels_panes_load_entity($subtype_name) {
  list($type, $id) = explode(':', $subtype_name);
  if ($type == 'uuid' && module_exists('uuid')) {
    $ids = entity_get_id_by_uuid('fieldable_panels_pane', array($id));
    if ($content = entity_load('fieldable_panels_pane', $ids)) {
      $content = reset($content);
    }
  }
  elseif ($type == 'vid') {
    $fpid = db_query('SELECT fpid FROM {fieldable_panels_panes_revision} WHERE vid = :vid', array(':vid' => $id))->fetchField();
    $content = fieldable_panels_panes_load($fpid, $id);
  }
  else {
    $content = fieldable_panels_panes_load($id);
  }

  return $content;
}

/**
 * Access callback for creating a new content type.
 */
function fieldable_panels_panes_content_type_create_access($type, $subtype) {
  return fieldable_panels_panes_access('create', $subtype['name']);
}
