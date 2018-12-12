#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H


typedef struct dado{
    int matricula;
    char nome[40];
    float n1,n2,n3;
}Aluno;

typedef struct dado Aluno;
typedef struct elemento Lista;

Lista** lista_cria();
int lista_libera(Lista** li);
int lista_insereFim(Lista **li, Aluno *al);
void lista_esvazia(Lista **pLista);
int lista_buscaMat(Lista **li, int mat, Aluno *al);
int lista_buscaNome(Lista **li, char* nomeAluno, Aluno *al);
void lista_imprime(Lista **pLista);





#endif // LISTAENCADEADA_H

