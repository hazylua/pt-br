#include "fila.h"

// Inicialização, liberação e merge de filas:
FilaPrio *criar_fila()
{
    FilaPrio *fila;
    fila = ( FilaPrio * ) malloc( sizeof( FilaPrio ) );
    if( fila != NULL )
        fila->qtd = 0;

    return fila;
}

void liberar_fila( FilaPrio **fila )
{
    free( *fila );
    *fila = NULL;
}

// A fila 1 será a fila com os novos elementos após o merge.
void merge_heap( FilaPrio* fila_1, FilaPrio* fila_2, int index )
{
    if( index < 0 )
        return;

    else
    {
        if( fila_1->qtd == MAX)
            return;
        
        if( procura( fila_1, fila_2->dados[index] ) != 0 )
            fila_inserir( fila_1, fila_2->dados[index].nome, fila_2->dados[index].prio );
        merge_heap( fila_1, fila_2, index-1 );
    }
}

// Procura na fila. Caso encontrar alguém com o mesmo nome na fila, retorna 0, indicando que não é necessário inserí-lo na fila pois ele já existe nela. Caso contrário, retorna 1, indicando que é possível inserí-lo. 
// Procura por nome:
int procura( FilaPrio *fila, Paciente paciente )
{
    int i;
    for ( i = 0 ; i < fila->qtd ; i++ )
    {
        if( strcmp( fila->dados[i].nome, paciente.nome ) == 0 )
            return 0;
    }

    return 1;
}

// Verificação do tamanho e da quantidade de elementos da fila:
int fila_tamanho( FilaPrio *fila )
{
    if( fila == NULL )
        return -1;

    return fila->qtd;
}

int fila_vazia( FilaPrio *fila )
{
    if( fila == NULL )
        return -1;
    
    // Caso esteja vazia (qtd = 0), retorna 1, senão retorna 0.
    return ( fila->qtd == 0 );
}

int fila_cheia( FilaPrio *fila )
{
    if( fila == NULL )
        return -1;

    // Caso esteja cheia (qtd = MAX), retorna 1, senão retorna 0.
    return ( fila->qtd == MAX );
}

// Inserção e promoção de elementos:
int fila_inserir( FilaPrio *fila, char *nome, int prio )
{
    if( fila == NULL )
        return -1;

    if( fila->qtd == MAX )
        return 0;
    
    strcpy( fila->dados[fila->qtd].nome, nome );
    fila->dados[fila->qtd].prio = prio;
    fila_promover ( fila, fila->qtd );
    fila->qtd++;

    return 1;
}

void fila_promover( FilaPrio *fila, int filho )
{
    int pai;
    Paciente temp;
    pai = (filho - 1) / 2;
    while ( (filho > 0 ) && ( fila->dados[pai].prio <= fila->dados[filho].prio ) )
    {
        temp = fila->dados[filho];
        fila->dados[filho] = fila->dados[pai];
        fila->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    } 
}

// Remoção e rebaixamento de elementos:
int fila_remover( FilaPrio *fila )
{
    if( fila == NULL )
        return -1;

    if( fila->qtd == 0 )
        return 0;

    fila->qtd--;
    fila->dados[0] = fila->dados[fila->qtd];
    fila_rebaixar( fila, 0 );

    return 1;
}

void fila_rebaixar( FilaPrio *fila, int pai )
{
    Paciente temp;
    int filho = (2 * pai) + 1;
    while( filho < fila->qtd )
    {
        if( filho < fila->qtd-1 )
            if( fila->dados[filho].prio < fila->dados[filho+1].prio )
                filho++;

        if( fila->dados[pai].prio >= fila->dados[filho].prio )
            break;
        
        temp = fila->dados[pai];
        fila->dados[pai] = fila->dados[filho];
        fila->dados[filho] = temp;

        pai = filho;
        filho = (2 * pai) + 1;
    }
}
