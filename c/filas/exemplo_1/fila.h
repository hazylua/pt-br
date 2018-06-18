#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct aluno
{
    int num_matricula;
    char nome[MAX];
} ALUNO;

typedef struct fila
{
    int qtd;
    int inicio;
    int fim;
    ALUNO dados[MAX];
} FILA;

FILA *criar_fila ();
void liberar_fila (FILA *);

#endif