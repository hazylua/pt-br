#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tabelashashencad.h"
#include "./ListaEncadeada/listaencadeada.h"


//definição do tipo Hash
struct hash{
    int qtd;
    int TABLE_SIZE;
    Lista **itens;
};




Hash* hash_cria(int size_tabela){
    Hash *newHash = (Hash*) malloc(sizeof(Hash)); //Descritor da tabela Hash
    if(newHash != NULL){
        int i;
        newHash->TABLE_SIZE = size_tabela;
        newHash->qtd = 0;
        newHash->itens = (Lista**) malloc(size_tabela*sizeof(Lista*)); //alocação do Vetor de listas limplemente encadeadas
        if(newHash->itens == NULL){
            free(newHash);
            return NULL;
        }

        //inicializa a tabela Inicializa todas as listas como listas vazias
        for(i=0;i<size_tabela;i++)
            newHash->itens[i]=NULL;
    }
    return newHash;
}

void hash_libera(Hash **tabHash){
    int count = 0;
    int table_size = (*tabHash)->TABLE_SIZE;

    for ( count = 0; count < table_size; count++){
        printf("Liberando lista #%d\n", count);
        if ((*tabHash)->itens[count]!=NULL)
            lista_libera(&((*tabHash)->itens[count]));
    }
    free((*tabHash)->itens);
    printf("Lista liberada!\n");
    
    free(*tabHash);
    *tabHash = NULL;

}

int hash_valorString(char* str){
    int i, valor = 7;
    int tam = strlen(str);
    for(i=0; i<tam;i++)
        valor = 31 * tam + (int)str[i];
    return valor;
}

int hash_hashing(int chave, int tableSize){
    //completar com a chamada da função conforme método adotado   //return hash_chaveMultiplicacao(chave, tableSize);
    return hash_chaveMultiplicacao(chave,tableSize);
}

int hash_chaveDivisao(int chave, int tableSize){
    return (chave & 0x7FFFFFFF)%tableSize;
}

int hash_chaveMultiplicacao(int chave, int tableSize){
    float A = 0.6180339887; //constante 0<A<1
    float val = chave * A; //chave inteira * constante
    val = val - (int)val; // descarta parte inteira (Extraindo a parte fracionária )
    return (int)(tableSize*val); // aproveita apenas a parte inteira da multiplicação
}

int hash_chaveDobra(int chave, int tableSize){
    int num_bits = 10; //determina o número de bits para dobra.
    int parte1 = chave >> num_bits; //Desloca 10 bits à direita
    int parte2 = chave & (tableSize - 1);
    return (parte1 ^ parte2);
}


int hash_insereEncadeamento(Hash* tabHash, Aluno *al, int tipoChave){
    if(tabHash == NULL)
        return 0;
    
    int index;

    if (tipoChave == 2)
        index = hash_chaveDobra(hash_valorString(al->nome), tabHash->TABLE_SIZE);
    else
        index = hash_chaveDobra(al->matricula, tabHash->TABLE_SIZE);
    
    lista_insereFim(&(tabHash->itens[index]), al);
    printf("Dados salvos na lista: %d\n", index);

}

int hash_buscaMatEncadeamento(Hash* tabHash, int mat, Aluno *al ){
     //completar
    int index = hash_chaveDobra(mat, tabHash->TABLE_SIZE);
    int check = lista_buscaMat(&(tabHash->itens[index]), mat, al);
    if(check){
        printf("\n ECONTRADO ALUNO COM A MATRICULA INFORMADA (%d) \n",mat);
        return 1;
    }
    printf("\n NÃO CONSTA NENHUM ALUNO COM A MATRÍCULA INFORMADA (%d) \n",mat);
    return 0;

}

int hash_buscaNomeEncadeamento(Hash* tabHash, char *nome, Aluno *al ){
    int index = hash_chaveDobra(hash_valorString(nome), tabHash->TABLE_SIZE);
    int check = lista_buscaNome(&(tabHash->itens[index]), nome, al);
    if(check){
        printf("\n ECONTRADO ALUNO COM O NOME INFORMADO (%s) \n",nome);
        return 1;
    }
    printf("\n NÃO CONSTA NENHUM ALUNO COM O NOME INFORMADO (%s) \n",nome);
    return 0;

}


void hash_printAluno(Aluno *al){
    if(al == NULL){
        printf("ERRO NA LEITURA DO ALUNO");
        return;
    }
    printf("\n DADOS DO ALUNO:");
    printf("\n Nome: %s",al->nome);
    printf("\n Matrícula: %d", al->matricula);
    printf("\n Nota 01: %f", al->n1);
    printf("\n Nota 02: %f", al->n2);
    printf("\n Nota 03: %f\n", al->n3);
    return;
}

void hash_printTable(Hash *tabHash){
    int i;
    for(i=0;i < tabHash->TABLE_SIZE; i++){
        if(tabHash->itens[i]!=NULL){
            printf("______________________\n");
           lista_imprime(&(tabHash->itens[i])); //imprime a lista de colisão
            printf("______________________\n");
        }else{
            printf("______________________\n");
            printf("\n");
            printf("%p\n",tabHash->itens[i]);
            printf("______________________\n");
        }
    }
}






