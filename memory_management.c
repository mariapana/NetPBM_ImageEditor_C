#include "memory_management.h"

// PIXELMAP FUNCTIONS

// dynamically allocating a matrix containing pixel elements
void alloc_pixmap(int m, int n, pixel ***map)
{
	pixel **tmp = (pixel **)malloc(m * sizeof(pixel *));
	if (!tmp) {
		fprintf(stderr, "malloc() failed for matrix allocation\n");
		*map = NULL;
		return;
	}
	for (int i = 0; i < m; i++) {
		tmp[i] = (pixel *)malloc(n * sizeof(pixel));
		if (!tmp[i]) {
			fprintf(stderr, "malloc() failed for matrix allocation\n");
			for (int j = 0; j < i; j++)
				free(tmp[i]);
			free(tmp);
			*map = NULL;
			return;
		}
	}
	*map = tmp;
}

// freeing the pixel matrix
void free_pixmap(int m, pixel **map)
{
	for (int i = 0; i < m; i++)
		free(map[i]);
	free(map);
}

void realloc_pixmap(int m, int n, pixel ***map)
{
	pixel **tmp = (pixel **)realloc(*map, m * sizeof(pixel *));
	if (!tmp) {
		fprintf(stderr, "realloc() failed for matrix allocation\n");
		*map = NULL;
		return;
	}
	for (int i = 0; i < m; i++) {
		tmp[i] = (pixel *)realloc((*map)[i], n * sizeof(pixel));
		if (!tmp[i]) {
			fprintf(stderr, "malloc() failed for matrix allocation\n");
			for (int j = 0; j < i; j++)
				free(tmp[i]);
			free(tmp);
			*map = NULL;
			return;
		}
	}
	free_pixmap(m, *map);
	*map = tmp;
}

// BITMAP FUNCTIONS

// dynamically allocating a matrix containing bit elements
void alloc_bitmap(int m, int n, bit ***map)
{
	bit **tmp = (bit **)malloc(m * sizeof(bit *));
	if (!tmp) {
		fprintf(stderr, "malloc() failed for matrix allocation\n");
		*map = NULL;
		return;
	}
	for (int i = 0; i < m; i++) {
		tmp[i] = (bit *)malloc(n * sizeof(bit));
		if (!tmp[i]) {
			fprintf(stderr, "malloc() failed for matrix allocation\n");
			for (int j = 0; j < i; j++)
				free(tmp[i]);
			free(tmp);
			*map = NULL;
			return;
		}
	}
	*map = tmp;
}

// freeing the bit matrix
void free_bitmap(int m, bit **map)
{
	for (int i = 0; i < m; i++)
		free(map[i]);
	free(map);
}

// freeing the dynamically allocated elements of struct image a.k.a. the map
void free_picture(image photo)
{
	//if (strcmp(pic_type(photo.mgc_wrd), "g_txt") == 0 || strcmp(pic_type(photo.mgc_wrd), "g_bin") == 0)
	if (photo.type == '2' || photo.type == '5')
		free_bitmap(photo.height, photo.bitmap);
	else
		free_pixmap(photo.height, photo.pixmap);
}
