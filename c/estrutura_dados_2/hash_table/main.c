#include <stdio.h>
#include <stdlib.h>
#include "hash.h"


int main()
{
    Hash *tabela_hash = NULL;
    Aluno *al = ( Aluno* ) malloc( sizeof( Aluno ) );
    Aluno al_novo;

    //printf( "Defina o tamanho da tabela hash: " );
    int tam;
    scanf( "%d", &tam );
    tabela_hash = cria_hash( tam );

    //printf( "Defina o número de alunos a serem inseridos: " );
    int i, qtd_alunos;
    scanf( "%d", &qtd_alunos );
    for( i = 0 ; i < qtd_alunos ; i++ )
    {
        //printf( "Informe o nome: " );
        scanf( "%s", al_novo.nome );
        //printf( "Informe a matricula: " );
        scanf( "%d", &al_novo.matricula );
        //printf( "Informe as notas 1, 2 e 3, respectivamente: " );
        scanf( "%f%f%f", &al_novo.nota_1, &al_novo.nota_2, &al_novo.nota_3 );
        
        hash_insere( tabela_hash, al_novo );
    }

    imprime( tabela_hash );

    //printf( "Informe a matrícula a ser procurada: " );
    int mat;
    scanf( "%d", &mat );
    hash_busca_matricula( tabela_hash, mat, al );
    printf( "Resultado:\n"
    "Nome: %s; Matrícula: %d; Nota 1: %0.2f; Nota 2: %0.2f; Nota 3: %0.2f\n", al->nome, al->matricula, al->nota_1, al->nota_2, al->nota_3 );

    //printf( "Informe o nome a ser procurado: " );
    char nome[MAX];
    scanf( "%s", nome );
    hash_busca_nome( tabela_hash, nome, al );
    printf( "Resultado:\n"
    "Nome: %s; Matrícula: %d; Nota 1: %0.2f; Nota 2: %0.2f; Nota 3: %0.2f\n", al->nome, al->matricula, al->nota_1, al->nota_2, al->nota_3 );

    //printf( "Informa a matrícula a ser removida: " );
    scanf( "%d", &mat );
    if( hash_remove( tabela_hash, mat ) )
        printf( "%d removido.\n", mat );





    libera_hash( &tabela_hash );

    return 0;
}
