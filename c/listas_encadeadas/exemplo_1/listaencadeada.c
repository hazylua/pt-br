#include "listaencadeada.h"

void verificar_erro (LISTA **l)
{
    printf ("Teste.\n");

    // if (l == NULL)
        // printf ("Erro.");
        // EXIT_FAILURE;
}

void inicializar_lista (LISTA **l)
{
    l = (LISTA **) malloc (sizeof (LISTA *));
}
void liberar_lista (LISTA **l)
{
    verificar_erro (l);

    if (*l != NULL)
        free (l);
}

void verificar_lista (LISTA **l)
{
    verificar_erro (l);

    if (*l == NULL)
        printf ("Lista vazia.\n");
    else
        printf ("Lista não-vazia.\n");
}

void adicionar_inicio (LISTA **l)
{
    LISTA *novo = (LISTA *) malloc (sizeof (LISTA *));
    novo->dados.num_id = 1;
    novo->dados.matricula = 10000;
    novo->prox = *l;
    *l = novo;
}

void listar_elementos (LISTA *l)
{
    while (l->prox != NULL)
    {
        printf ("%d - Núm. ID: %d", 0, l->dados.num_id);
        printf ("%d - Matricula: %d", 0, l->dados.matricula);
    }
}