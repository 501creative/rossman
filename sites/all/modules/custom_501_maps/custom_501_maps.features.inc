<?php
/**
 * @file
 * custom_501_maps.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function custom_501_maps_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function custom_501_maps_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function custom_501_maps_node_info() {
  $items = array(
    'location' => array(
      'name' => t('Location'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
