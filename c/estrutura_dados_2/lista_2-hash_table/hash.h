#ifndef HASH_H
#define HASH_H

#include <stdio.h>

struct dados
{
    char nome[30];
    int matricula;
    float nota_1, nota_2, nota_3;
};

typedef struct dados Aluno;
typedef struct lista Lista;
typedef struct hash Hash;

typedef struct node Node;
typedef struct node1 Node_hash;

Hash *cria_hash( int );
int libera_hash( Hash ** );
int hash_insere( Hash *, Aluno );
int hash_calc( int, int );
int hash_busca( Hash *, int, Aluno * );
int hash_busca_nome( Hash *, char *, Aluno * );

void imprime( Hash * );

int chave_multi( int, int );
int chave_div( int, int );

int sondagem( int, int, int );
int sondagem_quad( int, int, int );
int hash_duplo( int, int, int, int );

int hash_string( char * );

int hash_remove( Hash *, int );

#endif