#include <stdio.h>
#include <stdlib.h>

#define MAX 50

typedef struct aeronave
{
    int numVoo;
    int codAeronave;
    int qtdCombustivel;
} Aeronave;

typedef struct fila_prioridade
{
    int qtd;
    struct aeronave dados[MAX];
} FilaPrio;

FilaPrio *criar_fila();
void liberar_fila(FilaPrio **fila);
int fila_tamanho(FilaPrio *fila);
int fila_vazia(FilaPrio *fila);
int fila_cheia(FilaPrio *fila);
int fila_insere(FilaPrio *fila, int codAeronave, int numVoo, int qtdCombustivel);
int fila_remove(FilaPrio *fila);