#include "pilha.h"

PILHA *criar_pilha ()
{
    PILHA *p = (PILHA *) malloc (sizeof (PILHA));
    if (p != NULL)
        p->qtd = 0;
    return p;
}
void liberar_pilha (PILHA *p)
{
    free (p);
    p = NULL;
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

    if (p->qtd == MAX)
        return 1;

    else
        return 0;
}
int verificar_vazia (PILHA *p)
{
    if (p == NULL)
        return -1;

    if (p->qtd == 0)    
        return 1;

    else
        return 0;
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

    int i, cont = 1;

    printf ("Exibindo elementos:\n\n");
    for (i = 0; i < p->qtd; i++)
    {
        printf ("Elemento #%d:\n", cont);
        printf ("Nome: %s\n", p->dados[i].nome);
        printf ("Número de matrícula: %d\n\n", p->dados[i].num_matricula);
        cont++;
    }
    printf ("Pressione qualquer tecla para continuar: ");
    while (getchar () != '\n' && getchar () != EOF);
    getchar ();
    return 1;
}

int inserir_dados (PILHA *p)
{
    if (p == NULL)
        return -1;

    if (p->qtd == MAX)
        return 0;

    ALUNO al;

    printf ("Nome do aluno: ");
    scanf ("%s", al.nome);
    printf ("Nome inserido: %s\n", al.nome);

    printf ("Matrícula do aluno: ");
    scanf ("%d", &al.num_matricula);
    printf ("Matrícula inserida: %d\n", al.num_matricula);

    p->dados[p->qtd] = al;
    p->qtd++;
    return 1;
}

int remover_elemento (PILHA *p)
{
    if (p == NULL)
        return -1;

    if (p->qtd == MAX)
        return 0;

    p->qtd--;
    return 1;
}