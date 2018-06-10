#include "listaencadeada.h"

LISTA **inicializar_lista ()
{
    LISTA **l = (LISTA **) malloc (sizeof (LISTA *));
    if (*l != NULL)
        *l = NULL; //Coloca lista como vazia.
    return l;
}
void liberar_lista (LISTA **l)
{
    LISTA *temp;
    while (*l != NULL)
    {
        temp = *l;
        *l = (*l)->prox;
        free (temp);
    }
}

void verificar_lista (LISTA **l)
{
    if (*l == NULL)
        printf ("Lista vazia.\n");
    else
        printf ("Lista não-vazia.\n");
}

void adicionar_inicio (LISTA **l, ALUNO aluno)
{
    LISTA *novo = (LISTA *) malloc (sizeof (LISTA));
    novo->dados = aluno;
    novo->prox = *l;
    *l = novo;
}

void listar_elementos (LISTA **l)
{
    printf ("%d\n", (*l)->dados.num_id);
}

