#include "pilha.h"

int menu_escolha ();

int main ()
{
    PILHA *p;
    int op;
    
    while (1)
    {
        op = menu_escolha ();
        switch (op)
        {
            default:
            {
                printf ("> Tente novamente.\n");
                clean_stdin ();
            } break;

            case 0:
            {
                liberar_pilha (p);
                printf ("Encerrando o programa...\n");
                return 0;
            } break;

            case 1:
            {
                p = criar_pilha ();
                printf ("> Pilha criada.\n");
            }
            break;

            case 2:
            {
                liberar_pilha (p);
                printf ("> Pilha liberada.\n");
            }
            break;
            
            case 3:
                printf ("> Tamanho da pilha: %d\n", verificar_tam (p));
            break;

            case 4:
            {
                if (verificar_preenchida (p) == -1)
                    printf ("> Pilha não alocada.\n");
                    
                printf ("> Pilha não preenchida.\n");
            }
            break;

            case 5:
            {
                if (verificar_vazia (p) == 1)
                    printf ("> Pilha vazia.\n");
                else if (verificar_vazia (p) == 0)
                    printf ("> Pilha não vazia.\n");
                else
                    printf ("> Pilha não alocada.\n");
            }
            break;

            case 6:
            {
                if (inserir_final (p) == 1)
                    printf ("> Novo elemento inserido.\n");
                else if (inserir_final (p) == 0)
                    printf ("> Pilha cheia.\n");
                else
                    printf ("> Pilha não alocada.\n");
            }
            break;

            case 7:
            {
                if (remover_final (p) == 1)
                    printf ("> Elemento removido.\n");
                else if (remover_final (p) == 0)
                    printf ("> Pilha vazia.\n");
                else
                    printf ("> Pilha não alocada.\n");
            }
            break;

            case 8:
                mostrar_elementos (p);
            break;

            case 9:
                mostrar_topo (p);
            break;

            case 10:
            {
                if (remover_final (p) == 1)
                    printf ("> Pilha esvaziada.\n");
                else if (remover_final (p) == 0)
                    printf ("> Pilha vazia.\n");
                else
                    printf ("> Pilha não alocada.\n");
            }
        }
    }

    return 0;
}

int menu_escolha ()
{
    int escolha;

    printf ("\n* Menu de comandos: \n");
    printf ("0. Sair do programa\n");
    printf ("1. Criar pilha\n");
    printf ("2. Liberar pilha\n");
    printf ("3. Ver tamanho da pilha\n");
    printf ("4. Verificar se a pilha está preenchida\n");
    printf ("5. Verificar se a pilha está vazia\n");
    printf ("6. Inserir elemento no fim da lista\n");
    printf ("7. Remover elemento do início da lista\n");
    printf ("8. Exibir elementos\n");
    printf ("9. Exibir elemento no topo da pilha\n");
    printf ("10. Esvaziar pilha\n");

    printf ("\n> Escolha: ");
    scanf ("%d", &escolha);
    printf ("\n");

    system ("clear");
    /*
    system ("cls");
    */
    return escolha;
}