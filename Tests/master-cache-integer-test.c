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


//PRIu64
int main(int argc, char** argv) {
  //TEST FOR CONVERSION
  /*uint64_t id = SHIFT - 1234;
  printf("id: %" PRIu64 "\n", id);
  id = id | SHIFT;
  mpz_t mpz;
  mpz_init(mpz);
  cached_int_mpz(id, mpz);
  printf("mpz: %f\n", mpz_get_d(mpz));

  uint64_t back;
  back = mpz_cached_int(mpz);
  printf("back id: %" PRIu64 "\n", back);
  mpz_clear(mpz);*/

  //TEST FOR MASTERCACHE

  MasterCache* cache;
  cached_int_init_cache(&cache, SIZE_C);

  //mpz_ts zum cachen
  mpz_t* integers;
  integers = malloc(sizeof(mpz_t) * MPZTS);
  mpz_t* integers_neg;
  integers_neg = malloc(sizeof(mpz_t) * MPZTS);

  cachedInt* ids = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_neg = malloc(sizeof(uint64_t) * MPZTS);

  cachedInt* ids_add = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_add_neg = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_sub = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_mul = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_mul_neg = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_div = malloc(sizeof(uint64_t) * MPZTS);
  cachedInt* ids_mod = malloc(sizeof(uint64_t) * MPZTS);

  //erstelle mpz_ts und füge zum cache hinzu
  int i;
  for(i=0; i < MPZTS; i++){
    mpz_init(integers[i]);
    mpz_set_si(integers[i], i);
    ids[i] = cached_int_set(cache, integers[i]);
  }
  for(i=0; i < MPZTS; i++){
    mpz_init(integers_neg[i]);
    mpz_set_si(integers_neg[i], -i);
    ids_neg[i] = cached_int_set(cache, integers_neg[i]);
  }

  for(i=0;i < MPZTS;i++){
    printf("id: %" PRIu64 " d: %f\n", ids[i], cached_int_get_d(cache, ids[i]));
    printf("id: %" PRIu64 " d: %f\n", ids_neg[i], cached_int_get_d(cache, ids_neg[i]));
  }


  //add test
  for(i=0;i<MPZTS;i++){
    ids_add[i] = cached_int_add(cache, ids[i], ids[i]);
    printf("i: %d, id: %" PRIu64 "\n",i, ids_add[i]);
  }

  //add test neg
  for(i=0;i<MPZTS;i++){
    ids_add_neg[i] = cached_int_add(cache, ids_neg[i], ids_neg[i]);
    printf("i: %d, id: %" PRIu64 "\n",i*-1, ids_add_neg[i]);
  }

  //sub test
  for(i=0;i<MPZTS;i++){
    ids_sub[i] = cached_int_sub(cache, ids[i], ids[MPZTS-i-1]);
    printf("i: %d, id: %" PRIu64 "\n",i, ids_sub[i]);
  }

  //mul test
  for(i=0;i<MPZTS;i++){
    ids_mul[i] = cached_int_mul(cache, ids[i], ids[i]);
    printf("i: %d, id: %" PRIu64 "\n",i, ids_mul[i]);
  }

  //mul test neg
  for(i=0;i<MPZTS;i++){
    ids_mul_neg[i] = cached_int_mul(cache, ids[i], ids_neg[i]);
    printf("i: %d, id: %" PRIu64 "\n",i, ids_mul_neg[i]);
  }

  //div test neg
  for(i=0;i<MPZTS;i++){
    ids_div[i] = cached_int_tdiv(cache, ids[i], ids[MPZTS-i-1], &ids_mod[i]);
    printf("%d / %d, id: %" PRIu64 " mod: %" PRIu64 "\n",i, MPZTS-i-1, ids_div[i], ids_mod[i]);
  }

  //lösche mpz_ts
  for(i=0; i < MPZTS; i++){
    mpz_clear(integers[i]);
    mpz_clear(integers_neg[i]);
  }


  free(ids);
  free(ids_neg);
  free(ids_add);
  free(ids_add_neg);
  free(ids_sub);
  free(ids_mul);
  free(ids_mul_neg);
  free(ids_div);
  free(ids_mod);
  cached_int_clear_cache(&cache);
  return 0;
}
