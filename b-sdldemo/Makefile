LINKER_ARGS = `sdl2-config --cflags --libs`
STANDARD_ARGS = -Wall $(LINKER_ARGS)
FILES = main.c

all: bin main-debug
release: bin main-release
tags:
	ctags -R --sort=yes -f tags /usr/local/include/SDL2/

bin:
	mkdir -p bin

main-debug: main.c main.h
	gcc $(STANDARD_ARGS) -O0 -g -o bin/main $(FILES)

main-release: main.c main.h
	gcc $(STANDARD_ARGS) -O2 -o bin/main-release $(FILES)
