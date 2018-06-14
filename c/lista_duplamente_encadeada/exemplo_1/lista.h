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
    struct lista *prox;
    ALUNO dados_aluno;
} LISTA;

#endif