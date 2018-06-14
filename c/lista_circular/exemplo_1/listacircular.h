#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aluno
{
    char *nome;
    int matricula;
} ALUNO;

typedef struct lista
{
    struct lista *prox;
    ALUNO dados_aluno;
} LISTA;

LISTA *inicializar_lista ();
void liberar_lista (LISTA **l);

void listar_elementos (LISTA *);
void listar_recursivo (LISTA *, LISTA *, int);
int verificar_lista (LISTA *);
int verificar_tamanho (LISTA *);

void adicionar_inicio (LISTA **, ALUNO);
void adicionar_fim (LISTA **, ALUNO);

void remover_inicio (LISTA **);

#endif