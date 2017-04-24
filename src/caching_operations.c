#include "caching_operations.h"
#include "mpz_caching.h"
#include "hashtable.h"
#include "hashing.h"
#include <stdlib.h>


/*local definitions*/
;


void initCache(lookup_table* cache_simple, lookup_table_binary* cache_binary, uint64_t cachesize){
    
    //simple cache for mpz_t
    mpz_t_cache* newcache = malloc(sizeof(mpz_t_cache));
    
    init_mpz_cache(newcache, cachesize);
    cache_simple->cache = newcache;
    
    Hashtable* newtable = malloc(sizeof(Hashtable));
    create_hashtable(newtable, (uint64_t)cachesize*hashtable_RATIO);
    cache_simple->ht = newtable;
    
    //cache for mpz_t binary operations
    mpz_t_cache* newcache_bin = malloc(sizeof(mpz_t_cache));
    
    init_mpz_cache(newcache_bin, cachesize);
    cache_binary->cache = newcache_bin;
    
    Hashtable_binary* newtable_bin = malloc(sizeof(Hashtable_binary));
    create_hashtable_binary(newtable_bin, (uint64_t)cachesize*hashtable_RATIO);
    cache_binary->ht = newtable_bin;
}

void get_mpz(lookup_table* cache, uint64_t id, mpz_t val){
    get_cached_mpz(cache->cache, id, val);
}

double get_double(lookup_table* cache, uint64_t id){
    return get_cached_double(cache->cache, id);
}

//try insert, if not working return -1
uint64_t cache_insert_mpz(lookup_table* cache, mpz_t val){
    //check first if exists or not?
    
    int64_t id = insert_mpz(cache->cache, val);
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    if(id >= 0)
        insert_element(cache->ht, (uint64_t)id, hashes);
    
    return id;
}

bool cache_exists_mpz(lookup_table* cache, mpz_t val){
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    return exists_element(cache->ht, hashes, val, cache->cache);
}

bool cache_exists_mpz_binary(lookup_table* cache, mpz_t op1, mpz_t op2){
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1, op2, hashes);
    
    //return exists_element(cache->ht, hashes, val, cache->cache);
    return 0;
}


void add_cached_mpz(lookup_table* cache, mpz_t op1, mpz_t op2, uint64_t result){
    cache_exists_mpz_binary(cache, op1, op2);
}

void substract_cached_mpz(lookup_table* cache, mpz_t op1, mpz_t op2, uint64_t result){
    
}