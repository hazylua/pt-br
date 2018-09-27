#include "hash.h"

int main() {
    Hash *hashtable = hash_cria();
    inserir(hashtable, 2017001, "Yago" );
    buscar(hashtable, 201701);
    hash_libera(&hashtable);
    return 0;
}