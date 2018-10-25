#ifndef ARV_H
#define ARV_H

#include <stdio.h>
#include <stdlib.h>

typedef struct info{
    char *nome;
    int matricula;
    float nota_1, nota_2, nota_3;
} Info;

typedef struct arvore{
    Info aluno;
    struct arvore *esq;
    struct arvore *dir;
} No;

No **arvore_criar();

#endif