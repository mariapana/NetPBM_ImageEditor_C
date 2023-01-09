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

// dynamically reallocating the pixmap to change its size
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
			fprintf(stderr, "realloc() failed for matrix allocation\n");
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

// dynamically reallocating the pixmap to change its size
void realloc_bitmap(int m, int n, bit ***map)
{
	bit **tmp = (bit **)realloc(*map, m * sizeof(bit *));
	if (!tmp) {
		fprintf(stderr, "realloc() failed for matrix allocation\n");
		*map = NULL;
		return;
	}
	for (int i = 0; i < m; i++) {
		tmp[i] = (bit *)realloc((*map)[i], n * sizeof(bit));
		if (!tmp[i]) {
			fprintf(stderr, "realloc() failed for matrix allocation\n");
			for (int j = 0; j < i; j++)
				free(tmp[i]);
			free(tmp);
			*map = NULL;
			return;
		}
	}
	free_bitmap(m, *map);
	*map = tmp;
}

// OTHER MEMORY FUNCTIONS

// freeing the dynamically allocated elements of struct image a.k.a. the map
void free_picture(image photo)
{
	if (photo.type == '2' || photo.type == '5')
		free_bitmap(photo.height, photo.bitmap);
	else
		free_pixmap(photo.height, photo.pixmap);
}

void alloc_1D_array(int size, int **v)
{
	int *tmp = (int *)malloc(size * sizeof(int));
	if (!tmp) {
		fprintf(stderr, "malloc failed for array allocation\n");
		v = NULL;
		return;
	}
	*v = tmp;
}

void alloc_2D_array(int m, int n, double ***mat)
{
	double **tmp = (double **)malloc(m * sizeof(double *));
	if (!tmp) {
		fprintf(stderr, "malloc failed for matrix allocation\n");
		*mat = NULL;
		return;
	}

	for (int i = 0; i < m; i++) {
		tmp[i] = (double *)malloc(n * sizeof(double));
		if (!tmp[i]) {
			for (int j = 0; j < i; j++)
				free(tmp[j]);
			free(tmp);
			fprintf(stderr, "malloc failed for matrix allocation\n");
			*mat = NULL;
			return;
		}
	}

	*mat = tmp;
}

void free_2D_array(int m, double **mat)
{
	for (int i = 0; i < m; i++)
		free(mat[i]);
	free(mat);
}
