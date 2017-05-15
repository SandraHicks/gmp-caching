 /**
  * @file master_cache_integer.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Integer operations in gmp
  */
#include <stdint.h> //always include first
#include <gmp.h>
#include <limits.h>

#include "defines.h"
#include "mastercache.h"
#include "master_cache_integer.h"
#include "caching_operations.h"
#include "overflow_detection.h"

//Debug
#include <stdio.h>
#include <inttypes.h>



/*local definitions*/
#define SHIFT ((uint64_t)1 << cachedInt_IsID)
#define NEG ((uint64_t)1 << cachedInt_SIGN)

cachedInt direct_add(cachedInt val1, cachedInt val2);
cachedInt direct_sub(cachedInt val1, cachedInt val2);

uint64_t mpz_cached_int(mpz_t number){
    int64_t cmp = cachedInt_MAX;
    int limbs = number->_mp_size;
    limbs = (limbs < 0) ? limbs*(-1) : limbs;
    
    
#if (GMP_NAIL_BITS == 0)
    uint64_t data = number->_mp_d[0];
    #if (GMP_LIMB_BITS < 62)
        //also get second limb
        data = data + (uint64_t)(number->_mp_d[1] << GMP_LIMB_BITS);
        if(data <= cachedInt_MAX)
            return data;
    #else
        if(data <= cachedInt_MAX)
            return data;
    #endif
#else //nail bits are enabled in GMP, nail bits are most significant
    uint64_t data = number->_mp_d[0];
    data = data & GMP_NUMB_MASK;
    
    #if (GMP_NUMB_BITS < 62)
        //also get second limb
        data = data + (uint64_t)((number->_mp_d[1] & GMP_NUMB_MASK) << GMP_NUMB_BITS);
        if(data <= cachedInt_MAX)
            return data
    #else
        if(data <= cachedInt_MAX)
            return data;
    #endif
#endif
    return 0;
}

void cached_int_mpz(cachedInt id, mpz_t number){
    id = id & (~SHIFT);
    if(id & NEG){
        id = id & ~NEG;
        int64_t input = (int64_t)id*(-1);
        mpz_import(number, 1, 1, sizeof(int64_t), 0, 0, &input);
    }
    else{
        int64_t input = (int64_t)id;
        mpz_import(number, 1, 1, sizeof(int64_t), 0, 0, &input);
    }    
}

/**
 * @brief function for master cache to set a mpz_t and get back an id
 * @param mstr MasterCache pointer
 * @param number number to cache
 */
cachedInt cached_int_set(MasterCache* mstr, mpz_t number){
    cachedInt id = mpz_cached_int(number);
    
    if(id==0){
        id = cache_insert_mpz(mstr->_integers->cache, number);
        return id;
    }
    
    if(number->_mp_size < 0)
        return id | NEG;
    else
        return id;
}
/**
 * @brief function for master cache to get a previously cached mpz_t from an id
 * @param mstr MasterCache pointer
 * @param id cachedInt id that was cached
 * @param number mpz_t number to set
 */
void cached_int_get(MasterCache* mstr, cachedInt id, mpz_t number){
    //convert cachedInt to mpz if it is no id
    if((id & SHIFT) == 0){
        mpz_init(number);
        cached_int_mpz(id, number);
    }
    else{
        get_mpz(mstr->_integers->cache, id, number);
    }
}

/**
 * @brief function for master cache to add two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt cached_int_add(MasterCache* mstr, cachedInt val1, cachedInt val2){
    //add integers
    uint64_t result;
    //if val1 and val2 small: return Result as number if result < maxResult
    //if result > maxResult: cache and return ID
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_add(val1, val2);
        if((result & SHIFT) == 0){
            return result;
        }
        mpz_t op1;
        mpz_t op2;
        mpz_t res;
        mpz_init(op1);
        mpz_init(op2);
        mpz_init(res);
        cached_int_mpz(val1, op1);
        cached_int_mpz(val2, op2);
        
        mpz_add(res, op1, op2);
        result = cache_insert_mpz(mstr->_integers->cache, res);
        
        return result;
    }
    
  //else: cache add
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz(mstr->_integers->cache, val1, op1);
    get_mpz(mstr->_integers->cache, val2, op2);
    result = cached_mpz_add(mstr->_integers->cache, op1, op2);
   
    return result;
}
cachedInt direct_add(cachedInt val1, cachedInt val2){
    int val1neg=0;
    if((val1 & NEG) == 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    int val2neg=0;
    if((val2 & NEG) == 1){
        val2neg = 1;
        val2 = val2 & ~NEG;
    }
    //case 1: both positive.
    if(val1neg == 0 && val2neg == 0){
        if(!additionOverflow(val1, val2)){
            return val1 + val2;
        }
        else{
            return SHIFT;
        }
    }
    //case 2: both negative
    else if(val1neg == 1 && val2neg == 1){
        if(!additionOverflow(val1, val2)){
            return (val1 + val2) | NEG;
        }
        else{
            return SHIFT;
        }
    }
    //case 3: one pos, one neg
    else{
        if(val1neg < val2neg){
            uint64_t temp;
            temp = val2;
            val2 = val1;
            val1 = temp;
        }
        if(!subtractionOverflow(val1, val2)){
            return val1 - val2;
        }
        else{
            return SHIFT;
        }
    }
}
/**
 * @brief function for master cache to subtract two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt cached_int_sub(MasterCache* mstr, cachedInt val1, cachedInt val2){
    if((val2 & NEG) == 1){
        return cached_int_add(mstr, val1, (val2 & ~NEG));
    }
    else{
        return cached_int_add(mstr, val1, (val2 | NEG));
    }
}

/**
 * @brief function for master cache to multiply two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 */
cachedInt cached_int_mul(MasterCache* mstr, cachedInt val1, cachedInt val2){
    return 0;
}

/**
 * @brief function for master cache to divide two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param divident id of the first operand
 * @param divisor id of the second operand
 * @param rest pointer to id for rest of division
 */
cachedInt cached_int_tdiv(MasterCache* mstr, cachedInt divident, cachedInt divisor, cachedInt* rest){
    return 0;
}

/**
 * @brief function for master cache to calculate the modulo of two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param number id of the first operand
 * @param n id of the second operand
 */
cachedInt cached_int_mod(MasterCache* mstr, cachedInt number, cachedInt n){
    return 0;
}

/**
 * @brief function for master cache to calculate the greatest common divisor of two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param operand1 id of the first operand
 * @param operand2 id of the second operand
 */
cachedInt cached_int_gcd(MasterCache* mstr, cachedInt operand1, cachedInt operand2){
    return 0;
}

/**
 * @brief function for master cache to calculate the inverse of a cached value mod n and cache the result if large.
 * @param mstr MasterCache pointer
 * @param number id of the first operand
 * @param n id of the second operand
 */
cachedInt cached_int_invers(MasterCache* mstr, cachedInt number, cachedInt n){
    return 0;
}