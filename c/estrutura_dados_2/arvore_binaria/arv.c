#include "arv.h"

No **arvore_criar()
{
    No **arv;
    arv = (No **) malloc( sizeof( No * ) );
    
    return arv;
}

int arvore_inserir( No **arv, Info aluno )
{
    if( arv == NULL )
        return -1;

    if( *arv == NULL )
    {
        *arv = (No *) malloc( sizeof( No ) );
        (*arv)->dir = NULL;
        (*arv)->esq = NULL;
        (*arv)->aluno = aluno;
    }
    else
    {
        if( aluno.matricula < ((*arv)->aluno.matricula) )
            arvore_inserir( &((*arv)->esq), aluno );
        else
            arvore_inserir( &((*arv)->dir), aluno );
    } 

    return 1;
}

int arvore_exibir( No *arv )
{
    if (arv == NULL )
        return -1;

    arvore_exibir( arv->esq );
    printf( "MATRCULA = %d\n"
            "NOME = %s\n"
            "NOTAS: %0.2f, %0.2f, %0.2f\n\n", arv->aluno.matricula, arv->aluno.nome, arv->aluno.nota_1, arv->aluno.nota_2, arv->aluno.nota_3 );
    arvore_exibir( arv->dir );

    return 1;
}

