//Exemplo.
#include <stdio.h>
#include <limits.h>

int matrix_chain_order( int *, int );

int printparents( int (*)[], int, int );

int main()
{   
    int A[] = {10, 30, 5, 10};
    int n = sizeof(A)/sizeof(A[0]);
    printf( "res=%d\n", matrix_chain_order( A, n ) );

    return 0;
}

int matrix_chain_order( int A[], int n )
{
    //Linha 0 e coluna 0 não são usadas.
    int m[n][n];
    int s[n][n];

    int i, j, k, L, q;

    for( i = 1 ; i < n ; i++ )
        m[i][i] = 0;
    
    for( L = 2 ; L < n ; L++ )
    {
        for( i = 1 ; i < n - L + 1 ; i++ )
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for( k = i ; k <= j - 1 ; k++ )
            {
                q = m[i][k] + m[k + 1][j] + (A[i - 1] * A[k] * A[j]);
                if( q < m[i][j] )
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }    
    }

    printparents( s, 1, n-1 );

    return m[1][n - 1];
}

int printparents( int s[][4], int i, int j )
{
    if( i == j )
    {
        printf( " A_%d ", i );
    }
    else
    {
        printf( "(" );
        printparents( s, i, s[i][j] );
        printparents( s, s[i][j] + 1, j );
        printf( ")" );
    }
}










