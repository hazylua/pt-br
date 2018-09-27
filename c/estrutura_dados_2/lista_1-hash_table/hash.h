#ifndef HASHING_H
#define HASHING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <list>

using namespace std;

#define TABELA_TAM 101

struct dados{
    
    char *nome;
    int matricula;
};
typedef struct lista Lista;
typedef struct dados Alunos;
typedef struct hash Hash;

Lista *lista_cria();
int lista_insere( Lista *, int, char const * );
void lista_libera( Lista ** );

//Alocação da tabela hash.
Hash *hash_cria();

//Desalocação da tabela hash.
void hash_libera( Hash ** );

//Hashing por multiplicação.
int inserir( Hash *, Hash *, int, char const * );
int buscar( Hash *, int );
int hashing( int, int );
int string_key(char *);

//Tratamento de colisões.
//Endereçamento aberto por sondagem linear.
int sondagem_linear( int, int, int );
//Endereçamento aberto por sondagem quadrática.
int sondagem_quadratica( int, int, int );
//Endereçamento aberto por duplo hash.
int duplo_hash( int, int, int, int );

#endif