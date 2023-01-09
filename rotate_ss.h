#pragma once

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"

/*
@desc	Rotates the square selection of the bitmap by 90 degrees clockwise
@param	photo - structure containing the image data (including bitmap)
*/
void rotate_ss_bitmap_90(image photo);

/*
@desc	Rotates the square selection of the pixmap by 90 degrees clockwise
@param	photo - structure containing the image data (including pixmap)
*/
void rotate_ss_pixmap_90(image photo);

/*
@desc	Rotates the square selection of the bitmap by 180 degrees clockwise
@param	photo - structure containing the image data (including bitmap)
*/
void rotate_ss_bitmap_180(image photo);

/*
@desc	Rotates the square selection of the pixmap by 180 degrees clockwise
@param	photo - structure containing the image data (including pixmap)
*/
void rotate_ss_pixmap_180(image photo);

/*
@desc	Rotates the square selection of the bitmap by 270 degrees clockwise
@param	photo - structure containing the image data (including bitmap)
*/
void rotate_ss_bitmap_270(image photo);

/*
@desc	Rotates the square selection of the pixmap by 270 degrees clockwise
@param	photo - structure containing the image data (including pixmap)
*/
void rotate_ss_pixmap_270(image photo);
