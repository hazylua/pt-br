#include <stdio.h>

int main()
{
    int num = 1;
    int *p = &num;
    int **pp = &p;

    printf( "num = %p"
            "*p = %p"
            "**p = %p", &num, &p, &pp
    );

    return 0;
}