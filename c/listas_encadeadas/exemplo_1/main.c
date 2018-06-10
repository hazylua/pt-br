#include "listaencadeada.h"

int main ()
{
    LISTA **l; //Lista declara como ponteiro duplo permite passar a cabeça da lista por referência.
    l = inicializar_lista (); //Não é possível (?) passar por referência.
    verificar_lista (l);

    ALUNO aluno_1;
    aluno_1.num_id = 1;
    aluno_1.matricula = 10000;

    adicionar_inicio (l, aluno_1);
    verificar_lista (l);

    listar_elementos (l);

    return 0;
}