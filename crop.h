#pragma once

#include "struct_def.h"
#include "map_management.h"
#include "memory_management.h"

/*
@desc	Realloc's the memory for the pixmap / bitmap according to the selection
@param	photo - the structure cointaining the map (image *)
*/
void resize(image *photo);

/*
@desc	The implementation of the CROP command.
		Crops the initial image to the selected area and keeps the modification
@param	photo - the structure cointaining the map (image *)
		input - the file where the original image is loaded from (FILE *)
*/
void crop (image *photo, FILE *input);
