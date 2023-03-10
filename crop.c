#include "crop.h"

// changes the size of the pixmap / bitmap
void resize(image *photo)
{
	// the selected interval: [ , )
	int new_width = photo->x2 - photo->x1;
	int new_height = photo->y2 - photo->y1;
	// check to see which map should be altered
	if (photo->type == '2' || photo->type == '5') {
		// bitmap
		bit **tmp = NULL;
		alloc_bitmap(new_height, new_width, &tmp);
		if (!tmp)
			return;
		copy_elems_from_bitmap(tmp, photo->bitmap, photo->y1, photo->y2,
							   photo->x1, photo->x2);
		free_bitmap(photo->height, photo->bitmap);
		photo->bitmap = tmp;
	} else if (photo->type == '3' || photo->type == '6') {
		// pixmap
		pixel **tmp = NULL;
		alloc_pixmap(new_height, new_width, &tmp);
		if (!tmp)
			return;
		copy_elems_from_pixmap(tmp, photo->pixmap, photo->y1, photo->y2,
							   photo->x1, photo->x2);
		free_pixmap(photo->height, photo->pixmap);
		photo->pixmap = tmp;
	}
	photo->x1 = 0;
	photo->y1 = 0;
	photo->x2 = new_width;
	photo->y2 = new_height;
	photo->width = new_width;
	photo->height = new_height;
}

void crop(image *photo, FILE *input)
{
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	// change width and height
	// realloc the map to the new size
	resize(photo);
	photo->width = photo->x2 - photo->x1;
	photo->height = photo->y2 - photo->y1;
	printf("Image cropped\n");
}
