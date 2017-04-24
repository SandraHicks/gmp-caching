#include "hashtable.h"
#include "mpz_caching.h"
#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7
#define SIZE_C 20

int main(int argc, char** argv) {
  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  mpz_t val2;
  mpz_init(val2);
  mpz_set_si(val2, 1337);

  mpz_t val3;
  mpz_init(val3);
  mpz_set_si(val3, 1337);

  uint64_t* hashes;
  hashes = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val, hashes);

  uint64_t* hashes2;
  hashes2 = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val2, hashes2);

  uint64_t* hashes3;
  hashes3 = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val3, hashes3);

  int i;
  for(i=0;i<3;i++){
    printf("Hash %" PRIu64 "\n", hashes[i]);
  }

  Hashtable* mytable;
  mytable = malloc(sizeof(Hashtable));
  create_hashtable(mytable, SIZE);
printf("size %" PRIu64 "\n", mytable->size);

  mpz_t_cache* mycache = malloc(sizeof(mpz_t_cache));
  init_mpz_cache(mycache, SIZE_C);

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }
  int64_t id = insert_mpz(mycache, val);
  if(id >= 0){
    insert_element(mytable, (uint64_t)id, hashes);
  }
  
  int exists = exists_element(mytable, hashes, val, mycache);
  printf("exists 42: %d\n", exists);

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }

  exists = exists_element(mytable, hashes2, val2, mycache);
  printf("exists 1337: %d\n", exists);

  id = insert_mpz(mycache, val2);
  if(id >= 0){
    insert_element(mytable, (uint64_t)id, hashes2);
  }

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }

  exists = exists_element(mytable, hashes2, val2, mycache);
  printf("exists 1337: %d\n", exists);

  id = insert_mpz(mycache, val3);
  if(id >= 0){
    insert_element(mytable, (uint64_t)id, hashes3);
  }


  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }

  delete_hashtable(mytable);
  return 0;
}
