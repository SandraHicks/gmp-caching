#ifndef MASTER_CACHE_RATIONAL_H
#define MASTER_CACHE_RATIONAL_H



void cached_rational_set_mpq(MasterCache* mstr, mpq_t number, cachedRational* value);
void cached_rational_set(MasterCache* mstr, mpz_t counter, mpz_t denominator, cachedRational* value);
void cached_rational_get(MasterCache* mstr, cachedRational* id, mpz_t counter, mpz_t denominator);
void cached_rational_get_mpq(MasterCache* mstr, cachedRational* id, mpq_t number);
double cached_rational_get_d(MasterCache* mstr, cachedRational* id);

void cached_rational_add(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result);
void cached_rational_reduce(MasterCache* mstr, cachedRational* val);
void cached_rational_sub(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result);
void cached_rational_mul(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result);
void cached_rational_div(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result);
void cached_rational_abs(MasterCache* mstr, cachedRational* val, cachedRational* result);
void cached_rational_inv(MasterCache* mstr, cachedRational* val);
void cached_rational_neg(MasterCache* mstr, cachedRational* val);
#endif /* MASTER_CACHE_RATIONAL_H */