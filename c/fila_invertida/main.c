#include "fila.h"

int main() {
    FilaPrio *fila = criar_fila();
    int numVoo = 100, codAeronave = 100, qtdCombustivel = 1000, i = 0;
    for(i = 0; i < 5; i++)
        fila_insere(fila, codAeronave, numVoo, qtdCombustivel);
    
    i = 0;
    while (i != fila->qtd)
    {
        printf("%d\n", fila->dados[i].numVoo);
        i++;
    }
    return 0;
}