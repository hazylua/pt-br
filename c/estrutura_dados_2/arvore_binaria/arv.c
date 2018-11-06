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
        return 1;
    }
    else
    {
        if( aluno.matricula < ((*arv)->aluno.matricula) )
            return arvore_inserir( &((*arv)->esq), aluno );
        else
            return arvore_inserir( &((*arv)->dir), aluno );
    }

    printf("Matrícula ja cadastrada!\n");
    return 0;
}

int arvore_exibirOrdem( No *arv )
{
    if( arv == NULL )
        return -1;

    arvore_exibirOrdem( arv->esq );
    printf( "MATRÍCULA = %d\n"
            "NOME = %s\n"
            "NOTAS: %0.2f, %0.2f, %0.2f\n\n", arv->aluno.matricula, arv->aluno.nome, arv->aluno.nota_1, arv->aluno.nota_2, arv->aluno.nota_3 );
    arvore_exibirOrdem( arv->dir );

    return 1;
}

int arvore_exibirPreOrdem( No *arv )
{
    if( arv == NULL )
        return -1;

    printf( "MATRÍCULA = %d\n"
            "NOME = %s\n"
            "NOTAS: %0.2f, %0.2f, %0.2f\n\n", arv->aluno.matricula, arv->aluno.nome, arv->aluno.nota_1, arv->aluno.nota_2, arv->aluno.nota_3 );
    arvore_exibirPreOrdem( arv->esq );
    arvore_exibirPreOrdem( arv->dir );

    return 1;
}

int arvore_exibirPosOrdem( No *arv )
{
    if( arv == NULL )
        return -1;

    arvore_exibirPosOrdem( arv->esq );
    arvore_exibirPosOrdem( arv->dir );
    printf( "MATRÍCULA = %d\n"
            "NOME = %s\n"
            "NOTAS: %0.2f, %0.2f, %0.2f\n\n", arv->aluno.matricula, arv->aluno.nome, arv->aluno.nota_1, arv->aluno.nota_2, arv->aluno.nota_3 );

    return 1;
}

int arvore_vazia( No *arv )
{
    if( arv == NULL )
        return 1;
    else
        return 0;
}

int arvore_contarNos( No *arv )
{
    if( arv == NULL )
        return 0;
    else
        return (1 + arvore_contarNos( arv->esq ) + arvore_contarNos( arv->dir ));
}

int arvore_contarFolhas( No *arv )
{
    if( arv == NULL )
        return 0;
    if( arv->esq == NULL && arv->dir == NULL )
        return 1;

    return arvore_contarFolhas( arv->esq ) + arvore_contarFolhas( arv->dir );
}

int arvore_contarNaoFolhas( No *arv )
{
    if( arv == NULL )
        return 0;
    if( arv->esq == NULL && arv->dir == NULL )
        return 0;

    return arvore_contarFolhas( arv->esq ) + arvore_contarFolhas( arv->dir );
}

int arvore_altura( No *arv )
{
    if( arv == NULL )
        return 0;
    else
        return (1 + maior( arvore_altura( arv->esq ), arvore_altura( arv->dir ) ));
}

int maior( int a, int b )
{
    if( a > b )
        return a;
    else
        return b;
}

int no_libera( No *no )
{
    if( no == NULL )
        return 0;
    no_libera( no->esq );
    no_libera( no->dir );
    free( no );
    no = NULL;
}

int arvore_destroi( No **arv )
{
    if( arv == NULL)
        return 1;

    no_libera( *arv );
    free( arv );
}