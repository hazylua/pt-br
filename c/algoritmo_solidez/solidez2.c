#include <stdio.h>
#include <stdlib.h>

int solidez_2( int *, int, int );
int max( int, int, int );

int main()
{
    int vetor[5] = {2, 0, -1, 1, 1}
    int resultado = solidez_2( vetor, 0, 4 );
    printf( "Resultado = %d\n", resultado );

    return 0;
}

int solidez_2( int *vetor, int p, int r )
{
    int x, x1, x2, y1, y2;
    if( p == r )
        return vetor[p];
    else
    {
        q = (p + r) / 2;
        x1 = solidez_2( vetor, p, q );
        x2 = solidez_2( vetor, (q + 1), r );
        
    }
    return x;
}