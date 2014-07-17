<?php
/**
 * @file
 * custom_501_maps.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function custom_501_maps_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'mp23';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Multi-Location Map';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'gmap';
  $handler->display->display_options['style_options']['markertype'] = 'letters';
  $handler->display->display_options['style_options']['latfield'] = 'title';
  $handler->display->display_options['style_options']['lonfield'] = 'title';
  $handler->display->display_options['style_options']['markerfield'] = 'title';
  $handler->display->display_options['style_options']['enablermt'] = 0;
  $handler->display->display_options['style_options']['rmtfield'] = 'title';
  $handler->display->display_options['style_options']['center_on_nodearg'] = 1;
  $handler->display->display_options['style_options']['center_on_nodearg_arg'] = 'null';
  $handler->display->display_options['style_options']['highlight_nodearg_arg'] = 'null';
  $handler->display->display_options['style_options']['tooltipfield'] = 'title';
  $handler->display->display_options['style_options']['bubbletextenabled'] = 1;
  $handler->display->display_options['style_options']['bubbletextfield'] = 'field_location_3';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_location_3']['id'] = 'field_location_3';
  $handler->display->display_options['fields']['field_location_3']['table'] = 'field_data_field_location_3';
  $handler->display->display_options['fields']['field_location_3']['field'] = 'field_location_3';
  $handler->display->display_options['fields']['field_location_3']['label'] = '';
  $handler->display->display_options['fields']['field_location_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_location_3']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_location_3']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_location_3']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_location_3']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_location_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_location_3']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_location_3']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_location_3']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_location_3']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_location_3']['field_api_classes'] = 0;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Global: Null */
  $handler->display->display_options['arguments']['null']['id'] = 'null';
  $handler->display->display_options['arguments']['null']['table'] = 'views';
  $handler->display->display_options['arguments']['null']['field'] = 'null';
  $handler->display->display_options['arguments']['null']['default_action'] = 'default';
  $handler->display->display_options['arguments']['null']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['null']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['null']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['null']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['null']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['null']['must_not_be'] = 0;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'location' => 'location',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $export['mp23'] = $view;

  return $export;
}
