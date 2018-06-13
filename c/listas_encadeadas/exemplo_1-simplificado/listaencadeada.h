#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct lista
{
    struct lista *prox;
    int num;
} LISTA;

LISTA *inicializar_lista ();
void liberar_lista (LISTA *l);

void listar_elementos (LISTA *);
void verificar_lista (LISTA *);
int verificar_tamanho (LISTA *);

void adicionar_inicio (LISTA **, int);
void adicionar_fim (LISTA **, int);
void adicionar_ppos (LISTA **, int, int);

#endif