#include "fila.h"

FilaPrio *criar_fila()
{
    FilaPrio *fila;
    fila = malloc(sizeof(FilaPrio));
    if(fila != NULL)
        fila->qtd = 0;
    return fila;
}

void liberar_fila(FilaPrio **fila)
{
    free(*fila);
    *fila = NULL;
}

int fila_tamanho(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return fila->qtd;
}

int fila_vazia(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return (fila->qtd == 0);
}

int fila_cheia(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return (fila->qtd == MAX);
}