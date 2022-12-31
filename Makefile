#compiler
CC=gcc

#flags for warnings
CFLAGS=-g -Wall -Wextra -std=c99

build: main.c struct_def.h memory_management.c memory_management.h map_management.c map_management.h load.c load.h select.c select.h crop.c crop.h
	$(CC) $(CFLAGS) main.c memory_management.c map_management.c load.c select.c crop.c -o image_editor

run: build
	./image_editor

pack:
	zip -Fsr 315CA_PanaMaria_Tema3.zip README Makefile *.c *.h

clean:
	rm -f *.o ./image_editor

.PHONY: pack clean