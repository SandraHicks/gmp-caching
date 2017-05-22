 /**
  * @file mastercache.c
  * @author Sandra Hicks
  * @brief Master Cache for caching Integers and Integer operations from gmp.
  */

#include <stdint.h>
#include <gmp.h>

#include "mastercache.h"

/**
 * @brief Init function for master cache
 * @param mstr MasterCache pointer to be initialized
 * @param cache_size size of the cache for mpz_t
 */
void cache_init(MasterCache* mstr, uint64_t cache_size){
    
}

/**
 * @brief add function for master cache
 * @param mstr MasterCache pointer
 * @param new mpz_t to be added to cache
 */
cachedInt cache_add(MasterCache* mstr, mpz_t new){
    return 0;
}

/**
 * @brief function for master cache to check if an item exists
 * @param mstr MasterCache pointer
 * @param element mpz_t to be added to cache
 */
int cache_exists(MasterCache* mstr, mpz_t element){
    
    return 0;
}

/**
 * @brief function for master cache to get an item back from cache as mpq_t
 * @param mstr MasterCache pointer
 * @param element id of the element to get from cache
 * @param result
 */
void cache_get(MasterCache* mstr, cachedInt element, mpz_t result){

}