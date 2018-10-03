#include "hash.h"

void clean_stdin();
int menu_escolha ();

int main()
{
    int op;
    Hash *hashtable_nome;
    Hash *hashtable_matr;
    Lista *lista;

    while( 1 )
    {
        op = menu_escolha();
        switch( op ) {
            default:
            {
                printf ("> Tente novamente.\n");
                clean_stdin ();
            } break;

            case 0:
            {
                lista = lista_cria();
                hashtable_nome = hash_cria();
                hashtable_matr = hash_cria();
            } break;

            case 1:
            {
                lista_libera(&lista);
                hash_libera(&hashtable_nome);
                hash_libera(&hashtable_matr);
            } break;

            case 2:
            {
                lista_insere( lista, 2017001, "Yago" );
                inserir(hashtable_nome, hashtable_matr, 2017001, "Yago" );
            } break;

            case 3:
            {
                buscar(hashtable_nome, 2017001);
            } break;

            case 4:
            {
                buscar(hashtable_matr, 2017001);
            } break;
        }    
    }

    return 0;
}

int menu_escolha ()
{
    int escolha;

    printf ("\n* Menu de comandos: \n");
    printf ("0. Criar tabelas\n");
    printf ("1. Liberar tabelas\n");
    printf ("2. Inserir\n");
    printf ("3. Busca nome\n");
    printf ("4. Busca matricula\n");

    printf ("\n> Escolha: ");
    scanf ("%d", &escolha);
    printf ("\n");

    return escolha;
}

void clean_stdin ()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}