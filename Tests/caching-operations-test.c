#include "caching_operations.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_C 200

int main(int argc, char** argv) {
  lookup_table* table = malloc(sizeof(lookup_table));
  lookup_table_binary* table_binary = malloc(sizeof(lookup_table_binary));
  initCache(table, table_binary, SIZE_C);

  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  mpz_t val2;
  mpz_init(val2);
  mpz_set_si(val2, 1337);

  mpz_t val3;
  mpz_init(val3);
  mpz_set_si(val3, 12345);

  uint64_t id = cache_insert_mpz(table, val);
  uint64_t id2 = cache_insert_mpz(table, val2);
  uint64_t id3 = cache_insert_mpz(table, val3);

  printf("Val1: %f Val2: %f Val3: %f\n", get_double(table, id), get_double(table, id2), get_double(table, id3));

  printf("Exists Val1?: %d\n", cache_exists_mpz(table, val));

  mpz_t val4;
  mpz_init(val4);
  mpz_set_si(val4, 10061992);

  printf("Exists Val4?: %d\n", cache_exists_mpz(table, val4));
}
