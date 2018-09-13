#include "hash.h"

int main() {
    Hash *ht = hash_cria();
    insere(ht);
    busca(130, ht);
    return 0;
}
