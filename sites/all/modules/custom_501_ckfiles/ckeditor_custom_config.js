/*
Copyright (c) 2003-2012, CKSource - Frederico Knabben. All rights reserved.
For licensing, see LICENSE.html or http://ckeditor.com/license
*/

CKEDITOR.editorConfig = function( config )
{
	config.templates_files = [ '/sites/all/modules/custom_501_ckfiles/templates.js' ];
	config.templates = 'custom';
	config.templates_replaceContent = false;
	
	config.stylesSet = [];
	config.plugins += ",stylesheetparser"; // Comment out if you need names defined below.
	// Comment in if you need names instead of tag.class listing.
	// config.stylesSet = 
	// [
	//  { name : 'Page Title'		, element : 'h1', attributes : {'class': 'title'} },
	// 	{ name : 'Subheader'		, element : 'h2', attributes : {'class': 'subheader'} },
	// 	{ name : 'Normal Text'		, element : 'p', attributes : {'class': 'normal'} },
	// 	{ name : 'List'		, element : 'ul', attributes : {'class': 'normal'} },
	// ];

};
