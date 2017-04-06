
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

    //data types
    struct cachedIntElement{
        uint64_t id;
        uint64_t hash;
        cachedIntElement* next;
        cachedIntElement* prev;
    };
    
    struct cachedIntList{
        cachedIntElement* head;
        cachedIntElement* tail;
    };
    
    struct Hashtable{
        int* counter;
        cachedIntList* lists;
        int size;
    };

    //functions
    
    void create_hashtable(Hashtable* ht, int size);
    
    //hashes are not modulo size yet!!
    void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes);
    bool exists_element(Hashtable* ht, uint64_t* hashes);
    uint64_t* get_k_hashes(mpz_t val);
    

#ifdef __cplusplus
}
#endif

#endif /* HASHTABLE_H */

