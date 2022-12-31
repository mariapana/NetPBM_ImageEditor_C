#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"
#include "load.h"
#include "select.h"
#include "crop.h"

#define CMAX 10	// the maximum command name length
#define LMAX 70 // the maximum line length
				// source: https://netpbm.sourceforge.net/doc/pgm.html

int main(void)
{
	FILE *input = NULL;
	image photo;
	char cmd[CMAX], input_file[LMAX];

	while (scanf("%s", cmd)) {
		if (strcmp(cmd, "LOAD") == 0) {
			scanf("%s", input_file);
			load(input_file, &photo, &input);
		} else if (strcmp(cmd, "SELECT") == 0) {
			select(&photo, input);
		} else if (strcmp(cmd, "CROP") == 0) {
			crop(&photo, input);
		} else if(strcmp(cmd, "vezi") == 0){
			copiaza_poza(photo);
		} else {
			printf("Invalid command\n");
		}
	}
	return 0;
}

/******************************************************************************
*							NOTES TO SELF
* - add comments and documentation
* 
* _notdone_ HISTOGRAM
* _notdone_ EQUALIZE
* _notdone_ ROTATE
* _notdone_ APPLY
* _notdone_ SAVE
* _notdone_ EXIT
*
* _done_ LOAD
* _done_ SELECT
* _done_ SELECT ALL
* _done_ CROP
******************************************************************************/