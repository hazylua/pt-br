#include "fila.h"

int main ()
{
    filaPrio *filaPousos;

    filaPousos = fila_cria ();

    fila_libera (&filaPousos);
    return 0;
}