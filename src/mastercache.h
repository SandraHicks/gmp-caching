 /**
  * @file mastercache.h
  * @author Sandra Hicks
  * @brief header for Master Cache for caching Integers and Integer operations from gmp.
  */

#ifndef MASTERCACHE_H
#define MASTERCACHE_H

#ifdef __cplusplus
extern "C" {
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
     * Master cache for rationals
     */
    typedef struct MasterCacheRational{
        
    } MasterCacheRational;
    
    /**
     * @brief MasterCache
     */
    typedef struct MasterCache {
        MasterCacheInt* _integers;          /**< cache for integer caching*/
        MasterCacheRational* _rationals;    /**< cache for rational caching*/
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


#ifdef __cplusplus
}
#endif

#endif /* MASTERCACHE_H */

