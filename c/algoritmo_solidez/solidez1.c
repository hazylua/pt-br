#include <stdio.h>
#include <stdlib.h>

int solidez( int*, int, int );

int main()
{
    int vetor[5] = {0, -1, 1, 1, 1};
    int resultado = solidez(vetor, 0, 5);
    printf( "%d\n", resultado );
}

int solidez( int *vetor, int p, int r )
{
    int x = vetor[r-1];
    int q, j, s;
    //do inicio-1 até o fim
    for( q = r - 1; q >= p; q-- )
    {
        s = 0;
        printf("----> valor de q : %d\n", q);
        //do q(loop anterior) até o fim
        for( j = q; j < r; j++ )
        {
            printf("valor de j : %d\n", j);
            s += vetor[j];

            printf("valor de s : %d\n", s);
            if( s > x )
                x = s;
            printf("valor de x : %d\n", x);
        printf("---------\n");
        }
    }

    return x;
}
