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
        while (no->prox != NULL)
        {
            aux = no;
            no = no->prox;
            free (aux);
        }
        free (no);
        free (l);
    }
    else
        printf ("Lista já desalocada.\n");
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
void listar_recursivo (LISTA *l, LISTA *inicio, int i)
{
    if (i == 1)
        printf ("\n### Listando elementos ###\n\n");
    if (l->prox == NULL)
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
void listar_recursivo_reverso (LISTA *l, int i, int cond)
{
    if (i == 0)
        printf ("\n### Listando elementos ###\n\n");
        i++;
    if (l->prox != NULL && cond == 0)
        listar_recursivo_reverso (l->prox, i, cond);
    else
    {
        if (l->ant == NULL)
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
            l = l->ant;
            i++;
            listar_recursivo_reverso (l->ant, i, 1);
        }
    }
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
int inserir_pordem (LISTA **l, ALUNO al)
{
    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;
    
    if ((*l) == NULL)
    {
        (*l) = novo;
        novo->prox = NULL;
    }
    else
    {
        LISTA *aux = *l;
        while (aux->prox != NULL)
        {
            if (aux->dados_aluno.matricula == al.matricula)
                return 0;
            if (aux->prox->dados_aluno.matricula < al.matricula)
                break;
            aux = aux->prox;
        }
        aux->prox = novo->prox;
        novo->prox = aux;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}