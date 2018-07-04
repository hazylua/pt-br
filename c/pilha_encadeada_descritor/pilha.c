#include "pilha.h"

PILHA *criar_pilha ()
{
    PILHA *p = (PILHA *) malloc (sizeof (PILHA));
    if (p != NULL)
    {
        p->inicio = NULL;
        p->fim = NULL;
        p->qtd = 0;
    }
    return p;
}

void liberar_pilha (PILHA *p)
{
    if (p != NULL)
    {
        ELEMENTO *no;
        while (p->inicio != NULL)
        {
            no = p->inicio;
            p->inicio = p->inicio->prox;
            free (no);
        }
        free (p);
    }
}

int verificar_tam (PILHA *p)
{
    if (p == NULL)
        return -1;

    return p->qtd;
}
int verificar_preenchida (PILHA *p)
{
    if (p == NULL)
        return -1;

    return 0;
}
int verificar_vazia (PILHA *p)
{
    if (p == NULL)
        return -1;

    if (p->qtd != 0)    
        return 0;

    return 1;
}

int mostrar_elementos (PILHA *p)
{
    if (p == NULL)
    {
        printf ("> Fila não alocada.\n");
        return -1;
    }

    if (p->qtd == 0)
    {
        printf ("> Fila vazia.\n");
        return 0;
    }

    int cont = 1;

    ELEMENTO *aux = p->inicio;
    printf ("Exibindo elementos:\n\n");
    while (aux != NULL)
    {
        printf ("Elemento #%d:\n", cont);
        printf ("Nome: %c\n", aux->letra);
        printf ("aux->prox: %p\n", aux->prox);
        aux = aux->prox;
        cont++;
    }
    
    clean_stdin ();
    return 1;
}
int mostrar_topo (PILHA *p)
{
    if (p == NULL)
        return -1;
    
    printf ("> Elemento no inicio da pilha: %c\n", p->inicio->letra);
    printf ("> Elemento no topo da pilha: %c\n", p->fim->letra);
    return 1;
}

int inserir_final (PILHA *p)
{
    if (p == NULL)
        return -1;

    ELEMENTO *no = (ELEMENTO *) malloc (sizeof (ELEMENTO));
    if (no == NULL)
        return 0;

    printf ("Letra: ");
    clean_stdin ();
    scanf ("%c", &no->letra);
    printf ("Letra inserida: %c\n", no->letra);

    no->prox = NULL;
    
    if (p->fim == NULL)
        p->inicio = no;
    else
        p->fim->prox = no;
    p->fim = no;
    p->qtd++;
    return 1;
}
int remover_final (PILHA *p)
{
    if (p == NULL)
        return -1;
    
    if (p->inicio == NULL)
        return 0;

    ELEMENTO *no = p->fim;
    free (no);

    ELEMENTO *aux = p->inicio;
    
    while (aux->prox != p->fim)
        aux = aux->prox;
    aux->prox = NULL;
    p->fim = aux;
    p->qtd--;

    return 1;
}
int esvaziar_pilha (PILHA *p)
{
    if (p == NULL)
        return -1;
    
    if (p->inicio == NULL)
        return 0;

    int i;
    for (i = 0; i <= p->qtd; i++)
        esvaziar_pilha (p);

    return 1;
}

void clean_stdin ()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}