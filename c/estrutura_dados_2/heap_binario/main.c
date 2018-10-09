#include "fila.h"

#define NUM_PACIENTES 10

int main ()
{
    system( "clear" );

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

    printf( "+---+ Fila 1 +---+\n");
    for( i = 0 ; i < qtd ; i++ )
        printf( "%d) Nome: %s; Prioridade na fila: %d\n", i, fila_1->dados[i].nome, fila_1->dados[i].prio );
    printf( "+---+ Fila 2 +---+\n");
    for( i = 0 ; i < qtd ; i++ )
        printf( "%d) Nome: %s; Prioridade na fila: %d\n", i, fila_2->dados[i].nome, fila_2->dados[i].prio );

    
    liberar_fila( &fila_1 );
    liberar_fila( &fila_2 );

    return 0;
}

// int main()
// {
//     FilaPrio *fila1 = criar_fila();

//     FilaPrio *fila2 = criar_fila();

//     char nome[30];

//     int i;
//     for(i = 2; i < NUM_PACIENTES+2; i++)
//     {
//         sprintf(nome, "A%d", i);
//         fila_inserir(fila1, nome, NUM_PACIENTES+i);
//         nome[0] = '\0';
//     }
//     for(i = 0; i < NUM_PACIENTES; i++)
//     {
//         sprintf(nome, "B%d", i);
//         fila_inserir(fila2, nome, NUM_PACIENTES+i);
//         nome[0] = '\0';
//     }

//     mostrar_fila( fila1 );
//     mostrar_fila( fila2 );

//     merge_heap( fila1, fila2, fila_tamanho(fila2)-1 );
//     liberar_fila( &fila2 );
//     nome[0] = '\0';

//     Paciente teste;
//     teste.nome[30] = "A3";
//     teste.prio = 3;

//     if( procura(fila1, teste) == 1)
//         printf( "Paciente existe na fila.\n" );
//     else
//         printf( "Paciente não existe na fila.\n" );

//     mostrar_fila( fila1 );
//     liberar_fila( &fila1 );
//     return 0;
// }

// void mostrar_fila(FilaPrio *fila)
// {
//     int i;
//     printf ("Lista: [");
//     int qtd = fila_tamanho(fila);
//     for(i = 0; i < qtd; i++)
//     {
//         printf ("%s", fila->dados[i].nome);
//         if(i!=qtd-1)
//             printf (", ");
//     }
//     printf ("]\n");
//     printf("Tamanho da fila: %d\n", qtd);
// }