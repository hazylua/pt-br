#ifndef HASH_H
#define HASH_H
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;

#define TABELA_TAM 101

struct dados
{    
    char *nome;
    int matricula;
    int nota_1;
    int nota_2;
    int nota_3;
};

typedef struct lista Lista;
typedef struct dados Alunos;
typedef struct hash Hash;

Lista *lista_cria();
int lista_insere( Lista *, int, char const * );
void lista_libera( Lista ** );

Hash *hash_cria();
void hash_libera( Hash ** );

int inserir( Hash *, Hash *, int, char const * );
int buscar( Hash *, int );
int hashing( int, int );
int string_key(char *);

int sondagem_linear( int, int, int );
int sondagem_quadratica( int, int, int );
int duplo_hash( int, int, int, int );

#endif