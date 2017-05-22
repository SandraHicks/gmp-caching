/*
 * Master Cache for caching Rational values in mpq
 *
 */
#include "defines.h"
#include <gmp.h>
#include "mastercache.h"


typedef uint64_t cache_mpq;


//Master Cache struct version
/**
 * cached Rational
 */
typedef struct cachedRational {
    cache_mpq counter;      /**< counter*/
    cache_mpq denominator;  /**< denominator*/
} cache_rational;



/*
 * typedef based functions
 */
/**
 * (TODO)
 * @param mstr
 * @param value
 * @param result
 */
void int_cache_get(MasterCacheRational mstr, cache_mpq value, mpq_t result){
    //get value from cache if exists
    
    //error handling?
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_exists(MasterCacheRational mstr, mpq_t value){
    //value exists in cache?
    return 0;
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_insert(MasterCacheRational mstr, mpq_t value){
    //insert value in table
    return 0;
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_insert_l(MasterCacheRational mstr, cache_mpq value){
    //insert long
    return 0;
}
/**
 * (TODO)
 * @param mstr
 * @param val1
 * @param val2
 * @param result
 */
void int_cache_add(MasterCacheRational mstr, cache_mpq val1, cache_mpq val2, mpq_t result){
    //add rationals

}


/*
 * struct based functions
 */
/**
 * (TODO)
 * @param mstr
 * @param value
 * @param result
 */
void int_cache_get_(MasterCacheRational mstr, cache_rational value, mpq_t result){
    //get value from cache if exists
    
    //error handling?
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_exists_(MasterCacheRational mstr, mpq_t value){
    //value exists in cache?
    return 0;
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_insert_(MasterCacheRational mstr, mpq_t value){
    //insert value in table
    return 0;
}
/**
 * (TODO)
 * @param mstr
 * @param value
 * @return 
 */
int int_cache_insert_d_(MasterCacheRational mstr, double value){
    //insert double
    return 0;
}