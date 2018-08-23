#include "fila.h"

FilaPrio *criar_fila()
{
    FilaPrio *fila;
    fila = malloc(sizeof(FilaPrio));
    if(fila != NULL)
        fila->qtd = 0;
    return fila;
}

<<<<<<< HEAD
void mergeHeap(FilaPrio* fila1, FilaPrio* fila2, int index){
    if ( index < 0 ){
        return;
    } else {
        if(procura(fila1, fila2->dados[index])){
            fila_inserir(fila1, fila2->dados[index].nome, fila2->dados[index].prio);
        }
        mergeHeap(fila1, fila2, index-1);
    }

}

int procura(FilaPrio *fila1, Paciente paciente){
    int i;
    for ( i = 0; i < fila1->qtd; i++ ){
        if (!strcmp(fila1->dados[i].nome, paciente.nome)){
            return 0;            
        }

    }
    return 1;
}

=======
>>>>>>> 8b9ca447c08d7c5e211000860cf9094e41dbfff8
void liberar_fila(FilaPrio **fila)
{
    free(*fila);
    *fila = NULL;
}

int fila_tamanho(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return fila->qtd;
}

int fila_vazia(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return (fila->qtd == 0);
}

int fila_cheia(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    return (fila->qtd == MAX);
}

void fila_promover(FilaPrio *fila, int filho)
{
    int pai;
    Paciente temp;
    pai = (filho - 1) / 2;
    while ((filho > 0) && (fila->dados[pai].prio <= fila->dados[filho].prio))
    {
        printf("Pai = %d, Filho = %d, Executou.\n", pai, filho);
        temp = fila->dados[filho];
        fila->dados[filho] = fila->dados[pai];
        fila->dados[pai] = temp;

        filho = pai;
        pai = (pai - 1) / 2;
    } 
}

int fila_inserir(FilaPrio *fila, char *nome, int prio)
{
    if(fila == NULL)
        return -1;
    if(fila->qtd == MAX)
        return 0;
    
    strcpy(fila->dados[fila->qtd].nome, nome);
    fila->dados[fila->qtd].prio = prio;
    fila_promover (fila, fila->qtd);
    fila->qtd++;

    return 1;
}

void fila_rebaixar(FilaPrio *fila, int pai)
{
    Paciente temp;
    int filho = (2 * pai) + 1;
    while(filho < fila->qtd)
    {
        if(filho < fila->qtd-1)
            if(fila->dados[filho].prio < fila->dados[filho+1].prio)
                filho++;
        if(fila->dados[pai].prio >= fila->dados[filho].prio)
            break;
        
        temp = fila->dados[pai];
        fila->dados[pai] = fila->dados[filho];
        fila->dados[filho] = temp;

        pai = filho;
        filho = (2 * pai) + 1;
    }
}

int fila_remover(FilaPrio *fila)
{
    if(fila == NULL)
        return -1;
    if(fila->qtd == 0)
        return 0;

    fila->qtd--;
    fila->dados[0] = fila->dados[fila->qtd];
    fila_rebaixar(fila, 0);

    return 1;
}