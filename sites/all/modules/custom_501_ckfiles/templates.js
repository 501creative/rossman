// Register a template definition set named "default".
CKEDITOR.addTemplates('custom',
{
	// The name of the subfolder that contains the preview images of the templates.
//	imagesPath:CKEDITOR.getUrl(CKEDITOR.plugins.getPath('templates')+'templates/images/'),
	imagesPath : CKEDITOR.getUrl('/sites/all/modules/custom_501_ckfiles/img/'),
 
	// Template definitions.
	templates :
		[
			{
				title: 'Image Right',
				image: 'image-right.png',
				description: 'Image and Caption aligned right.',
				html:
					'<div class="image-right">' +
					'<img src="" alt="">' +
					'<p class="caption">Type caption here</p>' +
					'</div>'
			},
			{
				title: 'Image Left',
				image: 'image-left.png',
				description: 'Image and Caption aligned left.',
				html:
					'<div class="image-left">' +
					'<img src="" alt="">' +
					'<p class="caption">Type caption here</p>' +
					'</div>'
			}
		]
});