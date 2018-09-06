#include "hash.h"

int main() {
    Hash *ht = hash_cria();
    insere(ht);
    busca(13769644, ht);
    return 0;
}
