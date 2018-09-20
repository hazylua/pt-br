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

//Alocação da tabela hash.
Hash *hash_cria();

//Desalocação da tabela hash.
void hash_libera( Hash ** );

//Hashing por multiplicação.
int inserir( Hash *, int, char * );
int buscar( Hash *, int );
int hashing( int, int );

#endif