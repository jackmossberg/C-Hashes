#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

int main() {
    hash* var = hash_calloc(5, T{INT, CHAR});
    hash_dealloc(var);
    
    printf("hello world!");
    return 0;
}