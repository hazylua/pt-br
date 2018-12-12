#include "lista_encadeada.h"

#ifndef HASH_TABLE_H
#define HASH_TABLE_H

typedef struct hash_table
{
    int qtd;
    int TAM_TABELA;
    Lista **itens;
} Hash;

Hash* hash_cria( int tam_tabela );


#endif