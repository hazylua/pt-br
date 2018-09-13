#include "hashing.h"

Hash *hash_cria() {

    Hash *hashtable = malloc( sizeof ( Hash ) );

    if( hashtable ) {
        hashtable->qtd = 0;
        hashtable->tam = TABELA_TAM;
        hashtable->dados = malloc( TABELA_TAM * sizeof( Alunos * ) );
        for( int i = 0 ; i < TABELA_TAM ; i++ ) {
            printf( "%d, ", i);

            hashtable->dados[i] = NULL;
            
            // if( hashtable->dados[i] == NULL)
            //     printf( "%d\n", 1);
            // else
            //     printf( "%d\n", 0);
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

int hash_insere( Hash *hashtable, int matricula, char *nome ) {

    Alunos *al;
    al->matricula = matricula;
    al->nome = nome;

    int index = hashing( hashtable, matricula );
    
    

    if( hashtable->dados[index] ) {
        hashtable->qtd++;
        return 1;
    }

    return 0;
}

int hash_busca( Hash *hashtable, int matricula ) {

    Alunos *al;
    int index = hashing( hashtable, matricula );

    al = hashtable->dados[index];
    printf( "Matricula: %d\n", hashtable->dados[index]->matricula);
    if( al )
        return 1;

    return 0;
}

int hashing( Hash *hashtable, int matricula ) {

    return ((matricula & 0x7FFFFFFF) % hashtable->tam);
}