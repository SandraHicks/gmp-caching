#include "caching_operations.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <time.h>

#define SIZE_C 1000
#define MPZTS 10

//tdiv, gcd, invert tests

int main(int argc, char** argv) {

  //cache erstellen
  lookup* cache  = malloc(sizeof(lookup));

  //cache initialisieren
  init_cache(cache, SIZE_C);

  //mpz_ts zum cachen
  mpz_t* integers;
  integers = malloc(sizeof(mpz_t) * MPZTS);
  mpz_t* integers_neg;
  integers_neg = malloc(sizeof(mpz_t) * MPZTS);


  //speichern der ids
  uint64_t* ids = malloc(sizeof(uint64_t) * MPZTS);
  uint64_t* ids_neg = malloc(sizeof(uint64_t) * MPZTS);
  uint64_t* tdiv_ids_q = malloc(sizeof(uint64_t) * MPZTS*MPZTS);
  uint64_t* tdiv_ids_r = malloc(sizeof(uint64_t) * MPZTS*MPZTS);
  uint64_t* mod_ids = malloc(sizeof(uint64_t) * MPZTS*MPZTS);
  uint64_t* gcd_ids = malloc(sizeof(uint64_t) * MPZTS*MPZTS);
  uint64_t* inv_ids = malloc(sizeof(uint64_t) * MPZTS*MPZTS);
  //erstelle mpz_ts und füge zum cache hinzu
  int i;
  for(i=0; i < MPZTS; i++){
    mpz_init(integers[i]);
    mpz_set_si(integers[i], i);
    ids[i] = cache_insert_mpz(cache, integers[i]);
  }
  for(i=0; i < MPZTS; i++){
    mpz_init(integers_neg[i]);
    mpz_set_si(integers_neg[i], -i);
    ids_neg[i] = cache_insert_mpz(cache, integers_neg[i]);
  }



  clock_t c0 = clock();
  //dividiere/mod/inv jeweils zwei mpz_ts
  for(i=0; i < MPZTS; i++){
    int j;
    for(j=0; j < MPZTS; j++){
      tdiv_ids_q[i*10+j] = cached_mpz_tdiv(cache, &tdiv_ids_r[i*10+j], integers[i], integers[j]);
      mod_ids[i*10+j] = cached_mpz_mod(cache, integers[i], integers[j]);
      inv_ids[i*10+j] = cached_mpz_invert(cache, integers[i], integers[j]);
      gcd_ids[i*10+j] = cached_mpz_gcd(cache, integers[i], integers[j]);
    }
  }
  clock_t end = clock();
  double runtime_diff_ms = (end - c0) * 1000. / CLOCKS_PER_SEC;
  printf("end time %f\n", runtime_diff_ms);
  uint64_t test = tdiv_ids_r[0];
  //gebe werte aus
  for(i=0; i < MPZTS; i++){
    int j;
    for(j=0; j < MPZTS; j++){
      printf("ID %d %d: %" PRIu64 " inv: %f\n",i,j, inv_ids[i*10+j], get_double(cache, inv_ids[i*10+j]));
      //printf("result: %f\n", get_double(cache, tdiv_ids_q[i*10+j]));
      //printf("r_id: %" PRIu64 "\n", tdiv_ids_r[i*10+j]);
      //printf("gcd: %f.\n", get_double(cache, gcd_ids[i*10+j])); 
    }
  }

  //lösche cache
  delete_cache(cache);

  //lösche mpz_ts
  for(i=0; i < MPZTS; i++){
    mpz_clear(integers[i]);
    mpz_clear(integers_neg[i]);
  }

  free(integers);
  integers = NULL;
  free(integers_neg);
  integers_neg = NULL;
  free(ids);
  ids = NULL;
  free(ids_neg);
  ids_neg = NULL;
  free(tdiv_ids_q);
  tdiv_ids_q = NULL;
  free(tdiv_ids_r);
  tdiv_ids_r = NULL;
  free(mod_ids);
  mod_ids = NULL;
  free(gcd_ids);
  gcd_ids = NULL;
  free(inv_ids);
  inv_ids = NULL;
}
