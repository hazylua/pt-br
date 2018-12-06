#include "arv.h"

int main()
{
    No **arv, **arv_espelho, **arv_compara;
    Info aluno;
    int i;

    arv = arvore_criar();
    arv_espelho = arvore_criar();
    arv_compara = arvore_criar();

    arv_espelho = arv;

    srand( time( NULL ) );

    for( i = 1 ; i <= 5 ; i++ )
    {
        snprintf( aluno.nome, 100, "Aluno %d", i );
        aluno.matricula = rand()%100;
        aluno.nota_1 = rand()%4 + 6;
        aluno.nota_2 = rand()%4 + 6;
        aluno.nota_3 = rand()%4 + 6;
        arvore_inserir( arv, aluno );
        arvore_inserir( arv_compara, aluno );
    }

    printf("*-----------------------------*\n");
    arvore_exibirOrdem( *arv );
    printf("*-----------------------------*\n");
    

    No *teste;
    teste = arvore_maior_no( arv );
    printf( "Resultado busca: %d\n", teste->aluno.matricula);
    // arvore_remove( arv, teste->aluno.matricula );
    // printf( "Número de nós: %d\n", arvore_contarNos( *arv ) );

    if( verificaBST( *arv, NULL ) == 1 )
        printf( "A árvore é BST.\n" );
    else
        printf( "Arvore vazia/Não é BST.\n" );

    printf("*-----------------------------*\n");

    arvore_exibirOrdem( *arv_compara );
    // arvore_espelhada( *arv );
    // arvore_exibirOrdem( *arv );

    printf("*-----------------------------*\n");

    printf( "Resultado: %d\n", verificaIgual( *arv, *arv_compara ));

    printf( "Resultado: %d\n", verificaSBST( *arv ));

    arvore_destroi( arv );

    return 0;
}