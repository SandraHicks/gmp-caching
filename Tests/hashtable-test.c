#include "hashtable.h"
#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 7

int main(int argc, char** argv) {
  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  mpz_t val2;
  mpz_init(val2);
  mpz_set_si(val2, 1337);

  uint64_t* hashes;
  hashes = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val, hashes);

  uint64_t* hashes2;
  hashes2 = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val2, hashes2);

  int i;
  for(i=0;i<3;i++){
    printf("Hash %" PRIu64 "\n", hashes[i]);
  }

  Hashtable* mytable;
  mytable = malloc(sizeof(Hashtable));
  create_hashtable(mytable, SIZE);
printf("size %" PRIu64 "\n", mytable->size);

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }
  insert_element(mytable, 0, hashes);
  int exists = exists_element(mytable, hashes);
  printf("exists: %d\n", exists);

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }

  exists = exists_element(mytable, hashes2);
  printf("exists: %d\n", exists);

  insert_element(mytable, 1, hashes2);

  for(i=0;i<SIZE;i++){
    int counter = mytable->counter[i];
    printf("init counter %d %d\n", i, counter);
  }

  exists = exists_element(mytable, hashes2);
  printf("exists: %d\n", exists);

  delete_hashtable(mytable);
  return 0;
}
