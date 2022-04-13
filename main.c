#include <stdio.h>

int main(void)
{
    int x[] = {12,4,98,2,35456,65};


    printf("%d\n", *x >> 2 & 1);
    // printf("%d\n", *(x >> 2 & 1));
    return 0;
}