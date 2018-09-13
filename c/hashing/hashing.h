#ifndef HASHING_H
#define HASHING_H

#include <stdio.h>
#include <stdlib.h>

#define TABELA_TAM 101

struct dados{
    
    char *nome;
    int matricula;
};
typedef struct dados Alunos;

struct hash{

    Alunos **dados;
    int qtd;
    int tam;
};
typedef struct hash Hash;

Hash *hash_cria();
void hash_libera( Hash ** );
int hash_insere( Hash *, int, char * );
int hash_busca( Hash *, int );
int hashing( Hash *, int);

#endif
