 /**
  * @file master_cache_integer.h
  * @author Sandra Hicks
  * @brief header for Master Cache functions for caching Integer operations in gmp
  */

#ifndef MASTER_CACHE_INTEGER_H
#define MASTER_CACHE_INTEGER_H

#ifdef __cplusplus
#include <gmp.h>
extern "C" {
#else
#include <gmp.h>
#endif
#include "mastercache.h"


void cached_int_init_cache(MasterCache** mstr, uint64_t cachesize);
void cached_int_clear_cache(MasterCache** mstr);

cachedInt cached_int_set(const MasterCache* mstr, mpz_t number);
void cached_int_get(const MasterCache* mstr, cachedInt id, mpz_t number);
double cached_int_get_d(const MasterCache* mstr, cachedInt id);


cachedInt cached_int_abs(const MasterCache* mstr, cachedInt val);
cachedInt cached_int_neg(const MasterCache* mstr, cachedInt val);
int cached_int_sgn(const MasterCache* mstr, cachedInt val);
cachedInt cached_int_add(const MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_sub(const MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_mul(const MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_tdiv(const MasterCache* mstr, cachedInt divident, cachedInt divisor, cachedInt* rest);
cachedInt cached_int_mod(const MasterCache* mstr, cachedInt number, cachedInt n);
cachedInt cached_int_gcd(const MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_lcm(const MasterCache* mstr, cachedInt val1, cachedInt val2);
int cached_int_invert(const MasterCache* mstr, cachedInt val1, cachedInt val2, cachedInt* result);


#ifdef __cplusplus
}
#endif
#endif /* MASTER_CACHE_INTEGER_H */