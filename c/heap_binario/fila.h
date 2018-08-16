#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct paciente
{
    string nome;
    int prioridade;
} Paciente;

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