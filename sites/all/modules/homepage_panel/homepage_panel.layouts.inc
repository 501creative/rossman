<?php
/**
 * @file
 * homepage_panel.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function homepage_panel_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'home';
  $layout->admin_title = 'Home';
  $layout->admin_description = 'Home layout';
  $layout->category = 'Misc';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 3,
          1 => 1,
          2 => 2,
        ),
        'parent' => 'canvas',
      ),
      1 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'big_button_left',
          1 => 'big_button_center',
          2 => 'big_button_right',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'news',
          1 => 'flex_left',
          2 => 'flex_center',
          3 => 'flex_right',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'big_button_left' => array(
        'type' => 'region',
        'title' => 'big-button-left',
        'width' => '39.84518957887799',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'big_button_center' => array(
        'type' => 'region',
        'title' => 'big-button-center',
        'width' => '23.721695614742412',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'big_button_right' => array(
        'type' => 'region',
        'title' => 'big-button-right',
        'width' => '36.4331148063796',
        'width_type' => '%',
        'parent' => '1',
        'class' => '',
      ),
      'news' => array(
        'type' => 'region',
        'title' => 'news',
        'width' => '31.24041886829714',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'flex_left' => array(
        'type' => 'region',
        'title' => 'flex-left',
        'width' => '15.233044191737362',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'flex_center' => array(
        'type' => 'region',
        'title' => 'flex-center',
        'width' => '21.329801315811014',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      'flex_right' => array(
        'type' => 'region',
        'title' => 'flex-right',
        'width' => '26.35105239588422',
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 5,
        ),
        'parent' => 'main',
        'class' => '',
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 9,
        ),
        'class' => '',
      ),
      5 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '3',
        'children' => array(
          0 => 10,
          1 => 6,
          2 => 7,
          3 => 8,
        ),
        'class' => '',
      ),
      6 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'button_top',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'button_top' => array(
        'type' => 'region',
        'title' => 'button-top',
        'width' => 100,
        'width_type' => '%',
        'parent' => '6',
        'class' => '',
      ),
      7 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'button_middle',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'button_middle' => array(
        'type' => 'region',
        'title' => 'button-middle',
        'width' => 100,
        'width_type' => '%',
        'parent' => '7',
        'class' => '',
      ),
      8 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'button_bottom',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'button_bottom' => array(
        'type' => 'region',
        'title' => 'button-bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '8',
        'class' => '',
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'slideshow',
        ),
        'parent' => '4',
        'class' => '',
      ),
      'slideshow' => array(
        'type' => 'region',
        'title' => 'slideshow',
        'width' => 100,
        'width_type' => '%',
        'parent' => '9',
        'class' => '',
      ),
      10 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'button_column_text',
        ),
        'parent' => '5',
        'class' => '',
      ),
      'button_column_text' => array(
        'type' => 'region',
        'title' => 'Button Column Text',
        'width' => 100,
        'width_type' => '%',
        'parent' => '10',
        'class' => '',
      ),
    ),
  );
  $export['home'] = $layout;

  return $export;
}
