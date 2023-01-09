#include "map_management.h"

// reading function for struct pixel elements
void read_pixel_val_txt(int i, int j, pixel **pixmap, FILE *input)
{
	pixel pxl;
	fscanf(input, "%lf %lf %lf", &pxl.r, &pxl.g, &pxl.b);
	pixmap[i][j] = pxl;
}

// reading function for struct bit elements
void read_pixel_val_bin(int i, int j, pixel **pixmap, FILE *input)
{
	char r, g, b;
	pixel pxl;
	fread(&r, sizeof(char), 1, input);
	fread(&g, sizeof(char), 1, input);
	fread(&b, sizeof(char), 1, input);

	pxl.r = (double)r;
	if (pxl.r < 0)
		pxl.r += 256;

	pxl.g = (double)g;
	if (pxl.g < 0)
		pxl.g += 256;

	pxl.b = (double)b;
	if (pxl.b < 0)
		pxl.b += 256;

	pixmap[i][j] = pxl;
}

// grayscale ASCII P2
void read_bitmap_txt(int m, int n, bit **bitmap, FILE *input)
{
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			fscanf(input, "%lf", &bitmap[i][j].val);
}

// grayscale binary P5
void read_bitmap_bin(int m, int n, bit **bitmap, FILE *input)
{
	char val_ch;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			fread(&val_ch, sizeof(char), 1, input);
			bitmap[i][j].val = (double)val_ch;
			if (bitmap[i][j].val < 0)
				bitmap[i][j].val += 256;
		}
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
	for (int i = m_start; i < m_end; i++) {
		for (int j = n_start; j < n_end; j++) {
			tmp[i - m_start][j - n_start].r = map[i][j].r;
			tmp[i - m_start][j - n_start].g = map[i][j].g;
			tmp[i - m_start][j - n_start].b = map[i][j].b;
		}
	}
}

void copy_elems_to_pixmap(pixel **map, pixel **tmp,
						  int m_start, int m_end,
						  int n_start, int n_end)
{
	for (int i = m_start; i < m_end; i++) {
		for (int j = n_start; j < n_end; j++) {
			map[i][j].r = tmp[i - m_start][j - n_start].r;
			map[i][j].g = tmp[i - m_start][j - n_start].g;
			map[i][j].b = tmp[i - m_start][j - n_start].b;
		}
	}
}

void copy_elems_from_bitmap(bit **tmp, bit **map,
							int m_start, int m_end,
							int n_start, int n_end)
{
	for (int i = m_start; i < m_end; i++)
		for (int j = n_start; j < n_end; j++)
			tmp[i - m_start][j - n_start].val = map[i][j].val;
}

void copy_elems_to_bitmap(bit **map, bit **tmp,
						  int m_start, int m_end,
						  int n_start, int n_end)
{
	for (int i = m_start; i < m_end; i++)
		for (int j = n_start; j < n_end; j++)
			map[i][j].val = tmp[i - m_start][j - n_start].val;
}
