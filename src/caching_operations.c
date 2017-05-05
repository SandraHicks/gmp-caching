#include "caching_operations.h"
#include "mpz_caching.h"
#include "hashtable.h"
#include "hashing.h"
#include <stdlib.h>

//Debug
#include <stdio.h>


/*local definitions*/
;


void init_cache(lookup* cache, uint64_t cachesize){
    
    lookup_table* table = malloc(sizeof(lookup_table));
    lookup_table_binary* table_binary = malloc(sizeof(lookup_table_binary));
    
    cache->lkup = table;
    cache->add = table_binary;
    
    //simple cache for mpz_t
    mpz_t_cache* newcache = malloc(sizeof(mpz_t_cache));
    
    init_mpz_cache(newcache, cachesize);
    cache->lkup->cache = newcache;
    
    Hashtable* newtable = malloc(sizeof(Hashtable));
    init_hashtable(newtable, (uint64_t)cachesize*hashtable_RATIO);
    cache->lkup->ht = newtable;
    
    //cache for mpz_t binary operations
    cache->add->cache = newcache;
    
    Hashtable_binary* newtable_bin = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin, (uint64_t)cachesize*hashtable_RATIO);
    cache->add->ht = newtable_bin;
}

void delete_cache(lookup* cache){
    //call delete for mpz_t cache
    delete_mpz_cache(cache->lkup->cache);
    free(cache->lkup->cache);
    cache->lkup->cache = NULL;
    cache->add->cache = NULL;
    
    //call delete for hashtables
    delete_hashtable(cache->lkup->ht);
    free(cache->lkup->ht);
    cache->lkup->ht = NULL;
    delete_hashtable_binary(cache->add->ht);
    free(cache->add->ht);
    cache->add->ht = NULL;
}

void get_mpz(lookup* cache, uint64_t id, mpz_t val){
    get_cached_mpz(cache->lkup->cache, id, val);
}

double get_double(lookup* cache, uint64_t id){
    return get_cached_double(cache->lkup->cache, id);
}

//try insert, if not working return -1
uint64_t cache_insert_mpz(lookup* lu, mpz_t val){
    //check first if exists or not
    lookup_table* cache = lu->lkup;
    uint64_t check_id = cache_exists_mpz(lu, val);
    if(check_id)
        return check_id;
    
    int64_t id = insert_mpz(cache->cache, val);
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    if(id >= 0)
        insert_element(cache->ht, (uint64_t)id, hashes);
    
    free(hashes);
    hashes = NULL;
    
    return (uint64_t)id;
}

uint64_t cache_exists_mpz(lookup* lu, mpz_t val){
    lookup_table* cache = lu->lkup;
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    uint64_t id = exists_element(cache->ht, hashes, val, cache->cache);
    
    free(hashes);
    hashes = NULL;
            
    return id;
}

uint64_t cache_exists_mpz_binary(lookup_table_binary* cache, mpz_t op1, mpz_t op2){

    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1, op2, hashes);
    
    uint64_t id = exists_element_binary(cache->ht, hashes, op1, op2, cache->cache);
            
    free(hashes);
    hashes = NULL;
    
    return id;
}

void mpz_swap(mpz_t op1, mpz_t op2){
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, op1);
    mpz_set(op1, op2);
    mpz_set(op2, temp);
    mpz_clear(temp);
}

uint64_t cached_mpz_add(lookup* cache, mpz_t op1, mpz_t op2){
    
    ////// cache addition result
    
    //sort operands and check signs
    if(mpz_cmp(op1, op2) < 0){
        mpz_swap(op1, op2);
    }
    
    
    //Case 1: a>=0, b>=0
    if(op1->_mp_size >= 0 && op2->_mp_size >= 0){
        //check if +a,+b is cached in addition table
        uint64_t id = cache_exists_mpz_binary(cache->add, op1, op2);
        if(id)
            return id;
        //cached: return result
        
        //not cached:
        
        //add mpz_t's
        mpz_t result;
        mpz_init(result);
        mpz_add(result, op1, op2);
        
        //add to cache addition
        
        //add to mpz_t cache
        
        
        //return id
    }
    //Case 2: a<0, b<0
    else if(op1->_mp_size < 0 && op2->_mp_size < 0){
        //check if +a,+b is cached in addition table
        uint64_t id = cache_exists_mpz_binary(cache->add, op1, op2);
        if(id){
            //negate id
            
            return id;
        }

        //cached: return -result
        
        //not cached:
        
        //add mpz_t's
        mpz_t result;
        mpz_init(result);
        mpz_add(result, op1, op2);
        
        //add to cache addition
        
        //add to mpz_t cache
        
        //return id
    }
    //Case 3: a>=0, b<0
    else if(op1->_mp_size >= 0 && op2->_mp_size < 0){
        //check if +a,+b cached in subtraction table
        uint64_t id = cache_exists_mpz_binary(cache->sub, op1, op2);
        if(id)
            return id;
        //cached: return result
        
        //not cached:
        
        //add mpz_t's
        mpz_t result;
        mpz_init(result);
        mpz_add(result, op1, op2);
        
        //add to cache subtraction
        
        //add to mpz_t cache
        
        
        //return id
    }
    //should not be reached
    else{
        
    }
    
    //return new id
    return 0;
}

uint64_t cached_mpz_sub(lookup* cache, mpz_t op1, mpz_t op2){
    mpz_neg(op2, op2);
    return cached_mpz_add(cache, op1, op2);
}