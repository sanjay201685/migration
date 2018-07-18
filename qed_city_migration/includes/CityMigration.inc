<?php

/**
 * @file
 * Handlers for Cities migrations.
 */

/**
 * Class CitiesMigration handles the migration of the Cities.
 */
class CitiesMigration extends Migration {

  public function __construct($arguments) {
    parent::__construct($arguments);

    // Json Source URL
    $list_url = drupal_get_path('module', 'qed_city_migration') . '/data/cities.json';

    // Define mongo db username and password to connect with mongo
    //$mongo_db_conn = 'mongodb://mongo:mongo@localhost:27017/qed_migrate';
    //$mdb = new MongoClient($mongo_db_conn);

    $this->description = t('Cities.');

    // Define source.
    $this->source = new MigrateSourceJSON($list_url, '_id');

    // Define destination.
    $this->destination = new MigrateDestinationEntityAPI('qedcities', 'qedcities');

    $this->map = new MigrateSQLMap($this->machineName, array(
      '_id' => array(
        'type' => 'varchar',
        'length' => 255,
        'description' => 'ID',
        'not null' => TRUE,
      ),
        ), MigrateDestinationEntityAPI::getKeySchema('qedcities')
    );

    // addFieldMapping(Destination, Source)
        /*$qed_maped_field = variable_get('qed_migrate_field_map');
    $exp_map_field = explode("\n", $qed_maped_field);
    
    for($i = 0; $i < count($exp_map_field); $i++) {
      $exp_fields = explode(":", $exp_map_field[$i]);
      $this->addFieldMapping($exp_fields[0], $exp_fields[1]);  
    }*/

    $this->addFieldMapping('city_id', '_id');
    $this->addFieldMapping('city_name', 'city');
    $this->addFieldMapping('city_pop', 'pop');
    $this->addFieldMapping('city_state', 'state');
    $this->addFieldMapping('city_location', 'location');
  }
  
  // Prepare row to migrate from mongo to drupal.
  public function prepareRow($row) {
    if (!empty($row->loc)) {
      $row->location = $row->loc[0] . ', ' . $row->loc[1];
    }
    else {
      $row->location = '';
    }
  }
}
