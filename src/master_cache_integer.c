/*
 * Master Cache for caching Integer values in mpz
 *
 */
#include <stdint.h> //always include first
#include <gmp.h>
#include <limits.h>

#include "defines.h"
#include "hash_table_double_linked_sorted.h"


//Master Cache typedef and instance
struct MasterCacheInteger {
    //LookUp Table instances
};

//Master Cache bit mask version
typedef long cache_mpz; //max: 1073741823 (2^30 - 2)


#define SIGN (1 << 31)
#define INDEX (1 << 30)

//Master Cache struct version
typedef unsigned long u_cache_mpz;

struct cache_mpz_ {
    u_cache_mpz number;
    bool sign;
    bool isIndex;
};

struct cache_rational {
    u_cache_mpz counter;
    u_cache_mpz denominator;
    bool sign;
    bool isIndex;
};
//oder
struct cache_mpz__ {
    u_cache_mpz number;
    uint8_t info; //include information about sign and isIndex
};

/*
 * typedef based functions
 */
mpz_t int_cache_get(MasterCacheInteger mstr, cache_mpz value){
    //get value from cache if exists
    
    //error handling?
}

bool int_cache_exists(MasterCacheInteger mstr, mpz_t value){
    //value exists in cache?
}

bool int_cache_insert(MasterCacheInteger mstr, mpz_t value){
    //insert value in table
}

bool int_cache_insert_l(MasterCacheInteger mstr, cache_mpz value){
    //insert long
}

mpz_t int_cache_add(MasterCacheInteger mstr, cache_mpz val1, cache_mpz val2){
    //add integers
}


/*
 * struct based functions
 */

mpz_t int_cache_get_(MasterCacheInteger mstr, cache_mpz_ value){
    //get value from cache if exists
    
    //error handling?
}

bool int_cache_exists_(MasterCacheInteger mstr, mpz_t value){
    //value exists in cache?
}

bool int_cache_insert_(MasterCacheInteger mstr, mpz_t value){
    //insert value in table
}

bool int_cache_insert_l_(MasterCacheInteger mstr, cache_mpz_ value){
    //insert long
}

mpz_t int_cache_add_(MasterCacheInteger mstr, cache_mpz_ val1, cache_mpz_ val2){
    //add integers
}