#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct paciente
{
    char nome[30];
    int prio;
} Paciente;

typedef struct fila_prioridade
{
    int qtd;
    Paciente dados[MAX];
} FilaPrio;

FilaPrio *criar_fila();
int procura( FilaPrio*, Paciente );
void mergeHeap( FilaPrio*, FilaPrio*, int );
void liberar_fila( FilaPrio **fila );
int fila_tamanho( FilaPrio *fila );
int fila_vazia( FilaPrio *fila );
int fila_cheia( FilaPrio *fila );
void fila_promover( FilaPrio *fila, int filho );
int fila_inserir( FilaPrio *fila, char *nome, int prio );
void fila_rebaixar( FilaPrio *fila, int pai );
int fila_remover( FilaPrio *fila );