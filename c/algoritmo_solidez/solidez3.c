#include <stdio.h>
#include <stdlib.h>

#define TAM 5

int Solidez( int *, int, int );

int main()
{
    int Vetor[TAM] = {-10, 0, 1, 1, 1};
    printf( "Resultado: %d\n", Solidez( Vetor, 0, TAM-1 ) );

    return 0;
}

int Solidez( int *A, int p, int r )
{
    int F[TAM];
    int q, s, x;

    F[p] = A[p];
    for( q = p + 1 ; q <= r ; q++ )
    {
        s = F[q - 1] + A[q];
        if( s > A[q] )
            F[q] = s;
        else
            F[q] = A[q];
    }
    x = F[p];
    for( q = p + 1 ; q <= r ; q++ )
    {
        if( F[q] > x )
            x = F[q];
    }
    return x;
}