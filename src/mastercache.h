 /**
  * @file mastercache.h
  * @author Sandra Hicks
  * @brief header for Master Cache for caching Integers and Integer operations from gmp.
  */

#ifndef MASTERCACHE_H
#define MASTERCACHE_H

#ifdef __cplusplus
#include <gmp.h>
extern "C" {
#else
#include <gmp.h>
#endif

#include "defines.h"
#include "caching_operations.h"
    /**
     * Master cache for integers
     */
    typedef struct MasterCacheInt{
        lookup* cache;      /**< cache for integer caching*/
    } MasterCacheInt;
    
    
    /**
     * @brief MasterCache
     */
    typedef struct MasterCache {
        MasterCacheInt* _integers;          /**< cache for integer caching*/
    } MasterCache;

/** cachedInt can be either an id to a cached mpz_t (indicated by MSB) or an actual number,
 * the sign is indicated by MSB-1
 */
typedef uint64_t cachedInt; //max: 1073741823 (2^62 - 2)

/**
 * cached Rational
 */
typedef struct cache_rational {
    cachedInt counter;      /**< counter*/
    cachedInt denominator;  /**< denominator*/
} cachedRational;


void cache_init(MasterCache** mstr, uint64_t cache_size);
void cache_clear(MasterCache* mstr);

#ifdef __cplusplus
}
#endif

#endif /* MASTERCACHE_H */

