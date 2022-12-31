#include "crop.h"

void resize(image *photo)
{
	int new_width = photo->x2 - photo->x1;
	int new_height = photo->y2 - photo->y1;
	// check to see which map should be altered
	if (photo->type == '2' || photo->type == '5') {
		// bitmap
		bit **tmp = photo->bitmap;
		alloc_bitmap(photo->width, photo->height, &tmp);
		free_bitmap(photo->width, photo->bitmap);
		photo->bitmap = tmp;
	} else if (photo->type == '3' || photo->type == '6') {
		// pixmap
		pixel **tmp = NULL;
		alloc_pixmap(new_height, new_width, &tmp);
		copy_elems_from_pixmap(tmp, photo->pixmap, photo->x1, photo->x2,
							   photo->y1, photo->y2);
		free_pixmap(photo->height, photo->pixmap);
		photo->pixmap = tmp;
	}
}

void crop(image *photo, FILE *input)
{
	if (!input) {
		printf("No image loaded\n");
	} else {
		// change width and height
		// realloc the map to the new size
		resize(photo);
		photo->width = photo->x2 - photo->x1;
		photo->height = photo->y2 - photo->y1;
		printf("Image cropped\n");
	}
}
