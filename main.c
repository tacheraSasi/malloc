#include <stdio.h>

int main()
{
    void *ptr = my_malloc(100);
    if (ptr == NULL)
    {
        return 1;
    }

    printf("Memory allocated at: %p\n", ptr);
    return 0;
}
