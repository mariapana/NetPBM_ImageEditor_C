#pragma once

#include "struct_def.h"

/*
@desc	Functions for reading structure elements (pixel: r, g, b / bit: val)
@param	i, j - indices in the correspondent map of the struct to be read (int)
		pixmap, bitmap - the matrix / map in which the struct in stored
		(pixel ** / bit **)
		input - the file where values are read from (FILE *)
*/
void read_pixel_val_txt(int i, int j, pixel * *pixmap, FILE * input);

void read_pixel_val_bin(int i, int j, pixel **pixmap, FILE *input);

/*
@desc	Functions for reading the pixmap / bitmap (essentialy, a matrix storing
		either pixel or bit elements) depending on the file type of the input
		(text / binary)
@param	m - number of lines (int)
		n - number of columns (int)
		pixmap, bitmap - the matrix / map being read into
		(pixel ** / bit **)
		input - the file where values are read from (FILE *)
*/
void read_pixmap_txt(int m, int n, pixel **pixmap, FILE *input);

void read_pixmap_bin(int m, int n, pixel **pixmap, FILE *input);

void read_bitmap_txt(int m, int n, bit **bitmap, FILE *input);

void read_bitmap_bin(int m, int n, bit **bitmap, FILE *input);

/*
@desc	Functions for copying elements FROM the pixmap / bitmap to another map
		element by element
			- used for CROP (copy elements from wherever in the map) to create
		a submatrix a.k.a. the cropping result
@param	tmp - destination matrix / map (pixel ** / bit **)
		pixmap, bitmap - source matrix / map
		(pixel ** / bit **)
		m_start - the row index in the map where to begin (int)
		m_end - the row index in the map where to stop (int)
		n_start - the column index in the map where to begin (int)
		n_end - the row index in the map where to stop (int)
*/
void copy_elems_from_pixmap(pixel **tmp, pixel **map,
							int m_start, int m_end,
							int n_start, int n_end);

void copy_elems_from_bitmap(bit **tmp, bit **map,
							int m_start, int m_end,
							int n_start, int n_end);

/*
@desc	Functions for copying elements TO the pixmap / bitmap to another map
		element by element
			- used for ROTATE
@param	tmp - source matrix / map (pixel ** / bit **)
		pixmap, bitmap - destination matrix / map
		(pixel ** / bit **)
		m_start - the row index in the map where to begin (int)
		m_end - the row index in the map where to stop (int)
		n_start - the column index in the map where to begin (int)
		n_end - the row index in the map where to stop (int)
*/
void copy_elems_to_pixmap(pixel **map, pixel **tmp,
						  int m_start, int m_end,
						  int n_start, int n_end);

void copy_elems_to_bitmap(bit **map, bit **tmp,
						  int m_start, int m_end,
						  int n_start, int n_end);
