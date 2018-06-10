//Estou entendendo (será?).

#include "listaencadeada.h"

int main ()
{
    LISTA **l = NULL;

    inicializar_lista (l);
    
    free (l);
    
    return 0;
}