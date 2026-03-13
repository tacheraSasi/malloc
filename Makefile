build:
	cc main.c my_malloc.c -o my_malloc_test

run: build
	./my_malloc_test