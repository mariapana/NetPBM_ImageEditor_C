#include "rotate.h"
#include "rotate_ss.h"
#include "rotate_wi.h"

#define MAXDEG 360

// ss = square selection; wi = whole image

// wrapper
void rotate_ss_90(image photo)
{
	// determine map type (bitmap / pixmap)
	if (photo.type == '2' || photo.type == '5')
		// bitmap
		rotate_ss_bitmap_90(photo);
	else
		// pixmap
		rotate_ss_pixmap_90(photo);
}

// wrapper
void rotate_ss_180(image photo)
{
	// determine map type (bitmap / pixmap)
	if (photo.type == '2' || photo.type == '5')
		// bitmap
		rotate_ss_bitmap_180(photo);
	else
		// pixmap
		rotate_ss_pixmap_180(photo);
}

// wrapper
void rotate_ss_270(image photo)
{
	// determine map type (bitmap / pixmap)
	if (photo.type == '2' || photo.type == '5')
		// bitmap
		rotate_ss_bitmap_270(photo);
	else
		// pixmap
		rotate_ss_pixmap_270(photo);
}

// wrapper
void rotate_wi_90(image *photo)
{
	// determine map type (bitmap / pixmap)
	if (photo->type == '2' || photo->type == '5')
		// bitmap
		rotate_wi_bitmap_90(photo, &photo->bitmap);
	else
		// pixmap
		rotate_wi_pixmap_90(photo, &photo->pixmap);
}

// wrapper
void rotate_wi_180(image *photo)
{
	// determine map type (bitmap / pixmap)
	if (photo->type == '2' || photo->type == '5')
		// bitmap
		rotate_wi_bitmap_180(photo);
	else
		// pixmap
		rotate_wi_pixmap_180(photo);
}

// wrapper
void rotate_wi_270(image *photo)
{
	// determine map type (bitmap / pixmap)
	if (photo->type == '2' || photo->type == '5')
		// bitmap
		rotate_wi_bitmap_270(photo, &photo->bitmap);
	else
		// pixmap
		rotate_wi_pixmap_270(photo, &photo->pixmap);
}

void rotate(image *photo, FILE *input)
{
	// read angle
	int angle;
	scanf("%d", &angle);

	// check if image is loaded
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	// check angle validity
	if (angle % 90 != 0 || angle < -360 || angle > 360) {
		printf("Unsupported rotation angle\n");
		return;
	}

	// +-90 <=> -+270
	// +180 <=> -180
	// +-360, 0 <=> the picture remains the same after rotation
	int abs_angle;
	if (angle < 0)
		abs_angle = angle + MAXDEG;
	else
		abs_angle = angle;

	// determine rotation type (whole image / square selection)
	int slct_width = photo->x2 - photo->x1;
	int slct_height = photo->y2 - photo->y1;

	if (slct_width == photo->width && slct_height == photo->height) {
		// rotate the whole image
		switch (abs_angle) {
		case 90:
			rotate_wi_90(photo);
			break;
		case 180:
			rotate_wi_180(photo);
			break;
		case 270:
			rotate_wi_270(photo);
			break;
		}
		printf("Rotated %d\n", angle);
		return;
	}

	if (slct_width != slct_height) {
		// selection should have been square
		printf("The selection must be square\n");
		return;
	}

	// rotate the square selection
	switch (abs_angle) {
	case 90:
		rotate_ss_90(*photo);
		break;
	case 180:
		rotate_ss_180(*photo);
		break;
	case 270:
		rotate_ss_270(*photo);
		break;
	}

	printf("Rotated %d\n", angle);
}
