#include "hash.h"

struct hash {

	Alunos **dados;
	int qtd;
	int tam;
};

Hash* hash_cria() {

	Hash *hashtable = malloc( sizeof( Hash ) );

	if ( hashtable ) {
		
		hashtable->qtd = 0;
		hashtable->tam = table_tam;
		hashtable->dados = malloc( table_tam * sizeof( Alunos * ));
		for ( int i = 0 ; i < table_tam ; i++ )
			hashtable->dados[i] = NULL;
	}

	return hashtable;
}

void hash_libera( Hash **hashtable ) {
	int cont2 = (*hashtable)->tam;
	int cont;

	for (cont = 0; cont < cont2; cont++)
		if ((*hashtable)->dados[cont] != NULL)
			free((*hashtable)->dados[cont]);
	
	free((*hashtable)->dados);
	free(*hashtable);
	*hashtable = NULL;
}

int insere(Hash *ht){
    Alunos *al = (Alunos*) malloc(sizeof(Alunos));
	al->matricula = 130;
	printf("Insere QTD %d\n", ht->qtd);
	int index = hashCode(al->matricula, ht);
	printf("Insere INDEX %d\n", index);
	
	ht->dados[index] = al;
	if(ht->dados[index]){
		
		ht->qtd++;
		printf("Insere QTD %d\n", ht->qtd);
		return 1;
	}
	return 0;
}

int busca(int matricula, Hash *ht){
	Alunos *al;
	int index = hashCode(matricula, ht);
	printf("Busca INDEX %d\n", index);

	al = ht->dados[index];
	if ( al )
		return 1;
	return 0;
}

int hashCode(int matricula, Hash* table){
	return ((matricula & 0x7FFFFFFF) % table->tam);
}
