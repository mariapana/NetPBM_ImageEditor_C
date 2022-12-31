#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned char val;
} bit;

typedef struct {
	unsigned char r, g, b;
} pixel;

typedef struct {
	char type;
	int width, height, x1, x2, y1, y2, max_val;
	bit **bitmap;
	pixel **pixmap;
} image;
