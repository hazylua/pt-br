#include "arv.h"

int menu( int * );

int main()
{
    int opcao;
    No **arv, **arv_compara, **arv_espelho;
    srand(time(NULL));
    while( menu(&opcao) )
    {
        switch( opcao )
        {
            case 1:
            {
                arv = arvore_criar();
                printf( "OK.\n" );
            } break;
            case 2:
            {
                Info aluno;
                for( int i = 1 ; i <= 5 ; i++ )
                {
                    snprintf( aluno.nome, 100, "Aluno %d", i );
                    aluno.matricula = rand()%100 + 10;
                    aluno.nota_1 = rand()%4 + 6;
                    aluno.nota_2 = rand()%4 + 6;
                    aluno.nota_3 = rand()%4 + 6;
                    arvore_inserir( arv, aluno );
                }
                printf( "OK.\n" );
            } break;
            case 3:
            {
                arvore_exibirOrdem( *arv );
                printf( "OK.\n" );
            } break;
            case 4:
            {
                arvore_exibirPreOrdem( *arv );
                printf( "OK.\n" );
            } break;
            case 5:
            {
                arvore_exibirPosOrdem( *arv );
                printf( "OK.\n" );
            } break;
            case 6:
            {
                if( arvore_vazia( *arv ) == 1 )
                    printf( "Árvore vazia.\n" );
                else if( arvore_vazia( *arv ) == 0 )
                    printf( "Árvore não vazia.\n" );
                printf( "OK.\n" );
            } break;
            case 7:
            {
                printf( "Número de nós: %d\n", arvore_contarNos( *arv ) );
                printf( "OK.\n" );
            } break;
            case 8:
            {
                printf( "Número de folhas: %d\n", arvore_contarFolhas( *arv ) );
                printf( "OK.\n" );
            } break;
            case 9:
            {
                printf( "Número de nós não folha: %d\n", arvore_contarNaoFolhas( *arv ) );
                printf( "OK.\n" );
            } break;
            case 10:
            {
                printf( "Altura: %d\n", arvore_altura( *arv ) );
                printf( "OK.\n" );
            } break;
            case 11:
            {
                arvore_destroi( arv );
                printf( "OK.\n" );
            } break;
        }
    }
}

int menu( int *opcao )
{
    printf(
            "0 - Sair do programa;\n"
            "1 - Criar árvore;\n"
            "2 - Inserir elementos pré-definidos;\n"
            "3 - Exibir em ordem;\n"
            "4 - Exibir pré ordem;\n"
            "5 - Exibir pós ordem;\n"
            "6 - Verificar se a árvore está vazia;\n"
            "7 - Contar número de nós;\n"
            "8 - Contar número de nós folhas;\n"
            "9 - Contar número de nós não folhas;\n"
            "10 - Exibir altura da árvore;\n"
            "11 - Destruir árvore;\n"
        );
        printf( "Opção: " );
        scanf( "%d", opcao );

    return *opcao;
}