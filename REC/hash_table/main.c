#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hash_table.h"

#define MAX_ALUNOS 10
#define TAM_TABELA 51


Aluno gerar_aluno( int );

int main()
{
    srand( time( NULL ) );
    
    Hash *tabela_alunos = NULL;
    tabela_alunos = hash_criar( TAM_TABELA );

    Aluno aluno;
    snprintf( aluno.nome, 100, "Aluno %d", 1 );
    aluno.matricula = rand()%99 + 100;
    aluno.nota_1 = rand() % 10;
    aluno.nota_2 = rand() % 10;
    aluno.nota_3 = rand() % 10;

    hash_insere_encadeamento( tabela_alunos, &aluno, 2 );

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