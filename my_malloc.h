#ifndef MY_MALLOC_H
#define MY_MALLOC_H
#include<stdio.h>
#include<unistd.h>
#include <string.h>
typedef struct block_header {
    size_t size;
    int free;
    struct block_header *next;
} block_header_t;   

#define HEADER_SIZE sizeof(block_header_t)

void *my_malloc(size_t size);
void my_free(void *ptr);
void *my_calloc(size_t n, size_t size);
#endif