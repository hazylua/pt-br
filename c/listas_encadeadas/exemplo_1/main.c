//Estou entendendo (será?).

#include "listaencadeada.h"

int main ()
{
    LISTA **l;

    inicializar_lista (l);
    verificar_lista (l);

    listar_elementos (l);

    liberar_lista (l);
    free (l);
    
    return 0;
}