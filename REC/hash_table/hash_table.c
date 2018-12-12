#include "hash_table.h"
#include "lista_encadeada.h"

Hash *hash_cria( int tam_tabela )
{
    Hash *hash = (Hash *) malloc( sizeof( Hash) );

    if( hash != NULL)
    {
        hash->TAM_TABELA = tam_tabela;
        hash->qtd = 0;
        hash->itens = lista_criar();
    }

    int i;
    // Inicializa a tabela tendo todas as listas como vazias.
    for( i = 0 ; i < tam_tabela ; i++ )
        hash->itens[i] = NULL;
    
    return hash;
}

int hash_libera( Hash **hash )
{
    if( hash == NULL )
        return -1;

    int tam_tabela = (*hash)->TAM_TABELA;

    int i;
    // Libera as listas da tabela hash.
    // ***
    for( i = 0 ; i < tam_tabela ; i++ )
        if( (*hash)->itens[i] != NULL )
            lista_libera( &((*hash)->itens[i]) );
    // ???
    free( (*hash)->itens );
    free( *hash );

    return 1;
}

// ???
int valor_string( char *str )
{
    int valor = 7;
    int tam = strlen( str );

    int i;
    for( i = 0 ; i < tam ; i++ )
        valor = 31 * tam + ((int) str[i]);

    return valor;
}

int hash_hashing( int chave, int tam_tabela )
{
    return hash_chave_mult( chave, tam_tabela );
}

int hash_chave_mult( int chave, int tam_tabela )
{
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
    int cond = lista_busca_nome( &(hash->itens[index]), al, mat );
    if( cond == 1 )
        return 1;
    
    return 0;
}








