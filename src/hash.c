#include "hash.h"

#define _FL "hash.h"
#define API static

API int ikeycomparator(int _v1, int _v2);
API int ivalcomparator(void* _v1, void* _v2);
API int bkeycomparator(int _v1, int _v2);
API int bvalcomparator(void* _v1, void* _v2);
API int fkeycomparator(int _v1, int _v2);
API int fvalcomparator(void* _v1, void* _v2);
API int chkeycomparator(int _v1, int _v2);
API int chvalcomparator(void* _v1, void* _v2);
API int strkeycomparator(int _v1, int _v2);
API int strvalcomparator(void* _v1, void* _v2);

#define __POINTER_VALIDATE(ptr, rcode, vname) if (!ptr) {\
    printf("[%s] - Failure to allocate memory for '%s' on heap", _FL, vname);\
    return rcode;\
}

#define __ARG_VALIDATE(arg, rcode, argname) if (!arg) {\
    printf("[%s] - Invalid '%s' argument", _FL, argname); \
    return rcode;\
}

hash* hash_calloc(int ecount, tcouple hashtype) { 
    if (ecount==0) { 
        printf("[%s] - Invalid 'ecount' arg in hash_calloc(int ecount, tcouple hashtype)", _FL);
        return NULL;
    }

    hash* h = (hash*)calloc(1, sizeof(hash));
    __POINTER_VALIDATE(h, NULL, "h")
    h->keytype = hashtype.keytype;
    h->valuetype = hashtype.valuetype;
    h->size = ecount;
    
    void** key_arr;
    void** value_arr;
    
#define __FILL_HASH_ARR_C(type, kcomparator, vcomparator, arr)\
    h->comparevalue = vcomparator;\
    h->comparekey = kcomparator;\
    arr = (void*)calloc(h->size, sizeof(type*));\
    __POINTER_VALIDATE(arr, NULL, "key_arr");\
    for (int i = 0; i <  h->size; i++) {\
        arr[i] = (type*)calloc(1, sizeof(type));\
        __POINTER_VALIDATE(arr[i], NULL, "hash arr element i");\
    }

#define __POPULATE_HASH_ARR_C(condition, arr)\
    switch (h->keytype) {\
    case BOOL || INT:\
        __FILL_HASH_ARR_C(int_c, ikeycomparator, ivalcomparator, arr) break;\
    case FLOAT:\
        __FILL_HASH_ARR_C(float_c, fkeycomparator, fvalcomparator, arr) break;\
    case CHAR:\
        __FILL_HASH_ARR_C(char_c, chkeycomparator, chvalcomparator, arr) break;\
    case STRING:\
        __FILL_HASH_ARR_C(string_c, strkeycomparator, strvalcomparator, arr) break;\
    default:\
        printf("[%s] - Invalid 'tcouple' arg in hash_calloc(int ecount, tcouple hashtype)", _FL);\
        return NULL;\
    }

    __POPULATE_HASH_ARR_C(h->keytype, key_arr)
    h->keys = key_arr;
    __POPULATE_HASH_ARR_C(h->valuetype, value_arr)
    h->values = value_arr;
    return h;
}

hash* hash_malloc(int ecount, tcouple hashtype) { 
    if (ecount==0) { 
        printf("[%s] - Invalid 'ecount' arg in hash_calloc(int ecount, tcouple hashtype)", _FL);
        return NULL;
    }

    hash* h = (hash*)calloc(1, sizeof(hash));
    __POINTER_VALIDATE(h, NULL, "h")
    h->keytype = hashtype.keytype;
    h->valuetype = hashtype.valuetype;
    h->size = ecount;
    
    void** key_arr;
    void** value_arr;
    
#define __FILL_HASH_ARR_M(type, kcomparator, vcomparator, arr)\
    h->comparevalue = vcomparator;\
    h->comparekey = kcomparator;\
    arr = (void*)calloc(h->size, sizeof(type*));\
    __POINTER_VALIDATE(arr, NULL, "key_arr");\
    for (int i = 0; i <  h->size; i++) {\
        arr[i] = (type*)malloc(1 * sizeof(type));\
        __POINTER_VALIDATE(arr[i], NULL, "hash arr element i");\
    }

#define __POPULATE_HASH_ARR_M(condition, arr)\
    switch (h->keytype) {\
    case BOOL || INT:\
        __FILL_HASH_ARR_M(int_c, ikeycomparator, ivalcomparator, arr) break;\
    case FLOAT:\
        __FILL_HASH_ARR_M(float_c, fkeycomparator, fvalcomparator, arr) break;\
    case CHAR:\
        __FILL_HASH_ARR_M(char_c, chkeycomparator, chvalcomparator, arr) break;\
    case STRING:\
        __FILL_HASH_ARR_M(string_c, strkeycomparator, strvalcomparator, arr) break;\
    default:\
        printf("[%s] - Invalid 'tcouple' arg in hash_calloc(int ecount, tcouple hashtype)", _FL);\
        return NULL;\
    }

    __POPULATE_HASH_ARR_M(h->keytype, key_arr)
    h->keys = key_arr;
    __POPULATE_HASH_ARR_M(h->valuetype, value_arr)
    h->values = value_arr;
    return h;
}

void hash_dealloc(hash* hash) {
    __ARG_VALIDATE(hash, , "hash")
    __POINTER_VALIDATE(hash->keys, ,"hash->keys")
    __POINTER_VALIDATE(hash->values, ,"hash->values")
    for (int i = 0; i < hash->size; i++){
        __POINTER_VALIDATE(hash->keys[i], ,"hash->keys[i]")
        free(hash->keys[i]);
        __POINTER_VALIDATE(hash->values[i], ,"hash->values[i]");
        free(hash->values[i]);
    }
    free(hash->keys);
    free(hash->values);
}

void hash_push(hash* hash, hcouple htable) {

}

void hash_add(hash* hash, hcouple htable) {

}

void hash_insert(hash* hash, hcouple htable, int i) {

}

void* hash_getv(hash* hash, void* key) {
    __ARG_VALIDATE(hash, NULL, "thash")
    __ARG_VALIDATE(hash, NULL, "key")
    void* v = NULL;
    
    return v;
}

void* hash_getk(hash* hash, int i) {
    __ARG_VALIDATE(hash, NULL, "hash")
    void* k = NULL;
    
    return k;
}

API int ikeycomparator(int _v1, int _v2) {}
API int ivalcomparator(void* _v1, void* _v2) {}
API int bkeycomparator(int _v1, int _v2) {}
API int bvalcomparator(void* _v1, void* _v2) {}
API int fkeycomparator(int _v1, int _v2) {}
API int fvalcomparator(void* _v1, void* _v2) {}
API int chkeycomparator(int _v1, int _v2) {}
API int chvalcomparator(void* _v1, void* _v2) {}
API int strkeycomparator(int _v1, int _v2) {}
API int strvalcomparator(void* _v1, void* _v2) {}