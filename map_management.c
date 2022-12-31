#include "map_management.h"

// reading function for struct pixel elements
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

// reading function for struct bit elements
void read_pixel_val_bin(int i, int j, pixel **pixmap, FILE *input)
{
	pixel pxl;
	fread(&pxl.r, sizeof(char), 1, input);
	fread(&pxl.g, sizeof(char), 1, input);
	fread(&pxl.b, sizeof(char), 1, input);
	pixmap[i][j] = pxl;
}

// grayscale ASCII P2
void read_bitmap_txt(int m, int n, bit **bitmap, FILE *input)
{
	int aux;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			fscanf(input, "%d", &aux);
			bitmap[i][j].val = (char)aux;
		}
}

// grayscale binary P5
void read_bitmap_bin(int m, int n, bit **bitmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fread(&(bitmap[i][j].val), sizeof(char), 1, input);
}

// coloured ASCII P3
void read_pixmap_txt(int m, int n, pixel **pixmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			read_pixel_val_txt(i, j, pixmap, input);
}

// coloured binary P6
void read_pixmap_bin(int m, int n, pixel **pixmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			read_pixel_val_bin(i, j, pixmap, input);
}

void copy_elems_from_pixmap(pixel **tmp, pixel **map,
							int m_start, int m_end,
							int n_start, int n_end)
{
	for (int i = 0; i < m_end - m_start; i++) {
		for (int j = 0; j < n_end - n_start; j++) {
			tmp[i][j].r = map[i][j].r;
			tmp[i][j].g = map[i][j].g;
			tmp[i][j].b = map[i][j].b;
		}
	}
}

void copy_elems_from_bitmap(bit **tmp, bit **map,
							int m_start, int m_end,
							int n_start, int n_end)
{
	for (int i = 0; i < m_end - m_start; i++)
		for (int j = 0; j < n_end - n_start; j++)
			tmp[i][j].val = map[i][j].val;
}
