#pragma once

#include "struct_def.h"
#include "select.h"
#include "memory_management.h"
#include "map_management.h"
#include "rotate_ss.h"

/*
@desc	Rotates the whole image (bitmap) by 90 degrees clockwise.
		Reallocates memory for the result, updates dimensions.
@param	photo - pointer to the structure containing the image data
		(including bitmap)
		bitmap - pointer to the bitmap (bit ***)
*/
void rotate_wi_bitmap_90(image * photo, bit * **bitmap);

/*
@desc	Rotates the whole image (pixmap) by 90 degrees clockwise.
		Reallocates memory for the result, updates dimensions.
@param	photo - pointer to the structure containing the image data
		(including pixmap)
		pixmap - pointer to the bitmap (pixel ***)
*/
void rotate_wi_pixmap_90(image *photo, pixel ***pixmap);

/*
@desc	Rotates the whole image (bitmap) by 180 degrees clockwise.
		Unlike 90, 270 degree options, reallocation is not required here.
@param	photo - pointer to the structure containing the image data
		(including bitmap)
*/
void rotate_wi_bitmap_180(image *photo);

/*
@desc	Rotates the whole image (pixmap) by 180 degrees clockwise.
		Unlike 90, 270 degree options, reallocation is not required here.
@param	photo - pointer to the structure containing the image data
		(including pixmap)
*/
void rotate_wi_pixmap_180(image *photo);

/*
@desc	Rotates the whole image (bitmap) by 270 degrees clockwise.
		Reallocates memory for the result, updates dimensions.
@param	photo - pointer to the structure containing the image data
		(including bitmap)
		bitmap - pointer to the bitmap (bit ***)
*/
void rotate_wi_bitmap_270(image *photo, bit ***bitmap);

/*
@desc	Rotates the whole image (bitmap) by 270 degrees clockwise.
		Reallocates memory for the result, updates dimensions.
@param	photo - pointer to the structure containing the image data
		(including bitmap)
		bitmap - pointer to the bitmap (bit ***)
*/
void rotate_wi_pixmap_270(image *photo, pixel ***pixmap);
