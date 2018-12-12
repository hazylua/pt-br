#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "lista_encadeada.h"

typedef struct hash Hash;

Hash* hash_criar( int tam_tabela );;
int hash_libera( Hash **hash );

int valor_string( char *str );
int hash_hashing( int chave, int tam_tabela );
int hash_chave_mult( int chave, int tam_tabela );
int hash_chave_dobra( int chave, int tam_tabela );

int hash_insere_encadeamento( Hash *hash, Aluno *al, int tipo_chave );

int hash_busca_nome( Hash *hash, Aluno *al, char *nome );
int hash_busca_mat( Hash *hash, Aluno *al, int mat );

void hash_imprime( Hash *hash );

#endif