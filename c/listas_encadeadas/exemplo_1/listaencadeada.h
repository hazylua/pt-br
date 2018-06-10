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

void verificar_erro (LISTA **);

void inicializar_lista (LISTA **);
void liberar_lista (LISTA **);

void verificar_lista (LISTA **);

void adicionar_inicio (LISTA **);

void listar_elementos (LISTA *);

#endif