#include "hashtable.h"
#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  mpz_t val;
  mpz_init(val);
  mpz_set_si(val, 42);

  uint64_t* hashes;
  hashes = malloc(sizeof(uint64_t)*3);
  get_k_hashes(val, hashes);

  int i;
  for(i=0;i<3;i++){
    printf("Hash %" PRIu64 "\n", hashes[i]);
  }

  Hashtable* mytable;
  mytable = malloc(sizeof(Hashtable));
  create_hashtable(mytable, 5);
printf("size %" PRIu64 "\n", mytable->size);
  insert_element(mytable, 0, hashes);
  delete_hashtable(mytable);
  return 0;
}
