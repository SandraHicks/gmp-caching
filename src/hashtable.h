
/* 
 * File:   hashtable.h
 * Author: sandra
 *
 * Created on March 24, 2017, 12:49 PM
 */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifdef __cplusplus
extern "C" {
#endif
    #include <stdint.h>
    #include "defines.h"
    #include "mpz_caching.h"
    #include <gmp.h>

    /* MPZ-T */
    typedef struct cachedIntElement cachedIntElement;
    //data types
    typedef struct cachedIntElement{
        uint64_t id;
        uint64_t hash;
        cachedIntElement* next;
        cachedIntElement* prev;
    } cachedIntElement;
    
    typedef struct cachedIntList{
        cachedIntElement* head;
        cachedIntElement* tail;
    } cachedIntList;
    
    typedef struct Hashtable{
        int* counter;
        cachedIntList* lists;
        uint64_t size;
    } Hashtable;
    
    //functions
    
    void init_hashtable(Hashtable* ht, uint64_t size);
    void delete_hashtable(Hashtable* ht);
    
    void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes);
    uint64_t exists_element(Hashtable* ht, uint64_t* hashes, mpz_t element, mpz_t_cache* cache);
    void get_k_hashes(mpz_t val, uint64_t* hashes);
    
    /*UNARY*/
    
    /*BINARY*/
    typedef struct cachedIntElement_binary cachedIntElement_binary;
    typedef struct cachedIntElement_binary{
        uint64_t op1;
        uint64_t op2;
        uint64_t result;
        uint64_t extra_info;  //this is for example for the modulo result in addition to division result
        uint64_t hash;
        cachedIntElement_binary* next;
        cachedIntElement_binary* prev;
    } cachedIntElement_binary;
    
    typedef struct cachedIntList_binary{
        cachedIntElement_binary* head;
        cachedIntElement_binary* tail;
    } cachedIntList_binary;
    
    typedef struct Hashtable_binary{
        int* counter;
        cachedIntList_binary* lists;
        uint64_t size;
    } Hashtable_binary;
    
    void init_hashtable_binary(Hashtable_binary* ht, uint64_t size);
    void delete_hashtable_binary(Hashtable_binary* ht);
    
    //extra_info is optional and can be passed as NULL
    void insert_element_binary(Hashtable_binary* ht, uint64_t id_op1, uint64_t id_op2, uint64_t id_res, uint64_t* extra_info, uint64_t* hashes);
    uint64_t exists_element_binary(Hashtable_binary* ht, uint64_t* hashes, mpz_t op1, mpz_t op2, mpz_t_cache* cache, uint64_t* extra_info);
    void get_k_hashes_cpf(mpz_t val1, mpz_t val2, uint64_t* hashes);

#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

