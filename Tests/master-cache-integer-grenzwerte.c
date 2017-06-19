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
  cache_init(cache, SIZE_C);

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
  mpz_add_ui(large, large, large_ul);

  mpz_t small;
  mpz_init(small);
  long small_l = 1234;
  mpz_set_si(small, small_l);

  mpz_t border_smaller;
  mpz_init(border_smaller);
  unsigned long border_smaller_l = ((unsigned long)1 << 62)-3;
  mpz_set_ui(border_smaller, border_smaller_l);

  mpz_t border_greater;
  mpz_init(border_greater);
  unsigned long border_greater_l = LONG_MAX;
  unsigned long addition = 2;
  mpz_set_ui(border_greater, border_greater_l);
  //mpz_add_ui(large, large, addition);

  if(border_smaller_l < cachedInt_MAX)
    printf("notyet smaller cachedIntMax\n");
  printf("notyet %" PRIu64 " cachedInt max: %" PRIu64 "\n", border_smaller_l, cachedInt_MAX);

  //caching
  cachedInt small_id = cached_int_set(cache, small);
  printf("small_id id: %" PRIu64 "\n", small_id & ~SHIFT);
  printf("isID %" PRIu64 "\n", (small_id & SHIFT) >> 62);
  cachedInt large_id = cached_int_set(cache, large);
  printf("large_id id: %" PRIu64 "\n", large_id & ~SHIFT);
  printf("isID %" PRIu64 "\n", (large_id & SHIFT) >> 62);

  //gerade noch nicht cachen
  cachedInt notYet = cached_int_set(cache, border_smaller);
  printf("notYet id: %" PRIu64 "\n", notYet & ~SHIFT);
  printf("isID %" PRIu64 "\n", (notYet & SHIFT) >> 62);

  //gerade cachen
  cachedInt justYet = cached_int_set(cache, border_greater);
  printf("justYet id: %" PRIu64 "\n", justYet & ~SHIFT);
  printf("isID %" PRIu64 "\n", (justYet & SHIFT) >> 62);

  //Grenzwerte Operationen
  //Addition overflow
  cachedInt add_of = cached_int_add(cache, notYet, notYet);
  printf("add_of id: %" PRIu64 "\n", add_of & ~SHIFT);
  printf("isID %" PRIu64 "\n", (add_of & SHIFT) >> 62);

  //Addition ein Wert cached, einer uncached
  cachedInt add_c = cached_int_add(cache, justYet, notYet);
  printf("add_c id: %" PRIu64 "\n", add_c & ~SHIFT);
  printf("isID %" PRIu64 "\n", (add_c & SHIFT) >> 62);

  //Subtraktion ein Wert cached, einer uncached
  
  //Multiplikation overflow
  cachedInt mul_of = cached_int_mul(cache, justYet, small_id);
  printf("mul_of id: %" PRIu64 "\n", mul_of & ~SHIFT);
  printf("isID %" PRIu64 "\n", (mul_of & SHIFT) >> 62);

  //Multiplikation ein Wert cached, einer uncached
  cachedInt mul_c = cached_int_mul(cache, justYet, notYet);
  printf("mul_c id: %" PRIu64 "\n", mul_c & ~SHIFT);
  printf("isID %" PRIu64 "\n", (mul_c & SHIFT) >> 62);

  //Division ein Wert cached, einer uncached
  cachedInt rest;
  cachedInt div_c = cached_int_tdiv(cache, justYet, notYet, &rest);
  printf("div_c id: %" PRIu64 "\n", div_c & ~SHIFT);
  printf("isID %" PRIu64 "\n", (div_c & SHIFT) >> 62);
  printf("rest id: %" PRIu64 "\n", rest & ~SHIFT);
  printf("isID %" PRIu64 "\n", (rest & SHIFT) >> 62);

  //Mod ein cached, ein uncached
  cachedInt mod_c = cached_int_mod(cache, justYet, notYet);
  printf("mod_c id: %" PRIu64 "\n", mod_c & ~SHIFT);
  printf("isID %" PRIu64 "\n", (mod_c & SHIFT) >> 62);

  //inverse ein cached, ein uncached
  cachedInt inv_c;
  int invertable = cached_int_invert(cache, justYet, notYet, &inv_c);
  printf("inv_c id: %" PRIu64 ", invertible %d\n", inv_c & ~SHIFT, invertable);
  printf("isID %" PRIu64 "\n", (inv_c & SHIFT) >> 62);
  //inverse overflow

  cache_clear(cache);
  free(cache);
  cache = NULL;
  mpz_clear(large);
  mpz_clear(small);
  mpz_clear(border_smaller);
  mpz_clear(border_greater);
  return 0;
}
