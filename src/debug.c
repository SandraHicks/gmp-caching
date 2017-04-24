#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "debug.h"

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
