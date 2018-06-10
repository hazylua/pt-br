#include "listaencadeada.h"

int main ()
{
    LISTA **l;
    l = inicializar_lista (); //Não é possível (?) passar por referência.
    verificar_lista (l);

    return 0;
}