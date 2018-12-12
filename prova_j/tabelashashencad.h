#ifndef TABELASHASHENCAD_H
#define TABELASHASHENCAD_H
#include "ListaEncadeada/listaencadeada.h"


typedef struct hash Hash;

Hash* hash_cria(int size_tabela);
void hash_libera(Hash **tabHash);
int hash_hashing(int chave, int tableSize);
int hash_chaveDivisao(int chave, int tableSize);
int hash_chaveMultiplicacao(int chave, int tableSize);
int hash_chaveDobra(int chave, int tableSize);
int hash_valorString(char* str);
int hash_insereEncadeamento(Hash* tabHash, Aluno *al, int tipoChave);
int hash_buscaMatEncadeamento(Hash* tabHash, int mat, Aluno *al );
int hash_buscaNomeEncadeamento(Hash* tabHash, char *nome, Aluno *al );
void hash_printAluno(Aluno *al);
void hash_printTable(Hash *tabHash);


#endif //TABELASHASHENCAD_H
