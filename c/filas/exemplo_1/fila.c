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

int verificar_tam (FILA *f)
{
    if (f == NULL)
        return -1;
    if (f->qtd == MAX)    
    {
        printf ("Fila não cheia.\n");
        return 1;
    }
    else
    {
        printf ("Fila não cheia.\n");
        return 0;
    }
}
int verificar_vazio (FILA *f)
{
    if (f == NULL)
        return -1;
    if (f->qtd == 0)    
    {
        printf ("Fila vazia.\n");
        return 1;
    }
    else
    {
        printf ("Fila não vazia.\n");
        return 0;
    }
}

int inserir_fila (FILA *f, ALUNO al)
{
    if (f == NULL)
        return 0;
    if (f->qtd == MAX)
        return 0;
    f->dados[f->fim] = al;
    f->fim = (f->fim+1) % MAX;
    f->qtd++;
    return 1;
}
