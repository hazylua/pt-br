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