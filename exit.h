#pragma once

#include "struct_def.h"
#include "memory_management.h"

/*
@desc	Frees and closes resources (photo, input) if any are loaded
@param	photo - the structure holding the image date (image)
		input - the file where the image data is read from (FILE *)
*/
void exit_editor(image photo, FILE * input);
