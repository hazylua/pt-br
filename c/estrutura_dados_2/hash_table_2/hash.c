#include "hash.h"
#include "string.h"
#include "stdlib.h"

struct hash
{
    int qtd;
    int qtd_2;
    int tam;
    Lista *lista;
    Node_hash **tabela_1;
    Node_hash **tabela_2;
};

typedef struct node1
{
    Node *info;
    Node_hash *prox;
} Node_hash;

typedef struct lista
{
    int tam;
    Node *inicio;
    Node *final;
} Lista;

typedef struct node
{
    Aluno dado;
    Node *prox;
    Node *ant;
} Node;

//Cria tabela hash.
Hash *cria_hash( int n )
{
    Hash *p = ( Hash* ) malloc( sizeof( Hash ) ); 
    if( p != NULL )
    {
        p->qtd = 0;
        p->qtd_2 = 0;
        p->tam = n;
        p->tabela_1 = ( Node_hash ** ) malloc ( n * sizeof( Node_hash * ) );
        p->tabela_2  = (Node_hash ** ) malloc ( n * sizeof( Node_hash * ) );
        p->lista = ( Lista* ) malloc( sizeof( Lista ) );
        p->lista->final = NULL;
        p->lista->inicio = NULL;
        p->lista->tam = 0;
        
        for( int i = 0 ; i < n ; i++ )
        {
            p->tabela_1[i] = NULL;
            p->tabela_2[i] = NULL;
        }
    }

    return p;
}

//Libera tabela hash.
int libera_hash( Hash **p )
{
    if( *p == NULL )
        return 0;
    
    Node_hash *no, *q;
    for( int i = 0 ; i < (*p)->tam ; i++ )
    {
        //Libera tabela 1:
        if( (*p)->tabela_1[i] != NULL )
        {
            no = (*p)->tabela_1[i];
            while(no != NULL)
            {
                q = no;
                no = no->prox;
                free(q);
            }
        }

        //Libera tabela 2:
         if( (*p)->tabela_2[i] != NULL )
         {
            no = (*p)->tabela_2[i];
            while(no != NULL){
                q = no;
                no = no->prox;
                free(q);
            }
        }
    }
    free( (*p)->tabela_1 );
    free( (*p)->tabela_2 );

    //Libera lista:
    Node *x = (*p)->lista->inicio;
    Node *n;

    while( x !=NULL )
    {
        n = x;
        x =  x->prox;
        free( n );
    }
    free( (*p)->lista );
    free( *p );
    *p = NULL;

    return 1;
}

int hash_insere( Hash *hash, Aluno Al )
{
    int var = 0;

    //Verifica se "hash" está alocada ou cheia:
    if( hash == NULL || hash->qtd == hash->tam )
        return 0;

    Node *n = ( Node * ) malloc( sizeof ( Node ) );
    n->dado = Al;

    //Inserção na lista:
    if( hash->lista->tam == 0 )
    {
        //???
        //n->dado = Al;
        hash->lista->inicio = n;
        hash->lista->final = n;
        n->prox = NULL;
        n->ant = NULL;
        hash->lista->tam++;

    } else
    {
        //???
        //n->dado = Al;
        hash->lista->final->prox = n;
        n->prox = NULL;
        n->ant = hash->lista->final;
        hash->lista->final = n;
        hash->lista->tam++;
    }

    //Inserção na tabela 1 (matrícula):
    int pos = hash_calc( Al.matricula, hash->tam );
    Node_hash *no = ( Node_hash * ) malloc( sizeof( Node_hash ) );
    no->info = n;
    no->prox = NULL;

    if( hash->tabela_1[pos] == NULL )
    {
        hash->tabela_1[pos] = no;
        hash->qtd++;
    } else
    {
        Node_hash *p = hash->tabela_1[pos];
        while( p->prox != NULL )
            p = p->prox;
        p->prox = no;
        hash->qtd++;
    }

    //Inserção na tabela 2 (nome):
    pos = hash_calc( hash_string(Al.nome), hash->tam );
    Node_hash *no_2 = ( Node_hash * ) malloc( sizeof ( Node_hash ) );
    no_2->info = n;
    no_2->prox = NULL;
    if( hash->tabela_2[pos] == NULL )
    {
        hash->tabela_2[pos] = no_2;
        hash->qtd_2++;
    } else
    {
        Node_hash *p = hash->tabela_2[pos];
        while(p->prox != NULL )
            p = p->prox;
        p->prox = no_2;
        hash->qtd_2++;
    }
             
    return 1;
}

int hash_calc( int mat, int tam )
{
    return chave_multi( mat, tam );
}

int hash_busca( Hash *hash, int mat, Aluno *al )
{
    //Verificação:
    if( hash == NULL || hash->qtd == 0 ) 
        return 0;

    int pos = hash_calc ( mat, hash->tam );
    
    if( hash->tabela_1[pos] == NULL )
        return 0;

    Node_hash *p = hash->tabela_1[pos];
    while( p->info->dado.matricula != mat )
    {
        p = p->prox;
        if( p == NULL )
            return -1;
    }

    al->matricula = p->info->dado.matricula;
    al->nota_1 = p->info->dado.nota_1;
    al->nota_2 = p->info->dado.nota_2;
    al->nota_3 = p->info->dado.nota_3;
    strcpy( al->nome, p->info->dado.nome );

    return 1;
}


int hash_busca_nome( Hash *hash, char *nome, Aluno *al )
{
    //Verificação:
    if( hash == NULL || hash->qtd_2 == 0 ) 
        return 0;
   
    int pos = hash_calc( hash_string( nome ), hash->tam );
    
    if( hash->tabela_2[pos] == NULL )
        return 0;

    Node_hash *p = hash->tabela_2[pos];
    while( strcmp( p->info->dado.nome, nome ) != 0 )
    {
        p = p->prox;
        if(p == NULL)
            return -1;
    }

    al->matricula = p->info->dado.matricula;
    al->nota_1 = p->info->dado.nota_1;
    al->nota_2 = p->info->dado.nota_2;
    al->nota_3 = p->info->dado.nota_3;
    strcpy( al->nome,p->info->dado.nome );

    return 1;
}


void imprime( Hash *hash )
{
    printf("Numero de elementos: %d\n", hash->lista->tam);

    Node *p = hash->lista->inicio;
    while( p != NULL )
    {
        printf("Nome: %s;  Mat: %d\n", p->dado.nome, p->dado.matricula );
        p=p->prox;
    }
}

int chave_multi( int chave,int tam )
{
     float a = chave * 0.6180339887;
     a = a - (int) a;
     return (int) (tam * a);
}

int chave_div( int chave,int tam )
{
    return (chave & 0x7fffffff) % tam;
}

int sondagem( int pos, int i, int tam )
{
    return ((pos+i) & 0x7fffffff) % tam;
}

int sondagem_quad(int pos, int i, int tam)
{
    pos = pos + (2 * i) + (5 * i * i);
    return (pos & 0x7fffffff) % tam;
}

int hash_duplo( int h1, int chave, int i, int tam )
{
    int h2 = chave_div( chave,tam ) + 1;
    return ((h1 + (i * h2)) & 0x7fffffff) % tam;
}

int hash_string( char *str )
{
    int i, valor = 7;
    for( i = 0 ; i < strlen(str) ; i++ )
        valor = (31 * valor) + (int) str[i];
    return valor;
}

int hash_remove( Hash *hash, int mat )
{        
    char nome[30];
    if( hash == NULL || hash->qtd == 0 ) 
        return 0;

    int pos = hash_calc( mat, hash->tam );
    
    if( hash->tabela_1[pos] == NULL )
        return 0;

    Node_hash *p, *ant;
    ant = p = hash->tabela_1[pos];

    while( p->info->dado.matricula != mat && p->prox != NULL )
    {
        ant = p;
        p = p->prox;
    }
    
    if( p->info->dado.matricula != mat )
        return -1;
    strcpy(nome,p->info->dado.nome);
    
    Node *q;
    if( p == hash->tabela_1[pos] )
        hash->tabela_1[pos] = NULL;
    else if( p->prox == NULL )
        ant->prox = NULL;
    else
        ant->prox = p->prox;
    free(p);

    pos = hash_calc( hash_string(nome), hash->tam );
    if( hash->tabela_2[pos] == NULL )
        return 0;
    p = hash->tabela_2[pos];
    while( strcmp( p->info->dado.nome, nome ) != 0 && p->prox != NULL )
    {
        ant = p;
        p = p->prox;
    }
    if( strcmp( p->info->dado.nome, nome ) != 0 )
        return -1;

    if( p == hash->tabela_2[pos] )
        hash->tabela_2[pos] = NULL;
    else if( p->prox == NULL )
        ant->prox = NULL;
    else
        ant->prox = p->prox;
        
    if( p->info->prox == NULL )
    {
        q = p->info->ant;
        printf( "Teste.\n" );
        q->prox = NULL;
    } else
    {        
        q = p->info->ant;
        q->prox = p->info->prox;
        (q->prox)->ant = q;
    }

    free(p->info);
    free(p);

    hash->qtd--;
    hash->qtd_2--;
    hash->lista->tam --;

    return 1;
}