#include "listaencadeada.h"

int cont_id = 1;
int cont_mat = 10000;

ALUNO criar_aluno ();
ALUNO criar_especifico ();
void verificar (LISTA **);

int main ()
{
    LISTA **l;
    l = inicializar_lista ();

    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    //adicionar_final (l, criar_aluno ());
    //adicionar_ppos (l, criar_especifico (), 1);
    //adicionar_pordem (l, criar_especifico ());
    verificar (l);

    //remover_inicio (l);
    //remover_final (l);
    
    verificar (l);

    return 0;
}

ALUNO criar_aluno ()
{
    ALUNO aluno;
    aluno.num_id = cont_id;
    cont_id++;
    aluno.matricula = cont_mat;
    cont_mat++;
    return aluno;
}
ALUNO criar_especifico ()
{
    ALUNO aluno;
    aluno.num_id = 12;
    aluno.matricula = 12345;
    return aluno;
}
void verificar (LISTA **l)
{
    printf ("> Tamanho da lista: %d elementos.\n", verificar_tamanho (l));
    listar_elementos (l);
}