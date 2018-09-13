#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#define table_tam 101

struct dados {

	char *nome;
	int matricula;
};
typedef struct dados Alunos;
typedef struct hash Hash;

Hash* hash_cria();
void Hash_libera(Hash**);
int insere(Hash*);
int busca(int, Hash*);
int hashCode(int, Hash*);

#endif