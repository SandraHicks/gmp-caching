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
    
    //check for positive value
    int isNeg = 0;
    if(val->_mp_size < 0){
        isNeg = 1;
        mpz_neg(val, val);
    }
    
    uint64_t check_id = cache_exists_mpz(lu, val);
    if(check_id){
        if(isNeg)
            return check_id | cachedInt_SIGN | cachedInt_IsID;
        else
            return check_id | cachedInt_IsID;
    }
    
    int64_t id = insert_mpz(cache->cache, val);
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    if(id >= 0)
        insert_element(cache->ht, (uint64_t)id, hashes);
    
    free(hashes);
    hashes = NULL;
    
    if(isNeg)
        return (uint64_t)id | cachedInt_SIGN | cachedInt_IsID;
    else
        return (uint64_t)id | cachedInt_IsID;
}

uint64_t cache_exists_mpz(lookup* lu, mpz_t val){
    lookup_table* cache = lu->lkup;
    
    int isNeg = 0;
    if(val->_mp_size < 0){
        isNeg = 1;
        mpz_neg(val, val);
    }
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val, hashes);
    
    uint64_t id = exists_element(cache->ht, hashes, val, cache->cache);
    
    free(hashes);
    hashes = NULL;
            
    if(isNeg)
        return id | cachedInt_SIGN | cachedInt_IsID;
    else
        return id | cachedInt_IsID;
}

uint64_t cache_exists_mpz_binary(lookup* cache, mpz_t op1, mpz_t op2, int op){
    //check if op1, op2 positive
    mpz_t t_op1;
    mpz_t t_op2;
    mpz_init(t_op1);
    mpz_init(t_op2);
    mpz_set(t_op1, op1);
    mpz_set(t_op2, op2);
    if(op1->_mp_size < 0)
        mpz_neg(t_op1, t_op1);
    if(op2->_mp_size < 0)
        mpz_neg(t_op2, t_op2);
    
    lookup_table_binary* lkuptable;
    switch(op){
        case SUB:
            lkuptable = cache->sub;
            //go to case ADD
        case ADD:
            lkuptable = cache->add;
            break;
        case MUL:
            lkuptable = cache->mul;
            break;
        case DIV:
            lkuptable = cache->div;
            break;
        case MOD:
            lkuptable = cache->mod;
            break;
        case GCD:
            lkuptable = cache->gcd;
            break;
        case INV:
            lkuptable = cache->inv;
            break;
        default:
            lkuptable = cache->add;
            break;
    }
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1, op2, hashes);
    
    uint64_t id = exists_element_binary(lkuptable->ht, hashes, t_op1, t_op2, lkuptable->cache);
    
    mpz_clear(t_op1);
    mpz_clear(t_op2);
    free(hashes);
    hashes = NULL;
    
    return id | cachedInt_IsID;
}

void mpz_swap(mpz_t op1, mpz_t op2){
    //simple triangle exchange
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
    
    lookup_table_binary* lkuptable;
    mpz_t result;
    mpz_init(result);
    
    //Case 1: a>=0, b>=0
    if(op1->_mp_size >= 0 && op2->_mp_size >= 0){
        //check if +a,+b is cached in addition table
        uint64_t id = cache_exists_mpz_binary(cache, op1, op2, ADD);
        if(id){
            id |= cachedInt_IsID;
            return id;
        }
        
        lkuptable = cache->add;
        mpz_add(result, op1, op2);
    }
    //Case 2: a<0, b<0
    if(op1->_mp_size < 0 && op2->_mp_size < 0){
        //check if +a,+b is cached in addition table
        uint64_t id = cache_exists_mpz_binary(cache, op1, op2, ADD);
        if(id)
            return id | cachedInt_SIGN | cachedInt_IsID;

        lkuptable = cache->add;
        mpz_add(result, op1, op2);
    }
    //Case 3: a>=0, b<0
    if(op1->_mp_size >= 0 && op2->_mp_size < 0){
        //check if +a,+b cached in subtraction table
        uint64_t id = cache_exists_mpz_binary(cache, op1, op2, SUB);
        if(id)
            return id | cachedInt_IsID;

        lkuptable = cache->sub;
        mpz_add(result, op1, op2);
    }
    
    int resNeg = 0;
    if(result->_mp_size < 0){
        resNeg = 1;
        mpz_neg(result, result);
    }
    
    //hash tuple
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1, op2, hashes);
    
    //insert
    
    //add to cache addition
    uint64_t id_op1 = cache_insert_mpz(cache, op1);
    uint64_t id_op2 = cache_insert_mpz(cache, op2);
    uint64_t id_res = cache_insert_mpz(cache, result);
    insert_element_binary(lkuptable->ht, id_op1, id_op2, id_res, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    if(resNeg)
        return id_res | cachedInt_IsID;
    else
        return id_res | cachedInt_IsID;
}

uint64_t cached_mpz_sub(lookup* cache, mpz_t op1, mpz_t op2){
    //every subtraction is an addition
    mpz_neg(op2, op2);
    return cached_mpz_add(cache, op1, op2);
}