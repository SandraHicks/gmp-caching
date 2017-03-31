 /**
  * @file mpz_caching.c
  * @author Sandra Hicks
  * @brief cache
  */
#include "mpz_caching.h"

cached_mpz_t* init_mpz_cache(int64_t size){
    cached_mpz_t cache[size];
    return cache;
}