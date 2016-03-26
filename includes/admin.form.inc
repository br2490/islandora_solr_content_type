<?php 
/**
 * @file 
 * Decription TK
 */

/**
 * Implements hook_form().
 */
function islandora_solr_content_type_config($form, &$form_state) {
  
  $form['comment_islandora_solr_content_type'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => array (
      0 => t('Disable and disallow comments by default. (default)'),
      1 => t('Enable and allow comments by default.'),
    ),
    '#title' => t('Default to use for <em>Comments</em> when creating a new ISCT.'),
    '#description' => t('<strong>Note:</strong> This can be overriden on each individual page.'),
    '#default_value' => variable_get('comment_islandora_solr_content_type', '0'),
  );
  
  $form['node_submitted_islandora_solr_content_type'] = array(
    '#type' => 'radios',
    '#required' => TRUE,
    '#options' => array (
      0 => t('Do <strong>not</strong> diplay authorship and timestamp on pages. (default)'),
      1 => t('Display authorship and timestampe on pages.'),
    ),
    '#title' => t('Hide authorship and timestamp on all ISCT pages.'),
    '#default_value' => variable_get('node_submitted_islandora_solr_content_type', '0'),
  );
  
  $form['pathauto_node_islandora_solr_content_type_pattern'] = array(
    '#type' => 'textfield',
    '#title' => t('Automatic Path Setting'),
    '#default_value' => variable_get('pathauto_node_islandora_solr_content_type_pattern', 'collections/[node:title]'),
  );

  $form['isct_menu_by_default'] = array(
    '#type' => 'radios',
    '#options' => array (
      1 => t('Enabled'),
      0 => t('Disabled'),
    ),
    '#title' => t('By default add new Islandora Solr Content to a menu?'),
    '#description' => t('This can be override by anyone with access administer menu.'),
    '#default_value' => variable_get('isct_menu_by_default', '0'),
  );
  
  $options = menu_parent_options(menu_get_menus(), 0); // Should this be restricted to "main-menu"? Implications? Use Cases?

  $form['menu_parent_islandora_solr_content_type'] = array(
    '#type' => 'select',
    '#title' => t('Parent item'),
    '#states' => array(
      'invisible' => array(
        'input[name="isct_menu_by_default"]' => array('value' => 0),
      ),
    ),
    '#default_value' => variable_get('menu_parent_islandora_solr_content_type', ''),
    '#options' => $options,
  );

  return system_settings_form($form);
}