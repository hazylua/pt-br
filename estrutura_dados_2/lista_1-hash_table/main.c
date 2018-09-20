#include "hash.h"

int main() {
    Hash *hashtable = hash_cria();
    inserir( hashtable, 2017000, "Yago" );
    buscar( hashtable, 2017000 );
    
    return 0;
}