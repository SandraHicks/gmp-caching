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
  MasterCache* cache = malloc(sizeof(MasterCache));
  cached_int_init_cache(cache, SIZE_C);

  printf("1. create large mpz_t and cache\n");
  //Test large mpz_t
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
  uint64_t l_id;
  l_id = cached_int_set(cache, large);
  printf("large id: %" PRIu64 "\n",l_id);
  uint64_t l_id_stripped = l_id & ~SHIFT;
  printf("large id: %" PRIu64 "\n",l_id_stripped);
  printf("limb0: %lu\n", large->_mp_d[0]);
  printf("limb1: %lu\n", large->_mp_d[1]);

  printf("\n2. get large mpz_t back from cache\n");
  //get cached mpz_t
  mpz_t cached;
  mpz_init(cached);
  cached_int_get(cache, l_id, cached);
  int size = cached->_mp_size;
  printf("cached size: %d\n", size);
  printf("limb0: %lu\n", cached->_mp_d[0]);
  printf("limb1: %lu\n", cached->_mp_d[1]);

  uint64_t id_add = cached_int_add(cache, l_id, l_id);
  uint64_t id_add_stripped = id_add & ~SHIFT;
  printf("add id: %" PRIu64 "\n",id_add);
  printf("add id: %" PRIu64 "\n",id_add_stripped);

  printf("\n3. add in cache or direct mpz-function\n");
  //get added cached mpz_t
  mpz_t cachedadd;
  mpz_init(cachedadd);
  cached_int_get(cache, id_add, cachedadd);
  int sizeadd = cachedadd->_mp_size;
  printf("cached size: %d\n", sizeadd);
  printf("limb0: %lu\n", cachedadd->_mp_d[0]);
  printf("limb1: %lu\n", cachedadd->_mp_d[1]);

  //compare with adding
  mpz_t add;
  mpz_init(add);
  mpz_add(add, large, large);
  int sizeadd2 = add->_mp_size;
  printf("cached size: %d\n", sizeadd2);
  printf("limb0: %lu\n", add->_mp_d[0]);
  printf("limb1: %lu\n", add->_mp_d[1]);

  //check caching existence
  printf("\n4. caching existence\n");
  uint64_t id_add2 = cached_int_add(cache, l_id, l_id);
  printf("id: %" PRIu64 " exists %d\n",id_add2, (id_add == id_add2));
  mpz_clear(large);
  mpz_clear(cachedadd);
  mpz_clear(add);
  mpz_clear(cached);
  cached_int_clear_cache(cache);
return 0;


}
