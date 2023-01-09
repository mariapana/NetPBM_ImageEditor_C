#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"
#include "load.h"
#include "select.h"
#include "apply.h"
#include "histogram.h"
#include "equalize.h"
#include "rotate.h"
#include "crop.h"
#include "save.h"
#include "exit.h"

#define CMAX 10	// the maximum command name length
#define LMAX 70 // the maximum line length
				// source: https://netpbm.sourceforge.net/doc/pgm.html

int main(void)
{
	FILE *input = NULL;
	image photo;
	char cmd[CMAX], input_file[LMAX];

	int stop = 0;

	while (scanf("%s", cmd) && !stop) {
		if (strcmp(cmd, "LOAD") == 0) {
			scanf("%s", input_file);
			load(input_file, &photo, &input);
		} else if (strcmp(cmd, "SELECT") == 0) {
			select(&photo, input);
		} else if (strcmp(cmd, "ROTATE") == 0) {
			rotate(&photo, input);
		} else if (strcmp(cmd, "CROP") == 0) {
			crop(&photo, input);
		} else if (strcmp(cmd, "APPLY") == 0) {
			apply(&photo, input);
		} else if (strcmp(cmd, "HISTOGRAM") == 0) {
			histogram(photo, input);
		} else if (strcmp(cmd, "EQUALIZE") == 0) {
			equalize(photo, input);
		} else if (strcmp(cmd, "SAVE") == 0) {
			save(photo, input);
		} else if (strcmp(cmd, "EXIT") == 0) {
			exit_editor(photo, input);
			stop = 1;
		} else {
			// the given command is invalid
			printf("Invalid command\n");

			// ignore the rest of the line
			char rest_of_line[LMAX];
			fgets(rest_of_line, LMAX - strlen(cmd), stdin);
		}
	}

	return 0;
}
