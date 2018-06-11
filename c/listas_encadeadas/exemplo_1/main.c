#include "listaencadeada.h"

int cont_id = 1;
int cont_mat = 10000;

ALUNO criar_aluno ();
ALUNO criar_especifico ();

int main ()
{
    LISTA **l; //Lista declarada como ponteiro duplo permite passar a cabeça da lista por referência.
    l = inicializar_lista (); //Não é possível (?) passar por referência.

    listar_elementos (l);
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_final (l, criar_especifico ());
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
    aluno.num_id = 111;
    aluno.matricula = 222222;
    return aluno;
}