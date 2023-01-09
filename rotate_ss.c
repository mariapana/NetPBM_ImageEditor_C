#include "rotate_ss.h"

// SQUARE SELECTION ROTATIONS

// 90 degrees

void rotate_ss_bitmap_90(image photo)
{
	bit **aux = NULL;
	alloc_bitmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	// parse the original submatrix according to the angle and initialize it
	for (int i = photo.y1; i < photo.y2; i++)
		for (int j = photo.x1; j < photo.x2; j++) {
			// indexing for aux starts at 0
			int new_i = j - photo.x1;
			int new_j = photo.x2 - photo.x1 - (i - photo.y1) - 1;
			aux[new_i][new_j].val = photo.bitmap[i][j].val;
		}

	// copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_bitmap(photo.bitmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_bitmap(photo.y2 - photo.y1, aux);
}

void rotate_ss_pixmap_90(image photo)
{
	pixel **aux = NULL;
	alloc_pixmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	// parse the original submatrix according to the angle and initialize it
	for (int i = photo.y1; i < photo.y2; i++) {
		for (int j = photo.x1; j < photo.x2; j++) {
			// indexing for aux starts at 0
			int new_i = j - photo.x1;
			int new_j = photo.x2 - photo.x1 - (i - photo.y1) - 1;
			aux[new_i][new_j].r = photo.pixmap[i][j].r;
			aux[new_i][new_j].g = photo.pixmap[i][j].g;
			aux[new_i][new_j].b = photo.pixmap[i][j].b;
		}
	}
	//copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_pixmap(photo.pixmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_pixmap(photo.y2 - photo.y1, aux);
}

// 180 degrees

void rotate_ss_bitmap_180(image photo)
{
	bit **aux = NULL;
	alloc_bitmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	for (int i = photo.y1; i < photo.y2; i++)
		for (int j = photo.x1; j < photo.x2; j++) {
			// new_i = photo.y2 - photo.y1 - 1 - (i - photo.y1)
			int new_i = photo.y2 - i - 1;
			// new_j = photo.x2 - photo.x1 - 1 - (j - photo.x1)
			int new_j = photo.x2 - j - 1;
			aux[new_i][new_j].val = photo.bitmap[i][j].val;
		}

	// copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_bitmap(photo.bitmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_bitmap(photo.y2 - photo.y1, aux);
}

void rotate_ss_pixmap_180(image photo)
{
	pixel **aux = NULL;
	alloc_pixmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	// parse the original submatrix according to the angle and initialize it
	for (int i = photo.y1; i < photo.y2; i++) {
		for (int j = photo.x1; j < photo.x2; j++) {
			// new_i = photo.y2 - photo.y1 - 1 - (i - photo.y1)
			int new_i = photo.y2 - i - 1;
			// new_j = photo.x2 - photo.x1 - 1 - (j - photo.x1)
			int new_j = photo.x2 - j - 1;
			aux[new_i][new_j].r = photo.pixmap[i][j].r;
			aux[new_i][new_j].g = photo.pixmap[i][j].g;
			aux[new_i][new_j].b = photo.pixmap[i][j].b;
		}
	}

	//copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_pixmap(photo.pixmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_pixmap(photo.y2 - photo.y1, aux);
}

// 270 degrees

void rotate_ss_bitmap_270(image photo)
{
	bit **aux = NULL;
	alloc_bitmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	for (int i = photo.y1; i < photo.y2; i++)
		for (int j = photo.x1; j < photo.x2; j++) {
			// new_i = photo.y2 - photo.y1 - 1 - (i - photo.y1)
			// int new_i = photo.y2 - i - 1;
			// int new_j = j - photo.x1;
			int new_i = photo.x2 - j - 1;
			int new_j = i - photo.y1;

			aux[new_i][new_j].val = photo.bitmap[i][j].val;
		}

	// copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_bitmap(photo.bitmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_bitmap(photo.y2 - photo.y1, aux);
}

void rotate_ss_pixmap_270(image photo)
{
	pixel **aux = NULL;
	alloc_pixmap(photo.y2 - photo.y1, photo.x2 - photo.x1, &aux);

	if (!aux)
		return;

	// parse the original submatrix according to the angle and initialize it
	for (int i = photo.y1; i < photo.y2; i++) {
		for (int j = photo.x1; j < photo.x2; j++) {
			int new_i = photo.x2 - j - 1;
			int new_j = i - photo.y1;
			// int new_i = photo.y2 - i - 1;
			// int new_j = j - photo.x1;
			aux[new_i][new_j].r = photo.pixmap[i][j].r;
			aux[new_i][new_j].g = photo.pixmap[i][j].g;
			aux[new_i][new_j].b = photo.pixmap[i][j].b;
		}
	}

	//copy the elements of the auxiliary matrix into the main submatrix
	copy_elems_to_pixmap(photo.pixmap, aux, photo.y1, photo.y2,
						 photo.x1, photo.x2);
	free_pixmap(photo.y2 - photo.y1, aux);
}
