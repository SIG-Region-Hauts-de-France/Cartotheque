<?php

/**
 * Implements hook_drush_command().
 */

function content_types_command_drush_command() {

	$items = array();

	$items['import-data'] = array(
		'description' => dt('Import content type'),
		'callback' => 'drush_import_data',
		'aliases' => array('cdi')
	);

	return $items;
}

function drush_import_data() {

	$module_path = drupal_get_path('module', 'content_types_command') . '/var';
	$files = array_diff(scandir($module_path), array('..', '.'));

	foreach($files as $file) {

		drupal_set_message('--- Debut de l\'import du fichier ' . $file . ' ---');

		$file_contents = file_get_contents($module_path . '/' . $file);
		$form = drupal_get_form('bundle_copy_import');
		$form_state['values']['macro'] = $file_contents;
		bundle_copy_import_submit($form, $form_state);

		drupal_set_message('--- Fin de l\'import du fichier ' . $file . ' ---');
	}
}
