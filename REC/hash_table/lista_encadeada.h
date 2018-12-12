#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H

typedef struct dados
{
    char nome[40];
    int matricula;
    float nota_1, nota_2, nota_3;
} Aluno;

typedef struct dados Aluno;
typedef struct lista_elemento Lista;

Lista **lista_criar();
int lista_libera( Lista ** );
void lista_esvazia( Lista ** );

int lista_insere_fim( Lista **, Aluno * );
int lista_busca_mat( Lista **, Aluno *, int );
int lista_busca_nome( Lista **, Aluno *, char * );

void lista_imprime( Lista ** );

#endif