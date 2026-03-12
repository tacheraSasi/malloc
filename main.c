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
    
    printf("Hello, World!");
    return 0;
}

