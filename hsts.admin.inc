<?php

/**
 * @file
 * Admininstrative forms for hsts module.
 */

/**
 * Implements hook_form().
 *
 * Settings form
 */
function hsts_admin_settings_form() {
  $form = array();
  $config = config('hsts.settings');

  $form['hsts_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable HTTP Strict Transport Security'),
    '#description' => t('Whether to start adding the HSTS header information or not.'),
    '#default_value' => $config->get('enabled'),
  );

  $form['hsts_https_only'] = array(
    '#type' => 'checkbox',
    '#title' => t('Restrict the HSTS header only for HTTPS (a.k.a. do not include on HTTP only requests).'),
    '#description' => t('!url. Uncheck this only if you are behind an SSL terminated load balancer.', array(
      '!url' => l(t('For security reasons, an HSTS Host MUST NOT include the STS header field in HTTP responses conveyed over non-secure transport'), 'http://tools.ietf.org/html/draft-ietf-websec-strict-transport-sec-14#section-7.2', array('external' => TRUE)),
    )),
    '#default_value' => $config->get('https_only'),
    '#states' => array(
      'disabled' => array(
        ':input[name=hsts_enabled]' => array('checked' => FALSE),
      ),
    ),
  );

  $form['hsts_max_age'] = array(
    '#type' => 'textfield',
    '#title' => t('Max Age'),
    '#description' => t('The maximum age value for the header in seconds. See the <a href="http://lists.w3.org/Archives/Public/www-archive/2009Sep/att-0051/draft-hodges-strict-transport-sec-05.plain.html#syntax">Strict Transport Security Definition</a> for more information.'),
    '#default_value' => $config->get('max_age'),
    '#maxlength' => 9,
    '#size' => 11,
  );

  $form['hsts_subdomains'] = array(
    '#type' => 'checkbox',
    '#title' => t('Include subdomains'),
    '#description' => t('Whether to include the subdomains as part of the HSTS implementation.'),
    '#default_value' => $config->get('subdomains'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );

  return $form;
}

/**
 * Implements hook_validate().
 *
 * @param $form
 * @param $form_state
 */
function hsts_admin_settings_form_validate($form, &$form_state) {
  if (!is_numeric($form_state['values']['hsts_max_age']) || $form_state['values']['hsts_max_age'] < 0) {
    form_set_error('hsts_max_age', t('Value is not a number or out of bounds.'));
  }
}

/**
 * Implements hook_submit().
 *
 * @param $form
 * @param $form_state
 */
function hsts_admin_settings_form_submit($form, &$form_state) {
  $config = config('hsts.settings');
  $values = $form_state['values'];
  $config->set('enabled', (bool) $values['hsts_enabled']);
  $config->set('https_only', (bool) $values['hsts_https_only']);
  $config->set('max_age', $values['hsts_max_age']);
  $config->set('subdomains', (bool) $values['hsts_subdomains']);
  $config->save();
}
