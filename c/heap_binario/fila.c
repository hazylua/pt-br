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

void fila_promover(FilaPrio *fila, int filho)
{
    int pai;
    Paciente temp;
    pai = (filho - 1) / 2;
    while ((filho > 0) && (fila->dados[pai].prio <= fila->dados[filho].prio))
    {
        temp = fila->dados[filho];
        fila->dados[filho] = fila->dados[pai];
        fila->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    } 
}

int fila_inserir(FilaPrio *fila, char *nome, int prio)
{
    if(fila == NULL)
        return -1;
    if(fila->qtd == MAX)
        return 0;
    
    strcpy(fila->dados[fila->qtd].nome, nome);
    fila->dados[fila->qtd].prio = prio;
    fila_promover (fila, fila->qtd);
    fila->qtd++;

    return 1;
}

void fila_rebaixar(FilaPrio *fila, int pai)
{
    Paciente temp;
    int filho = (2 * pai) + 1;
}