#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct aluno
{
    int num_matricula;
    char nome[MAX];
} ALUNO;

typedef struct pilha
{
    int qtd;
    ALUNO dados[MAX];
} PILHA;

PILHA *criar_pilha ();
void liberar_pilha (PILHA *);

int verificar_tam (PILHA *);
int verificar_preenchida (PILHA *);
int verificar_vazia (PILHA *);
int mostrar_elementos (PILHA *);

int inserir_dados (PILHA *);
int remover_elemento (PILHA *);

#endif