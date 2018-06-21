#include "fila.h"

int menu_escolha ();

int main ()
{
    printf ("*** Menu ***\n");
    FILA *f;
    int op;
    
    do
    {
        op = menu_escolha ();
        switch (0)
        {
            case 1:
            {
                f = criar_fila ();
            }
            break;

            case 2:
            {
                liberar_fila (f);
            }
            break;
        }
    }
    while (op != 0);

    return 0;
}

int menu_escolha ()
{
    int escolha;
    printf ("0. Sair do programa;\n");
    printf ("1. Criar fila;\n");
    printf ("2. Liberar fila.\n");
    printf ("Escolha: ");
    scanf ("%d", &escolha);
    return escolha;
}