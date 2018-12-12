#include "hash_table.h"
#include "lista_encadeada.h"

#define MAX_ALUNOS 10

Aluno gerar_aluno( int );

int main()
{
    srand( time( NULL ) );
    
    Lista **lista;
    lista = lista_criar();

    int i;
    for( i = 0 ; i < MAX_ALUNOS ; i++ )
    {
        lista_insere_fim( lista, gerar_aluno( i ) );
    }

    lista_imprime( lista );

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