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
        ELEMENTO *no;
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

    return 0;
}
int verificar_vazia (FILA *f)
{
    if (f == NULL)
        return -1;

    if (f->qtd != 0)    
        return 0;

    return 1;
}
int mostrar_elementos (FILA *f)
{
    if (f == NULL)
    {
        printf ("> Fila não alocada.\n");
        return -1;
    }

    if (f->inicio == NULL)
    {
        printf ("> Fila vazia.\n");
        return 0;
    }

    int cont = 1;

    ELEMENTO *aux = f->inicio;
    printf ("Exibindo elementos:\n\n");
    do
    {
        printf ("Elemento #%d:\n", cont);
        printf ("Nome: %s\n", aux->dados.nome);
        printf ("Número de matrícula: %d\n", aux->dados.num_matricula);
        aux = aux->prox;
        cont++;
    }
    while (aux != NULL);
    
    printf ("Pressione qualquer tecla para continuar: ");
    while (getchar () != '\n' && getchar () != EOF);
    getchar ();
    return 1;
}

int inserir_final (FILA *f)
{
    if (f == NULL)
        return -1;

    ELEMENTO *no = (ELEMENTO *) malloc (sizeof (ELEMENTO));
    if (no == NULL)
        return 0;

    printf ("Nome do aluno: ");
    scanf ("%s", no->dados.nome);
    printf ("Nome inserido: %s\n", no->dados.nome);

    printf ("Matrícula do aluno: ");
    scanf ("%d", &(no->dados.num_matricula));
    printf ("Matrícula inserida: %d\n", no->dados.num_matricula);

    no->prox = NULL;
    
    if (f->fim == NULL)
        f->inicio = no;
    else
        f->fim->prox = no;
    f->fim = no;
    f->qtd++;
    return 1;
}
int remover_inicio (FILA *f)
{
    if (f == NULL)
        return -1;

    if (f->inicio == NULL)
        return 0;
        
    ELEMENTO *no = f->inicio;
    f->inicio = f->inicio->prox;
    free (no);
    if (f->inicio == NULL)
        f->fim = NULL;
    f->qtd--;
    return 1;
}