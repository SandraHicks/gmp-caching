#include "master_cache_integer.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE_C 1000
#define MPZTS 10

#define SHIFT ((uint64_t)1 << 62)
#define NEG ((uint64_t)1 << cachedInt_SIGN)


//PRIu64
int main(int argc, char** argv) {
  uint64_t id = SHIFT - 1234;
  printf("id: %" PRIu64 "\n", id);
  id = id | SHIFT;
  mpz_t mpz;
  mpz_init(mpz);
  cached_int_mpz(id, mpz);
  printf("mpz: %f\n", mpz_get_d(mpz));

  uint64_t back;
  back = mpz_cached_int(mpz);
  printf("back id: %" PRIu64 "\n", back);
  mpz_clear(mpz);
  return 0;
}
