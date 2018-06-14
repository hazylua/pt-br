#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aluno
{
    char *nome;
    int matricula;
    float n1, n2, n3;
} ALUNO;

typedef struct lista
{
    struct lista *prox;
    ALUNO dados_aluno;
} LISTA;

// a)
LISTA *inicializar_lista ();
// b)
int verificar_lista (LISTA *);
// c)
void esvaziar_lista (LISTA **);
// d)
void liberar_lista (LISTA **);
// e)
int verificar_tamanho (LISTA *);
// f)
void listar_elementos (LISTA *);
// g)
void listar_recursivo (LISTA *, LISTA *, int);
// h)
void adicionar_inicio (LISTA **, ALUNO);
// i)
void adicionar_fim (LISTA **, ALUNO);
// j)
int adicionar_ppos (LISTA **, ALUNO, int pos);
// k)
int adicionar_pordem (LISTA **, ALUNO);
// l)
void remover_inicio (LISTA **);
// m)
void remover_fim (LISTA **);
// n)
LISTA *busca_matricula (LISTA *, int);

#endif