#include "fila.h"

int menu_escolha ();

int main ()
{
    FILA *f;
    int op;
    
    do
    {
        op = menu_escolha ();
        switch (op)
        {
            case 1:
            {
                f = criar_fila ();
                printf ("> Fila criada.\n");
            }
            break;

            case 2:
            {
                liberar_fila (f);
                printf ("> Fila liberada.\n");
            }
            break;
            
            case 3:
                printf ("> Tamanho da fila: %d\n", verificar_tam (f));
            break;

            case 4:
            {
                if (verificar_preenchida (f) == 1)
                    printf ("> Fila preenchida.\n");
                else if (verificar_preenchida (f) == 0)
                    printf ("> Fila não preenchida.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 5:
            {
                if (verificar_vazia (f) == 1)
                    printf ("> Fila vazia.\n");
                else if (verificar_vazia (f) == 0)
                    printf ("> Fila não vazia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 6:
            {
                if (inserir_final (f) == 1)
                    printf ("> Novo elemento inserido.\n");
                else if (inserir_final (f) == 0)
                    printf ("> Fila cheia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 7:
            {
                if (remover_inicio (f) == 1)
                    printf ("> Elemento removido.\n");
                else if (remover_inicio (f) == 0)
                    printf ("> Fila vazia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 8:
                mostrar_elementos (f);
            break;      
        }
    } while (op != 0);
    
    return 0;
}

int menu_escolha ()
{
    int escolha;

    printf ("\n* Menu de comandos: \n");
    printf ("0. Sair do programa\n");
    printf ("1. Criar fila\n");
    printf ("2. Liberar fila\n");
    printf ("3. Ver tamanho da fila\n");
    printf ("4. Verificar se a fila está preenchida\n");
    printf ("5. Verificar se a fila está vazia\n");
    printf ("6. Inserir elemento no fim da lista\n");
    printf ("7. Remover elemento do início da lista\n");
    printf ("8. Exibir elementos\n");

    printf ("\n> Escolha: ");
    scanf ("%d", &escolha);
    printf ("\n");

    system ("cls");
    /*
    system ("clear");
    */
    return escolha;
}