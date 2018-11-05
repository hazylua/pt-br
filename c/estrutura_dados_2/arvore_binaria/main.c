#include "arv.h"

int main()
{
    No **arv;
    arv = arvore_criar();
    
    Info aluno;
    for( int i = 1 ; i <= 5 ; i++ )
    {
        snprintf( aluno.nome, 100, "Aluno %d", i );
        aluno.matricula = i;
        aluno.nota_1 = 6.00;
        aluno.nota_2 = 6.00;
        aluno.nota_3 = 6.00;
        arvore_inserir( arv, aluno );
    }

    arvore_exibir( *arv );
    printf( "Número de nós: %d\n", arvore_contarNos( *arv ) );
    printf( "Altura da árvore: %d\n", arvore_altura( *arv ) );

    if ( arvore_vazia( *arv ) == 1 )
        printf( "Árvore vazia.\n" );
    else
        printf( "Árvore não vazia.\n" );

    return 0;
}