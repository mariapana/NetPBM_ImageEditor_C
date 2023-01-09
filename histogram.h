#pragma once

#include "struct_def.h"
#include "memory_management.h"

/*
@desc	Compute the maximum value stored in given 1D array (vector)
@param	size - number of elements stored in v (int)
		v - the 1D array (int *)
@return max - the maximum value (int)
*/
int maxval_in_array(int size, int *v);

/*
@desc	Prints the histogram visual to the console
@param	star_max - maximum number of stars that can be displayed (int)
		bins - number of bins the values are divided into (int)
		freq - frequency vector containing the number of appearances of each
		value in the bitmap (int *)
		max_freq - most appearances of a bitmap value (int)
*/
void display_histogram(int star_max, int bins, int *freq, int max_freq);

/*
@desc	Populates the freq array by counting the appearanced of each value in
		the bitmap.
		Also used for EQUALIZE.
@param	bins - number of bins the values are divided into (int)
		freq - frequency vector containing the number of appearances of each
		value in the bitmap (int *)
		photo - structure holding the image data (image)
*/
void populate_freq(int bins, int *freq, image photo);

/*
@desc	"Prepares the ground" for display_diagram by allocating and populating
		freq, computing max_freq, calling display_diagram and freeing freq
@param	photo - structure holding the image data (image)
		star_max - maximum number of stars that can be displayed (int)
		bins - number of bins the values are divided into (int)
*/
void generate_histogram(image photo, int star_max, int bins);

/*
@desc	Implementation of the HISTOGRAM command.
		Checks command validity. Calls generate_histogram() if appropiate.
@param	photo - structure holding the image data (image)
		input - the file where the image data is read from (FILE *)
*/
void histogram(image photo, FILE *input);
