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
    ALUNO dados;
    struct lista *prox;
} LISTA;

LISTA **inicializar_lista ();
void liberar_lista (LISTA **);

void verificar_lista (LISTA **);

void adicionar_inicio (LISTA **, ALUNO);

void listar_elementos (LISTA **);

#endif