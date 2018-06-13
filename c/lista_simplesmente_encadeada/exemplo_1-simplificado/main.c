#include "listaencadeada.h"

int num = 100;

int criar_elemento ();
void verificar (LISTA *);

int main ()
{
    LISTA *l = inicializar_lista ();

    adicionar_inicio (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());
    adicionar_fim (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());
    
    verificar (l);
    
    adicionar_ppos (&l, criar_elemento (), 3);

    verificar (l);

    liberar_lista (l);
    return 0;
}

int criar_elemento ()
{
    num++;
    return num;
}
void verificar (LISTA *l)
{
    printf ("> Tamanho da lista: %d elementos.\n", verificar_tamanho (l));
    listar_elementos (l);
}