#include "apply.h"

#define AOPTMAX 14 // maximum length of APPLY cmd parameter (including '\0')

double clamp(double x, int minimum, int maximum)
{
	if (x < minimum)
		return 1.0 * minimum;
	if (x > maximum)
		return 1.0 * maximum;
	return x;
}

void convolution(image photo, int x, int y, double **kernel, pixel **res)
{
	// check if element is on edge of image
	if (x < 1 || y < 1 || x >= photo.height - 1 || y >= photo.width - 1)
		return;

	// computing new values
	double sum_r = 0.0, sum_g = 0.0, sum_b = 0.0;

	for (int i = x - 1; i <= x + 1; i++) {
		for (int j = y - 1; j <= y + 1; j++) {
			sum_r += photo.pixmap[i][j].r * kernel[i - x + 1][j - y + 1];
			sum_g += photo.pixmap[i][j].g * kernel[i - x + 1][j - y + 1];
			sum_b += photo.pixmap[i][j].b * kernel[i - x + 1][j - y + 1];
		}
	}

	// updating results
	res[x][y].r = clamp(sum_r, 0, photo.max_val);
	res[x][y].g = clamp(sum_g, 0, photo.max_val);
	res[x][y].b = clamp(sum_b, 0, photo.max_val);
}

void apply_eff(image *photo, pixel ***pixmap, double **kernel)
{
	// creating a result matrix that will replace pixmap
	// initially acts as a copy of the pixmap
	pixel **res = NULL;
	alloc_pixmap(photo->height, photo->width, &res);
	if (!res)
		return;
	copy_elems_from_pixmap(res, photo->pixmap, 0, photo->height,
						   0, photo->width);

	for (int i = photo->y1; i < photo->y2; i++)
		for (int j = photo->x1; j < photo->x2; j++)
			convolution(*photo, i, j, kernel, res);

	// updating the pixmap (by replacing with res)
	free_pixmap(photo->height, photo->pixmap);
	*pixmap = res;
}

void apply(image *photo, FILE *input)
{
	// parameter separator - if exists, command is valid; read param
	char param_sep;
	scanf("%c", &param_sep);

	// reading filter option
	char option[AOPTMAX];
	if (param_sep != '\n')
		scanf("%s", option);

	// checking if the image is loaded
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	// command validity - check for space between APPLY and possible param
	if (param_sep == '\n') {
		printf("Invalid command\n");
		return;
	}

	// checking image type (grayscale / coloured)
	if (photo->type == '2' || photo->type == '5') {
		// grayscale
		printf("Easy, Charlie Chaplin\n");
		return;
	}

	// determine kernel type
	if (strcmp(option, "EDGE") == 0) {
		double **edge = create_edge();
		if (!edge)
			return;
		apply_eff(photo, &photo->pixmap, edge);
		free_2D_array(K, edge);
	} else if (strcmp(option, "SHARPEN") == 0) {
		double **sharpen = create_sharpen();
		if (!sharpen)
			return;
		apply_eff(photo, &photo->pixmap, sharpen);
		free_2D_array(K, sharpen);
	} else if (strcmp(option, "BLUR") == 0) {
		double **blur = create_blur();
		if (!blur)
			return;
		apply_eff(photo, &photo->pixmap, blur);
		free_2D_array(K, blur);
	} else if (strcmp(option, "GAUSSIAN_BLUR") == 0) {
		double **gauss = create_gauss();
		if (!gauss)
			return;
		apply_eff(photo, &photo->pixmap, gauss);
		free_2D_array(K, gauss);
	} else {
		printf("APPLY parameter invalid\n");
		return;
	}

	printf("APPLY %s done\n", option);
}
