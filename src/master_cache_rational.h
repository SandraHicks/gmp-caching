 /**
  * @file master_cache_rational.h
  * @author Sandra Hicks
  * @brief header for Master Cache functions for caching Rational operations in gmp
  */


#ifndef MASTER_CACHE_RATIONAL_H
#define MASTER_CACHE_RATIONAL_H

#ifdef __cplusplus
#include <gmp.h>
extern "C" {
#else
#include <gmp.h>
#endif
    
#include "mastercache.h"
#include "master_cache_integer.h"
#include "defines.h"

cachedRational cached_rational_set(const MasterCache* mstr, mpz_t counter, mpz_t denominator);
cachedRational cached_rational_set_mpq(const MasterCache* mstr, mpq_t number);
cachedRational cached_rational_set_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator);

void cached_rational_reset_mpq(const MasterCache* mstr, mpq_t number, cachedRational* value);
void cached_rational_reset(const MasterCache* mstr, mpz_t counter, mpz_t denominator, cachedRational* value);
void cached_rational_reset_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator, cachedRational* value);


void cached_rational_get(const MasterCache* mstr, cachedRational id, mpz_t counter, mpz_t denominator);
void cached_rational_get_mpq(const MasterCache* mstr, cachedRational id, mpq_t number);
double cached_rational_get_d(const MasterCache* mstr, cachedRational id);

cachedRational cached_rational_add(const MasterCache* mstr, cachedRational val1, cachedRational val2);
cachedRational cached_rational_reduce(const MasterCache* mstr, cachedRational val);
void cached_rational_reduce_inplace(const MasterCache* mstr, cachedRational* val);
cachedRational cached_rational_sub(const MasterCache* mstr, cachedRational val1, cachedRational val2);
cachedRational cached_rational_mul(const MasterCache* mstr, cachedRational val1, cachedRational val2);
cachedRational cached_rational_div(const MasterCache* mstr, cachedRational val1, cachedRational val2);
cachedRational cached_rational_abs(const MasterCache* mstr, cachedRational val);
cachedRational cached_rational_inv(const MasterCache* mstr, cachedRational val);
cachedRational cached_rational_neg(const MasterCache* mstr, cachedRational val);
void cached_rational_neg_inplace(const MasterCache* mstr, cachedRational* val);
int cached_rational_sgn(const MasterCache* mstr, cachedRational val);

#ifdef __cplusplus
}
#endif
#endif /* MASTER_CACHE_RATIONAL_H */