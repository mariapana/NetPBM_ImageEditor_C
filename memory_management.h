#pragma once

#include "struct_def.h"
#include "map_management.h"

/*
@desc	Dynamically allocating memory for matrix containing pixel elements
@param	m - number of lines (int)
		n - number of columns (int)
		map - pointer to matrix for which memory will be allocated (pixel ***)
*/
void alloc_pixmap(int m, int n, pixel ***map);

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
