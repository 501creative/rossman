<?php
/**
 * @file
 * custom_501_maps.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function custom_501_maps_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'location_block_map';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'location' => 'location',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-mp23-block_1' => array(
          'module' => 'views',
          'delta' => 'mp23-block_1',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['location_block_map'] = $context;

  return $export;
}
