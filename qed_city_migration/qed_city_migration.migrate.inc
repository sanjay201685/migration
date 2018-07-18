<?php

/**
 * @file
 * When hook_migrate_api is invoked by the Migrate module this file is automatically
 * loaded - thus, we don't need to implement in the .module file.
 */

/*
 * Implements hook_migrate_api().
 */
function qed_city_migration_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'qed_city_migrate' => array(
        'title' => t('Migrate Cities'),
      )
    ),
    'migrations' => array(
      'QedCities' => array(
        'class_name' => 'CitiesMigration',
        'group_name' => 'qed_city_migrate',
      ),
    ),
  );
  return $api;
}
