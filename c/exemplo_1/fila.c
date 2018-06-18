#include "fila.h"

FILA *criar_fila ()
{
    FILA *f = malloc (sizeof (f));
    if (f != NULL)
    {
        f->inicio = 0;
        f->fim = 0;
        f->qtd = 0;
    }
    return f;
}
void liberar_fila (FILA *f)
{
    free (f);
}