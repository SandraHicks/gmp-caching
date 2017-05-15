#ifndef MASTER_CACHE_INTEGER_H
#define MASTER_CACHE_INTEGER_H

#include "mastercache.h"

cachedInt cached_int_set(MasterCache* mstr, mpz_t number);
void cached_int_get(MasterCache* mstr, cachedInt id, mpz_t number);
void cached_int_mpz(cachedInt id, mpz_t number);
uint64_t mpz_cached_int(mpz_t number);

cachedInt cached_int_add(MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_sub(MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_mul(MasterCache* mstr, cachedInt val1, cachedInt val2);
cachedInt cached_int_tdiv(MasterCache* mstr, cachedInt divident, cachedInt divisor, cachedInt* rest);
cachedInt cached_int_mod(MasterCache* mstr, cachedInt number, cachedInt n);
cachedInt cached_int_gcd(MasterCache* mstr, cachedInt operand1, cachedInt operand2);
cachedInt cached_int_invers(MasterCache* mstr, cachedInt number, cachedInt n);

#endif /* MASTER_CACHE_INTEGER_H */