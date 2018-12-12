#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hash_table.h"

#define MAX_ALUNOS 10
#define TAM_TABELA 10


Aluno gerar_aluno( int );

int main()
{
    srand( time( NULL ) );
    
    Hash *tabela_alunos = NULL;
    tabela_alunos = hash_criar( TAM_TABELA );
    
    int i;
    for( i = 0 ; i < MAX_ALUNOS ; i++ )
    {
        Aluno aluno = gerar_aluno( i );
        hash_insere_encadeamento( tabela_alunos, &aluno, 2 );
    }

    hash_imprime( tabela_alunos );

    return 0;
}

Aluno gerar_aluno( int num )
{
    Aluno aluno;
    snprintf( aluno.nome, 100, "Aluno %d", num );
    aluno.matricula = rand()%99 + 100;
    aluno.nota_1 = rand() % 10;
    aluno.nota_2 = rand() % 10;
    aluno.nota_3 = rand() % 10;

    return aluno;
}