 /**
  * @file mpz_caching.c
  * @author Sandra Hicks
  * @brief cache for mpz_t
  */
#ifdef __cplusplus
extern "C" {
#endif

#include "mpz_caching.h"
#include "mastercache.h"
#include <stdlib.h>

//debug
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>
    
#define DOUBLE_BITS 1019


int is_double_castable(mpz_t m);
    
//keine ID 0, fange an bei 2 zu zählen weil praktischer bei Abfragen

/**
 * @brief initialization of the cache
 * @param cache pointer to cache
 * @param size initial size of the cache
 */
void init_mpz_cache(mpz_t_cache* cache, uint64_t size){
    cache->cache = malloc(sizeof(cached_mpz_t) * size);
    cache->next_id = CACHE_START_ID;
    cache->size = size;
    printf("size: %" PRIu64 "\n", size);
}

/**
 * @brief deletion of the cache and free of all underlying data structures
 * @param cache pointer to cache
 */
void delete_mpz_cache(mpz_t_cache* cache){
    unsigned int i = CACHE_START_ID;
    printf("cache grown to: %" PRIu64 "\n", cache->next_id);
    for(i=CACHE_START_ID; i<cache->next_id; i++){
        cached_mpz_t* curr = &(cache->cache[i]);
        mpz_clear(curr->integer);
    }
    free(cache->cache);
    cache->cache = NULL;
}

//insert new mpz_t at the end, return ID
/**
 * @brief insert a new mpz_t in cache, no check for double, start at id=2 (0 is reserved for errors, 1 for infinity)
 * @param cache pointer to cache
 * @param val mpz_t to insert
 * @return id of inserted element
 */
int64_t insert_mpz(mpz_t_cache* cache, mpz_t val){
    
    if(cache->next_id >= cache->size){
        printf("----------Cache Status----------\n");
        printf("100 percent\n");
        printf("[====================>]\n");
        printf("--------------------------------\n");
        assert(cache->next_id < cache->size);
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.1)){
        printf("----------Cache Status----------\n");
        printf("10 percent\n");
        printf("[==>                  ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.2)){
        printf("----------Cache Status----------\n");
        printf("20 percent\n");
        printf("[====>                ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.3)){
        printf("----------Cache Status----------\n");
        printf("30 percent\n");
        printf("[======>              ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.4)){
        printf("----------Cache Status----------\n");
        printf("40 percent\n");
        printf("[========>            ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.5)) {
        printf("----------Cache Status----------\n");
        printf("50 percent\n");
        printf("[==========>          ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.6)) {
        printf("----------Cache Status----------\n");
        printf("50 percent\n");
        printf("[============>        ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.7)) {
        printf("----------Cache Status----------\n");
        printf("70 percent\n");
        printf("[==============>      ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.8)) {
        printf("----------Cache Status----------\n");
        printf("80 percent\n");
        printf("[================>    ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.8)) {
        printf("----------Cache Status----------\n");
        printf("90 percent\n");
        printf("[==================>  ]\n");
        printf("--------------------------------\n");
    }
    else if(cache->next_id == (uint64_t)(cache->size*0.8)) {
        printf("----------Cache Status----------\n");
        printf("95 percent -- CRITICAL\n");
        printf("[===================> ]\n");
        printf("--------------------------------\n");
    }
    
    double fp_rep;
    if(is_double_castable(val)){
        fp_rep = mpz_get_d(val);
    }
    else{
        fp_rep = 0.0;
    }
    
    uint64_t id = cache->next_id;
    cached_mpz_t* new = &cache->cache[id];
    mpz_set(new->integer,val);
    
    new->fp = fp_rep;
    
    cache->next_id = id+1;
    //printf("--Inserted new mpz_t--%" PRIu64 "\n", id);
    return id;
}
/**
 * @brief print function for debugging, prints double representation
 * @param cache
 * @param i id
 */
void printEntry(mpz_t_cache* cache, uint64_t i){
    cached_mpz_t* element = &cache->cache[i];
    printf("Element i=%" PRIu64 ": %f\n",i, element->fp);
}

/**
 * @brief get a cached mpz_t by id, set mpz_t to direct value if no ID
 * @param cache pointer to cache
 * @param i requested id,  must have deleted NEG and SHIFT bit!
 * @param val mpz_t to set for return
 */
void get_cached_mpz(mpz_t_cache* cache, uint64_t i, mpz_t val){
    if(i >= cache->next_id){
        printf("id: %" PRId64 "\n", i);
    }
    assert(i < cache->next_id);
    cached_mpz_t* element = &cache->cache[i];
    if(val == NULL){
        mpz_init_set(val, element->integer);
    }
    else{
        mpz_set(val, element->integer);
    }
}
/**
 * @brief get double representation of a cached mpz_t by id
 * @param cache pointer to cache
 * @param i requested id
 * @return double representation
 */
double get_cached_double(mpz_t_cache* cache, uint64_t i){
    return (&cache->cache[i])->fp;
}

/**
 * @brief test if an mpz_t can be cast into a double without loss of data
 * @param m mpz_t
 * @return 1 if castable, 0 if not
 */
int is_double_castable(mpz_t m){
    unsigned int longsize = sizeof(long) * 8;
    //maximum value of a long fits into 1019 bits (conservative)
    unsigned int maxlimbs = DOUBLE_BITS / longsize;
    long size = m->_mp_size;
    if(size < 0)
        size = size * (-1);
    if(size > maxlimbs)
        return 0;
    else
        return 1;
}

#ifdef __cplusplus
}
#endif
