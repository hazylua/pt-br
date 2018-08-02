#include "fila.h"

struct aeronave
{
    int numVoo;
    int codAeronave;
    int qtdCombustivel;
};

struct filaPrioridade
{
    int qtd;
    struct aeronave dados[MAX];
};

filaPrio *fila_cria ()
{
    filaPrio* fila;
    fila = malloc (sizeof (filaPrio));
    if (fila != NULL)
        fila->qtd = 0;
    return fila;
}

void *fila_libera (filaPrio **fila)
{
    free (*fila);
    *fila = NULL;
}

void acessa_tamanho (filaPrio *fila)
{
    printf ("Tamanho da fila: %d\n", fila->qtd);
}

void verifica_vazio (filaPrio *fila)
{
    if (fila->qtd == 0)
        printf ("Fila vazia.\n");
    else
        printf ("Fila não vazia.\n");
}

void verifica_cheia (filaPrio *fila)
{
    if (fila->qtd == MAX)
        printf ("Fila cheia.\n");
    else
        printf ("Fila não cheia.\n");
}