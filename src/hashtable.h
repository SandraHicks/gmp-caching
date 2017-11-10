/**
  * @file hashtable.h
  * @author Sandra Hicks
  * @brief Header for hash table implementation
  */

#ifndef HASHTABLE_H
#define HASHTABLE_H

#ifdef __cplusplus
#include <cstdint>
#include <gmp.h>
extern "C" {
#else
#include <stdint.h>
    #include <gmp.h>
#endif
    #include "defines.h"
    #include "mpz_caching.h"


    /* MPZ-T */
    typedef struct cachedIntElement cachedIntElement;
    //data types
    /**
     * @brief Element of the hash table
     */
    typedef struct cachedIntElement{
        uint64_t id;            /**< id to element in singleton cache*/
        uint64_t hash;          /**< hashed element*/
        cachedIntElement* next; /**< next element in list*/
        cachedIntElement* prev; /**< previous element in list*/
    } cachedIntElement;
    
    /**
     * @brief List of Elements in one slot of the hash table
     */
    typedef struct cachedIntList{
        cachedIntElement* head; /**< head pointer of list*/
        cachedIntElement* tail; /**< tail pointer of list for fast insert*/
    } cachedIntList;
    
    /**
     * @brief hash table
     */
    typedef struct Hashtable{
        unsigned int* counter;           /**< array of counters of elements in each list*/
        cachedIntList* lists;   /**< array of lists*/
        uint64_t size;          /**< number of lists, size of hash table*/
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
    /**
     * @brief element of hash table binary mapping
     */
    typedef struct cachedIntElement_binary{
        uint64_t op1;                   /**< id of operator 1 in singleton cache*/
        uint64_t op2;                   /**< id of operator 2 in singleton cache*/
        uint64_t result;                /**< id of result in singleton cache*/
        uint64_t extra_info;            /**< id of extra information (e.g. rest of division)*/
        uint64_t hash;                  /**< hashed element*/
        cachedIntElement_binary* next;  /**< next element in list*/
        cachedIntElement_binary* prev;  /**< previous element in list*/
    } cachedIntElement_binary;
    
    /**
     * @brief list of elements in one slot of the hash table binary mapping
     */
    typedef struct cachedIntList_binary{
        cachedIntElement_binary* head;  /**< head pointer of list*/
        cachedIntElement_binary* tail;  /**< tail pointer of list for fast insert*/
    } cachedIntList_binary;
    
    /**
     * @brief hash table binary mapping
     */
    typedef struct Hashtable_binary{
        int* counter;                   /**< array of counters of elements in each list*/
        cachedIntList_binary* lists;    /**< array of lists*/
        uint64_t size;                  /**< number of lists, size of hash table*/
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

