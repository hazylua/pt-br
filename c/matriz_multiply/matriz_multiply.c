#include <stdio.h>

int matriz_multiply( int (*)[], int (*)[] );

int main()
{
    int A[2][2] = {1, 2, 3, 4};
    int B[2][2] = {1, 2, 3, 4};
    matriz_multiply( A, B );
}

int matriz_multiply( int A[][2], int B[][2] )
{
    int i, j, k, C[2][2];
    for( i = 0 ; i < 2 ; i++ )
    {
        for( j = 0 ; j < 2 ; j++ )
        {
            C[i][j] = 0;
            for( k = 0; k < 2 ; k++ )
            {
                C[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }

    for( i = 0 ; i < 2 ; i++ )
    {
        for( j = 0 ; j < 2 ; j++ )
        {
            printf( "%d ", C[i][j] );
        }
        printf( "\n" );
    }

    return 1;
}