#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

#define MAX 256

typedef struct dados
{
    char nome[MAX];
    int matricula;
    float nota_1, nota_2, nota_3;
} Aluno;

typedef struct lista_elemento
{
    Aluno dados;
    struct lista_elemento *prox;
} Lista;

Lista **lista_criar();
int lista_libera( Lista ** );
void lista_esvazia( Lista ** );

int lista_insere_fim( Lista **, Aluno );
int lista_busca_mat( Lista **, Aluno *, int );
int lista_busca_nome( Lista **, Aluno *, char * );

void lista_imprime( Lista ** );

#endif