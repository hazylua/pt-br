#include "arv.h"

int main()
{
    No **arv;
    arv = arvore_criar();
    
    Info aluno;
    for( int i = 1 ; i <= 5 ; i++ )
    {
        snprintf( aluno.nome, 100, "Aluno %d", i );
        aluno.matricula = i;
        aluno.nota_1 = 6.00;
        aluno.nota_2 = 6.00;
        aluno.nota_3 = 6.00;
        arvore_inserir( arv, aluno );
    }
    arvore_exibir( *arv );


    return 0;
}