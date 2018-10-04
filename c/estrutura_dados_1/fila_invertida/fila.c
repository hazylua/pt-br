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

int fila_insere(FilaPrio *fila, int codAeronave, int numVoo, int qtdCombustivel)
{
    if(fila == NULL)
        return -1;

    if(fila_cheia (fila))
        return 0;

    int i = fila->qtd-1;
    while(i >= 0 && fila->dados[i].qtdCombustivel <= qtdCombustivel ){
        fila->dados[i+1] = fila->dados[i];
        i--;
    }
    fila->dados[i+1].codAeronave = codAeronave;
    fila->dados[i+1].numVoo = numVoo;
    fila->dados[i+1].qtdCombustivel = qtdCombustivel;
    fila->qtd++;
    return 1;

}

int fila_remove(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    if(fila->qtd == 0 )
        return 0;

    fila->qtd--;
    return 1;
}