#include "caching_operations.h"
#include "mpz_caching.h"
#include "hashtable.h"
#include "hashing.h"
#include "defines.h"
#include <stdlib.h>

//Debug
#include <stdio.h>
#include <inttypes.h>


/*local definitions*/
uint64_t cache_insert_mpz_raw(lookup* lu, mpz_t val);
uint64_t cache_exists_mpz_raw(lookup* lu, mpz_t val);
uint64_t cache_exists_mpz_binary_raw(lookup* cache, mpz_t op1, mpz_t op2, uint64_t* extra_info, int op);


void init_cache(lookup* cache, uint64_t cachesize){
    
    lookup_table* table = malloc(sizeof(lookup_table));
    lookup_table_binary* table_binary_add = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_sub = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_mul = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_tdiv = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_mod = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_gcd = malloc(sizeof(lookup_table_binary));
    lookup_table_binary* table_binary_inv = malloc(sizeof(lookup_table_binary));
    
    cache->lkup = table;
    cache->add = table_binary_add;
    cache->sub = table_binary_sub;
    cache->mul = table_binary_mul;
    cache->tdiv = table_binary_tdiv;
    cache->mod = table_binary_mod;
    cache->gcd = table_binary_gcd;
    cache->inv = table_binary_inv;
    
    //simple cache for mpz_t
    mpz_t_cache* newcache = malloc(sizeof(mpz_t_cache));
    
    init_mpz_cache(newcache, cachesize);
    cache->lkup->cache = newcache;
    
    Hashtable* newtable = malloc(sizeof(Hashtable));
    init_hashtable(newtable, (uint64_t)cachesize*hashtable_RATIO);
    cache->lkup->ht = newtable;
    
    //cache for mpz_t binary operations
    
    //cache for addition
    cache->add->cache = newcache;
    
    Hashtable_binary* newtable_bin_add = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_add, (uint64_t)cachesize*hashtable_RATIO);
    cache->add->ht = newtable_bin_add;
    
    //cache for subtraction
    cache->sub->cache = newcache;

    Hashtable_binary* newtable_bin_sub = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_sub, (uint64_t)cachesize*hashtable_RATIO);
    cache->sub->ht = newtable_bin_sub;
    
    //cache for multiplication
    cache->mul->cache = newcache;

    Hashtable_binary* newtable_bin_mul = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_mul, (uint64_t)cachesize*hashtable_RATIO);
    cache->mul->ht = newtable_bin_mul;
    
    //cache for division
    cache->tdiv->cache = newcache;

    Hashtable_binary* newtable_bin_tdiv = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_tdiv, (uint64_t)cachesize*hashtable_RATIO);
    cache->tdiv->ht = newtable_bin_tdiv;
    
    //cache for mod
    cache->mod->cache = newcache;

    Hashtable_binary* newtable_bin_mod = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_mod, (uint64_t)cachesize*hashtable_RATIO);
    cache->mod->ht = newtable_bin_mod;
    
    //cache for gcd
    cache->gcd->cache = newcache;

    Hashtable_binary* newtable_bin_gcd = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_gcd, (uint64_t)cachesize*hashtable_RATIO);
    cache->gcd->ht = newtable_bin_gcd;
    
    //cache for invers
    cache->inv->cache = newcache;

    Hashtable_binary* newtable_bin_inv = malloc(sizeof(Hashtable_binary));
    init_hashtable_binary(newtable_bin_inv, (uint64_t)cachesize*hashtable_RATIO);
    cache->inv->ht = newtable_bin_inv;
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
    id = id & ~SHIFT;
    if(id & NEG){
        id = id & ~NEG;
        get_cached_mpz(cache->lkup->cache, id, val);
        mpz_neg(val, val);
    }
    else
        get_cached_mpz(cache->lkup->cache, id, val);
}

double get_double(lookup* cache, uint64_t id){
    id = id & ~SHIFT;
    if(id & NEG){
        id = id & ~NEG;
        return (-1)*get_cached_double(cache->lkup->cache, id);
    }
    else
        return get_cached_double(cache->lkup->cache, id);
}

//try insert, if not working return -1
uint64_t cache_insert_mpz_raw(lookup* lu, mpz_t val){
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, val);
    //check first if exists or not
    lookup_table* cache = lu->lkup;
    
    if(val->_mp_size < 0){
        mpz_neg(temp, temp);
    }
    
    uint64_t check_id = cache_exists_mpz_raw(lu, temp);
    if(check_id){
        mpz_clear(temp);
        return check_id;
    }
    
    int64_t id = insert_mpz(cache->cache, temp);
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(temp, hashes);
    
    if(id >= 0)
        insert_element(cache->ht, (uint64_t)id, hashes);
    
    free(hashes);
    hashes = NULL;
    mpz_clear(temp);
    
    return (uint64_t)id;
}

uint64_t cache_insert_mpz(lookup* lu, mpz_t val){
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, val);
    //check for positive value
    int isNeg = 0;
    if(val->_mp_size < 0){
        isNeg = 1;
        mpz_neg(temp, temp);
    }
    uint64_t id = cache_insert_mpz_raw(lu, temp);
    mpz_clear(temp);
    
    if(id == 0)
        return 0;
    
    if(isNeg)
        return id | NEG | SHIFT;
    else
        return id | SHIFT;
}

uint64_t cache_exists_mpz_raw(lookup* lu, mpz_t val){
    
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, val);
    
    lookup_table* cache = lu->lkup;
    
    if(temp->_mp_size < 0){
        mpz_neg(temp, temp);
    }
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(temp, hashes);
    
    uint64_t id = exists_element(cache->ht, hashes, temp, cache->cache);
    
    free(hashes);
    hashes = NULL;
    mpz_clear(temp);
    //not found: return 0 instantly
    if(id == 0){
        return 0;
    }
    
    return id;
}

uint64_t cache_exists_mpz(lookup* lu, mpz_t val){
    mpz_t temp;
    mpz_init(temp);
    mpz_set(temp, val);
    
    int isNeg = 0;
    if(temp->_mp_size < 0){
        isNeg = 1;
        mpz_neg(temp, temp);
    }
    
    uint64_t id = cache_exists_mpz_raw(lu, val);
    
    mpz_clear(temp);
    
    if(id == 0)
        return 0;
    
    if(isNeg)
        return id | NEG | SHIFT;
    else
        return id | SHIFT;
}


uint64_t cache_exists_mpz_binary_raw(lookup* cache, mpz_t op1, mpz_t op2, uint64_t* extra_info, int op){
    //check if op1, op2 positive
    mpz_t t_op1;
    mpz_t t_op2;
    mpz_init(t_op1);
    mpz_init(t_op2);
    mpz_set(t_op1, op1);
    mpz_set(t_op2, op2);
    if(op1->_mp_size < 0)
        t_op1->_mp_size = t_op1->_mp_size * (-1);
    if(op2->_mp_size < 0)
        t_op2->_mp_size = t_op2->_mp_size * (-1);
    
    lookup_table_binary* lkuptable;
    switch(op){
        case SUB:
            lkuptable = cache->sub;
            break;
        case ADD:
            lkuptable = cache->add;
            break;
        case MUL:
            lkuptable = cache->mul;
            break;
        case TDIV:
            lkuptable = cache->tdiv;
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
    get_k_hashes_cpf(t_op1, t_op2, hashes);
    uint64_t id = exists_element_binary(lkuptable->ht, hashes, t_op1, t_op2, lkuptable->cache, extra_info);
    mpz_clear(t_op1);
    mpz_clear(t_op2);
    free(hashes);
    hashes = NULL;
    
    //not found: return 0 instantly
    if(id == 0){
        return 0;
    }
    
    return id;
}

uint64_t cache_exists_mpz_binary(lookup* cache, mpz_t op1, mpz_t op2, uint64_t* extra_info, int op){
    uint64_t id = cache_exists_mpz_binary_raw(cache, op1, op2, extra_info, op);
    return id | SHIFT;
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

uint64_t cached_mpz_add(lookup* cache, mpz_t op1_in, mpz_t op2_in){
    
    ////// cache addition result
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    mpz_set(op1, op1_in);
    mpz_set(op2, op2_in);
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
        uint64_t id = cache_exists_mpz_binary_raw(cache, op1, op2, NULL, ADD);
        if(id){
            mpz_clear(op1);
            mpz_clear(op2);
            id |= SHIFT;
            return id;
        }
        
        lkuptable = cache->add;
        mpz_add(result, op1, op2);
    }
    //Case 2: a<0, b<0
    if(op1->_mp_size < 0 && op2->_mp_size < 0){
        //check if +a,+b is cached in addition table
        uint64_t id = cache_exists_mpz_binary_raw(cache, op1, op2, NULL, ADD);
        if(id){
            mpz_clear(op1);
            mpz_clear(op2);
            return id | NEG | SHIFT;
        }
        lkuptable = cache->add;
        mpz_add(result, op1, op2);
    }
    //Case 3: a>=0, b<0
    if(op1->_mp_size >= 0 && op2->_mp_size < 0){
        //check if +a,+b cached in subtraction table IS NEGATIVE??
        uint64_t id = cache_exists_mpz_binary_raw(cache, op1, op2, NULL, SUB);
        if(id){
            int cmp = mpz_cmpabs(op1, op2);
            mpz_clear(op1);
            mpz_clear(op2);
            if(cmp >= 0)
                return id | SHIFT;
            else
                return id | NEG | SHIFT;
        }
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
    uint64_t id_op1 = cache_insert_mpz_raw(cache, op1);
    uint64_t id_op2 = cache_insert_mpz_raw(cache, op2);
    uint64_t id_res = cache_insert_mpz_raw(cache, result);
    insert_element_binary(lkuptable->ht, id_op1, id_op2, id_res, NULL, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    mpz_clear(op1);
    mpz_clear(op2);
    mpz_clear(result);
    if(resNeg)
        return id_res | SHIFT | NEG;
    else
        return id_res | SHIFT;
}

uint64_t cached_mpz_sub(lookup* cache, mpz_t op1, mpz_t op2){
    //every subtraction is an addition
    
    mpz_t op2_neg;
    mpz_init(op2_neg);
    mpz_neg(op2_neg, op2);
    uint64_t id = cached_mpz_add(cache, op1, op2_neg);
    mpz_clear(op2_neg);
    return id;
}

uint64_t cached_mpz_mul(lookup* cache, mpz_t op1, mpz_t op2){
    ////// cache multiplication result
    mpz_t op1_in;
    mpz_t op2_in;
    mpz_init(op1_in);
    mpz_init(op2_in);
    mpz_set(op1_in, op1);
    mpz_set(op2_in, op2);
    //sort operands
    if(mpz_cmp(op1_in, op2_in) < 0){
        mpz_swap(op1_in, op2_in);
    }
    //check if exists in cache
    uint64_t id = cache_exists_mpz_binary_raw(cache, op1_in, op2_in, NULL, MUL);
    if(id){
        mpz_clear(op1_in);
        mpz_clear(op2_in);
        if(((op1->_mp_size < 0) + (op2->_mp_size < 0))%2)
            return id | SHIFT | NEG;
        else
           return id | SHIFT; 
    }
    
    mpz_t result;
    mpz_init(result);
    
    mpz_mul(result, op1_in, op2_in);
    
    int resNeg = 0;
    if(result->_mp_size < 0){
        resNeg = 1;
        mpz_neg(result, result);
    }
    //hash tuple
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1_in, op2_in, hashes);
    
    //add to cache
    uint64_t id_op1 = cache_insert_mpz_raw(cache, op1_in);
    uint64_t id_op2 = cache_insert_mpz_raw(cache, op2_in);
    uint64_t id_res = cache_insert_mpz_raw(cache, result);
    insert_element_binary(cache->mul->ht, id_op1, id_op2, id_res, NULL, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    mpz_clear(op1_in);
    mpz_clear(op2_in);
    mpz_clear(result);
    
    if(resNeg)
        return id_res | SHIFT | NEG;
    else
        return id_res | SHIFT;
}

uint64_t cached_mpz_tdiv(lookup* cache, uint64_t* rest, mpz_t op1, mpz_t op2){
    //return 0 if operand2 == 0
    int cmp = mpz_cmpabs_ui(op2, 0);
    if(cmp == 0){
        uint64_t r_temp = 0;
        rest = &r_temp;
        return 0;
    }
    ////// cache division result
    mpz_t op1_in;
    mpz_t op2_in;
    mpz_init(op1_in);
    mpz_init(op2_in);
    mpz_set(op1_in, op1);
    mpz_set(op2_in, op2);

    //check if exists in cache
    uint64_t id = cache_exists_mpz_binary_raw(cache, op1_in, op2_in, rest, TDIV);
    if(id!=0){
        mpz_clear(op1_in);
        mpz_clear(op2_in);
        if(((op1->_mp_size < 0) + (op2->_mp_size < 0))%2){
            return id | SHIFT | NEG;
        }
        else{
            return id | SHIFT; 
        }
    }
    
    mpz_t result_q;
    mpz_init(result_q);
    mpz_t result_r;
    mpz_init(result_r);
    
    mpz_tdiv_qr(result_q, result_r, op1_in, op2_in);
    
    int resNeg = 0;
    if(result_q->_mp_size < 0){
        resNeg = 1;
        mpz_neg(result_q, result_q);
    }
    //hash tuple
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1_in, op2_in, hashes);
    
    //add to cache
    uint64_t id_op1 = cache_insert_mpz_raw(cache, op1_in);
    uint64_t id_op2 = cache_insert_mpz_raw(cache, op2_in);
    uint64_t id_res_q = cache_insert_mpz_raw(cache, result_q);
    uint64_t id_res_r = cache_insert_mpz_raw(cache, result_r);
    insert_element_binary(cache->tdiv->ht, id_op1, id_op2, id_res_q, &id_res_r, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    mpz_clear(op1_in);
    mpz_clear(op2_in);
    mpz_clear(result_q);
    mpz_clear(result_r);
    
    id_res_r = id_res_r | SHIFT; 
    *rest = id_res_r;
    if(resNeg)
        return id_res_q | SHIFT | NEG;
    else
        return id_res_q | SHIFT;
}

uint64_t cached_mpz_mod(lookup* cache, mpz_t op1, mpz_t op2){
    uint64_t mod_id;
    cached_mpz_tdiv(cache, &mod_id, op1, op2);
    return mod_id;
}

uint64_t cached_mpz_gcd(lookup* cache, mpz_t op1, mpz_t op2){
    ////// cache ggT result
    //result always positive
    mpz_t op1_in;
    mpz_t op2_in;
    mpz_init(op1_in);
    mpz_init(op2_in);
    mpz_set(op1_in, op1);
    mpz_set(op2_in, op2);
    //sort operands
    if(mpz_cmp(op1_in, op2_in) < 0){
        mpz_swap(op1_in, op2_in);
    }
    //check if exists in cache
    uint64_t id = cache_exists_mpz_binary_raw(cache, op1_in, op2_in, NULL, GCD);
    if(id){
        mpz_clear(op1_in);
        mpz_clear(op2_in);
        return id | SHIFT; 
    }
    
    mpz_t result;
    mpz_init(result);
    
    mpz_gcd(result, op1_in, op2_in);
    
    //hash tuple
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1_in, op2_in, hashes);
    
    //add to cache
    uint64_t id_op1 = cache_insert_mpz_raw(cache, op1_in);
    uint64_t id_op2 = cache_insert_mpz_raw(cache, op2_in);
    uint64_t id_res = cache_insert_mpz_raw(cache, result);
    insert_element_binary(cache->gcd->ht, id_op1, id_op2, id_res, NULL, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    mpz_clear(op1_in);
    mpz_clear(op2_in);
    mpz_clear(result);
    
    return id_res | SHIFT;
}

uint64_t cached_mpz_invert(lookup* cache, mpz_t op, mpz_t mod){
    ////// cache inverse mod n result
    mpz_t op1_in;
    mpz_t op2_in;
    mpz_init(op1_in);
    mpz_init(op2_in);
    mpz_set(op1_in, op);
    mpz_set(op2_in, mod);

    //check if exists in cache
    uint64_t id = cache_exists_mpz_binary_raw(cache, op1_in, op2_in, NULL, INV);
    if(id){
        mpz_clear(op1_in);
        mpz_clear(op2_in);
        return id | SHIFT; 
    }
    
    mpz_t result;
    mpz_init(result);
    
    int exists = mpz_invert(result, op1_in, op2_in);
    
    if(!exists){
        mpz_clear(op1_in);
        mpz_clear(op2_in);
        mpz_clear(result);
        return 0;
    }
    //hash tuple
    
    uint64_t* hashes;
    hashes = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes_cpf(op1_in, op2_in, hashes);
    
    //add to cache
    uint64_t id_op1 = cache_insert_mpz(cache, op1_in);
    uint64_t id_op2 = cache_insert_mpz(cache, op2_in);
    uint64_t id_res = cache_insert_mpz(cache, result);
    insert_element_binary(cache->inv->ht, id_op1, id_op2, id_res, NULL, hashes);
    
    //free hashes
    free(hashes);
    hashes=NULL;
    
    //return new id
    mpz_clear(op1_in);
    mpz_clear(op2_in);
    mpz_clear(result);
    
    return id_res | SHIFT;
}