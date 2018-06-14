#include "listacircular.h"

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
}

void listar_elementos (LISTA *l)
{
    int i = 1;
    printf ("\n### Listando elementos ###\n\n");
    
    LISTA *inicio = l;
    do
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("> Nome: %s\n", l->dados_aluno.nome);
        printf ("> Matrícula: %d\n", l->dados_aluno.matricula);
        printf ("> Endereço atual: %p\n", l);
        printf ("> Endereço do próximo: %p\n\n", l->prox);
        l = l->prox;
        i++;
    }
    while (l != inicio);
    printf ("### Fim do listamento ###\n\n");
}
void listar_recursivo (LISTA *l, LISTA *inicio, int i)
{
    if (i == 1)
        printf ("\n### Listando elementos ###\n\n");
    if (l->prox == inicio)
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("> Nome: %s\n", l->dados_aluno.nome);
        printf ("> Matrícula: %d\n\n", l->dados_aluno.matricula);
        printf ("### Fim do listamento ###\n\n");
    }
    else
    {
        printf ("*** Elemento #%d ***\n", i);
        printf ("> Nome: %s\n", l->dados_aluno.nome);
        printf ("> Matrícula: %d\n\n", l->dados_aluno.matricula);
        l = l->prox;
        i++;
        listar_recursivo (l, inicio, i);
    }
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

void adicionar_inicio (LISTA **l, ALUNO al)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;

    if ((*l) == NULL)
    {
        (*l) = novo;
        novo->prox = novo;
    }
    else
    {
        LISTA *aux = *l;
        while (aux->prox != (*l))
            aux = aux->prox;
        aux->prox = novo;
        novo->prox = *l;
        *l = novo;
    }
}
void adicionar_fim (LISTA **l, ALUNO al)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;
    
    if ((*l) == NULL)
    {
        (*l) = novo;
        novo->prox = novo;
    }
    else
    {
        LISTA *aux = *l;
        while (aux->prox != (*l))
            aux = aux->prox;    
        aux->prox = novo;
        novo->prox = *l;
    }
}

void remover_inicio (LISTA **l)
{
    if ((*l)->prox == (*l))
    {
        free (*l);
        (*l) = NULL;
    }
    else
    {
        LISTA *aux = *l;
        while (aux->prox != (*l))
            aux = aux->prox;
        LISTA *inicio = *l;
        aux->prox = inicio->prox;
        *l = inicio->prox;
        free (inicio);
    }
}
