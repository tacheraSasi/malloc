#include <stdio.h>
#include "my_malloc.h"

int main()
{
    
    int *arr = (int *)my_malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        arr[i] = i * 10;
    for (int i = 0; i < 5; i++)
        printf("%d ", arr[i]); // 0 10 20 30 40
    printf("\n");

    my_free(arr);

    
    int *zeros = (int *)my_calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++)
        printf("%d ", zeros[i]); // 0 0 0 0 0
    printf("\n");

    // my_free(zeros);

    return 0;
}
