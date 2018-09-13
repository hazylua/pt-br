#include "hashing.h"

int main() {
    Hash *hashtable = hash_cria();
    hash_insere( hashtable, 2017000, "Yago" );
    hash_busca( hashtable, 2017000 );
    
    return 0;
}