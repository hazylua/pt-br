#include "fila.h"

#define NUM_PACIENTES 7

int main() {
    FilaPrio *fila = criar_fila();
    char nome[30];

    printf("> Verificação de tamanho antes da inserção dos elementos:\n");
    printf ("Tamanho da fila: %d\n", fila_tamanho(fila));

    int i;
    for(i = 0; i < NUM_PACIENTES; i++)
    {
        sprintf(nome, "Pessoa %d", i);
        fila_inserir(fila, nome, i);
        nome[0] = '\0';
    }
    
    printf("> Verificação de tamanho após a inserção dos elementos:\n");
    printf ("Tamanho da fila: %d\n", fila_tamanho(fila));

    // for(i = 0; i < NUM_PACIENTES; i++)
    // {
    //     printf ("Paciente #%d *\n", i);
    //     printf("Nome: %s\n", fila->dados[i].nome);
    //     printf("Prioridade: %d\n", fila->dados[i].prio);
    // }
        
    printf ("Lista: [");
    for(i = 0; i < NUM_PACIENTES; i++)
    {
        printf ("%d", fila->dados[i].prio);
        if (i != NUM_PACIENTES-1)
            printf (", ");
    }
    printf ("]\n");
    
    //liberar_fila(fila);
    return 0;
}