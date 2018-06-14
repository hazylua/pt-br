#ifndef LISTA_H
#define LISTA_H

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
    struct lista *ant;
    struct lista *prox;
    ALUNO dados_aluno;
} LISTA;

LISTA *inicializar_lista ();
void liberar_lista (LISTA **l);

int verificar_lista (LISTA *);
int verificar_tamanho (LISTA *);

void listar_elementos (LISTA *);
void listar_recursivo (LISTA *, LISTA *, int);
void listar_recursivo_reverso (LISTA *, int, int);

void inserir_inicio (LISTA **, ALUNO);
void inserir_fim (LISTA **, ALUNO);

#endif