#include "fila.h"

int main ()
{
    filaPrio *filaPousos;

    filaPousos = fila_cria ();

    acessa_tamanho (filaPousos);
    
    verifica_vazio (filaPousos);

    verifica_cheia (filaPousos);
    
    
    fila_libera (&filaPousos);

    return 0;
}