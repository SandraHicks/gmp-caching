#include "caching_operations.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_C 200

int main(int argc, char** argv) {

  lookup* cache  = malloc(sizeof(lookup));

  init_cache(cache, SIZE_C);

  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  mpz_t val2;
  mpz_init(val2);
  mpz_set_si(val2, 1337);

  mpz_t val3;
  mpz_init(val3);
  mpz_set_si(val3, 12345);

  uint64_t id = cache_insert_mpz(cache, val);
  uint64_t id2 = cache_insert_mpz(cache, val2);
  uint64_t id3 = cache_insert_mpz(cache, val3);

  printf("Val1: %f Val2: %f Val3: %f\n", get_double(cache, id), get_double(cache, id2), get_double(cache, id3));

  printf("Exists Val1?: %" PRIu64 "\n", cache_exists_mpz(cache, val));
  printf("Get Val1\n");
  
  mpz_t temp;
  mpz_init(temp);
  get_mpz(cache, id, temp);

  printf("temp %f\n", mpz_get_d(temp));

  mpz_t temp_noinit;
  get_mpz(cache, id, temp_noinit);

  printf("temp no init %f\n", mpz_get_d(temp_noinit));

  mpz_t val4;
  mpz_init(val4);
  mpz_set_si(val4, 10061992);
  printf("Val4: %f\n", mpz_get_d(val4));

  printf("Exists Val4?: %" PRIu64 "\n", cache_exists_mpz(cache, val4));

  delete_cache(cache);
  mpz_clear(val);
  mpz_clear(val2);
  mpz_clear(val3);
  mpz_clear(val4);
  mpz_clear(temp);
  mpz_clear(temp_noinit);
}
