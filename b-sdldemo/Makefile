LINKER_ARGS = `sdl2-config --cflags --libs`
STANDARD_ARGS = -Wall $(LINKER_ARGS)
HEADERS = main.h utils.h
FILES = main.c utils.c
TEST_FILES = test/utils_test.c

all: test bin/main
release: bin bin/main-release

.PHONY: test
test: bin bin/test
	bin/test

.PHONY: tags
tags:
	ctags -R --sort=yes -f tags /usr/local/include/SDL2/ /usr/local/include/check.h

bin:
	mkdir -p bin

bin/main: $(FILES) $(HEADERS)
	gcc $(STANDARD_ARGS) -O0 -g $(FILES) -o bin/main

bin/main-release: $(FILES) $(HEADERS)
	gcc $(STANDARD_ARGS) -O2 $(FILES) -o bin/main-release

bin/test: $(FILES) $(TEST_FILES) $(HEADERS)
	gcc $(STANDARD_ARGS) -lcheck -g $(TEST_FILES) -o bin/test

