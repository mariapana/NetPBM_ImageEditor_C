#pragma once

#include "memory_management.h"

#define K 3	// kernel dimension

/*
@desc	Generate kernel matrices depending on the effect (edge, sharpen,
		blur, gaussian blur)
@return	kernel matrix (double **)
*/

double **create_edge(void);

double **create_sharpen(void);

double **create_blur(void);

double **create_gauss(void);
