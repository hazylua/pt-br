#include "listaencadeada.h"

LISTA *inicializar_lista ()
{
    LISTA *l = malloc (sizeof (LISTA));
    if (l != NULL)
        l = NULL;
    return l;
}
void liberar_lista (LISTA *l)
{
    LISTA *temp;
    while (l != NULL)
    {
        temp = l;
        l = l->prox;
        free (temp);
    }
}

void listar_elementos (LISTA *l)
{
    int i = 1;
    printf ("\n### Listando elementos ###\n\n");
    
    while (l != NULL)
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("> Número: %d\n", l->num);
        printf ("> Endereço atual: %p\n", l);
        printf ("> Endereço do próximo: %p\n\n", l->prox);
        l = l->prox;
        i++;
    }
    printf ("### Fim do listamento ###\n\n");
}
void verificar_lista (LISTA *l)
{
    if (l == NULL)
        printf ("Lista vazia.\n");
    else
        printf ("Lista não-vazia.\n");
}
int verificar_tamanho (LISTA *l)
{
    int tam = 0;
    while (l != NULL)
    {
        tam++;
        l = l->prox;
    }
    return tam;
}

void adicionar_inicio (LISTA **l, int num)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->num = num;
    novo->prox = *l;
    *l = novo;
}
void adicionar_fim (LISTA **l, int num)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->num = num;
    novo->prox = NULL;

    LISTA *aux = *l;

    while (true)
    {
        if (aux->prox == NULL)
        {

            aux->prox = novo;
            break;
        }
        aux = aux->prox;
    }
}
void adicionar_ppos (LISTA **l, int num, int pos)
{
    if (pos > verificar_tamanho (*l) || pos < 0)
        printf ("Posição inválida.\n");
    else
    {
        LISTA *novo = malloc (sizeof (LISTA));
        novo->num = num;

        LISTA *prox;
        LISTA *aux = *l;
        int i;
        for (i = 1; i <= pos-1; i++)
        {
            printf ("> i = %d\n", i);
            aux = aux->prox;
        }
        prox = aux->prox;
        aux->prox = novo;
        novo->prox = prox;
    }
}