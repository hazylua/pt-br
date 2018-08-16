#include "fila.h"

#define NUM_PACIENTES 7

int main() {
    FilaPrio *fila = criar_fila();

    int i;
    for(i = 0; i < NUM_PACIENTES; i++)
        fila_inserir(fila, "Paciente", i);
    for(i = 0; i < NUM_PACIENTES; i++)
    {
        printf ("#%d\n", i);
        printf("Nome: %s\n", fila->dados[i].nome);
        printf("Prioridade: %d\n\n", fila->dados[i].prio);
    }
    return 0;
}