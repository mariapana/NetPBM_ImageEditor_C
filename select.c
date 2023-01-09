#include "select.h"

#define LMAX 71 // the maximum length of a line

// swapping two values using pointers
void swap(int *a, int *b)
{
	int aux = *a;
	*a = *b;
	*b = aux;
}

void select_all(image *photo, FILE *input)
{
	// SELECT ALL
	// checking if the command is valid
	if (!input) {
		printf("No image loaded\n");
		return;
	}

	printf("Selected ALL\n");

	photo->x1 = 0;
	photo->y1 = 0;
	photo->x2 = photo->width;
	photo->y2 = photo->height;
}

// the implementation of the SELECT command
// sets the operable area depending on the given coordinates

// since the command has multiple parameters, in order to ensure
// command validity, the entire line will be read
void select(image *photo, FILE *input)
{
	// ignore blank space between cmd and parameters
	char blank_space;
	scanf("%c", &blank_space);

	char line[LMAX];
	fgets(line, LMAX, stdin);
	if (line[strlen(line) - 1] == '\n')
		line[strlen(line) - 1] = '\0';

	char *param = strtok(line, " ");
	if (strstr(param, "ALL")) {
		select_all(photo, input);
	} else {
		// SELECT x1 y1 x2 y2
		int x1, y1, x2, y2, cnt = 0, nr = 0;
		while (param) {
			cnt++;
			for (int i = 0; i < (int)strlen(param); i++) {
				if ((param[i] < '0' || param[i] > '9') && param[i] != '-') {
					printf("Invalid command\n");
					return;
				}
			}

			nr = atoi(param);

			// which coordinate is read
			switch (cnt) {
			case 1:
				x1 = nr;
				break;
			case 2:
				y1 = nr;
				break;
			case 3:
				x2 = nr;
				break;
			case 4:
				y2 = nr;
				break;
			default:
				printf("Invalid command\n");
				return;
			}
			param = strtok(NULL, " ");
		}

		// enough coordinates?
		if (cnt != 4) {
			printf("Invalid command\n");
			return;
		}

		// checking if the command is valid
		if (!input) {
			printf("No image loaded\n");
			return;
		}

		if (x1 > x2)
			swap(&x1, &x2);
		if (y1 > y2)
			swap(&y1, &y2);

		if (x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) {
			printf("Invalid set of coordinates\n");
			return;
		} else if (x2 > (photo->width) || y2 > (photo->height)) {
			printf("Invalid set of coordinates\n");
			return;
		} else if (x1 == x2 || y2 == y1) {
			printf("Invalid set of coordinates\n");
			return;
		}

		printf("Selected %d %d %d %d\n", x1, y1, x2, y2);
		photo->x1 = x1; photo->y1 = y1; photo->x2 = x2; photo->y2 = y2;
	}
}
