 /**
  * @file mpz_caching.c
  * @author Sandra Hicks
  * @brief cache
  */
#include "mpz_caching.h"
#include "mastercache.h"

void init_mpz_cache(int64_t size, cached_mpz_t* result){
    cached_mpz_t cache[size];
    result = cache;
}