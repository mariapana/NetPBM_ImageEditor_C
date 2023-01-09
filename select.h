#pragma once

#include "struct_def.h"

/*
@desc	Swaps the integer values at the given addresses
@param	a, b - pointers to the integers to be swapped (int *)
*/
void swap(int *a, int *b);

/*
@desc	The implementation of the SELECT command.
		Sets the operable area to the entire image (coordinates 0, 0,
		width, height in the struct image photo).
@param	photo - structure holding image data (image *)
		input - the file where image is stored (FILE *)
*/
void select_all(image *photo, FILE *input);

/*
@desc	The implementation of the SELECT command.
		Checks command validity.
		Sets the operable area to the one determined by the given coordinates
		(x1, y1, x2, y2 in the struct image photo).
@param	photo - structure holding image data (image *)
		input - the file where image is stored (FILE *)
*/
void select(image *photo, FILE *input);
