#pragma once

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"

/*
@desc	Skipping reading the rest of the line by 'ignore-reading'
		(reading the rest of the line but not using any of the data)
@param	input - the file from where the program reads (FILE *)
*/
void skip_to_eol(FILE * input);

/*
@desc	Looks for commented lines and ignores them by using the
		skip_to_eol() function thus allowing only the relevant lines to be read
@param	input - the file from where the program reads (FILE *)
*/
void check_for_comment(FILE *input);

/*
@desc	Reading the image properties from the input file and initializing the
		elements of the structure accordingly
@param	photo - the structure whose elements are initialized (image *)
		input - the file from where the program reads (FILE *)
*/
int read_img(image *photo, FILE *input);

/*
@desc	The implementation of the LOAD command.
		Checks if any other image is loaded and loads a new one.
@param	input_file[] - the name of the file used as input (char)
		photo - the structure that will retain image properties (image *)
		input - pointer to the file from where the program reads (FILE **)
*/
void load(char input_file[], image *photo, FILE **input);
