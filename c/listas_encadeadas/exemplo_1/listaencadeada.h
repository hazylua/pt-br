#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

void listar_elementos (LISTA **);

void verificar_lista (LISTA **);
int verificar_tamanho (LISTA **);

void adicionar_inicio (LISTA **, ALUNO);
void adicionar_final (LISTA **, ALUNO);
void adicionar_ppos (LISTA **, ALUNO, int);
void adicionar_pordem (LISTA **, ALUNO);

#endif