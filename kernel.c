#include "kernel.h"

double **create_edge(void)
{
	double **edge = NULL;
	alloc_2D_array(K, K, &edge);
	if (!edge)
		return NULL;

	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			edge[i][j] = -1.0;
	edge[1][1] = 8.0;

	return edge;
}

double **create_sharpen(void)
{
	double **sharpen = NULL;
	alloc_2D_array(K, K, &sharpen);
	if (!sharpen)
		return NULL;

	sharpen[0][0] = 0.0;
	sharpen[0][1] = -1.0;
	sharpen[0][2] = 0.0;

	sharpen[1][0] = -1.0;
	sharpen[1][1] = 5.0;
	sharpen[1][2] = -1.0;

	sharpen[2][0] = 0.0;
	sharpen[2][1] = -1.0;
	sharpen[2][2] = 0.0;

	return sharpen;
}

double **create_blur(void)
{
	double **blur = NULL;
	alloc_2D_array(K, K, &blur);
	if (!blur)
		return NULL;

	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			blur[i][j] = 1.0 / 9.0;

	return blur;
}

double **create_gauss(void)
{
	double **gauss = NULL;
	alloc_2D_array(K, K, &gauss);
	if (!gauss)
		return NULL;

	gauss[0][0] = 1.0 / 16.0;
	gauss[0][1] = 2.0 / 16.0;
	gauss[0][2] = 1.0 / 16.0;

	gauss[1][0] = 2.0 / 16.0;
	gauss[1][1] = 4.0 / 16.0;
	gauss[1][2] = 2.0 / 16.0;

	gauss[2][0] = 1.0 / 16.0;
	gauss[2][1] = 2.0 / 16.0;
	gauss[2][2] = 1.0 / 16.0;

	return gauss;
}
