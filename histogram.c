#include "histogram.h"

#define LMAX 70

int maxval_in_array(int size, int *v)
{
	int max = v[0];
	for (int i = 1; i < size; i++)
		if (max < v[i])
			max = v[i];
	return max;
}

void display_histogram(int star_max, int bins, int *freq, int max_freq)
{
	for (int i = 0; i < bins; i++) {
		// computing number of stars for bin
		int star_count = (int)((1.0 * freq[i] / max_freq) * star_max);
		printf("%d\t|\t", star_count);

		// printing the stars
		for (int j = 0; j < star_count; j++)
			printf("*");
		printf("\n");
	}
}

void populate_freq(int bins, int *freq, image photo)
{
	for (int i = 0; i < bins; i++)
		freq[i] = 0;

	// populating freq
	int bin_size = (photo.max_val + 1) / bins;
	for (int i = 0; i < photo.height; i++)
		for (int j = 0; j < photo.width; j++)
			freq[(int)photo.bitmap[i][j].val / bin_size]++;
}

void generate_histogram(image photo, int star_max, int bins)
{
	// create a frequency array for the bins
	int *freq = NULL;
	alloc_1D_array(bins, &freq);
	if (!freq)
		return;

	populate_freq(bins, freq, photo);

	// determining the maximum value in freq
	int max_freq = maxval_in_array(bins, freq);

	display_histogram(star_max, bins, freq, max_freq);

	free(freq);
}

void histogram(image photo, FILE *input)
{
	// since the command has multiple parameters, in order to ensure
	// command validity, the entire line will be read (like for SELECT)

	// ignore blank space between cmd and parameters
	char blank_space;
	scanf("%c", &blank_space);

	// read number of maximum stars and bins
	int star_max, bins;
	if (blank_space != '\n') {
		char line[LMAX];
		fgets(line, LMAX, stdin);
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		char *param = strtok(line, " ");

		int cnt = 0, nr = 0;
		while (param) {
			cnt++;
			for (int i = 0; i < (int)strlen(param); i++) {
				if ((param[i] < '0' || param[i] > '9') && param[i] != '-') {
					printf("Invalid command\n");
					return;
				}
			}

			nr = atoi(param);

			if (nr > 0) {
				switch (cnt) {
				case 1:
					star_max = nr;
					break;
				case 2:
					bins = nr;
					break;
				default:
					printf("Invalid command\n");
					return;
				}
			} else {
				printf("Invalid command\n");
				return;
			}

			param = strtok(NULL, " ");
		}

		// enough params?
		if (cnt != 2) {
			printf("Invalid command\n");
			return;
		}
	}

	// check if image is loaded
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	// check if params exist
	if (blank_space == '\n') {
		printf("Invalid command\n");
		return;
	}

	// check for non-grayscale image
	if (photo.type != '2' && photo.type != '5') {
		printf("Black and white image needed\n");
		return;
	}

	// perform command
	generate_histogram(photo, star_max, bins);
}
