#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct elemento
{
    char letra;
    struct elemento *prox;
} ELEMENTO;

typedef struct pilha
{
    ELEMENTO *inicio;
    ELEMENTO *fim;
    int qtd;
} PILHA;

PILHA *criar_pilha ();
void liberar_pilha (PILHA *);

int verificar_tam (PILHA *);
int verificar_preenchida (PILHA *);
int verificar_vazia (PILHA *);
int mostrar_elementos (PILHA *);
int mostrar_topo (PILHA *);

int inserir_final (PILHA *);
int remover_final (PILHA *);
int esvaziar_pilha (PILHA *);

int validar_parenteses (PILHA *);

void clean_stdin ();

#endif