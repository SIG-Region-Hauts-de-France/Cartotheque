<?php

/**
 * @file
 * Defines PostgresSQL Combine Filter Views
 */

/**
 * Implements hook_views_data_alter()
 */
 
function pgsql_combine_filter_views_views_data_alter(&$data) {
	$data['node']['pgsql_combine_filter_views']['title'] = 'PostgresSQL insensitive/unaccent search';
	$data['node']['pgsql_combine_filter_views']['help'] = 'A filter that allow case insensitive and unaccent searches for postgres db on multiple fields.';
	$data['node']['pgsql_combine_filter_views']['filter']['handler'] = 'pgsql_combine_filter_views_handler';
}
