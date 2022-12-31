#pragma once

#include "struct_def.h"
#include "map_management.h"

void alloc_pixmap(int m, int n, pixel ***map);

void realloc_pixmap(int m, int n, pixel ***map);

void free_pixmap(int m, pixel **map);

void alloc_bitmap(int m, int n, bit ***map);

void free_bitmap(int m, bit **map);

void free_picture(image photo);
