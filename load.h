#pragma once

#include "struct_def.h"
#include "memory_management.h"
#include "map_management.h"

void skip_to_eol(FILE *input);

void check_for_comment(FILE *input);

int read_img(image *photo, FILE *input);

void copiaza_poza(image photo);

void load(char input_file[], image *photo, FILE **input);
