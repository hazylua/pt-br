#include "hash.h"

Hash *hash_cria() {

    Hash *hashtable = malloc( sizeof ( Hash ) );

    if( hashtable ) {
        hashtable->qtd = 0;
        hashtable->tam = TABELA_TAM;
        hashtable->dados = malloc( TABELA_TAM * sizeof( Alunos * ) );
        for( int i = 0 ; i < TABELA_TAM ; i++ ) {
            printf( "%d, ", i);

            hashtable->dados[i] = NULL;
        }    
    }

    return hashtable;
}

void hash_libera( Hash **hashtable ) {

    int cont;
    int tam = (*hashtable)->tam;

    for( cont = 0; cont < tam ; cont++ ) {
        if( (*hashtable)->dados[cont] != NULL )
            free( (*hashtable)->dados[cont] );
    }

    free( (*hashtable)->dados );
    free( *hashtable );
    *hashtable = NULL;
}

int inserir( Hash *hashtable, int matricula, char *nome ) {

    Alunos *al = (Alunos *) malloc( sizeof ( Alunos ) );
    
    al->matricula = matricula;
    al->nome = nome;

    int index = hashing( matricula, hashtable->tam );

    if( hashtable->dados[index] ) {
        hashtable->qtd++;
        return 1;
    }

    return 0;
}

int buscar( Hash *hashtable, int matricula ) {

    Alunos *al;
    int index = hashing( matricula, hashtable->tam );

    al = hashtable->dados[index];
    printf( "Matricula: %d\n", hashtable->dados[index]->matricula);
    if( al )
        return 1;

    return 0;
}

int hashing( int chave, int tabela_tam ) {

    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int) val;
    return (int) (tabela_tam * val);
}

int sondagem_linear( int pos, int i, int tabela_tam ) {

    return ((pos + i) & 0x7FFFFFFF) % tabela_tam;
}

int sondagem_quadratica( int pos, int i, int tabela_tam ) {

    pos = pos + (2 * i) + (5 * i * i);
    return (pos & 0x7FFFFFFF) % tabela_tam;
}

int duplo_hash( int hash_1, int chave, int i, int tabela_tam ) {

    int hash_2 = hashing( chave, tabela_tam - 1 ) + 1;
    return ((hash_1 + (i * hash_2)) & 0x7FFFFFFF) % tabela_tam;
}