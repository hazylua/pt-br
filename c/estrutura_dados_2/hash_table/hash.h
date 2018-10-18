#ifndef HASH_H
#define HASH_H

#include <stdio.h>

#define MAX 100

// Estrutura de dados que representa um aluno.
typedef struct dados
{
    char nome[MAX];
    int matricula;
    float nota_1, nota_2, nota_3;
} Aluno;

// Nodes da lista encadeada.
typedef struct node
{
    Aluno dado;
    struct node *prox;
    struct node *ant;
} Node;

// Nodes da tabela hash.
typedef struct node_hash
{
    Node *info;
    struct node_hash *prox;
} Node_hash;

// Lista encadeada usada para o tratamento de colisões.
typedef struct lista
{
    int tam;
    Node *inicio;
    Node *final;
} Lista;

typedef struct hash
{
    int qtd;
    int qtd_2;
    int tam;
    Lista *lista;
    Node_hash **tabela_1;
    Node_hash **tabela_2;
} Hash;

Hash *cria_hash( int );
int libera_hash( Hash ** );
int hash_insere( Hash *, Aluno );
int hash_calc( int, int );
int hash_busca_matricula( Hash *, int, Aluno * );
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