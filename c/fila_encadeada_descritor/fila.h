#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno
{
    int num_matricula;
    char nome[100];
} ALUNO;

typedef struct elemento
{
    ALUNO dados;
    struct elemento *prox;
} ELEMENTO;

typedef struct fila
{
    ELEMENTO *inicio;
    ELEMENTO *fim;
    int qtd;
} FILA;

FILA *criar_fila ();
void liberar_fila (FILA *);

int verificar_tam (FILA *);
int verificar_preenchida (FILA *);
int verificar_vazia (FILA *);
int mostrar_recursivo (FILA *, ELEMENTO *, int);
int mostrar_elementos (FILA *);

int inserir_final (FILA *);
int remover_inicio (FILA *);

#endif