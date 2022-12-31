#pragma once

#include "struct_def.h"

/*
@desc	Swaps the integer values at the given addresses
@param	a, b - pointers to the integers to be swapped (int *)
*/
void swap(int *a, int *b);

/*
@desc	The implementation of the SELECT and SELECT ALL commands.
		Checks command validity.
		Sets the operable area to the one determined by the given coordinates
		(x1, y1, x2, y2 in the struct image photo).
@param	i, j - indices in the correspondent map of the struct to be read (int)
		pixmap, bitmap - the matrix / map in which the struct in stored
		(pixel ** / bit **)
		input - the file where values are read from (FILE *)
*/
void select(image *photo, FILE *input);
