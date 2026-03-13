#include<stdio.h>
#include<unistd.h>
#include <string.h>

typedef struct block_header {
    size_t size;
    int free;
    struct block_header *next;
} block_header_t;

#define HEADER_SIZE sizeof(block_header_t)

block_header_t *heap_start = NULL;

void *my_malloc(size_t size){
    block_header_t *current = heap_start;
    while ( current != NULL){
        if(current->free && current->size >= size){
            current->free = 0;
            return (void*)(current + 1);
        }
        current = current->next;
    }

    block_header_t *new_block = sbrk(HEADER_SIZE + size);
    if(new_block == (void*) -1){
        return NULL;
    }
    new_block->size = size;
    new_block->free = 0;
    new_block->next = NULL;

    if(heap_start == NULL){
        heap_start = new_block;
    } else {
        block_header_t *last = heap_start;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = new_block;
    }

    return (void*)(new_block + 1);
}

void my_free(void *ptr){
    if(ptr == NULL) return;

    block_header_t *block = (block_header_t*)ptr - 1;
    block->free = 1;
}


int main()
{
    void *ptr = my_malloc(100);
    if(ptr == NULL){
        return 1;
    }

    printf("Memory allocated at: %p\n", ptr);
    return 0;
}

