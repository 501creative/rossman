<?php
/**
 * @file
 * homepage_panel.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function homepage_panel_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'home';
  $page->task = 'page';
  $page->admin_title = 'home';
  $page->admin_description = '';
  $page->path = 'home';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_home_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'home';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'panels_everywhere_site_template' => 'site_template_panel_context',
  );
  $display = new panels_display();
  $display->layout = 'flexible:home';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'big_button_left' => NULL,
      'big_button_center' => NULL,
      'big_button_right' => NULL,
      'news' => NULL,
      'flex_left' => NULL,
      'flex_center' => NULL,
      'flex_right' => NULL,
      'button_top' => NULL,
      'button_middle' => NULL,
      'button_bottom' => NULL,
      'slideshow' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '0dbc201b-39d6-4065-86f1-9528d70742bd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b4f355e4-4f68-4f96-9b7f-2397c18f6b33';
    $pane->panel = 'big_button_center';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:14';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b4f355e4-4f68-4f96-9b7f-2397c18f6b33';
    $display->content['new-b4f355e4-4f68-4f96-9b7f-2397c18f6b33'] = $pane;
    $display->panels['big_button_center'][0] = 'new-b4f355e4-4f68-4f96-9b7f-2397c18f6b33';
    $pane = new stdClass();
    $pane->pid = 'new-374ab82c-74d6-4802-94ca-e00614475287';
    $pane->panel = 'big_button_left';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:13';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '374ab82c-74d6-4802-94ca-e00614475287';
    $display->content['new-374ab82c-74d6-4802-94ca-e00614475287'] = $pane;
    $display->panels['big_button_left'][0] = 'new-374ab82c-74d6-4802-94ca-e00614475287';
    $pane = new stdClass();
    $pane->pid = 'new-de453ac9-2ac1-4ec3-b233-037c4a416d3a';
    $pane->panel = 'big_button_right';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:12';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'de453ac9-2ac1-4ec3-b233-037c4a416d3a';
    $display->content['new-de453ac9-2ac1-4ec3-b233-037c4a416d3a'] = $pane;
    $display->panels['big_button_right'][0] = 'new-de453ac9-2ac1-4ec3-b233-037c4a416d3a';
    $pane = new stdClass();
    $pane->pid = 'new-bb013fa7-7121-42ab-8092-3c71a918fc56';
    $pane->panel = 'button_bottom';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'bb013fa7-7121-42ab-8092-3c71a918fc56';
    $display->content['new-bb013fa7-7121-42ab-8092-3c71a918fc56'] = $pane;
    $display->panels['button_bottom'][0] = 'new-bb013fa7-7121-42ab-8092-3c71a918fc56';
    $pane = new stdClass();
    $pane->pid = 'new-29f3c896-2980-4f67-8ab4-a74d200d3bfd';
    $pane->panel = 'button_middle';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29f3c896-2980-4f67-8ab4-a74d200d3bfd';
    $display->content['new-29f3c896-2980-4f67-8ab4-a74d200d3bfd'] = $pane;
    $display->panels['button_middle'][0] = 'new-29f3c896-2980-4f67-8ab4-a74d200d3bfd';
    $pane = new stdClass();
    $pane->pid = 'new-719ba159-8daf-4640-b447-1091632fc41f';
    $pane->panel = 'button_top';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '719ba159-8daf-4640-b447-1091632fc41f';
    $display->content['new-719ba159-8daf-4640-b447-1091632fc41f'] = $pane;
    $display->panels['button_top'][0] = 'new-719ba159-8daf-4640-b447-1091632fc41f';
    $pane = new stdClass();
    $pane->pid = 'new-954a853b-8158-4723-853f-720ac5044949';
    $pane->panel = 'flex_center';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:10';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '954a853b-8158-4723-853f-720ac5044949';
    $display->content['new-954a853b-8158-4723-853f-720ac5044949'] = $pane;
    $display->panels['flex_center'][0] = 'new-954a853b-8158-4723-853f-720ac5044949';
    $pane = new stdClass();
    $pane->pid = 'new-4cdf6f2d-833c-4237-96d5-150ec775015b';
    $pane->panel = 'flex_left';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4cdf6f2d-833c-4237-96d5-150ec775015b';
    $display->content['new-4cdf6f2d-833c-4237-96d5-150ec775015b'] = $pane;
    $display->panels['flex_left'][0] = 'new-4cdf6f2d-833c-4237-96d5-150ec775015b';
    $pane = new stdClass();
    $pane->pid = 'new-872708cf-2ea7-4d5e-9ba6-97d00a30d7d1';
    $pane->panel = 'flex_right';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:11';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '872708cf-2ea7-4d5e-9ba6-97d00a30d7d1';
    $display->content['new-872708cf-2ea7-4d5e-9ba6-97d00a30d7d1'] = $pane;
    $display->panels['flex_right'][0] = 'new-872708cf-2ea7-4d5e-9ba6-97d00a30d7d1';
    $pane = new stdClass();
    $pane->pid = 'new-b88fbf62-d81a-4910-a9bf-459fad17d3bd';
    $pane->panel = 'slideshow';
    $pane->type = 'fieldable_panels_pane';
    $pane->subtype = 'fpid:6';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b88fbf62-d81a-4910-a9bf-459fad17d3bd';
    $display->content['new-b88fbf62-d81a-4910-a9bf-459fad17d3bd'] = $pane;
    $display->panels['slideshow'][0] = 'new-b88fbf62-d81a-4910-a9bf-459fad17d3bd';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['home'] = $page;

  return $pages;

}
