 /**
  * @file master_cache_integer.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Integer operations in gmp
  */
#include <stdint.h> //always include first
#include <gmp.h>
#include <limits.h>

#include "defines.h"
#include "mastercache.h"
#include "hashtable.h"
#include "mpz_caching.h"


/**
 * @brief function for master cache to add two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt int_cache_add(MasterCache mstr, cachedInt val1, cachedInt val2){
  //add integers
    
  //if val1 and val2 small: return Result as number if result < maxResult
    //if result > maxResult: cache and return ID
    
  //else: check if hash(val1, val2) or hash(val2, val1) valid
    
    //if cached: return ID_mpz
    //if not cached: add
      //if result small: add, cache ID, and return
      //else: 
         //add, 
         //look if mpz cached, cache in ID_mpz->mpz
         //cache ID_mpz in add table, 
         //access by ID_add = hash(val1, val2) if val1>=val2
         //return ID_mpz
    return 0;
}

/**
 * @brief function for master cache to subtract two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt int_cache_subtract(MasterCache mstr, cachedInt val1, cachedInt val2){
    return 0;
}

/**
 * @brief function for master cache to multiply two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt int_cache_multiply(MasterCache mstr, cachedInt val1, cachedInt val2){
    return 0;
}

/**
 * @brief function for master cache to divide two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param divident id of the first operand
 * @param divisor id of the second operand
 */
cachedInt int_cache_divide(MasterCache mstr, cachedInt divident, cachedInt divisor){
    return 0;
}