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
    free (fila);
}