<?php

/**
 * Implements hook_form().
 */
function qedcities_form($form, &$form_state, $qedcities = NULL) {
  $form = array();

  $form['city_id'] = array(
    '#title' => t('City ID'),
    '#type' => 'textfield',
    '#default_value' => isset($qedcities->city_id) ? $qedcities->city_id : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['city_name'] = array(
    '#title' => t('City Name'),
    '#type' => 'textfield',
    '#default_value' => isset($qedcities->city_name) ? $qedcities->city_name : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['city_location'] = array(
    '#title' => t('City Loation'),
    '#type' => 'textfield',
    '#default_value' => isset($qedcities->city_location) ? $qedcities->city_location : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['city_pop'] = array(
    '#title' => t('City Population'),
    '#type' => 'textfield',
    '#default_value' => isset($qedcities->city_pop) ? $qedcities->city_pop : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );
  $form['city_state'] = array(
    '#title' => t('City State'),
    '#type' => 'textfield',
    '#default_value' => isset($qedcities->city_state) ? $qedcities->city_state : '',
    '#required' => TRUE,
    '#maxlength' => 255,
  );

  field_attach_form('qedcities', $qedcities, $form, $form_state);

  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => isset($qedcities->id) ? t('Update') : t('Save'),
    ),
    'delete_link' => array(
      '#markup' => isset($qedcities->id) ? l(t('Delete'), 'admin/content/qedcities/manage/' . $qedcities->id . '/delete', array('attributes' => array('id' => array('qedcities-delete-' . $qedcities->id), 'class' => array('button remove')), 'query' => array('destination' => 'admin/content/qedcities'))) : ''
    ),
    'cancel' => ['#markup' => l(t('Cancel'), '/admin/content/qedcities')]
  );

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function qedcities_form_validate($form, &$form_state) {
  
}

/**
 * Implements hook_form_submit().
 */
function qedcities_form_submit($form, &$form_state) {
  $qedcities = entity_ui_form_submit_build_entity($form, $form_state);
  $qedcities->save();
  drupal_set_message(t('@city_name city has been saved.', array('@city_name' => $qedcities->city_name)));
  $form_state['redirect'] = 'admin/content/qedcities';
  $form_state['redirect'] = 'qedcities/' . $qedcities->id;
}
