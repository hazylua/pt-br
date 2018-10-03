#include "hash.h"

struct lista
{
    Alunos *al;
    Lista *prox;
    Lista *ant;
};

struct hash
{
    list<Alunos *> *dados;
    int qtd;
    int tam;
};

Lista *lista_cria()
{
    Lista *l = (Lista *) malloc( sizeof ( Lista ) ); 
    l->prox = NULL;
    l->ant = NULL;
    l->al = NULL;

    return l;
}

int lista_insere( Lista *l, int matricula, char const *nome )
{
    Lista *novo = lista_cria();
    Lista *temp = l;

    if( l->prox == NULL && l->ant == NULL )
    {
        l->al->matricula = matricula;
        printf("teste\n");
        l->al->nome = (char *)malloc(strlen(nome));
        strcpy(l->al->nome, nome); 
        return 1;
    }
    else
    {
        printf( "teste1\n" );
        while( temp->prox != NULL ) temp = temp->prox;
        temp->prox = novo;
        novo->ant = temp;
        return 1;
    }
    return 0;
}

Hash *hash_cria()
{
    Hash *hashtable = (Hash *)malloc(sizeof(Hash));

    if (hashtable)
    {
        printf( "teste\n" );
        hashtable->qtd = 0;
        hashtable->tam = TABELA_TAM;
        hashtable->dados = new list<Alunos *>[TABELA_TAM];
        // if( hashtable->dados == NULL )
        //     printf( "dados = null\n" );
    }

    return hashtable;
}

void lista_libera( Lista **lista )
{
    Lista *temp;

    while ((*lista)->al != NULL)
    {
        temp = *lista;
        *lista = (*lista)->prox;
        free(temp);
    }
    free(*lista);
    *lista = NULL;
}

void hash_libera(Hash **hashtable)
{
    free(*hashtable);
    *hashtable = NULL;
}

int inserir(Hash *hashtable_nome, Hash *hashtable_matr, int matricula, char const *nome)
{
    printf( "teste.\n" );
    Alunos *al = (Alunos *)malloc(sizeof(Alunos));
    al->nome = (char *)malloc(strlen(nome));
    strcpy(al->nome, nome);
    al->matricula = matricula;

    int index1 = hashing(matricula, TABELA_TAM);
    int index2 = hashing(string_key(al->nome), TABELA_TAM);

    printf("Index: %d\n", index1);
    printf("Index: %d\n", index2);

    hashtable_nome->dados[index1].push_back(al);
    hashtable_matr->dados[index2].push_back(al);
    hashtable_nome->qtd++;
    hashtable_matr->qtd++;

    return 1;
}

int buscar(Hash *hashtable, int matricula)
{
    Alunos *al;
    int index = hashing(matricula, hashtable->tam);
    printf("Index: %d\n", index);
    if (hashtable->dados[index].size())
    {
        al = hashtable->dados[index].back();
        printf("Matricula: %d\n", al->matricula);
        return 1;
    }
    printf("Aluno não encontrado!\n");
    return 0;
}

int hashing(int chave, int tabela_tam)
{
    float A = 0.6180339887;
    float val = chave * A;
    val = val - (int)val;
    return (int)(tabela_tam * val);
}

int string_key(char *str)
{
    int i, valor = 7;
    int tam = strlen(str);
    for( i = 0; i < tam; i++ ){
        valor = valor * 11 + (int) str[i];
    }

    return valor;
}

int sondagem_linear(int pos, int i, int tabela_tam)
{
    return ((pos + i) & 0x7FFFFFFF) % tabela_tam;
}

int sondagem_quadratica(int pos, int i, int tabela_tam)
{
    pos = pos + (2 * i) + (5 * i * i);
    return (pos & 0x7FFFFFFF) % tabela_tam;
}

int duplo_hash(int hash_1, int chave, int i, int tabela_tam)
{
    int hash_2 = hashing(chave, tabela_tam - 1) + 1;
    return ((hash_1 + (i * hash_2)) & 0x7FFFFFFF) % tabela_tam;
}
