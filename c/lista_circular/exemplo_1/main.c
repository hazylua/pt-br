#include "listacircular.h"

int matricula = 2018001;

ALUNO criar_elemento ();
void verificar (LISTA *);

int main ()
{
    LISTA *l = inicializar_lista ();

    adicionar_inicio (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());

    listar_recursivo (l, l, 1);

    remover_inicio (&l);

    //listar_elementos (l);
    listar_recursivo (l, l, 1);

    liberar_lista (&l);
    return 0;
}

ALUNO criar_elemento ()
{
    ALUNO aluno;
    aluno.nome = "Aluno";
    aluno.matricula = matricula;
    matricula++;
    return aluno;
}