 /**
  * @file mastercache.c
  * @author Sandra Hicks
  * @brief Master Cache for caching Integers and Integer operations from gmp.
  */

#include <stdint.h>
#include <gmp.h>

#include "mastercache.h"
#include "master_cache_integer.h"

/**
 * @brief Init function for master cache
 * @param mstr MasterCache pointer to be initialized
 * @param cache_size size of the cache for mpz_t
 */
void cache_init(MasterCache** mstr, uint64_t cache_size){
    MasterCache* tmp;
    cached_int_init_cache(&tmp, cache_size);
    *mstr = tmp;
}

void cache_clear(MasterCache* mstr){
    cached_int_clear_cache(&mstr);
}