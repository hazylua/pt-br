#ifndef PILHA_H
#define PILHA_H

#include <stdio.h>
#include <stdlib.h>

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

// Criação e liberação da estrutura de dados
PILHA *criar_pilha ();
void liberar_pilha (PILHA *);

// Verificação e exibição de elementos da estrutura de dados
int verificar_tam (PILHA *);
int verificar_preenchida (PILHA *);
int verificar_vazia (PILHA *);
int mostrar_elementos (PILHA *);
int mostrar_topo (PILHA *);

// Remoção e inserção de elementos na estrutura de dados
int inserir_final (PILHA *);
int remover_final (PILHA *);
int esvaziar_pilha (PILHA *);

// Alternativa a função fflush (stdin)
void clean_stdin ();

#endif