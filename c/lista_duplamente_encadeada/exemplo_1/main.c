#include "lista.h"

int matricula = 2018000;

ALUNO criar_elemento ();
void verificar (LISTA *);

int main ()
{
    LISTA *l = inicializar_lista ();

    inserir_inicio  (&l, criar_elemento ());
    inserir_inicio  (&l, criar_elemento ());
    inserir_inicio  (&l, criar_elemento ());
    inserir_fim     (&l, criar_elemento ());

    listar_elementos (l);
    
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