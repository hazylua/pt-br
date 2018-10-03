#include "hash.h"

int menu();
void clean_stdin();

int main()
{
    printf(
        "\n+++ Implementação de Tabela Hash e suas Funções +++\n"
    );

    int escolha;
    Hash *hashtable_nome;
    Hash *hashtable_matr;
    Lista *lista;

    while( true )
    {
        escolha = menu();
        switch( escolha )
        {
            default:
            {
                printf( "Tente novamente.\n" );
                clean_stdin();
            } break;

            case 0:
            {
                printf( "Até a próxima.\n" );
                return 0;
            } break;

            case 1:
            {
                hashtable_nome = hash_cria();
                hashtable_matr = hash_cria();
                printf( "Tabelas criadas.\n" );
            } break;

            case 2:
            {
                lista = lista_cria();
                printf( "Listas criadas.\n" );
            } break;

            case 3:
            {
                lista_insere( lista, 2017001, "Aluno 1" );
                inserir( hashtable_nome, hashtable_matr, 2017001, "Aluno 1" );
                printf ( "Valores inseridos em ambas tabelas e lista.\n" );
            } break;

            // case 3:
            // {
            //     buscar( hashtable_nome, 2017001 );
            // } break;

            // case 4:
            // {
            //     buscar( hashtable_matr, 2017001 );
            // } break;

            case 9:
            {
                hash_libera( &hashtable_nome );
                hash_libera( &hashtable_matr );
            } break;

            case 10:
            {
                lista_libera( &lista );
            } break;
        }    
    }

    return 0;
}

int menu()
{
    printf(
        "Menu de comandos: \n"
        "0. Sair do programa.\n"
        "1. Criar tabelas.\n"
        "2. Criar listas.\n"
        "3. Inserir valores predefinidos nas tabelas e lista.\n"
        "9. Liberar tabelas.\n"
        "10. Liberar listas.\n"
    );

    int escolha;

    printf( "Escolha: " );
    scanf( "%d", &escolha );

    system( "cls" );
    return escolha;
}

void clean_stdin ()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}