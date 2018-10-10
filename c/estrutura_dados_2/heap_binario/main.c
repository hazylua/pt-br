#include "fila.h"

#define NUM_PACIENTES 10

int mostrar_fila( FilaPrio *, char *);

int main ()
{
    FilaPrio *fila_1 = criar_fila();
    FilaPrio *fila_2 = criar_fila();
    char nome[100];
    int prio, qtd, i;

    //printf( "Quantos pacientes deseja inserir na fila? " );
    scanf( "%d", &qtd );

    for( i = 0 ; i < qtd ; i++ )
    {
        //printf( "Digite o nome do paciente: " );
        scanf( "%s", nome );
        //printf( "Digite a sua prioridade na fila: " );
        scanf( "%d", &prio );

        fila_inserir( fila_1, nome, prio );
    }

    for( i = 0 ; i < qtd ; i++ )
    {
        //printf( "Digite o nome do paciente: " );
        scanf( "%s", nome );
        //printf( "Digite a sua prioridade na fila: " );
        scanf( "%d", &prio );

        fila_inserir( fila_2, nome, prio );
    }

    mostrar_fila( fila_1, "Fila 1" );
    mostrar_fila( fila_2, "Fila 2" );
    fila_remover( fila_2 );
    mostrar_fila( fila_2, "Fila 2" );


    merge_heap( fila_1, fila_2, fila_2->qtd-1);
    liberar_fila( &fila_2 );

    mostrar_fila( fila_1, "Fila 1" );

    liberar_fila( &fila_1 );

    return 0;
}


int mostrar_fila( FilaPrio *fila, char *nome_fila )
{
    if( fila == NULL )
    {
        printf( "%s não existe.\n", nome_fila );
        return -1;
    }

    int i;
    printf( "+++++ %s +++++\n", nome_fila );
    for( i = 0 ; i < fila->qtd ; i++ )
        printf( "%d) Nome: %s; Prioridade na fila: %d\n", i, fila->dados[i].nome, fila->dados[i].prio );
    printf( "Tamanho da fila: %d\n\n", fila_tamanho( fila ) );

    return 1;
}