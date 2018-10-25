#include "arv.h"

No **arvore_criar()
{
    No **arv;
    arv = (No **) malloc( sizeof ( No *) );

    return arv;
}

int arvore_inserir( No **arv, Info aluno )
{
    if( aluno == NULL )
        return -1;

    arv->aluno = aluno;
    
    return 1;
}

