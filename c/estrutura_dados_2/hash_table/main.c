#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main()
{
    Hash *p = NULL;
    Aluno d, *a;
    a = ( Aluno* ) malloc( sizeof( Aluno ) );

    int op = 1, tam;
    while( op )
    {
        // printf(
        //     "0 - Sair do programa.\n"
        //     "1 - Cria Hash\n"
        //     "2 - Libera Hash\n"
        //     "3 - Adiciona\n"
        //     "4 - Busca por matricula\n"
        //     "5 - Busca por nome\n"
        //     "6 - Imprime\n"
        //     "7 - Remove\n"
        // );
        scanf("%d",&op);

        switch( op )
        {
            case 1:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "Defina o tamanho da tabela hash: " );
                scanf( "%d", &tam );
                p = cria_hash( tam );
                if( p )
                    printf( "Tabela criada.\n");
                else
                    printf("Erro.\n");
            } break;

            case 2:
            {
                printf( "Opção escolhida: %d\n", op );

                if( libera_hash( &p ) )
                    printf( "Tabela hash liberada.\n");
                else
                    printf( "Erro.\n" );
            } break;

            case 3:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "Digite o nome: " );
                scanf( " %[^\n]", d.nome );
                fflush( stdin );
                printf( "Informe a matricula: " );
                scanf( "%d", &d.matricula );
                printf( "Insira as notas 1, 2 e 3, respectivamente: ");
                scanf( "%f%f%f", &d.nota_1, &d.nota_2, &d.nota_3 );
                if( ! hash_busca( p, d.matricula, a) )
                    if( hash_insere( p, d ) )
                        printf( "Valores inseridos.\n");
                    else
                        printf( "Erro.\n" );
                else
                    printf( "Erro.\n" );
            } break;

            case 4:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "Insira a matricula: " );
                scanf( "%d", &d.matricula );
                if( hash_busca( p, d.matricula, a ) )
                {
                    printf( "\n+++ RESULTADOS DA BUSCA +++\n\n") ;
                    printf( "Nome: %s; Matrícula: %d; Nota 1: %0.1f; Nota 2: %0.1f; Nota 3: %0.1f\n",a->nome,a->matricula,a->nota_1,a->nota_2,a->nota_3 );
                    printf( "\n+++ RESULTADOS DA BUSCA +++\n" );
                } else
                    printf( "Erro.\n" );
            } break;

            case 5:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "Insira o nome: " );
                fflush( stdin );
                scanf( " %[^\n]",d.nome );
                if( hash_busca_nome( p, d.nome, a ) )
                {
                    printf( "\n+++ RESULTADOS DA BUSCA +++\n\n") ;
                    printf( "Nome: %s; Matrícula: %d; Nota 1: %0.1f; Nota 2: %0.1f; Nota 3: %0.1f\n",a->nome,a->matricula,a->nota_1,a->nota_2,a->nota_3 );
                    printf( "\n+++ RESULTADOS DA BUSCA +++\n") ;
                } else
                    printf( "Erro.\n" );
            } break;

            case 6:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "\n+++ VISUALIZAÇÃO DOS VALORES JÁ INSERIDOS +++\n\n");
                imprime( p );
                printf( "\n+++ VISUALIZAÇÃO DOS VALORES JÁ INSERIDOS +++\n");
            } break;

            case 7:
            {
                printf( "Opção escolhida: %d\n", op );

                printf( "Insira a matricula: " );
                scanf( "%d", &d.matricula );
                if( hash_remove( p, d.matricula ) ) 
                    printf( "Removido.\n" );
                else
                    printf( "Erro.\n" );
            } break;
        }
        printf( "\n" );
    }

    printf( "Até a próxima.\n" );
    return 0;
}