#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_encadeada.h"

typedef struct lista_elemento
{
    Aluno dados;
    Lista *prox;
} Lista;

Lista **lista_criar()
{
    Lista **lista = (Lista **) malloc( sizeof (Lista *) );

    // Coloca a lista como vazia se ela já não estiver.
    if( lista != NULL )
        *lista = NULL;

    return lista;
}

int lista_libera( Lista **lista )
{
    // Se não estiver alocada.
    if( lista == NULL )
        return -1;

    // Se não estiver vazia.
    if( *lista != NULL )
        lista_esvazia( lista );

    return 1;
}

void lista_esvazia( Lista **lista )
{
    // Desnecessário?
    if( lista == NULL )
        return;

    // ***
    struct lista_elemento *atual;
    while( (*lista) != NULL )
    {
        atual = *lista;
        *lista = (*lista)->prox;
        free( atual );
    }
}

int lista_insere_fim( Lista **lista, Aluno *al )
{
    if( lista == NULL )
        return -1;

    Lista *atual, *novo;
    novo = (Lista *) malloc( sizeof( Lista ) );

    // Erro na alocação do nó.
    if( novo == NULL )
        return 0;
    novo->dados = *al;
    novo->prox = NULL;

    // Se a lista estiver vazia.
    if( (*lista) == NULL )
        *lista = novo;
    else
    {
        atual = *lista;
        // Percorre a lista até chegar ao seu fim.
        while( atual->prox != NULL )
            atual = atual->prox;
        atual->prox = novo;
    }
    
    return 1;
}

// O aluno passado pelo função vai receber o aluno caso ele esteja na lista.
int lista_busca_mat( Lista **lista, Aluno *al, int mat )
{
    if( lista == NULL )
        return -1;
    
    Lista *no = *lista;
    if( no != NULL && no->dados.matricula != mat )
        no = no->prox;

    if( no == NULL )
        return 0;

    *al = no->dados;
    return 1;
}

int lista_busca_nome( Lista **lista, Aluno *al, char *nome )
{
    if( lista == NULL )
        return -1;
    
    Lista *no = *lista;
    if( no != NULL && strcmp( no->dados.nome, nome) != 0 )
        no = no->prox;

    if( no == NULL )
        return 0;

    *al = no->dados;
    return 1;
}

void lista_imprime( Lista **lista )
{
    if( lista == NULL )
        return;
    
    Lista *atual = *lista;
    while( atual != NULL )
    {
        printf("\n DADOS DO ALUNO:");
        printf("\n Nome: %s",atual->dados.nome);
        printf("\n Matrícula: %d", atual->dados.matricula);
        printf("\n Nota 01: %0.2f", atual->dados.nota_1);
        printf("\n Nota 02: %0.2f", atual->dados.nota_2);
        printf("\n Nota 03: %0.2f \n", atual->dados.nota_3);
        atual = atual->prox;
    }
}





