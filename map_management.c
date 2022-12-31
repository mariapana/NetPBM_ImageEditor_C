#include "map_management.h"

// char* pic_type(char mgc_wrd[])
// {
// 	if (strcmp(mgc_wrd, "P2") == 0)
// 		return "g_txt";	// grayscale in text file
// 	else if (strcmp(mgc_wrd, "P5") == 0)
// 		return "g_bin";	// grayscale in binary file
// 	else if (strcmp(mgc_wrd, "P3") == 0)
// 		return "c_txt"; // coloured in txt
// 	return "c_bin"; // P6, coloured in binary file
// }

void read_pixel_val_txt(int i, int j, pixel **pixmap, FILE *input)
{
	pixel pxl;
	int r, g, b;
	fscanf(input, "%d %d %d", &r, &g, &b);
	pxl.r = (char)r;
	pxl.g = (char)g;
	pxl.b = (char)b;
	pixmap[i][j] = pxl;
}

void read_pixel_val_bin(int i, int j, pixel **pixmap, FILE *input)
{
	pixel pxl;
	fread(&pxl.r, sizeof(char), 1, input);
	fread(&pxl.g, sizeof(char), 1, input);
	fread(&pxl.b, sizeof(char), 1, input);
	pixmap[i][j] = pxl;
	//printf("%c%c%c ", pixmap[i][j].r, pixmap[i][j].g, pixmap[i][j].b);
}

// grayscale txt P2
void read_bitmap_txt(int m, int n, bit **bitmap, FILE *input)
{
	int aux;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			fscanf(input, "%d", &aux);
			bitmap[i][j].val = (char)aux;
		}
}

// grayscale bin P5
void read_bitmap_bin(int m, int n, bit **bitmap, FILE *input)
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			fread(&(bitmap[i][j].val), sizeof(char), 1, input);
			//printf("%c ", bitmap[i][j].val);
		}
		//printf("\n");
	}
}

// void print_bitmap_bin(int m, int n, bit **bitmap, FILE *output)
// {
// 	for (int i = 0; i < m; i++) {
// 		for (int j = 0; j < n; j++)
// 			printf(bitmap[i][j].val, sizeof(int), 1);
// 		printf("\n");
// 	}
// }
// color txt P3
void read_pixmap_txt(int m, int n, pixel **pixmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			read_pixel_val_txt(i, j, pixmap, input);
}

// color bin P6
void read_pixmap_bin(int m, int n, pixel **pixmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			read_pixel_val_bin(i, j, pixmap, input);
}


void copy_elems_from_pixmap(pixel **tmp, pixel **map,
							int m_start,int m_end,
							int n_start, int n_end)
{
	for (int i = m_start; i < m_end; i++) {
		for (int j = n_start; j < n_end; j++) {
			tmp[i][j] = map[i][j];
		}
	}
}
