#include "master_cache_integer.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#define SIZE_C 1000
#define MPZTS 10

int main(int argc, char** argv) {
  //init cache
  MasterCache* cache = malloc(sizeof(MasterCache));
  cached_int_init_cache(cache, SIZE_C);

  //init mpz_ts
  mpz_t large;
  mpz_init(large);
  long large_l = LONG_MAX;
  unsigned long large_ul = LONG_MAX;
  mpz_set_si(large, large_l);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);
  mpz_add_ui(large, large, large_ul);

  mpz_t small;
  mpz_init(small);
  long small_l = 1234;
  mpz_set_si(small, small_l);

  mpz_t border_smaller;
  mpz_init(border_smaller);
  unsigned long border_smaller_l = LONG_MAX-2;
  mpz_set_ui(border_smaller, border_smaller_l);

  mpz_t border_greater;
  mpz_init(border_greater);
  unsigned long border_greater_l = LONG_MAX;
  unsigned long addition = 2;
  mpz_set_ui(border_greater, border_greater_l);
  mpz_add_ui(large, large, addition);


  //caching
  cachedInt small_id = cached_int_set(cache, small);
  cachedInt large_id = cached_int_set(cache, large);

  //gerade noch nicht cachen
  cachedInt notYet = cached_int_set(cache, border_smaller);

  //gerade cachen
  cachedInt justYet = cached_int_set(cache, border_greater);

  //Grenzwerte Operationen
  //Addition overflow
  cachedInt add_of = cached_int_add(cache, notYet, notYet);

  //Addition ein Wert cached, einer uncached
  cachedInt add_c = cached_int_add(cache, justYet, notYet);

  //Subtraktion ein Wert cached, einer uncached
  
  //Multiplikation overflow
  cachedInt mul_of = cached_int_mul(cache, justYet, small_id);

  //Multiplikation ein Wert cached, einer uncached
  cachedInt mul_c = cached_int_mul(cache, justYet, notYet);

  //Division ein Wert cached, einer uncached
  cachedInt rest;
  cachedInt div_c = cached_int_tdiv(cache, justYet, notYet, &rest);

  //Mod ein cached, ein uncached
  cachedInt mod_c = cached_int_mod(cache, justYet, notYet);

  //inverse ein cached, ein uncached
  cachedInt inv_c;
  int invertable = cached_int_invert(cache, justYet, notYet, &inv_c);
  //inverse overflow

  cached_int_clear_cache(cache);
  free(cache);
  cache = NULL;
  mpz_clear(large);
  mpz_clear(small);
  mpz_clear(border_smaller);
  mpz_clear(border_greater);
  return 0;
}
