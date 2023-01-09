#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct {
	double val;
} bit;

typedef struct {
	double r, g, b;
} pixel;

typedef struct {
	char type;
	int width, height, x1, x2, y1, y2, max_val;
	bit **bitmap;
	pixel **pixmap;
} image;
