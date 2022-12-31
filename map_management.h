#pragma once

#include "struct_def.h"

// char pic_type(char mgc_wrd[]);

// void read_pixel_values(int i, int j, pixel **pixmap, FILE *input);

// void read_pixmap(int m, int n, pixel **pixmap, FILE *input);

// void read_bitmap(int m, int n, bit **bitmap, FILE *input);

//char* pic_type(char mgc_wrd[]);

void read_pixel_val_txt(int i, int j, pixel **pixmap, FILE *input);

void read_pixel_val_bin(int i, int j, pixel **pixmap, FILE *input);

void read_bitmap_txt(int m, int n, bit **bitmap, FILE *input);

void read_bitmap_bin(int m, int n, bit **bitmap, FILE *input);

//void print_bitmap_bin(int m, int n, bit **bitmap, FILE *output);

void read_pixmap_txt(int m, int n, pixel **pixmap, FILE *input);

void read_pixmap_bin(int m, int n, pixel **pixmap, FILE *input);

void copy_elems_from_pixmap(pixel **tmp, pixel **map,
							int m_start,int m_end,
							int n_start, int n_end);
