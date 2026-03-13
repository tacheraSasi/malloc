#include<stdio.h>
#include<unistd.h>

typedef struct block_header {
    size_t size;
    int free;
    struct block_header *next;
} block_header_t;

void *my_malloc(size_t size){
    void* ptr = sbrk(size);
    if(ptr == (void*) -1){
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    return ptr;
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

