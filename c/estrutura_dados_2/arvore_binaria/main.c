#include "arv.h"

#define NUM_ALUNOS 5
#define MAT_NUM 110

int menu( int * );
void gerar_alunos( No **, int );

int main()
{
    No **arv, **arv_compara, **arv_espelho;
    Info aluno;
    No *aux;

    srand(time(NULL));

    arv = arvore_criar();
    arv_compara = arvore_criar();

    int num;
    while( menu(&num) )
    {
        switch( num )
        {
            case 1:
            {
                gerar_alunos( arv, NUM_ALUNOS );

                printf( "OK.\n" );
            } break;

            case 2:
            {
                arvore_exibirOrdem( *arv );

                printf( "OK.\n" );
            } break;

            case 3:
            {
                arvore_exibirPreOrdem( *arv );

                printf( "OK.\n" );
            } break;

            case 4:
            {
                arvore_exibirPosOrdem( *arv );

                printf( "OK.\n" );
            } break;

            case 5:
            {
                if( arvore_vazia( *arv ) == 1 )
                    printf( "Árvore vazia.\n" );
                else if( arvore_vazia( *arv ) == 0 )
                    printf( "Árvore não vazia.\n" );

                printf( "OK.\n" );
            } break;

            case 6:
            {
                printf( "Número de nós: %d\n", arvore_contarNos( *arv ) );
                printf( "OK.\n" );

            } break;

            case 7:
            {
                printf( "Número de folhas: %d\n", arvore_contarFolhas( *arv ) );
                printf( "OK.\n" );

            } break;

            case 8:
            {
                printf( "Número de nós não folha: %d\n", arvore_contarNaoFolhas( *arv ) );
                printf( "OK.\n" );

            } break;

            case 9:
            {
                printf( "Altura: %d\n", arvore_altura( *arv ) );
                printf( "OK.\n" );

            } break;

            case 10:
            {
                arvore_destroi( arv );

                printf( "OK.\n" );
            } break;

            case 11:
            {
                if( busca_mat( *arv, MAT_NUM ) == 1 )
                    printf( "Essa matrícula existe.\n" );
                else
                    printf( "Essa matrícula não existe.\n" );

                printf( "OK.\n" );
            } break;

            case 12:
            {
                aux = arvore_maior_no( arv );
                printf( "Maior nó da árvore: %d\n", aux->aluno.matricula);
                arvore_remove( arv, aux->aluno.matricula );

                printf( "OK.\n" );
            } break;

            case 13:
            {
                if( busca_mat( *arv, MAT_NUM ) == 1 )
                {
                    printf( "Essa matrícula existe, removendo-a...\n" );
                    arvore_remove( arv, MAT_NUM ) == 1;
                }
                else
                    printf( "Essa matrícula não existe, não é possível removê-la.\n" );

                printf( "OK.\n" );
            } break;

            case 14:
            {
                if( verificaBST( *arv, NULL ) == 1 )
                    printf( "A árvore é BST.\n" );
                else
                    printf( "Arvore vazia/Não é BST.\n" );

                printf( "OK.\n" );
            } break;

            case 15:
            {
                arv_espelho = arvore_criar();
                arv_espelho = arv;
                arvore_espelhada( *arv_espelho );

                arvore_exibirOrdem( *arv_espelho );

                printf( "OK.\n" );
            } break;

            case 16:
            {
                gerar_alunos( arv_compara, NUM_ALUNOS );

                if( verificaIgual( *arv, *arv_compara ) == 1 )
                    printf( "Arvore de comparação é igual a arvore original.\n" );
                else
                    printf( "Arvore de comparação não é igual a arvore original.\n" );

                printf( "OK.\n" );
            } break;

            case 17:
            {
                gerar_alunos( arv_compara, NUM_ALUNOS );

                if( verificaSimilar( *arv, *arv_compara ) == 1 )
                    printf( "Arvore de comparação é similar a arvore original.\n" );
                else
                    printf( "Arvore de comparação não é similar a arvore original.\n" );

                printf( "OK.\n" );
            } break;

            case 18:
            {
                if( verificaSBST( *arv ) == 1 )
                    printf( "Arvore é estritamente binária.\n" );
                else
                    printf( "Arvore não é estritamente binária.\n" );

                printf( "OK.\n" );
            } break;

        }
    }
}

int menu( int *opcao )
{
    printf(
            "0 - Sair do programa;\n"
            "1 - Inserir %d elemento(s) aleatório(s);\n"
            "2 - Exibir em ordem;\n"
            "3 - Exibir pré ordem;\n"
            "4 - Exibir pós ordem;\n"
            "5 - Verificar se a árvore está vazia;\n"
            "6 - Contar número de nós;\n"
            "7 - Contar número de nós folhas;\n"
            "8 - Contar número de nós não folhas;\n"
            "9 - Exibir altura da árvore;\n"
            "10 - Destruir árvore;\n"
            "11 - Busca a existência da matrícula %d;\n"
            "12 - Buscar a maior matrícula e removê-la;\n"
            "13 - Buscar a matrícula %d e removê-la;\n"
            "14 - Verificar se árvore é binária;\n"
            "15 - Obter o espelho da árvore principal e exibí-la;\n"
            "16 - Verificar se duas árvores são iguais;\n"
            "17 - Verificar se duas árvores são similares;\n"
            "18 - Verificar se uma árvore é estritamente binária.\n"

            , NUM_ALUNOS, MAT_NUM, MAT_NUM
        );
        printf( "Opção: " );
        scanf( "%d", opcao );

    system( "clear" );
    return *opcao;
}

void gerar_alunos( No **arv, int num )
{
    Info aluno;
    int i;
    for( int i = 1 ; i <= num ; i++ )
        {
            snprintf( aluno.nome, 100, "Aluno %d", i );
            aluno.matricula = rand()%99 + 100;
            aluno.nota_1 = rand()%4 + 6;
            aluno.nota_2 = rand()%4 + 6;
            aluno.nota_3 = rand()%4 + 6;
            arvore_inserir( arv, aluno );
        }
}