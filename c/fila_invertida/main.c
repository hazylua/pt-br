#include "fila.h"

int main() {
    FilaPrio *fila = criar_fila();
    int numVoo = 100, codAeronave = 100, qtdCombustivel = 1000, i = 0;
    for(i = 0; i < 5; i++)
    {
        fila_insere(fila, codAeronave, numVoo, qtdCombustivel);
        numVoo++;
        codAeronave++;
        qtdCombustivel--;
    }
    
    i = 0;
    while (i != fila->qtd)
    {
        printf ("#%d\n", i+1);
        printf("numVoo: %d; codAeronave: %d; qtdCombustivel: %d\n", fila->dados[i].numVoo, fila->dados[i].codAeronave, fila->dados[i].qtdCombustivel);
        i++;
    }
    return 0;
}