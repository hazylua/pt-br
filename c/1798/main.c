#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_canos, tam_padrao;
    int cano[1000], venda[1000];

    scanf( "%d %d", &num_canos, &tam_padrao );
    printf( "num_canos: %d; tam_padrao: %d\n", num_canos, tam_padrao );

    int i;
    for( i = 0 ; i < num_canos ; i++ )
    {
       scanf( "%d %d", &cano[i], &venda[i] );
       printf( "cano[%d]: %d; venda[%d]: %d\n", i, cano[i], i, venda[i] );
       printf( "----------------------------------------------------\n" );
    }

    return 0;
}