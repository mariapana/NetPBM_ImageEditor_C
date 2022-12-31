#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned char val;
} bit;

// unsigned pentru a evita overflow la conversie intre int si char
// char pentru a asigura citirea din binar

typedef struct {
	unsigned char r, g, b;
} pixel;

typedef struct {
	//char mgc_wrd[MWMAX];
	char type;
	int width, height, x1, x2, y1, y2, max_val;
	bit **bitmap;
	pixel **pixmap;
} image;
