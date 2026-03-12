#include<stdio.h>
#include<unistd.h>

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

