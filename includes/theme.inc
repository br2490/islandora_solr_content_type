<?php
/**
 * @file
 * Collection page THEME modifications.
 */

/**
 * Implements theme_preprocess_page().
 *
 * @param $vars
 */
function islandora_solr_content_type_preprocess_page(&$vars) {
  // This code allows page level themeing based on the type of NODE.
  if (isset($vars['node']) &&
    $vars['node']->type == 'islandora_solr_content_type'
  ) {
    if (!(bool) strpos(current_path(), 'edit')) {
      $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
    } // else { do some edit page theming or nothing... }
  }
}

/**
 * Implements hook_theme().
 *
 * @param $existing
 * @param $type
 * @param $theme
 * @param $path
 *
 * @return array
 */
function islandora_solr_content_type_theme($existing, $type, $theme, $path) {
  $theme = array();

  // Content page template (i.e. what the end-user sees)
  $theme['page__node__islandora_solr_content_type'] = array(
    'render element' => 'content',
    'base hook'      => 'page',
    'template'       => 'page--node--islandora_solr_content_type',
    'path'           => drupal_get_path('module',
        'islandora_solr_content_type') . '/templates',
  );

  return $theme;
}
// vim: set filetype=php:
