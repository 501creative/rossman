<?php
/**
 * @file
 * homepage_panel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function homepage_panel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels" && $api == "layouts") {
    return array("version" => "1");
  }
}
