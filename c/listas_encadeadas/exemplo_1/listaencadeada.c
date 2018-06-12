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
int verificar_tamanho (LISTA **l)
{
    int tam = 0;
    LISTA *atual = *l;
    while (atual != NULL)
    {
        tam++;
        atual = atual->prox;
    }
    return tam;
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
//Não substitui a utilidade das funções adicionar_inicio() e adicionar_final().
void adicionar_ppos (LISTA **l, ALUNO aluno, int pos)
{
    if (pos > verificar_tamanho (l) || pos < 0)
        printf ("Erro: posição inválida.\n");
    else if (pos == 1)
        adicionar_inicio (l, aluno);
    else
    {
        LISTA *novo = (LISTA *) malloc (sizeof (LISTA));
        novo->dados = aluno;
        
        LISTA *temp = (LISTA *) malloc (sizeof (LISTA));
        LISTA *atual = *l;
        int i;
        for (i = 1; i <= pos-2; i++)
            atual = atual->prox;
        temp = atual->prox;
        atual->prox = novo;
        novo->prox = temp;
    }
}
//Adiciona um novo elemento de acordo com o número de ID.
void adicionar_pordem (LISTA **l, ALUNO aluno)
{
    LISTA *novo = (LISTA *) malloc (sizeof (LISTA));
    novo->dados = aluno;
    LISTA *temp = (*l)->prox;
    LISTA *ant = (*l);
    while (temp != NULL && temp->dados.num_id > novo->dados.num_id)
    {
        ant = temp;
        temp = temp->prox;
    }
    novo->prox = temp;
    ant->prox = novo;
}

void remover_inicio (LISTA **l)
{
    LISTA *temp = *l;
    temp = temp->prox;
    free (l);
    *l = temp;
}

void remover_final (LISTA **l)
{
    LISTA *temp = *l;
    LISTA *prox = (*l)->prox;
    while (prox->prox != NULL)
    {
        printf ("tnum_id: %d\n", temp->dados.num_id);
        temp = temp->prox;
        prox = prox->prox;
    }
    free (temp->prox);
    temp->prox = NULL;
}