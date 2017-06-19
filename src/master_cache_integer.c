 /**
  * @file master_cache_integer.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Integer operations in gmp
  */
#include <stdint.h> //always include first
#include <gmp.h>
#include <limits.h>
#include <stdlib.h>
#include <float.h>

#include "mastercache.h"
#include "master_cache_integer.h"
#include "caching_operations.h"
#include "overflow_detection.h"

//Debug
#include <stdio.h>
#include <inttypes.h>


/*local definitions*/
void get_mpz_from_id(MasterCache* mstr, cachedInt id, mpz_t mpz);

cachedInt direct_add(cachedInt val1, cachedInt val2);
cachedInt direct_mul(cachedInt val1, cachedInt val2);
cachedInt direct_div(cachedInt val1, cachedInt val2);
cachedInt direct_mod(cachedInt val1, cachedInt val2);
cachedInt direct_gcd(cachedInt val1, cachedInt val2);
cachedInt direct_lcm(cachedInt val1, cachedInt val2);
cachedInt direct_abs(cachedInt val);
cachedInt direct_invert(cachedInt val1, cachedInt val2);
void ext_euclid(cachedInt val1, cachedInt val2, cachedInt* d, cachedInt* s, cachedInt* t);

/**
 * @brief function for master cache to initialize
 * @param mstr MasterCache pointer
 * @param cachesize uint64_t with user defined size of the cache
 */
void cached_int_init_cache(MasterCache** mstr, uint64_t cachesize){
    (*mstr) = (MasterCache*)malloc(sizeof(MasterCache));
    MasterCacheInt* integers = malloc(sizeof(MasterCacheInt));
    (*mstr)->_integers = integers;
    
    lookup* cache  = malloc(sizeof(lookup));
    init_cache(cache, cachesize);
    (*mstr)->_integers->cache = cache;
}

/**
 * @brief function for master cache to clear all background data before free
 * @param mstr MasterCache pointer
 */
void cached_int_clear_cache(MasterCache** mstr){
    delete_cache((*mstr)->_integers->cache);
    free((*mstr)->_integers->cache);
    (*mstr)->_integers->cache = NULL;
    free((*mstr)->_integers);
    (*mstr)->_integers = NULL;
    free(*mstr);
    (*mstr) = NULL;
}



/**
 * (for internal use only!)
 * @param mstr
 * @param id
 * @param mpz
 */
void get_mpz_from_id(MasterCache* mstr, cachedInt id, mpz_t mpz){
    if((id & SHIFT) == 0){
        cached_int_mpz(id, mpz);
    }
    else{
        get_mpz(mstr->_integers->cache, id, mpz);
    }
}

/**
 * @brief function for master cache to set a mpz_t and get back an id
 * @param mstr MasterCache pointer
 * @param number number to cache
 * @return cachedInt id for cached mpz_t
 */
cachedInt cached_int_set(MasterCache* mstr, mpz_t number){
    cachedInt id = mpz_cached_int(number);
    
    if((id==SHIFT) && (number->_mp_size!=0)){
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
 * @brief function for master cache to get a previously cached mpz_t as double from an id
 * @param mstr MasterCache pointer
 * @param id cachedInt id that was cached
 * @return double the double representation of the mpz cached with id
 */
double cached_int_get_d(MasterCache* mstr, cachedInt id){
    //convert cachedInt to mpz if it is no id
    if((id & SHIFT) == 0){
        int64_t signed_id;
        if((id & NEG) >= 1){
            id = id & ~NEG;
            signed_id = (int64_t)(id);
            signed_id = signed_id * (-1);
        }
        else
            signed_id = id;
        
        return (double)signed_id;
    }
    else{
        return get_double(mstr->_integers->cache, id);
    }
}
/**
 * @brief function to negate a cachedInt
 * @param mstr MasterCache pointer
 * @param val cachedInt id of value to negate
 * @return negated id
 */
cachedInt cached_int_neg(MasterCache* mstr, cachedInt val){
    if((val & NEG) >= 1)
        return val & ~NEG;
    else
        return val | NEG;
}

/**
 * @brief function to get the absolute of a cachedInt
 * @param mstr MasterCache pointer
 * @param val cachedInt id of value to get absolute value
 * @return absolute value
 */
cachedInt cached_int_abs(MasterCache* mstr, cachedInt val){
    if((val & NEG) >= 1)
        return val & ~NEG;
    else
        return val;
}

/**
 * @brief function to get the sign of a cachedInt
 * @param mstr MasterCache pointer
 * @param val cachedInt id
 * @return 1 if positive, 0 if negative
 */
int cached_int_sgn(MasterCache* mstr, cachedInt val){
    if((val & NEG) >= 1)
        return 0;
    else
        return 1;
}
/**
 * (internal use only!)
 * @param val
 * @return 
 */
cachedInt direct_abs(cachedInt val){
    if((val & NEG) >= 1)
        return val & ~NEG;
    else
        return val;
}

/**
 * @brief function for master cache to add two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for addtion
 */
cachedInt cached_int_add(MasterCache* mstr, cachedInt val1, cachedInt val2){
    //add integers
    uint64_t result;
    //if val1 and val2 small: return Result as number if result < maxResult
    //if result > maxResult: cache and return ID
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_add(val1, val2);
        if(result != SHIFT){
            return result;
        }
        //in case of overflow go on to cached addition
    }
    
  //else: directly cache add
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    result = cached_mpz_add(mstr->_integers->cache, op1, op2);
   
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result or SHIFT if overflow
 */
cachedInt direct_add(cachedInt val1, cachedInt val2){
    int val1neg=0;
    if((val1 & NEG) >= 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    int val2neg=0;
    if((val2 & NEG) >= 1){
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
        //if val2neg = 0 (positive) and val1neg = 1 (negaive) -> swap
        if(val2neg < val1neg){
            uint64_t temp;
            temp = val2;
            val2 = val1;
            val1 = temp;
        }
        
        //no overflow possible if one value positive and one negative
        if(((int64_t)val1 - (int64_t)val2) < 0){
            return (val2 - val1) | NEG;
        }
        else{
            return val1 - val2;
        } 
    }
}
/**
 * @brief function for master cache to subtract two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for subtraction
 */
cachedInt cached_int_sub(MasterCache* mstr, cachedInt val1, cachedInt val2){
    if((val2 & NEG) >= 1){
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
 * @return cachedInt returns caching id or result for multiplication
 */
cachedInt cached_int_mul(MasterCache* mstr, cachedInt val1, cachedInt val2){
    uint64_t result;
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_mul(val1, val2);
        if(result != SHIFT){
            return result;
        }
        
        //in case of overflow go on to cached multiplication
    }
    
  //else: directly cache mul
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    result = cached_mpz_mul(mstr->_integers->cache, op1, op2);
   
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result or SHIFT if overflow
 */
cachedInt direct_mul(cachedInt val1, cachedInt val2){
    int val1neg=0;
    if((val1 & NEG) >= 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    int val2neg=0;
    if((val2 & NEG) >= 1){
        val2neg = 1;
        val2 = val2 & ~NEG;
    }
    
    if(!multiplicationOverflow(val1, val2)){
        if(val1neg < val2neg || val1neg > val2neg)
            return (val1 * val2) | NEG;
        else
            return (val1 * val2);
    }
    else
        return SHIFT;
}

/**
 * @brief function for master cache to divide two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param divident id of the first operand
 * @param divisor id of the second operand
 * @param rest pointer to id for rest of division
 * @return cachedInt returns caching id or result for division
 */
cachedInt cached_int_tdiv(MasterCache* mstr, cachedInt divident, cachedInt divisor, cachedInt* rest){
    if(divisor == 0)
        return SHIFT;
    
    cachedInt result;
    cachedInt mod;
    if(((divident & SHIFT) == 0) && ((divisor & SHIFT) == 0)){
        result = direct_div(divident, divisor);
        if(result != SHIFT){
            mod = direct_mod(divident, divisor);
            *rest = mod;
            return result;
        }
        
        //in case of overflow go on to cached division
    }
    
//else: directly cache div
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, divident, op1);
    get_mpz_from_id(mstr, divisor, op2);
    result = cached_mpz_tdiv(mstr->_integers->cache, rest, op1, op2);
   
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_div(cachedInt val1, cachedInt val2){
    int val1neg=0;
    if((val1 & NEG) >= 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    int val2neg=0;
    if((val2 & NEG) >= 1){
        val2neg = 1;
        val2 = val2 & ~NEG;
    }
    if(val2!=0){
        if(val1neg < val2neg || val1neg > val2neg)
            return (val1 / val2) | NEG;
        else
            return (val1 / val2);
    }
    else
        return SHIFT;
}

/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_mod(cachedInt val1, cachedInt val2){
    if((val1 & NEG) >= 1){
        val1 = val1 & ~NEG;
    }
    if((val2 & NEG) >= 1){
        val2 = val2 & ~NEG;
    }
    return val1 % val2;
}

/**
 * @brief function for master cache to calculate the modulo of two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param number id of the first operand
 * @param n id of the second operand
 * @return cachedInt returns caching id or result for mod
 */
cachedInt cached_int_mod(MasterCache* mstr, cachedInt number, cachedInt n){
    uint64_t result;
    
    if(((number & SHIFT) == 0) && ((n & SHIFT) == 0)){
        result = direct_mod(number, n);
        return result;
        
        //as the integer division rest is always smaller equals the number, it cannot overflow
    }
    
  //else: directly cache mod
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    
    get_mpz_from_id(mstr, number, op1);
    get_mpz_from_id(mstr, n, op2);
    result = cached_mpz_mod(mstr->_integers->cache, op1, op2);
   
    return result;
}


/**
 * @brief function for master cache to calculate the greatest common divisor of two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for gcd
 */
cachedInt cached_int_gcd(MasterCache* mstr, cachedInt val1, cachedInt val2){
    uint64_t result;
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_gcd(val1, val2);
        return result;
        
        //as gcd is always smaller equals the operands, it cannot overflow in direct calculation
    }
    
  //else: directly cache mod
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    result = cached_mpz_gcd(mstr->_integers->cache, op1, op2);
   
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_gcd(cachedInt val1, cachedInt val2){
    if((val1 & NEG) >= 1){
        val1 = val1 & ~NEG;
    }
    if((val2 & NEG) >= 1){
        val2 = val2 & ~NEG;
    }
    
    if(val2 == 0){
        return val1;
    }
    return direct_gcd(val2, val1 % val2);
}

/**
 * @brief function for master cache to calculate the least common multiple of two cached values and cache the result if large.
 * @param mstr MasterCaceh pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return result id
 */
cachedInt cached_int_lcm(MasterCache* mstr, cachedInt val1, cachedInt val2){
    uint64_t result;
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_lcm(val1, val2);
        if(result != SHIFT){
            return result;
        }
        
        //in case of overflow go to cached lcm
    }
    
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    result = cached_mpz_lcm(mstr->_integers->cache, op1, op2);
   
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_lcm(cachedInt val1, cachedInt val2){
    cachedInt mul = direct_mul(val1, val2);
    mul = direct_abs(mul);
    if(mul != SHIFT){
        cachedInt gcd = direct_gcd(val1, val2);
        cachedInt result = direct_div(mul, gcd);
        return result;
    }
    else{
        return SHIFT;
    }
}

/**
 * @brief function for master cache to calculate the inverse of a cached value mod n and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @param result pointer for returning result
 * @return int returns 0 if inverse does not exists, 1 if result is defined
 */
int cached_int_invert(MasterCache* mstr, cachedInt val1, cachedInt val2, cachedInt* result){
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        *result = direct_invert(val1, val2);
        //check for overflow
        if(*result != SHIFT)
            if(*result != 0){
                return 1;
            }
            else{
                return 0;
            }
        else{
            //there was an overflow when calculating the inverse
        }
        
        
    }
    
    cachedInt gcd = cached_int_gcd(mstr, val1, val2);
    if((gcd & ~SHIFT) != 1){
        return 0;
    }
    
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    *result = cached_mpz_invert(mstr->_integers->cache, op1, op2);
    return 1;
}

/**
 * (for internal use only!) invert modulo n
 * @param val1
 * @param val2
 * @return cachedInt result or SHIFT if overflow
 */
cachedInt direct_invert(cachedInt val1, cachedInt val2){
    cachedInt gcd = direct_gcd(val1, val2);
    if(gcd != 1)
        return 0;
    
    //extended euklid
    cachedInt d;
    cachedInt inverse;
    cachedInt t;
    ext_euclid(val1, val2, &d, &inverse, &t);
    
    //check inverse for overflow
    uint64_t check = (val1 * inverse) % val2;
    if(check == 1)
        return inverse;
    else
        return SHIFT;
}

/**
 * (for internal use only!) extended euclid
 * @param val1
 * @param val2
 * @param d
 * @param s
 * @param t
 */
void ext_euclid(cachedInt val1, cachedInt val2, cachedInt* d, cachedInt* s, cachedInt* t){
    if(val2 == 0){
        *d = val1;
        *s = 1;
        *t = 0;
    }
    cachedInt d_;
    cachedInt s_;
    cachedInt t_;
    ext_euclid(val2, val1 % val2, &d_, &s_, &t_);
    *d = d_;
    *s = t_;
    *t = s_ - (val1 / val2) * t_;
}
