#include <stdio.h>
#include <stdlib.h>
#include "listaencadeada.h"
#include <string.h>


typedef struct elemento {
    Aluno dados;
    Lista *prox;
}Lista;


Lista** lista_cria(){
    Lista** li = (Lista**)malloc(sizeof(Lista*));
    if(li!=NULL)
        *li = NULL; //coloca a lista como vazia
    return li;
}

int lista_libera(Lista** pLista){
    if(pLista==NULL)return 0;
    if(*pLista!=NULL)
        lista_esvazia(pLista);
    /*Lista Vazia - Ponteiro para a lista pode ser liberado*/

    return 1;

}

void lista_esvazia(Lista **pLista){
    if(pLista==NULL) return;
    struct elemento *atual;
    while((*pLista)!=NULL){
        atual = *pLista;
        *pLista = (*pLista)->prox;
        free(atual);
    }
}

int lista_insereFim(Lista **li, Aluno *al){
    if(li == NULL) return 0; //LISTA NÃO ALOCADA
    Lista *atual, *novo;
    novo = (struct elemento*)malloc(sizeof(struct elemento)); //ALOCANDO NOVO NODE
    if(novo == NULL) return 0; //ERRO NA ALOCAÇÃO DO NOVO NODE.
    novo->dados = *al;
    novo->prox = NULL;
    if((*li) == NULL){ //caso de lista vazia
        *li = novo;       
    }else{
        atual = *li; //Existe Pelo menos 1 elemento
        while(atual->prox !=NULL){
            atual=atual->prox;
        }
        atual->prox = novo;
    }
    return 1;
}

int lista_buscaMat(Lista **li, int mat, Aluno *al){
    if(li ==NULL)
        return -1;
    struct elemento *no = *li;
    while(no != NULL && no->dados.matricula !=mat){  //Percorre a lista até o final ou até encontrar a matricula buscada.
        no = no->prox;
    }
    if(no == NULL)
        return 0;

    *al = no->dados;
    return 1;
}

int lista_buscaNome(Lista **li, char* nomeAluno, Aluno *al){
    if(li ==NULL)
        return -1;
    struct elemento *no = *li;
    while(no != NULL && strcmp(no->dados.nome,nomeAluno)!=0){  //Percorre a lista até o final ou até encontrar a matricula buscada.
        no = no->prox;
    }
    if(no == NULL)
        return 0;

   *al = no->dados;
   return 1;
}

void lista_imprime(Lista **pLista){
    if(pLista==NULL) return;
    struct elemento *atual = *pLista;
    while(atual!=NULL){
        printf("\n DADOS DO ALUNO:");
        printf("\n Nome: %s",atual->dados.nome);
        printf("\n Matrícula: %d", atual->dados.matricula);
        printf("\n Nota 01: %f", atual->dados.n1);
        printf("\n Nota 02: %f", atual->dados.n2);
        printf("\n Nota 03: %f\n", atual->dados.n3);
        atual= atual->prox;
    }

}














