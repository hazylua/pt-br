#ifndef ARV_H
#define ARV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info{
    char nome[100];
    int matricula;
    float nota_1, nota_2, nota_3;
} Info;

typedef struct arvore{
    Info aluno;
    struct arvore *esq;
    struct arvore *dir;
} No;

No **arvore_criar();
int arvore_inserir( No **, Info );
int arvore_exibir( No * );
int arvore_vazia( No * );
int arvore_contarNos( No * );
int arvore_altura( No * );
int maior( int, int );
#endif