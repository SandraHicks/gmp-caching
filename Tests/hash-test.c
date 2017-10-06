#include "hashing.h"
#include "overflow_detection.h"
#include "defines.h"
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

void overflowTest(){
  uint64_t val1 = 549755813888;
  uint64_t val2 = 900719;

  int of = multiplicationOverflow(val1, val2);
  uint64_t res = val1 * val2;
  printf("overflow? %d Result: %" PRIu64 "\n", of, (res & (~SHIFT) & (~NEG)));
}

int main(int argc, char** argv) {
  /*mpz_t val;
  mpz_init(val);
  int number = atoi(argv[1]);
  printf("Number: %d\n", number);
  mpz_set_si(val, number);

printf("FNV1a\n");
  uint64_t hash = get_FNV1a_hash(val);
printf("MurMur\n");
  uint64_t hash2 = get_Murmur_hash(val);
printf("CRC\n");
  uint64_t hash3 = get_CRC_hash(val);
  printf("H1: %" PRIu64 "\n", hash);
  printf("H2: %" PRIu64 "\n", hash2);
  printf("H3: %" PRIu64 "\n", hash3);
  printf("Test: ");
  printtoBinary(hash3);

  mpz_set_si(val, 123456789123456789l);
  hash = get_FNV1a_hash(val);
  hash2 = get_Murmur_hash(val);
  hash3 = get_CRC_hash(val);
  printf("H: %" PRIu64 "\n", hash3);
  printf("Test: ");
  printtoBinary(hash3);*/
  overflowTest();
  return 0;
}



