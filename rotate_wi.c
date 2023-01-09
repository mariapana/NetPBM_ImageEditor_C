#include "rotate_wi.h"

// WHOLE IMAGE ROTATIONS

// 90 degrees

void rotate_wi_bitmap_90(image *photo, bit ***bitmap)
{
	// alloc new bitmap; inversed dimensions
	bit **new_bitmap = NULL;
	alloc_bitmap(photo->width, photo->height, &new_bitmap);

	if (!new_bitmap)
		return;

	// fill new bitmap
	for (int i = 0; i < photo->height; i++)
		for (int j = 0; j < photo->width; j++)
			new_bitmap[j][photo->height - i - 1].val = photo->bitmap[i][j].val;

	// free old bitmap
	free_bitmap(photo->height, photo->bitmap);

	// update photo
	*bitmap = new_bitmap;
	swap(&photo->width, &photo->height);
	swap(&photo->x2, &photo->y2);
}

void rotate_wi_pixmap_90(image *photo, pixel ***pixmap)
{
	// alloc new bitmap; inversed dimensions
	pixel **new_pixmap = NULL;
	alloc_pixmap(photo->width, photo->height, &new_pixmap);

	if (!new_pixmap)
		return;

	// fill new bitmap
	for (int i = 0; i < photo->height; i++) {
		for (int j = 0; j < photo->width; j++) {
			new_pixmap[j][photo->height - i - 1].r = photo->pixmap[i][j].r;
			new_pixmap[j][photo->height - i - 1].g = photo->pixmap[i][j].g;
			new_pixmap[j][photo->height - i - 1].b = photo->pixmap[i][j].b;
		}
	}

	// free old bitmap
	free_pixmap(photo->height, photo->pixmap);

	// update photo
	*pixmap = new_pixmap;
	swap(&photo->width, &photo->height);
	swap(&photo->x2, &photo->y2);
}

// 180 degrees - no need for new bitmap / pixmap

void rotate_wi_bitmap_180(image *photo)
{
	rotate_ss_bitmap_180(*photo);
}

void rotate_wi_pixmap_180(image *photo)
{
	rotate_ss_pixmap_180(*photo);
}

// 270 degrees
void rotate_wi_bitmap_270(image *photo, bit ***bitmap)
{
	// alloc new bitmap; inversed dimensions
	bit **new_bitmap = NULL;
	alloc_bitmap(photo->width, photo->height, &new_bitmap);

	if (!new_bitmap)
		return;

	// fill new bitmap
	for (int i = 0; i < photo->height; i++)
		for (int j = 0; j < photo->width; j++)
			new_bitmap[photo->width - j - 1][i].val = photo->bitmap[i][j].val;

	// free old bitmap
	free_bitmap(photo->height, photo->bitmap);

	// update photo
	*bitmap = new_bitmap;
	swap(&photo->width, &photo->height);
	swap(&photo->x2, &photo->y2);
}

void rotate_wi_pixmap_270(image *photo, pixel ***pixmap)
{
	// alloc new bitmap; inversed dimensions
	pixel **new_pixmap = NULL;
	alloc_pixmap(photo->width, photo->height, &new_pixmap);

	if (!new_pixmap)
		return;

	// fill new bitmap
	for (int i = 0; i < photo->height; i++) {
		for (int j = 0; j < photo->width; j++) {
			new_pixmap[photo->width - j - 1][i].r = photo->pixmap[i][j].r;
			new_pixmap[photo->width - j - 1][i].g = photo->pixmap[i][j].g;
			new_pixmap[photo->width - j - 1][i].b = photo->pixmap[i][j].b;
		}
	}

	// free old bitmap
	free_pixmap(photo->height, photo->pixmap);

	// update photo
	*pixmap = new_pixmap;
	swap(&photo->width, &photo->height);
	swap(&photo->x2, &photo->y2);
}
