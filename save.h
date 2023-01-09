#pragma once

#include "struct_def.h"
#include "load.h"

/*
@desc	Opening a text file for writing and checking if it opened correctly
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
*/
void open_w_output_txt(FILE * *output, char output_file[]);

/*
@desc	Opening a text file for appending and checking if it opened correctly
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
*/
void open_a_output_txt(FILE * *output, char output_file[]);

/*
@desc	Opening a binary file for writing and checking if it opened correctly
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
*/
void open_a_output_bin(FILE * *output, char output_file[]);

/*
@desc	Writing the header data (magic word, width, height, maximum value) to
		the output file
@param	output - the file where the program writes (FILE *)
		output_file[] - the name of the output file (char)
		photo - the structure holding the image (image)
		option - 't' if the output file is a text file
				 'b' if the output file is a binary file (char)
*/
void transf_header(FILE *output, char output_file[], image photo, char option);

/*
@desc	Writing the elements held in the matrix (bitmap/pixmap) to a text file
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
		photo - the structure holding the matrix (image)
*/
void transf_map_to_txt(FILE *output, char output_file[], image photo);

/*
@desc	Writing the elements held in the matrix (bitmap/pixmap) to binary file
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
		photo - the structure holding the matrix (image)
*/
void transf_map_to_bin(FILE *output, char output_file[], image photo);

/*
@desc	Reads parameters. Checks command validity.
		Implements the SAVE command (wrapper).
@param	output - the file where the program writes (FILE **)
		output_file[] - the name of the output file (char)
		photo - the structure holding the matrix (image)
*/
void save(image photo, FILE *input);
