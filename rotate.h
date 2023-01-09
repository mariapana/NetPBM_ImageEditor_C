#pragma once

#include "rotate_ss.h"

/*
@desc	Wrapper for the functions that rotate the square selection
		by 90 degrees clockwise (affect bitmap / pixmap).
@param	photo - structure containing the image data (including bitmap/pixmap)
*/
void rotate_ss_90(image photo);

/*
@desc	Wrapper for the functions that rotate the square selection
		by 180 degrees clockwise (affect bitmap / pixmap).
@param	photo - structure containing the image data (including bitmap/pixmap)
*/
void rotate_ss_180(image photo);

/*
@desc	Wrapper for the functions that rotate the square selection
		by 270 degrees clockwise (affect bitmap / pixmap).
@param	photo - structure containing the image data (including bitmap/pixmap)
*/
void rotate_ss_270(image photo);

/*
@desc	Wrapper for the functions that rotate the whole image by 90 degrees
		clockwise (affect and realloc bitmap / pixmap).
@param	photo - pointer to structure containing the image data (image *)
*/
void rotate_wi_90(image *photo);

/*
@desc	Wrapper for the functions that rotate the whole image by 180 degrees
		clockwise (affect bitmap / pixmap).
@param	photo - pointer to structure containing the image data (image *)
*/
void rotate_wi_180(image *photo);

/*
@desc	Wrapper for the functions that rotate the whole image by 270 degrees
		clockwise (affect and realloc bitmap / pixmap).
@param	photo - pointer to structure containing the image data (image *)
*/
void rotate_wi_270(image *photo);

/*
@desc	Implementation of ROTATE command.
		Checks command validity and wraps auxiliary functions.
@param	photo - pointer to structure containing the image data (image *)
		input - file containing the original image,
				where data is read from (FILE *)
*/
void rotate(image *photo, FILE *input);
