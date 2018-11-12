#include <stdio.h>
#include <stdlib.h>

typedef struct teste
{
    int num;
    char *palavra;
} Teste;

int main()
{
    Teste *teste1 = (Teste *) malloc( sizeof( Teste ) );

    printf( "teste1: %p\n", &teste1 );
    if( teste1->num == NULL )
        printf( "sim\n" );
    else
        printf( "nao\n" );

    return 0;
}