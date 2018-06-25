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
    return f->qtd;
}
int verificar_preenchida (FILA *f)
{
    if (f == NULL)
        return -1;
    if (f->qtd == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int verificar_vazia (FILA *f)
{
    if (f == NULL)
        return -1;
    if (f->qtd == 0)    
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void mostrar_elementos (FILA *f)
{
    int i;
    printf ("fim: %d\n", f->fim);
    for (i = f->inicio; i < f->fim; i++)
    {
        printf ("Elemento #%d:\n", i+1);
        printf ("Nome: %s\n", f->dados[i].nome);
        printf ("Número de matrícula: %d\n\n", f->dados[i].num_matricula);
    }
    
}

int inserir_final (FILA *f, ALUNO al)
{
    if (f == NULL)
        return -1;
    if (f->qtd == MAX)
        return 0;
    f->dados[f->fim] = al;
    f->fim = (f->fim+1); //% MAX;
    f->qtd++;
    return 1;
}
int remover_inicio (FILA *f)
{
    if (f == NULL)
        return -1;
    if (f->qtd == 0)
        return 0;
    f->inicio = (f->inicio+1) % MAX;
    f->qtd--;
    return 1;
}