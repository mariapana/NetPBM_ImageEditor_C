#compiler
CC=gcc

#flags for warnings
CFLAGS=-g -Wall -Wextra -std=c99

build: main.c struct_def.h memory_management.c memory_management.h map_management.c map_management.h \
load.c load.h select.c select.h rotate.c rotate.h rotate_ss.c rotate_ss.h rotate_wi.c rotate_wi.h \
crop.c crop.h apply.c apply.h kernel.c kernel.h histogram.c histogram.h equalize.c equalize.h save.c \
save.h exit.c exit.h
	$(CC) $(CFLAGS) main.c memory_management.c map_management.c load.c select.c rotate.c rotate_ss.c \
	rotate_wi.c apply.c kernel.c histogram.c equalize.c crop.c save.c exit.c -o image_editor -lm

run: build
	./image_editor

pack:
	zip -Fsr 315CA_PanaMaria_Tema3.zip README Makefile *.c *.h

clean:
	rm -f *.o ./image_editor

.PHONY: pack clean