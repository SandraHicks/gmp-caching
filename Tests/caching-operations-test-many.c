#include "caching_operations.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_C 2000

int main(int argc, char** argv) {

  lookup* cache  = malloc(sizeof(lookup));

  init_cache(cache, SIZE_C);

  mpz_t* integers;
  integers = malloc(sizeof(mpz_t) * 19);

  uint64_t* ids = malloc(sizeof(uint64_t) * 19);
  uint64_t* add_ids = malloc(sizeof(uint64_t) * 19*19);
  int i;
  for(i=0; i < 19; i++){
    mpz_init(integers[i]);
    mpz_set_si(integers[i], i);
    ids[i] = cache_insert_mpz(cache, integers[i]);
  }

  for(i=0; i < 19; i++){
    printf("Exists %d: %" PRIu64 "\n", i, cache_exists_mpz(cache, integers[i]));
  }

  
  for(i=0; i < 19; i++){
    int j;
    for(j=0; j < 19; j++){
      add_ids[i+j] = cached_mpz_add(cache, integers[i], integers[j]);
      printf("%d + %d =%f\n",i,j, get_double(cache, add_ids[i+j]));
    }
  }

  delete_cache(cache);
  for(i=0; i < 19; i++){
    mpz_clear(integers[i]);
  }
}
