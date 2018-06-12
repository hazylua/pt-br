#include "listaencadeada.h"

LISTA **inicializar_lista ()
{
    LISTA **l = (LISTA **) malloc (sizeof (LISTA *));
    if (*l != NULL)
        *l = NULL;
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

void listar_elementos (LISTA **l)
{
    int i = 1;
    LISTA *atual = *l;
    printf ("\n### Listando elementos ###\n\n");
    
    while (atual != NULL)
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("Número de ID: %d\n", atual->dados.num_id);
        printf ("Número de matrícula: %d\n", atual->dados.matricula);
        printf ("Endereço atual: %p\n", atual);
        printf ("Endereço do próximo: %p\n\n", atual->prox);
        atual = atual->prox;
        i++;
    }
    printf ("\n### Fim do listamento ###\n\n");
}

void verificar_lista (LISTA **l)
{
    if (*l == NULL)
        printf ("Lista vazia.\n");
    else
        printf ("Lista não-vazia.\n");
}
void verificar_tamanho (LISTA **l)
{
    int tam = 0;
    LISTA *atual = *l;
    while (atual != NULL)
    {
        tam++;
        atual = atual->prox;
    }
    printf ("Tamanho da lista: %d elementos.\n", tam);
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
            if (atual->prox == NULL)
            {
                atual->prox = novo;
                break;
            }
            atual = atual->prox;
        }
    }
}
void adicionar_ppos (LISTA **l, ALUNO aluno, int pos)
{
    LISTA *novo = (LISTA *) malloc (sizeof (LISTA));
    LISTA *temp = (LISTA *) malloc (sizeof (LISTA));
    novo->dados = aluno;
    
    LISTA *atual = *l;
    int i;
    //Para no elemento 2, insere "novo" em "atual->prox", tornando-o o terceiro elemento. Para continuar a lista, "novo" deve estar ligado ao quarto elemento, que é feito por meio de "novo->prox = temp".
    for (i = 1; i <= pos-1; i++)
        atual = atual->prox;
    temp = atual->prox;
    atual->prox = novo;
    novo->prox = temp;         
}
