
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
    #include <gmp.h>

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
        int size;
    } Hashtable;

    //functions
    
    void create_hashtable(Hashtable* ht, int size);
    
    //hashes are not modulo size yet!!
    void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes);
    bool exists_element(Hashtable* ht, uint64_t* hashes);
    uint64_t* get_k_hashes(mpz_t val, uint64_t* hashes);
    

#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */
