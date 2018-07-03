#include "fila.h"

FILA *criar_fila ()
{
    FILA *f = (FILA *) malloc (sizeof (FILA));
    if (f != NULL)
    {
        f->inicio = NULL;
        f->fim = NULL;
        f->qtd = 0;
    }
    return f;
}
void liberar_fila (FILA *f)
{
    if (f != NULL)
    {
        ALUNO *no;
        while (f->inicio != NULL)
        {
            no = f->inicio;
            f->inicio = f->inicio->prox;
            free (no);
        }
        free (f);
    }
}

int verificar_tam (FILA *f)
{
    if (f == NULL)
        return -1;

    return f->qtd;
}
int verificar_preenchida (FILA *f)
{
    if (f == NULL)
        return -1;

    else
        return 0;
}
int verificar_vazia (FILA *f)
{
    if (f == NULL)
        return -1;

    if (f->inicio == NULL)    
        return 1;

    else
        return 0;
}

/*
Continuar a partir daqui.
*/
int mostrar_elementos (FILA *f)
{
    if (f == NULL)
    {
        printf ("> Fila não alocada.\n");
        return -1;
    }

    if (f->qtd == 0)
    {
        printf ("> Fila vazia.\n");
        return 0;
    }

    int i, cont = 1;

    printf ("Exibindo elementos:\n\n");
    for (i = f->inicio; i < f->fim; i++)
    {
        printf ("Elemento #%d:\n", cont);
        printf ("Nome: %s\n", f->dados[i].nome);
        printf ("Número de matrícula: %d\n\n", f->dados[i].num_matricula);
        cont++;
    }
    printf ("Pressione qualquer tecla para continuar: ");
    while (getchar () != '\n' && getchar () != EOF);
    getchar ();
    return 1;
}

int inserir_final (FILA *f)
{
    if (f == NULL)
        return -1;

    if (f->qtd == MAX)
        return 0;

    ALUNO al;

    printf ("Nome do aluno: ");
    scanf ("%s", al.nome);
    printf ("Nome inserido: %s\n", al.nome);

    printf ("Matrícula do aluno: ");
    scanf ("%d", &al.num_matricula);
    printf ("Matrícula inserida: %d\n", al.num_matricula);

    f->dados[f->fim] = al;
    /* f->fim = (f->fim+1) % MAX; */
    f->fim = (f->fim+1);
    f->qtd++;
    return 1;
}
int remover_inicio (FILA *f)
{
    if (f == NULL)
        return -1;

    if (f->qtd == 0)
        return 0;
        
    /* f->inicio = (f->inicio+1) % MAX; */
    f->inicio = (f->inicio+1);
    f->qtd--;
    return 1;
}