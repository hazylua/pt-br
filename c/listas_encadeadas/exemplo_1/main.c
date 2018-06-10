#include "listaencadeada.h"

int cont_id = 1;
int cont_mat = 10000;

ALUNO criar_aluno ();

int main ()
{
    LISTA **l; //Lista declarada como ponteiro duplo permite passar a cabeça da lista por referência.
    l = inicializar_lista (); //Não é possível (?) passar por referência.
    verificar_lista (l);

    ALUNO aluno_1;
    aluno_1.num_id = 1;
    aluno_1.matricula = 10000;

    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    adicionar_inicio (l, criar_aluno ());
    verificar_lista (l);

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