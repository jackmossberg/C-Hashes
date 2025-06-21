#ifndef HASH_H
#define HASH_H

#include <stdio.h>
#include <stdlib.h>

#define H_API extern

#define T (tcouple)
#define H (hcouple)

#define INT 0
#define BOOL 0
#define FLOAT 1
#define DOUBLE 2
#define CHAR 3
#define STRING 4

typedef int (*vcomparator) (
    void* _v1, 
    void* _v2
);

typedef int (*kcomparator) (
    int _v1, 
    int _v2
);

typedef struct int_c { 
    int _v; 
    size_t _s; 
} int_c;

typedef struct float_c { 
    float _v; 
    size_t _s; 
} float_c;

typedef struct double_c {
    double _v;
    size_t _s;
} double_c;

typedef struct char_c { 
    char _v; 
    size_t _s; 
} char_c;

typedef struct string_c { 
    char* _v; 
    size_t _s; 
} string_c;

typedef struct hash {
    void** keys;
    void** values;
    int keytype;
    int valuetype;
    size_t size;
    vcomparator comparevalue;
    kcomparator comparekey;
} hash;

typedef struct tcouple {
    int keytype;
    int valuetype;
} tcouple;

typedef struct hcouple {
    void* key; 
    void* value;
} hcouple;

H_API hash* hash_calloc(int ecount, tcouple hashtype);
H_API void hash_dealloc(hash* hash);

H_API void hash_push(hash* hash, hcouple htable);
H_API void hash_add(hash* hash, hcouple htable);
H_API void hash_insert(hash* hash, hcouple htable, int i);
H_API void* hash_getv(hash* hash, void* key);
H_API void* hash_getk(hash* hash, int i);

H_API void hash_keysort(hash* hash);
H_API void hash_valsort(hash* hash);

#endif //HASH_H
