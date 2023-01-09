#include "save.h"

#define LMAX 70 // the maximum line length
				// source: https://netpbm.sourceforge.net/doc/pgm.html
#define ASCIIP 5 // the length of the parameter containing the ASCII option
				 // including '\0' and but not 'a'/'A'

// open a text file to write
void open_w_output_txt(FILE **output, char output_file[])
{
	*output = fopen(output_file, "wt");
	if (!*output) {
		printf("Failed to open %s\n", output_file);
		return;
	}
}

// open a text file to append
void open_a_output_txt(FILE **output, char output_file[])
{
	*output = fopen(output_file, "at");
	if (!*output) {
		printf("Failed to open %s\n", output_file);
		return;
	}
}

// open a binary file to append
void open_a_output_bin(FILE **output, char output_file[])
{
	*output = fopen(output_file, "ab");
	if (!*output) {
		printf("Failed to open %s\n", output_file);
		return;
	}
}

// write the header data into the output file
void transf_header(FILE *output, char output_file[], image photo, char option)
{
	open_w_output_txt(&output, output_file);

	// write the magic word
	if (option == 't') {
		// ASCII file
		if (photo.type == '2' || photo.type == '5')
			// grayscale
			fprintf(output, "P2\n");
		else
			// coloured
			fprintf(output, "P3\n");
	} else if (option == 'b') {
		// BINARY
		if (photo.type == '2' || photo.type == '5')
			// grayscale
			fprintf(output, "P5\n");
		else
			// coloured
			fprintf(output, "P6\n");
	}

	// write the width and height
	fprintf(output, "%d %d\n", photo.width, photo.height);

	// write the maximum value
	fprintf(output, "%d\n", photo.max_val);

	fclose(output);
}

// write the map elements to the output text file (ASCII)
void transf_map_to_txt(FILE *output, char output_file[], image photo)
{
	open_a_output_txt(&output, output_file);

	if (photo.type == '2' || photo.type == '5') {
		// bitmap
		for (int i = 0; i < photo.height; i++) {
			for (int j = 0; j < photo.width; j++)
				fprintf(output, "%.lf ", photo.bitmap[i][j].val);
			fprintf(output, "\n");
		}
	} else if (photo.type == '3' || photo.type == '6') {
		// pixmap
		for (int i = 0; i < photo.height; i++) {
			for (int j = 0; j < photo.width; j++) {
				fprintf(output, "%.lf ", photo.pixmap[i][j].r);
				fprintf(output, "%.lf ", photo.pixmap[i][j].g);
				fprintf(output, "%.lf ", photo.pixmap[i][j].b);
			}
			fprintf(output, "\n");
		}
	}

	fclose(output);
}

// write the map elements to the output binary file
void transf_map_to_bin(FILE *output, char output_file[], image photo)
{
	open_a_output_bin(&output, output_file);

	char aux;
	if (photo.type == '2' || photo.type == '5') {
		// bitmap
		for (int i = 0; i < photo.height; i++)
			for (int j = 0; j < photo.width; j++) {
				aux = (char)photo.bitmap[i][j].val;
				fwrite(&aux, sizeof(char), 1, output);
			}
	} else if (photo.type == '3' || photo.type == '6') {
		// pixmap
		for (int i = 0; i < photo.height; i++) {
			for (int j = 0; j < photo.width; j++) {
				aux = (char)photo.pixmap[i][j].r;
				fwrite(&aux, sizeof(char), 1, output);
				aux = (char)photo.pixmap[i][j].g;
				fwrite(&aux, sizeof(char), 1, output);
				aux = (char)photo.pixmap[i][j].b;
				fwrite(&aux, sizeof(char), 1, output);
			}
		}
	}

	fclose(output);
}

// SAVE command implementation
void save(image photo, FILE *input)
{
	// read command parameters
	char output_file[LMAX];
	scanf("%s", output_file);
	FILE *output = NULL;

	// ignoring any spaces after file name
	char aux_ch;
	do {
		scanf("%c", &aux_ch);
	} while (aux_ch != '\n' && aux_ch != 'a' && aux_ch != 'A');

	char ascii_option[ASCIIP] = "";
	if (aux_ch == 'a' || aux_ch == 'A') {
		scanf("%s", ascii_option);
		for (int i = 0; i < (int)strlen(ascii_option); i++)
			ascii_option[i] = tolower(ascii_option[i]);
	}

	// check command validity
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	if (aux_ch == '\n') {
		// save as binary
		transf_header(output, output_file, photo, 'b');
		transf_map_to_bin(output, output_file, photo);
	} else {
		if (strcmp(ascii_option, "scii") == 0) {
			// save as ASCII
			transf_header(output, output_file, photo, 't');
			transf_map_to_txt(output, output_file, photo);
		}
	}

	printf("Saved %s\n", output_file);
}
