#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int main() {
    hash* var = NULL;
    var = hash_calloc(5, T{INT, CHAR});
    if (var != NULL) printf("hash initialized\n");

    hash_dealloc(var);
    if (var == NULL) printf("hash deleted\n");

    printf("hello world!");
    return 0;
}