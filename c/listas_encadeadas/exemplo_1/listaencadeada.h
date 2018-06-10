#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct aluno
{
    int num_id;
    int matricula;
} ALUNO;

typedef struct lista
{
    struct lista *prox;
    ALUNO dados;
} LISTA;

void inicializar_lista (LISTA **);

#endif