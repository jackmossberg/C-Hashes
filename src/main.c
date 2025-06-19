#include <stdio.h>
#include <stdlib.h>

#include "hash.h"

// initalization...
// hash var;
// var = hash_calloc(int element_count, {int keytype, int valuetype}); // hash
// var = hash_malloc(int element_count, {int keytype, int valuetype}); // hash

// adding elements / finding elements..
// hash_push(hash* var, {void* key, void* data}); // void
// hash_insert(hash* var, {void* key, void* data}); // void
// int element = (int)hash_get(void* key); // void*

// deallocation...
// hash_dealloc(hash* var); // void

int main() {
    printf("hello world!");
    return 0;
}