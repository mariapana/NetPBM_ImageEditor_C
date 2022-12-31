#include "load.h"

#define MWMAX 3	// the maximum length of the magic word

void skip_to_eol(FILE *input)
{
	char ch;
	do {
		fscanf(input, "%c", &ch);
	} while (ch != '\n');
}

void check_for_comment(FILE *input)
{
	char ch;
	fscanf(input, "%c", &ch);
	if (ch == '#') {
		// 'ignore' the rest of the line
		skip_to_eol(input);
		// keep looking for comments
		check_for_comment(input);
	} else {
		// found a non-comment line
		fseek(input, -1, SEEK_CUR);
	}
}

int read_img(image *photo, FILE *input)
{
	// reading the magic word
	check_for_comment(input);
	char mgc_wrd[MWMAX];
	fscanf(input, "%s", mgc_wrd);
	// setting the image type
	if (strcmp(mgc_wrd, "P2") == 0) {
		photo->type = '2';
	} else if (strcmp(mgc_wrd, "P3") == 0) {
		photo->type = '3';
	} else if (strcmp(mgc_wrd, "P5") == 0) {
		photo->type = '5';
	} else if (strcmp(mgc_wrd, "P6") == 0) {
		photo->type = '6';
	} 
	skip_to_eol(input);

	// reading the width and height
	check_for_comment(input);
	fscanf(input, "%d %d", &(photo->width), &(photo->height));
	skip_to_eol(input);

	// setting selection area
	photo->x1 = 0;
	photo->y1 = 0;
	photo->x2 = photo->width;
	photo->y2 = photo->height;

	// reading the maximum value
	check_for_comment(input);
	fscanf(input, "%d", &(photo->max_val));
	skip_to_eol(input);

	// reading the map; height = no. of lines, width = no. of columns
	check_for_comment(input);
	if (photo->type == '2') {
		// reading the bitmap from ascii file
		alloc_bitmap(photo->height, photo->width, &(photo->bitmap));
		read_bitmap_txt(photo->height, photo->width, photo->bitmap, input);
		return 1;
	} else if (photo-> type == '5') {
		// reading the bitmap from binary file
		alloc_bitmap(photo->height, photo->width, &(photo->bitmap));
		read_bitmap_bin(photo->height, photo->width, photo->bitmap, input);
		return 1;
	} else if (photo-> type == '3') {
		// reading the pixmap from ascii file
		alloc_pixmap(photo->height, photo->width, &(photo->pixmap));
		read_pixmap_txt(photo->height, photo->width, photo->pixmap, input);
		return 1;
	} else {
		// photo-> type == '6'
		// reading the pixmap from binary file
		alloc_pixmap(photo->height, photo->width, &(photo->pixmap));
		read_pixmap_bin(photo->height, photo->width, photo->pixmap, input);
		return 1;
	}
	return -1;
}

void copiaza_poza(image photo)
{
	char output_filename[70];
	scanf("%s", output_filename);
	FILE *output = fopen(output_filename, "wt");
	if (!output) {
		printf("Failed to open output file\n");
	}
	fprintf(output, "P%c\n", photo.type);
	fprintf(output, "%d %d\n", photo.width, photo.height);
	fprintf(output, "%d\n", photo.max_val);
	// verific momentan pt grayscale
	for (int i = 0; i < photo.height; i++) {
		for (int j = 0; j < photo.width; j++) {
			//fprintf(output, "%c%c%c", photo.pixmap[i][j].r, photo.pixmap[i][j].g, photo.pixmap[i][j].b);
			fprintf(output, "%c", photo.bitmap[i][j].val);
		}
		//fprintf(output, "\n");
	}
	printf("s-a facut sefu o7\n");
	fclose(output);
}

void load(char input_file[], image *photo, FILE **input)
{
	// check if a file is already opened
	if (*input) {
		free_picture(*photo);
		fclose(*input);
	}

	// opening the new file
	*input = fopen(input_file, "rt");
	if (!*input) {
		printf("Failed to open %s\n", input_file);
	} else {
		// reading image properties
		int success = read_img(photo, *input);
		if (success) {
			printf("Loaded %s\n", input_file);
		} else {
			printf("Failed to open %s\n", input_file);
		}
	}
}
