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
void adicionar_final (LISTA **l, ALUNO aluno)
{
    LISTA *novo = (LISTA *) malloc (sizeof (LISTA));
    novo->dados = aluno;
    novo->prox = NULL;
    
    if ((*l)->prox == NULL)
        (*l)->prox = novo;

    else
    {
        LISTA *atual = *l;
        while (true)
        {
            if (atual->prox == NULL);
            {
                atual->prox = novo;
                break;
            }
            atual = atual->prox;
        }
    }
}

void listar_elementos (LISTA **l)
{
    int i = 1;

    printf ("\n### Listando elementos ###\n\n");
    while (l != NULL)
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("Número de ID: %d\n", (*l)->dados.num_id);
        printf ("Número de matrícula: %d\n", (*l)->dados.matricula);
        printf ("Endereço atual: %p\n", (*l));
        printf ("Endereço do próximo: %p\n\n", (*l)->prox);
        (*l) = (*l)->prox;
        i++;
    }
    printf ("\n### Fim do listamento ###\n\n");
}

