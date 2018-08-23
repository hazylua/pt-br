#include "fila.h"

#define NUM_PACIENTES 2

void mostrar_fila(FilaPrio *fila);

int main()
{
    FilaPrio *fila = criar_fila();

    FilaPrio *fila2 = criar_fila();

    char nome[30];

    int i;
    for(i = 0; i < NUM_PACIENTES; i++)
    {
        sprintf(nome, "P%d", i);

        fila_inserir(fila2, "Joao", NUM_PACIENTES+i);
        fila_inserir(fila, nome, NUM_PACIENTES+i);

        nome[0] = '\0';
    }
    
    
    printf("%d\n", fila_tamanho(fila));
    mergeHeap(fila, fila2, fila_tamanho(fila2)-1);
    liberar_fila(&fila2);
    nome[0] = '\0';

    mostrar_fila(fila);
    liberar_fila(&fila);
    return 0;
}

void mostrar_fila(FilaPrio *fila)
{
    int i;
    printf ("Lista: [");
    int qtd = fila_tamanho(fila);
    for(i = 0; i < qtd; i++)
    {
        printf ("%s", fila->dados[i].nome);
        if(i!=qtd-1)
            printf (", ");
    }
    printf ("]\n");
    printf("Tamanho da fila: %d\n", qtd);
}