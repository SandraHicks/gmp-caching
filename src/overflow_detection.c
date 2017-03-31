 /**
  * @file overflow_detection.c
  * @author Sandra Hicks
  * @brief Functions to detect overflows in integer operations
  */

#include <stdint.h>
#include "overflow_detection.h"
#include "defines.h"

#define MAXBIT 62

uint32_t MSB(cachedInt val);
cachedInt deleteIdBit(cachedInt val);

/**
 * @brief function to predict if an addition will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
bool additionOverflow(cachedInt op1, cachedInt op2){
    //check sign for problems
    bool sign = (op1 <= 0 && op2 >= 0) || (op2 <= 0 && op1 >= 0);
    if(sign)
        return 0;
    
    //first check based on msb
    int msb_op1 = MSB(op1);
    int msb_op2 = MSB(op2);
    if(msb_op1 < 62 && msb_op2 < 62){
        return 0;
    }
    
    //second check based on result
    op1 = deleteIdBit(op1);
    op2 = deleteIdBit(op2);
    cachedInt res = op1 + op2;
    cachedInt backwards = res - op1;
    if(backwards != op2){
        return 1;
    }
    return 0;
}

/**
 * @brief function to predict if a subtraction will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
bool subtractionOverflow(cachedInt op1, cachedInt op2){
    //check sign for problems
    additionOverflow(op1, op2*(-1));
}

/**
 * @brief function to predict if a multiplication will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
bool multiplicationOverflow(cachedInt op1, cachedInt op2){
    //first check based on msb
    int msb_op1 = MSB(op1);
    int msb_op2 = MSB(op2);
    if(msb_op1*msb_op2 < 62){
        return 0;
    }
    //second check based on result
    op1 = deleteIdBit(op1);
    op2 = deleteIdBit(op2);
    cachedInt res = op1*op2;
    cachedInt backwards = res/op1;
    if(backwards != op2){
        return 1;
    }
    return 0;
}

/**
 * @brief function to predict if a division will overflow
 * @param op1 first operator
 * @param op2 second operator
 */
bool divisionOverflow(cachedInt op1, cachedInt op2){
    return 0;
}

/**
 * @brief function to predict if an exponentiation will overflow
 * @param base first operator, base
 * @param exp second operator, exponent
 */
bool exponentiationOverflow(cachedInt base, cachedInt exp){
    //first check based on msb
    int msb_op1 = MSB(base);
    if(!multiplicationOverflow(msb_op1, exp)){
        if(msb_op1*exp < 62)
            return 0;
        
        //check based on result
        cachedInt res = base^exp;
        //backwards TODO
        if(res){
            return 0;
        }
    }
    return 1;
}

int MSB(cachedInt val){
  //get unsigned
  if(val < 0)
      val = val*(-1)
  //delete isID bit
  val = deleteIdBit(val);
  
  //get size of a long long on the current machine
  int size_ll = sizeof(unsigned long long);
  unsigned long long check = (unsigned long long)val;
  
  //built-in function of gcc, param unsigned long long, returns number of leading zeros
  int number_of_zeros = __builtin_clzll(check);
  int difference = size_ll - number_of_zeros;
  return difference-1;
}

cachedInt deleteIdBit(cachedInt val){
    return (val & cachedInt_IsID) ? (val & (~(1<<62))): val;
}