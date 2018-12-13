#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_table.h"
#include "lista_encadeada.h"

typedef struct hash
{
    int qtd;
    int TAM_TABELA;
    Lista **itens;
} Hash;

Hash *hash_criar( int tam_tabela )
{
    Hash *hash = (Hash *) malloc( sizeof( Hash) );

    if( hash != NULL)
    {
        hash->TAM_TABELA = tam_tabela;
        hash->qtd = 0;
        // Aloca o vetor de listas encadeadas.
        hash->itens = (Lista **) malloc( tam_tabela * sizeof( Lista *) );
        if( hash->itens == NULL )
        {
            free( hash );
            return NULL;
        }
    }

    int i;
    // Inicializa a tabela tendo todas as listas como vazias.
    for( i = 0 ; i < tam_tabela ; i++ )
        hash->itens[i] = NULL;
    
    return hash;
}

int hash_libera( Hash **hash )
{
    int tam_tabela = (*hash)->TAM_TABELA;

    int i;
    // Libera as listas da tabela hash.
    for( i = 0 ; i < tam_tabela ; i++ )
        if( (*hash)->itens[i] != NULL )
            lista_libera( &((*hash)->itens[i]) );
    free( (*hash)->itens );
    free( *hash );

    return 1;
}

int valor_string( char *str )
{
    int valor = 7;
    int tam = strlen( str );

    int i;
    for( i = 0 ; i < tam ; i++ )
        valor = (31 * tam) + ((int) str[i]);

    return valor;
}


int hash_chave_div( int chave, int tam_tabela )
{
    return (chave & 0x7FFFFFFF) % tam_tabela;
}

int hash_chave_mult( int chave, int tam_tabela )
{
    // Valor fixo.
    float A = 0.6180339887;
    float valor = chave * A;
    valor = valor - ((int) valor);

    return ((int) (tam_tabela * valor ));
}

int hash_chave_dobra( int chave, int tam_tabela )
{
    int num_bits = 10;
    int parte_1 = chave >> num_bits;
    int parte_2 = chave & (tam_tabela - 1);

    return (parte_1 ^ parte_2);
}

int hash_insere_encadeamento( Hash *hash, Aluno *al, int tipo_chave )
{
    if( hash == NULL )
        return -1;

    int index;

    if( tipo_chave == 2 )
        index = hash_chave_dobra( valor_string( al->nome ), hash->TAM_TABELA );
    else
        index = hash_chave_dobra( al->matricula, hash->TAM_TABELA );

    lista_insere_fim( &(hash->itens[index]), al );

    return 1;
}

int hash_busca_nome( Hash *hash, Aluno *al, char *nome )
{
    int index = hash_chave_dobra( valor_string( nome ), hash->TAM_TABELA );
    int cond = lista_busca_nome( &(hash->itens[index]), al, nome );
    if( cond == 1 )
        return 1;
    
    return 0;
}

int hash_busca_mat( Hash *hash, Aluno *al, int mat )
{
    int index = hash_chave_dobra( mat, hash->TAM_TABELA );
    int cond = lista_busca_mat( &(hash->itens[index]), al, mat );
    if( cond == 1 )
        return 1;
    
    return 0;
}

void hash_imprime( Hash *hash )
{
    int i;
    for( i = 0 ; i < hash->TAM_TABELA ; i++ )
    {
        if( hash->itens[i] != NULL )
        {
            printf( "____________________\n" );
            lista_imprime( &(hash->itens[i] ) );
            printf( "____________________\n" );
        }
        else
        {
            printf( "____________________\n\n" );
            printf( "%p\n", hash->itens[i] );
            printf( "____________________\n" );
        }
    }
}

// **************************************************

int hash_hashing( int chave, int tam_tabela )
{
    return hash_chave_mult( chave, tam_tabela );
}

// int sondagem_linear( int pos, int i, int tam_tabela )
// {
//     pos = pos + i;
//     return (pos & 0x7FFFFFFF) & tam_tabela;
// }

// i = tentativas de inserção. Se tentou inserir um elemento e houve colisão, i = 1, se houve colisão novamente, i = 2, e assim em diante.
// int sondagem_quadratica( int pos, int i, int tam_tabela )
// {
//     pos = pos + (i * 2) + (i * i * 5);
//     return (pos & 0x7FFFFFFF) & tam_tabela;
// }

// int insere_linear( Hash *hash, Aluno *al )
// {
//     if( hash == NULL || hash->qtd == hash->TAM_TABELA )
//         return 0;
    
//     int chave = al->matricula;
//     int nova_pos, pos = hash_chave_div( chave, hash->TAM_TABELA );

//     int i;
//     for( i = 0 ; i < hash->TAM_TABELA ; i++ )
//     {
//         nova_pos = sondagem_linear( pos, i, hash->TAM_TABELA );
//         if( hash->itens[i] == NULL )
//         {
//             hash->itens[i] = al;
//             hash->qtd++;
//             return 1;
//         }
//     }
// }

 