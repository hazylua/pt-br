#include "lista.h"

LISTA *inicializar_lista ()
{
    LISTA *l = malloc (sizeof (LISTA));
    if (l != NULL)
        l = NULL;
    return l;
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

void esvaziar_lista (LISTA **l)
{
    LISTA *inicio = *l;
    do
    {
        printf ("321321\n");
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
            LISTA *cabeca = *l;
            aux->prox = cabeca->prox;
            *l = cabeca->prox;
            free (cabeca);
        }
    }
    while (*l != NULL);
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
        printf ("Lista já desalocada.\n");
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

void listar_elementos (LISTA *l)
{
    if (l == NULL)
        printf ("Lista vazia, não há elementos para serem listados.\n");
    else
    {
        int i = 1;
        printf ("\n### Listando elementos ###\n\n");
        
        LISTA *inicio = l;
        do
        {
            printf ("*** Elemento #%d ***\n", i);
            printf ("> Nome: %s\n", l->dados_aluno.nome);
            printf ("> Matrícula: %d\n\n", l->dados_aluno.matricula);
            // printf ("> Endereço atual:\t%p\n", l);
            // printf ("> Endereço do próximo:\t%p\n\n", l->prox);
            l = l->prox;
            i++;
        }
        while (l != inicio);
        printf ("### Fim do listamento ###\n\n");
    }
}
void listar_recursivo (LISTA *l, LISTA *inicio, int i)
{
    if (l == NULL)
        printf ("Lista vazia, não há elementos para serem listados.\n");
    else    
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

int adicionar_ppos (LISTA **l, ALUNO al, int pos) // Primeira posição = 1.
{
    if (pos > verificar_tamanho (*l) + 1 || pos < 1)
    {
        printf ("Posição inválida.\n");
        return 0;
    }

    LISTA *novo = malloc (sizeof (LISTA));
    novo->dados_aluno = al;
    if ((*l) == NULL)
    {
        (*l) = novo;
        novo->prox = novo;
        return 1;
    }
    else
    {
        LISTA *aux = *l;
        if (pos == 1)
        {
            adicionar_inicio (l, al);
        }
        int i;
        for (i = 1; i <= pos-2; i++)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

int adicionar_pordem (LISTA **l, ALUNO al)
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
        {
            if (aux->dados_aluno.matricula == al.matricula)
                return 0;
            if (aux->prox->dados_aluno.matricula < al.matricula)
                break;
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
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

void remover_fim (LISTA **l)
{
    if ((*l)->prox == (*l))
    {
        free (*l);
        (*l) = NULL;
    }
    else
    {
        LISTA *ant, *aux = *l;
        while (aux->prox != (*l))
        {
            ant = aux;
            aux = aux->prox;
        }
        ant->prox = aux->prox;
        free (aux);
    }
}

LISTA *busca_matricula (LISTA *l, int mat)
{
    LISTA *inicio = l;
    do
    {
        if (l->dados_aluno.matricula == mat)
            return l;
        else
            l = l->prox;
    }
    while (l != inicio);
    return NULL;
}