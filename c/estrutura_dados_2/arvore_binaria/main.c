#include "arv.h"

int main()
{
    No **arv;
    Info aluno;
    int i;

    arv = arvore_criar();
    srand( time( NULL ) );
    printf( "Ok.\n" );

    for( i = 1 ; i <= 8 ; i++ )
    {
        snprintf( aluno.nome, 100, "Aluno %d", i );
        aluno.matricula = rand()%100;
        aluno.nota_1 = rand()%4 + 6;
        aluno.nota_2 = rand()%4 + 6;
        aluno.nota_3 = rand()%4 + 6;
        arvore_inserir( arv, aluno );
    }
    printf( "Ok.\n" );

    arvore_exibirOrdem( *arv );

    printf( "Número de nós: %d\n", arvore_contarNos( *arv ) );

    printf( "Altura: %d\n", arvore_altura( *arv ) );

    printf( "Resultado busca: %d\n", busca_binaria( *arv, 2 ));

    arvore_destroi( arv );

    return 0;
}