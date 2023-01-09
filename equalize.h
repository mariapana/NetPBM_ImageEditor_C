#pragma once

#include "struct_def.h"
#include "memory_management.h"
#include "histogram.h"
#include "apply.h"

/*
@desc	Implementation of the EQUALIZE command.
		Allocates and populates frequency vector freq. Based on it computes
		the new equalized values for the new bitmap.
@param	photo - structure holding the image data (image)
		input - the file where the image data is read from (FILE *)
*/
void equalize(image photo, FILE * input);
