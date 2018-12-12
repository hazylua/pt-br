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
        return 1 + arvore_contarNos(arv->esq) + arvore_contarNos(arv->dir );
}

int arvore_contarFolhas( No *arv )
{
    if( arv == NULL )
        return 0;
    if( arv->esq == NULL && arv->dir == NULL)
        return 1;
    else
        return arvore_contarFolhas( arv->esq ) + arvore_contarFolhas( arv->dir );
}

int arvore_contarNaoFolhas( No *arv )
{
    if(arv == NULL)
        return 0;
    else if( arv->esq != NULL || arv->dir != NULL )
    {
        return 1 + arvore_contarNaoFolhas(arv->esq) + arvore_contarNaoFolhas(arv->dir);
    }
}

int arvore_altura( No *arv )
{
    if( arv == NULL )
        return -1;
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

int arvore_esvazia( No **arv )
{
    if( arv == NULL)
        return 1;

    no_libera( *arv );
    *arv = NULL;
}

int busca_mat( No *arv, int mat )
{
    if( arv == NULL )
        return -1;
    if( arv->aluno.matricula > mat )
        busca_mat( arv->esq, mat );
    else if( arv->aluno.matricula < mat )
        busca_mat( arv->dir, mat );
    else if( arv->aluno.matricula == mat ) 
        return 1;
}

No* arvore_maior_no(No **arv)
{
    if( (*arv)->dir == NULL )
        return (*arv);
    
    else arvore_maior_no(&((*arv)->dir));
}

int arvore_remove(No **arv, int mat)
{
    if( (*arv) == NULL ) // esta verificação serve para caso o número não exista na arvore.
        return 0;

    if( (*arv)->aluno.matricula == mat )
    {
        if( (*arv)->dir == NULL && (*arv)->esq == NULL )
        {
            free( *arv );
            (*arv) = NULL;
            return 1;
        }
        if( (*arv)->dir != NULL && (*arv)->esq !=NULL ){
            No *aux = arvore_maior_no( &((*arv)->esq) );
            aux->dir = (*arv)->dir;
            aux->esq = (*arv)->esq;
            (*arv) = aux;
            aux = NULL;
            return 2;
        }
        if( (*arv)->dir == NULL )
        {
            (*arv) = (*arv)->esq;
            return 3;
        }
        else
        {
            (*arv) = (*arv)->dir;
            return 3;
        }
    }

    else if( (*arv)->aluno.matricula > mat )
        return arvore_remove( &((*arv)->esq), mat );
    else
        return arvore_remove( &((*arv)->dir), mat );
}

int verificaBST( No *arv, No *ant )
{
    if( arv )
    {
        if( !verificaBST( arv->esq, ant ))
            return -1;

        if( ant != NULL && arv->aluno.matricula <= ant->aluno.matricula )
            return -1;

        ant = arv;

        return verificaBST( arv->dir, ant );
    }

    return 1;
}

// int arvore_verificaBST( No *arv )
// {
//     No *ant = NULL;
//     return verificaBST( arv, ant );
// }

void arvore_espelhada( No *arv )
{
    if( arv == NULL )
        return;

    No *temp;
    arvore_espelhada( arv->esq );
    arvore_espelhada( arv->dir );
    temp = arv->esq;
    arv->esq = arv->dir;
    arv->dir = temp;
}

int verificaSimilar( No *a, No *b )
{
    if( a == NULL && b == NULL )
        return 1;
    if( a != NULL && b != NULL )
        return verificaSimilar( a->esq, b->esq) && verificaSimilar( a->dir, b->dir );
    else
        return 0;
}

int verificaIgual( No *a, No *b )
{
    if( a == NULL && b == NULL )
        return 1;
    if( a != NULL && b != NULL )
        return a->aluno.matricula == a->aluno.matricula && verificaIgual( a->esq, b->esq) && verificaIgual( a->dir, b->dir );
    else
        return 0;
}

int verificaSBST( No *arv )
{
    if( arv == NULL )
        return 1;

    if( arv->esq == NULL && arv->dir == NULL )
        return 1;

    if( arv->esq != NULL && arv->dir != NULL )
        return verificaSBST( arv->esq ) && verificaSBST( arv->dir );

    return 0;
}