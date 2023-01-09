#include "equalize.h"

void equalize(image photo, FILE *input)
{
	// check if image is loaded
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	// image is grayscale
	if (photo.type != '2' && photo.type != '5') {
		printf("Black and white image needed\n");
		return;
	}

	// frequency
	int *freq = NULL;
	alloc_1D_array(photo.max_val + 1, &freq);
	if (!freq)
		return;

	populate_freq(photo.max_val + 1, freq, photo);

	// equalized values
	for (int i = 0; i < photo.height; i++) {
		for (int j = 0; j < photo.width; j++) {
			double histo_sum = 0;
			for (int k = 0; k <= photo.bitmap[i][j].val; k++)
				histo_sum += (double)freq[k];

			double area;
			area = photo.width * photo.height;

			double res;
			res = histo_sum * (255.0 / area);

			photo.bitmap[i][j].val = round(res);

			if (photo.bitmap[i][j].val > 255 || photo.bitmap[i][j].val < 0)
				clamp(photo.bitmap[i][j].val, 0, 255);
		}
	}

	free(freq);
	printf("Equalize done\n");
}
