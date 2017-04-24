#include "hashing.h"
#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printtoBinary(uint64_t val){
  printf("Binary: ");
  int i = 0;
  while(i<64){
  if(val & 1){
    printf("1");
  }
  else{
    printf("0");
  }
  val = val >> 1;
  i++;
  }
  printf("\n");
}

int main(int argc, char** argv) {
  mpz_t val;
  mpz_init(val);
  int number = atoi(argv[1]);
  printf("Number: %d\n", number);
  mpz_set_si(val, number);

  uint64_t hash = get_FNV1a_hash(val);
  uint64_t hash2 = get_Murmur_hash(val);
  uint64_t hash3 = get_CRC_hash(val);
  printf("H: %" PRIu64 "\n", hash3);
  printf("Test: ");
  printtoBinary(hash3);

  mpz_set_si(val, 123456789123456789l);
  hash = get_FNV1a_hash(val);
  hash2 = get_Murmur_hash(val);
  hash3 = get_CRC_hash(val);
  printf("H: %" PRIu64 "\n", hash3);
  printf("Test: ");
  printtoBinary(hash3);
  return 0;
}


