#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpz_caching.h"

#define SIZE 7

int main(int argc, char** argv) {

  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  mpz_t val2;
  mpz_init(val2);
  mpz_set_si(val2, 1337);

  mpz_t_cache* mycache = malloc(sizeof(mpz_t_cache));
  init_mpz_cache(mycache, SIZE);

  int64_t id = insert_mpz(mycache, val);
  printf("ID %" PRIx64 "\n", id);
  printEntry(mycache, id);

  id = insert_mpz(mycache, val2);
  printf("ID %" PRIx64 "\n", id);
  printEntry(mycache, id);

  return 0;
}
