 /**
  * @file mpz_caching.c
  * @author Sandra Hicks
  * @brief cache
  */
#include "mpz_caching.h"
#include "mastercache.h"
#include <stdlib.h>

//debug
#include <stdio.h>
#include <inttypes.h>

void init_mpz_cache(mpz_t_cache* cache, uint64_t size){
    cache->cache = malloc(sizeof(cached_mpz_t) * size);
    cache->next_id = 0;
    cache->size = size;
}

//insert new mpz_t at the end, return ID
int64_t insert_mpz(mpz_t_cache* cache, mpz_t val){
    if(cache->next_id >= cache->size)
        return -1;
    
    double fp_rep = mpz_get_d(val);
    
    uint64_t id = cache->next_id;
    cached_mpz_t* new = &cache->cache[id];
    mpz_set(new->integer,val);
    
    new->fp = fp_rep;
    
    cache->next_id = id+1;
    return id;
}

void printEntry(mpz_t_cache* cache, uint64_t i){
    cached_mpz_t* element = &cache->cache[i];
    printf("Element i=%" PRIu64 ": %f\n",i, element->fp);
}

void get_cached_mpz(mpz_t_cache* cache, uint64_t i, mpz_t val){
    cached_mpz_t* element = &cache->cache[i];
    mpz_set(val, element->integer);
}

double get_cached_double(mpz_t_cache* cache, uint64_t i){
    cached_mpz_t* element = &cache->cache[i];
    return element->fp;
}