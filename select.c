#include "select.h"

#define PMAX 3	// the maximum length of the first parameter of the SELECT cmd

/* 
Note:
	Since SELECT ALL is a patricular case of SELECT, it will be approached
	within the select() function.
*/

// swapping two values using pointers
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

// the implementation of the SELECT and the SELECT ALL commands
// sets the operable area depending on the given coordinates
void select(image *photo, FILE *input)
{
	char param[PMAX];
	scanf("%s", param);
	if (strcmp(param, "ALL") == 0) {
		// SELECT ALL
		// checking if the command is valid
		if (!input) {
			printf("No image loaded\n");
		} else {
			printf("Selected ALL\n");
		}

		photo->x1 = 0;
		photo->y1 = 0;
		photo->x2 = photo->width;
		photo->y2 = photo->height;
	} else {
		// SELECT x1 y1 x2 y2
		int x1 = atoi(param);
		int y1, x2, y2;
		scanf("%d %d %d", &y1, &x2, &y2);
		// checking if the command is valid
		if (!input) {
			printf("No image loaded\n");
		} else if (x1 > x2) {
			swap(&x1, &x2);
		} else if (y1 > y2) {
			swap(&y1, &y2);
		} else if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {
			printf("Invalid coordinates\n");
		} else if (x2 > (photo->width) || y2 > (photo->height)) {
			printf("Invalid coordinates\n");
		} else if (x1 == x2 || y2 == y1) {
			printf("Invalid coordinates\n");
		} else {
			printf("Selected %d %d %d %d\n", x1, y1, x2, y2);
		}
		
		photo->x1 = x1;
		photo->y1 = y1;
		photo->x2 = x2;
		photo->y2 = y2;
	}
}
