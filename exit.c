#include "exit.h"

void exit_editor(image photo, FILE *input)
{
	// check if an image is loaded
	if (input) {
		// freeing and closing resources
		free_picture(photo);
		fclose(input);
	} else {
		printf("No image loaded\n");
	}
}
