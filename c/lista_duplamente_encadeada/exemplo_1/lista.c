#include "lista.h"

LISTA *inicializar_lista ()
{
    LISTA *l = malloc (sizeof (LISTA));
    if (l != NULL)
        l = NULL;
    return l;
}
void liberar_lista (LISTA **l)
{
    if (l != NULL && *l != NULL)
    {
        LISTA *aux, *no = *l;
        while ((*l) != no->prox)
        {
            aux = no;
            no = no->prox;
            free (aux);
        }
        free (no);
        free (l);
    }
    else
        printf ("Lista já vazia.\n");
}

int verificar_lista (LISTA *l)
{
    if (l == NULL)
    {
        printf ("Lista vazia.\n");
        return 0;
    }
    else
    {
        printf ("Lista não-vazia.\n");
        return 1;
    }
}
int verificar_tamanho (LISTA *l)
{
    int tam = 0;
    LISTA *inicio = l;
    do
    {
        tam++;
        l = l->prox;
    }
    while (l != inicio);
    return tam;
}

void listar_elementos  (LISTA *l)
{
    int i = 1;
    printf ("\n### Listando elementos:\n\n");
    while (l != NULL)
    {
        printf ("*** Elemento #%d:\n", i);
        printf ("> Nome: %s\n", l->dados_aluno.nome);
        printf ("> Matrícula: %d\n", l->dados_aluno.matricula);
        printf ("> Endereço anterior:\t%p\n", l->ant);
        printf ("> Endereço atual:\t%p\n", l);
        printf ("> Endereço próximo:\t%p\n\n", l->prox);
        l = l->prox;
        i++;
    }
    printf ("### Fim da lista.\n\n");
}
void listar_matriculas (LISTA *l)
{
    int i = 1;
    while (l != NULL)
    { 
        printf ("> Matrícula: %d\n", l->dados_aluno.matricula);
        l = l->prox;
        i++;
    }
    printf ("\n");
}

void inserir_inicio (LISTA **l, ALUNO al)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;
    novo->ant = NULL;

    if (*l == NULL)
    {
        novo->prox = *l;
        *l = novo;
    }
    else
    {
        (*l)->ant = novo;
        novo->prox = *l;
        *l = novo;
    }
}

void inserir_fim (LISTA **l, ALUNO al)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;
    novo->prox = NULL;

    if (*l == NULL)
    {
        novo->prox = *l;
        *l = novo;
    }
    else
    {
        LISTA *aux = *l;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
    }
}

void organizar (LISTA **l)
{
    int swap, i;
    do
    { 
        swap = 0;
        LISTA *aux = *l;
        LISTA *prox;
        LISTA *ant;
        if (aux->dados_aluno.matricula > aux->prox->dados_aluno.matricula)
        {
            prox = aux->prox;
            ant = aux->ant;
            aux->prox = prox->prox;
            aux->ant = prox->ant;
            prox->prox = aux;
            prox->ant = ant;
            swap = 1;
        }
        aux = aux->prox;
    }
    while (swap);
}