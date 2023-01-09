#pragma once

#include "struct_def.h"
#include "map_management.h"

/*
@desc	Dynamically allocating memory for matrix containing pixel elements
@param	m - number of lines (int)
		n - number of columns (int)
		map - pointer to matrix for which memory will be allocated (pixel ***)
*/
void alloc_pixmap(int m, int n, pixel * **map);

/*
@desc	Dynamically reallocating memory for matrix containing pixel elements
@param	m - number of lines (int)
		n - number of columns (int)
		map - pointer to matrix for which memory will be realloc'd (pixel ***)
*/
void realloc_pixmap(int m, int n, pixel ***map);

/*
@desc	Freeing the dynamically allocated memory for matrix of pixel elements
@param	m - number of lines (int)
		map - the matrix whose memory will be freed (pixel **)
*/
void free_pixmap(int m, pixel **map);

/*
@desc	Dynamically allocating memory for matrix containing bit elements
@param	m - number of lines (int)
		n - number of columns (int)
		map - pointer to matrix for which memory will be allocated (bit ***)
*/
void alloc_bitmap(int m, int n, bit ***map);

/*
@desc	Dynamically reallocating memory for matrix containing bit elements
@param	m - number of lines (int)
		n - number of columns (int)
		map - pointer to matrix for which memory will be realloc'd (bit ***)
*/
void realloc_bitmap(int m, int n, bit ***map);

/*
@desc	Freeing the dynamically allocated memory for matrix of bit elements
@param	m - number of lines (int)
		map - the matrix for whose memory will be freed (bit **)
*/
void free_bitmap(int m, bit **map);

/*
@desc	Freeing the dynamically allocated memory of matrix within the picture
		a.k.a. the pixmap/bitmap
@param	photo - struct element of type image
*/
void free_picture(image photo);

/*
@desc	Dynamically allocating memory for a 1D array (vector).
		Used for the frequency array of the HISTOGRAM command.
@param	size - the number of elements the array will hold (int)
		v - address to the array being allocated (int **)
*/
void alloc_1D_array(int size, int **v);

/*
@desc	Dynamically allocating memory for a 2D array (matrix).
		Used for kernel generation.
@param	m - number of lines (int)
		n - number of columns (int)
		v - address to the array being allocated (int **)
*/
void alloc_2D_array(int m, int n, double ***mat);

/*
@desc	Freeing the dynamically allocated memory for a 2D array (matrix).
@param	m - number of lines (int)
		v - address to the array being allocated (int **)
*/
void free_2D_array(int m, double **mat);
