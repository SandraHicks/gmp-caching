 /**
  * @file overflow_detection.c
  * @author Sandra Hicks
  * @brief Functions to detect overflows in integer operations
  */

#include <stdint.h>
#include "overflow_detection.h"
#include "defines.h"

/** maximal bit to be set before overflow*/
#define MAXBIT 62

/*local definitions*/

//debug
#include <stdio.h>
#include <inttypes.h>

uint32_t MSB(cachedInt val);
cachedInt deleteIdBit(cachedInt val);

/**
 * @brief function to predict if an addition will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
int additionOverflow(cachedInt op1, cachedInt op2){
    
    //first check based on msb
    int msb_op1 = MSB(op1);
    int msb_op2 = MSB(op2);
    if(msb_op1 < 61 && msb_op2 < 61){
        return 0;
    }
    return 1;
}

//if the sign is constant, there is no subtraction overflow


/**
 * @brief function to predict if a multiplication will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
int multiplicationOverflow(cachedInt op1, cachedInt op2){
    //first check based on msb
    int msb_op1 = MSB(op1);
    int msb_op2 = MSB(op2);
    if(msb_op1+msb_op2 <= 61){
        return 0;
    }
    return 1;
}

//there is no integer division overflow

/**
 * @brief function to predict if an exponentiation will overflow
 * @param base first operator, base
 * @param exp second operator, exponent
 */
int exponentiationOverflow(cachedInt base, cachedInt exp){
    //first check based on msb
    int msb_op1 = MSB(base);
    if(!multiplicationOverflow(msb_op1, exp)){
        if(msb_op1*exp < 61)
            return 0;
        
    }
    return 1;
}
/**
 * (for internal use only!)
 * @param val
 * @return 
 */
uint32_t MSB(cachedInt val){
  //get unsigned
  if(val < 0)
      val = val*(-1);
  //delete isID bit
  val = deleteIdBit(val);
  
  //get size of a long long on the current machine
  int size_ll = sizeof(unsigned long long);
  size_ll = size_ll*8;
  unsigned long long check = (unsigned long long)val;
  
  //built-in function of gcc, param unsigned long long, returns number of leading zeros
  int number_of_zeros = __builtin_clzll(check);
  int difference = size_ll - number_of_zeros;
  return difference-1;
}

/**
 * (for internal use only!)
 * @param val
 * @return 
 */
cachedInt deleteIdBit(cachedInt val){
    return val & ~(SHIFT);
}