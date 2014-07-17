<?php

function custom_501_site_description_form($form_state)
{
	$form = array();
	$form['description'] = array(
		'#type' => 'textarea',
		'#title' => t('Site Description'),
		'#default_value' => variable_get('custom_501_site_description', ''),
		'#required' => true,
	);
	$form['submit'] = array(
		'#type' => 'submit',
		'#value' => t('Update'),
	);
	return $form;
}

function custom_501_site_description_form_submit($form, &$form_state)
{
	variable_set('custom_501_site_description', $form_state['values']['description']);
	drupal_set_message(t('Site description has been updated'));
}