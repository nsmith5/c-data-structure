CFLAGS=-Wall -Wpedantic -Werror -fpic

all: lib/liblist.so test/list

lib:
	mkdir lib

lib/liblist.so: lib obj/list.o src/list.c
	gcc -shared -o lib/liblist.so obj/list.o

obj:
	mkdir obj

obj/list.o: src/list.c
	gcc -I./include -c src/list.c $(CFLAGS) -o obj/list.o

test/list: test/list.c include/list.h lib/liblist.so
	gcc -I./include -L./lib -llist test/list.c $(CFLAGS) -o test/list

.PHONY: test

test:
	DYLIB_LIBRARY_PATH=./lib test/list
