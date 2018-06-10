//Estou entendendo (será?).

#include "listaencadeada.h"

int main ()
{
    LISTA **l;

    inicializar_lista (l);
    
    free (l);
    
    return 0;
}