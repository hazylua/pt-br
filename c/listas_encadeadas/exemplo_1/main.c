#include "listaencadeada.h"

int cont_id = 1;
int cont_mat = 10000;

ALUNO criar_aluno ();
ALUNO criar_especifico ();

int main ()
{
    LISTA **l;
    l = inicializar_lista ();

    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_final (l, criar_aluno ());
    adicionar_ppos (l, criar_especifico (), 3);
    
    verificar_tamanho (l);
    listar_elementos (l);

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
    aluno.num_id = 123;
    aluno.matricula = 12345;
    return aluno;
}