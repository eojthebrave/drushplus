<?php
/**
 * @file
 */

/**
 * Implements of hook_drush_command().
 */
function drushplus_files_drush_command() {
  $items = array();

  $items['drushplus_files'] = array(
    'description' => "Update file paths in {files} table.",
		'arguments' => array(
			'from' => 'Path to convert from i.e) sites/example.com/files',
			'to' => 'Path to conver to i.e) sites/default/files',
		),
    'aliases' => array('dplus-files'),
  );

  return $items;
}

function drush_drushplus_files($from, $to) {
	if(!drush_confirm(dt('Do you really want to convert all paths in {files} from @from to @to?', array('@from' => $from, '@to' => $to)))) {
		return drush_user_abort();
	}

	db_query('UPDATE {files} SET filepath = REPLACE(filepath,"%s","%s")', $from, $to);
	drush_log(dt('Converted all file paths.'), 'ok');
}
