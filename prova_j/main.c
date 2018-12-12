#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "tabelashashencad.h"

int menu_op(int *n_menu);
int menu_chave();
void mudaCorScreen(int tipo);
void limpaDadosAluno(Aluno *aluno);
void printAluno(Aluno *aluno);


int main()
{    

    Hash *tabelaAlunos = NULL;
    int op, tamanho;
    Aluno novoAluno;

    int tipoChave=0;
    int matricula;
    char nome[50];
    int result=0;

    do{        
        if(tipoChave==0){//chave não definida
            tipoChave = menu_chave(); //define o tipo da chave (Numerica ou String) se não definido
            if(tabelaAlunos == NULL){
                printf("\n Escolha o tamanho da Tabela Hash: ");
                scanf("%d",&tamanho);
                tabelaAlunos = hash_cria(tamanho);

            }else
                printf("\n ATENCAO: TABELA JA ALOCADA");
        }

        //hash_print(tabelaAlunos);
        op = menu_op(&tipoChave);
        system("clear");

        switch (op) {
        case 1://ADICIONANDO NOVO ALUNO
            limpaDadosAluno(&novoAluno);
            mudaCorScreen(1);
            printf("\n INSIRA OS DADOS DO NOVO ALUNO: ");
            printf("\n MATRICULA: ");
            scanf("%d", &(novoAluno.matricula));
            printf(" NOME: ");
            scanf(" %[^\n]%*c", novoAluno.nome);
            //fgets(novoAluno.nome,30,stdin);
//            scanf("%s",novoAluno.nome) ;
            srand((unsigned)time(NULL));
            novoAluno.n1 = rand()%10+rand()%10*0.1;
            novoAluno.n2 = rand()%10+rand()%10*0.1;;
            novoAluno.n3 = rand()%10+rand()%10*0.1;
            system("clear");
            if(hash_insereEncadeamento(tabelaAlunos,&novoAluno, tipoChave)){
                mudaCorScreen(3);                
                printf("\nALUNO INSERIDO:\n");
                hash_printAluno(&novoAluno);
                printf("\n");
                mudaCorScreen(0);
            }
            else {
                mudaCorScreen(2);
                printf("\n A INSERÇÃO NAO PODE SER EXECUTADA\n"); mudaCorScreen(0);
            }             
            break;
        case 2: //BUSCA DE ELEMENTOS NA TABELA HASH
            if(tipoChave==1){
                printf("\n DIGITE O MATRICULA DO ALUNO QUE DESEJA BUSCAR: ");
                scanf("%d",&matricula);
                system("clear");
                result = hash_buscaMatEncadeamento(tabelaAlunos,matricula,&novoAluno);

            }else if(tipoChave==2){
                printf("\n DIGITE O NOME DO ALUNO QUE DESEJA BUSCAR: ");
                scanf(" %[^\n]%*c",nome);
                result = hash_buscaNomeEncadeamento(tabelaAlunos,nome,&novoAluno);
            }

            if(result){
                mudaCorScreen(1);
                hash_printAluno(&novoAluno);

            }else{
                mudaCorScreen(2);
                printf("\nPROBLEMA NA BUSCA");mudaCorScreen(0);
            }
            break;

        case 3: //IMPRIME TABELA HASH
            printf("\n TABELA HASH COMPLETA \n");
            hash_printTable(tabelaAlunos);
            break;

        case 8:
            printf("\n LIBERANDO DADOS\n");
            hash_libera(&tabelaAlunos);
            tipoChave=0;
            break;
        case 9:
            printf("\n SAINDO DO PROGRAMA\n");
            hash_libera(&tabelaAlunos);
            break;
        default:
            printf("\n ESCOLHA UMA OPCAO VALIDA\n");
            break;
        }

    }while (op!=9);


    return 0;


}

int menu_op(int *tipoChave){
    int opt;
    switch(*tipoChave){
    case 1:
        mudaCorScreen(1);
        printf("-------- CHAVE NUMERICA ------\n");mudaCorScreen(0);
        printf("DIGITE A OPÇÃO DESEJADA \n");
        printf("01 - INSERE NA TABELA HASH\n");
        printf("02 - BUSCA POR MATRICULA\n");
        printf("03 - IMPRIME TABELA\n");
        printf("08 - DESALOCA HASH TABLE\n");
        printf("09 - FINALIZA PROGRAMA DESALOCANDO\n");
        scanf("%d",&opt);

        break;

    case 2:
        mudaCorScreen(1);
        printf("\n\n\n\n -------- CHAVE STRING ------");mudaCorScreen(0);
        printf("\nDIGITE A OPÇÃO DESEJADA \n");
        printf("01 - INSERE NA TABELA HASH\n");
        printf("02 - BUSCA POR NOME\n");
        printf("03 - IMPRIME TABELA\n");
        printf("08 - DESALOCA HASH TABLE\n");
        printf("09 - FINALIZA PROGRAMA DESALOCANDO\n");
        scanf("%d",&opt);

    break;
    default:
        mudaCorScreen(2);
        printf("\nOPCAO INVALIDA. DIGITE A OPÇÃO CORRETA\n");
        mudaCorScreen(0);
        return -1; //retorna erro na passagem de parametros
        break;

    }


    return opt;
}

int menu_chave(){
    int opt=0;
    do{
        mudaCorScreen(1);
        printf("\n\n\n\n -------- ESCOLHA DO TIPO DA CHAVE ------\n");
        mudaCorScreen(0);
        printf("DIGITE A OPÇÃO DESEJADA \n");
        printf("01 - CRIA TABELA HASH -- CHAVE NUMÉRICA\n");
        printf("02 - CRIA TABELA HASH -- CHAVE STRING\n");
        printf("==> ");
        mudaCorScreen(1);
        scanf("%d",&opt);
        mudaCorScreen(0);
        if(opt!= 1 && opt != 2){
            system("@cls||clear");
            mudaCorScreen(2);
            printf("OPCAO INVALIDA.\n"
                   "SELECIONE CONFORME ABAIXO\n");
            mudaCorScreen(0);
        }
    }while(opt!= 1 && opt != 2);


    return opt;
}

void mudaCorScreen(int tipo){
            switch (tipo) {
            case 0:
                //Texto Padrão
                system (" printf '\e[0m';");
            break;
            case 1:
                //Texto Menu
                system ("printf '\e[38;5;226m'");//LETRAS AMARELAS
                system ("printf '\e[48;5;021m'"); //FUNDO AZUL
            break;
            case 2:
                //Texto ERRO
                system ("printf '\e[38;5;255m'");//LETRAS BRANCAS
                system ("printf '\e[48;5;196m'");//FUNDO VERMELHO
            break;
            case 3:
                //Texto Sucesso
                system ("printf '\e[38;5;255m'");//LETRAS BRANCAS
                system ("printf '\e[48;5;100m'"); //FUNDO VERDE
            break;
            default:
                //configuracao nao cadastrada
            break;
    }
}

void limpaDadosAluno(Aluno *aluno){
    aluno->matricula=0;
    strcpy(aluno->nome,"nulo");
    aluno->n1 = 0;
    aluno->n2 = 0;
    aluno->n3 = 0;
}

