#include<stdio.h>
#include<unistd.h>

typedef struct block_header {
    size_t size;
    int free;
    struct block_header *next;
} block_header_t;

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

