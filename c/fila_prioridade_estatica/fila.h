#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct filaPrioridade filaPrio;
filaPrio *fila_cria ();
void *fila_libera (filaPrio **fila);

#endif