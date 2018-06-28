#include "pilha.h"

int menu_escolha ();

int main ()
{
    PILHA *p = NULL;
    int op;
    
    do
    {
        op = menu_escolha ();
        switch (op)
        {
            case 1:
            {
                p = criar_pilha ();
                printf ("> Fila criada.\n");
            }
            break;

            case 2:
            {
                liberar_pilha (p);
                printf ("> Fila liberada.\n");
            }
            break;
            
            case 3:
                if (verificar_tam (p) == -1)
                    printf ("> Fila não alocada.\n");
                else
                    printf ("> Tamanho da pilha: %d\n", verificar_tam (p));
            break;

            case 4:
            {
                if (verificar_preenchida (p) == 1)
                    printf ("> Fila preenchida.\n");
                else if (verificar_preenchida (p) == 0)
                    printf ("> Fila não preenchida.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 5:
            {
                if (verificar_vazia (p) == 1)
                    printf ("> Fila vazia.\n");
                else if (verificar_vazia (p) == 0)
                    printf ("> Fila não vazia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 6:
            {
                if (inserir_dados (p) == 1)
                    printf ("> Novo elemento inserido.\n");
                else if (inserir_dados (p) == 0)
                    printf ("> Fila cheia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 7:
            {
                if (remover_elemento (p) == 1)
                    printf ("> Elemento removido.\n");
                else if (remover_elemento (p) == 0)
                    printf ("> Fila vazia.\n");
                else
                    printf ("> Fila não alocada.\n");
            }
            break;

            case 8:
                mostrar_elementos (p);
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
    printf ("1. Criar pilha\n");
    printf ("2. Liberar pilha\n");
    printf ("3. Ver tamanho da pilha\n");
    printf ("4. Verificar se a pilha está preenchida\n");
    printf ("5. Verificar se a pilha está vazia\n");
    printf ("6. Inserir elemento na pilha\n");
    printf ("7. Remover elemento da pilha\n");
    printf ("8. Exibir elementos\n");

    printf ("\n> Escolha: ");
    scanf ("%d", &escolha);
    printf ("\n");

    //system ("cls");
    system ("clear");

    return escolha;
}