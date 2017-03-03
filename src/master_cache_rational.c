/*
 * Master Cache for caching Rational values in mpq
 *
 */
#include "defines.h"
#include <gmp.h>


//Master Cache typedef and instance
struct MasterCacheRational {
    
};
//Master Cache bitmask version

typedef long cache_mpq;
typedef unsigned long u_cache_mpq;

#define SIGN 0b10000000000000000000000000000000
#define INDEX 0b01000000000000000000000000000000

//Master Cache struct version

struct cache_rational {
    u_cache_mpq counter;
    u_cache_mpq denominator;
    bool sign;
    bool isIndex;
};



/*
 * typedef based functions
 */
mpq_t int_cache_get(MasterCacheRational mstr, cache_mpq value){
    //get value from cache if exists
    
    //error handling?
}

bool int_cache_exists(MasterCacheRational mstr, mpq_t value){
    //value exists in cache?
}

bool int_cache_insert(MasterCacheRational mstr, mpq_t value){
    //insert value in table
}

bool int_cache_insert_l(MasterCacheRational mstr, cache_mpq value){
    //insert long
}

mpq_t int_cache_add(MasterCacheRational mstr, cache_mpq val1, cache_mpq val2){
    //add rationals
}


/*
 * struct based functions
 */

mpq_t int_cache_get_(MasterCacheRational mstr, cache_rational value){
    //get value from cache if exists
    
    //error handling?
}

bool int_cache_exists_(MasterCacheRational mstr, mpq_t value){
    //value exists in cache?
}

bool int_cache_insert_(MasterCacheRational mstr, mpq_t value){
    //insert value in table
}

bool int_cache_insert_d_(MasterCacheRational mstr, double value){
    //insert double
}