#include "caching_operations.h"
#include "mpz_caching.h"
#include "hashtable.h"
#include "hashing.h"
#include <stdlib.h>


/*local definitions*/
;


void init_cache(lookup_table* cache, lookup_table_binary* cache_binary, uint64_t cachesize){
    
    //simple cache for mpz_t
    mpz_t_cache* newcache = malloc(sizeof(mpz_t_cache));
    
    init_mpz_cache(newcache, cachesize);
    cache->cache = newcache;
    
    Hashtable* newtable = malloc(sizeof(Hashtable));
    init_hashtable(newtable, (uint64_t)cachesize*hashtable_RATIO);
    cache->ht = newtable;
    
    //cache for mpz_t binary operations
    cache_binary->cache = newcache;
    
    Hashtable_binary* newtable_bin = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin, (uint64_t)cachesize*hashtable_RATIO);
    cache_binary->ht = newtable_bin;
}

void delete_cache(lookup_table* cache, lookup_table_binary* cache_binary){
    //call delete for mpz_t cache
    delete_mpz_cache(cache->cache);
    free(cache->cache);
    cache->cache = NULL;
    cache_binary->cache = NULL;
    
    //call delete for hashtables
    delete_hashtable(cache->ht);
    free(cache->ht);
    cache->ht = NULL;
    delete_hashtable_binary(cache_binary->ht);
    free(cache_binary->ht);
    cache_binary->ht = NULL;
}

void get_mpz(lookup_table* cache, uint64_t id, mpz_t val){
    get_cached_mpz(cache->cache, id, val);
}

double get_double(lookup_table* cache, uint64_t id){
    return get_cached_double(cache->cache, id);
}

//try insert, if not working return -1
uint64_t cache_insert_mpz(lookup_table* cache, mpz_t val){
    //check first if exists or not
    uint64_t check_id = cache_exists_mpz(cache, val);
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

uint64_t cache_exists_mpz(lookup_table* cache, mpz_t val){
    
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

uint64_t add_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2){
    uint64_t id = cache_exists_mpz_binary(cache, op1, op2);
    if(id)
        return id;
    
    //cache addition result
    
    //add mpz_t's
    mpz_t result;
    mpz_init(result);
    mpz_add(result, op1, op2);
    
    //return new id
    return 0;
}

uint64_t substract_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2){
    uint64_t id = cache_exists_mpz_binary(cache, op1, op2);
    if(id)
        return id;
    
    return 0;
}