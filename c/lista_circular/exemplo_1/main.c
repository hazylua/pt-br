#include "lista.h"

int matricula = 2018001;

ALUNO criar_elemento ();

int main ()
{
    LISTA *l = inicializar_lista ();
    adicionar_inicio (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());
    adicionar_inicio (&l, criar_elemento ());
    adicionar_fim (&l, criar_elemento ());
    
    listar_elementos (l);

    liberar_lista (&l);

    return 0;
}

ALUNO criar_elemento ()
{
    ALUNO aluno;
    aluno.nome = "Aluno";
    aluno.matricula = matricula;
    aluno.n1 = 6.0;
    aluno.n2 = 6.0;
    aluno.n3 = 6.0;
    matricula++;
    return aluno;
}