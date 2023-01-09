#pragma once

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"
#include "kernel.h"

/*
@desc	Limiting position x to area [minimum, maximum].
		x < minimum => x = minimum
		x > maximum => x = maximum
		more info: https://en.wikipedia.org/wiki/Clamping_(graphics)
@param	x - the value being checked and changed (double)
		minimum - the lower end / the lowest number of the interval (int)
		maximum - the higher end / the highest number of the interval (int)
@return x - the new value of x (double)
*/
double clamp(double x, int minimum, int maximum);

/*
@desc	Performs the convolution for each pixel in the pixmap, based on the
		given kernel.
		more info on how convolution works:
		https://en.wikipedia.org/wiki/Kernel_(image_processing)
		animation of the convolution process (too cool not to include :)):
		https://en.wikipedia.org/wiki/File:2D_Convolution_Animation.gif
@param	photo - the structure holding the image data (image)
		x - the x coordinate (will be position i in pixmap) (int)
		y - the y coordinate (will be position j in pixmap) (int)
		kernel - matrix containing values according to the kernel definition
		(double **)
		res - pixmap containing the new values (after convolution) (pixel **)
*/
void convolution(image photo, int x, int y, double **kernel, pixel **res);

/*
@desc	"Prepares the ground" for the convolution by allocating res, wrapping
		convolution(), updating the pixmap and freeing res.
@param	photo - pointer to the structure holding the image data (image *)
		pixmap - pointer to the original pixmap (containing values before the
		convolution) (pixel ***)
		kernel - matrix containing values according to the kernel definition
		(double **)
*/
void apply_eff(image *photo, pixel ***pixmap, double **kernel);

/*
@desc	Implementation of the APPLY command.
		Checks command validity and wraps auxiliary functions.
@param	photo - pointer to the structure holding the image data (image *)
		input - file where the image data is originally read from (FILE *)
*/
void apply(image *photo, FILE *input);
