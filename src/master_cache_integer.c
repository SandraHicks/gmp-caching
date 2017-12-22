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
#include <assert.h>

#include "mastercache.h"
#include "master_cache_integer.h"
#include "caching_operations.h"
#include "overflow_detection.h"

//Debug
#include <stdio.h>
#include <inttypes.h>


/*local definitions*/
void get_mpz_from_id(const MasterCache* mstr, cachedInt id, mpz_t mpz);

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
void get_mpz_from_id(const MasterCache* mstr, cachedInt id, mpz_t mpz){
    if(id == NaN || id == PLUS_INFINITY || id == MINUS_INFINITY)
        return;

    if((id & SHIFT) >= 1)
        get_mpz(mstr->_integers->cache, id, mpz);
    else
        cached_int_mpz(id, mpz);
}

/**
 * @brief function for master cache to set a mpz_t and get back an id
 * @param mstr MasterCache pointer
 * @param number number to cache
 * @return cachedInt id for cached mpz_t
 */
cachedInt cached_int_set(const MasterCache* mstr, const mpz_t number){
    cachedInt id = mpz_cached_int(number);

    if((id==SHIFT) && (number->_mp_size!=0)){
        return cache_insert_mpz(mstr->_integers->cache, number);;
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
void cached_int_get(const MasterCache* mstr, cachedInt id, mpz_t number){
    if(id == NaN || id == PLUS_INFINITY || id == MINUS_INFINITY)
        return;
    
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
 * @brief function for master cache to get a previously cached mpz_t as double from an id, has the same behaviour as the mpz_get_double
 * @param mstr MasterCache pointer
 * @param id cachedInt id that was cached
 * @return double the double representation of the mpz_t cached with id
 */
double cached_int_get_d(const MasterCache* mstr, cachedInt id){
    //convert cachedInt to mpz if it is no id
    if(id == NaN || id == PLUS_INFINITY || id == MINUS_INFINITY){
        return 0.0;
    }
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
cachedInt cached_int_neg(const MasterCache* mstr, cachedInt val){
    return ((val & NEG) >= 1) ? (val & ~NEG) : (val | NEG);
}

/**
 * @brief function to get the absolute of a cachedInt
 * @param mstr MasterCache pointer
 * @param val cachedInt id of value to get absolute value
 * @return absolute value
 */
cachedInt cached_int_abs(const MasterCache* mstr, cachedInt val){
    return ((val & NEG) >= 1) ? (val & ~NEG) : val;
}

/**
 * @brief function to get the sign of a cachedInt
 * @param mstr MasterCache pointer
 * @param val cachedInt id
 * @return 1 if positive, 0 if negative
 */
int cached_int_sgn(const MasterCache* mstr, cachedInt val){
    if(val == 0)
        return 0;
    
    return (((val & NEG) >= 1) ? 0 : 1);
}
/**
 * (internal use only!)
 * @param val
 * @return 
 */
cachedInt direct_abs(cachedInt val){
    return ((val & NEG) >= 1) ? (val & ~NEG) : val;
}

/**
 * @brief function for master cache to add two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for addtion
 */
cachedInt cached_int_add(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    if(val1 == NaN || val2 == NaN){
        return NaN;
    }
    
    if(val1 == 0){
        return val2;
    }
    
    if(val2 == 0){
        return val1;
    }
    //add integers
    uint64_t result;
    
    //check for infinities
    if(val1 == PLUS_INFINITY){
        return (val2 == MINUS_INFINITY) ? (SHIFT | NEG) : PLUS_INFINITY;
    }
    if(val1 == MINUS_INFINITY){
        return (val2 == PLUS_INFINITY) ? (SHIFT | NEG) : MINUS_INFINITY;
    }
    //if val1 and val2 small: return Result as number if result < maxResult
    //if result > maxResult: cache and return ID
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        result = direct_add(val1, val2);
        if(result != SHIFT){
            return result;
        }
        //in case of overflow go on to cached addition
    }
    
    /*printf("iadd1: %" PRIu64 "\n",val1);
    printf("iadd1-: %" PRIu64 "\n",(val1 & ~NEG));
    printf("iadd1-s: %" PRIu64 "\n",((val1 & ~NEG) & ~SHIFT));
    printf("iadd2: %" PRIu64 "\n",val2);
    printf("iadd2-: %" PRIu64 "\n",(val2 & ~NEG));
    printf("iadd2-s: %" PRIu64 "\n",((val2 & ~NEG) & ~SHIFT));*/
  //else: cache add
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    //gmp_printf("op1: %Zd\n", op1);
    get_mpz_from_id(mstr, val2, op2);
    //gmp_printf("op2: %Zd\n", op2);
    result = cached_mpz_add(mstr->_integers->cache, op1, op2);
//printf("iaddresult: %" PRIu64 "\n",result);
//printf("iaddresult-: %" PRIu64 "\n",(result & ~NEG));
//printf("iaddresult-s: %" PRIu64 "\n",((result & ~NEG) & ~SHIFT));
    return result;
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result or SHIFT if overflow
 */
cachedInt direct_add(cachedInt val1, cachedInt val2){
    unsigned short val1neg=0;
    if((val1 & NEG) >= 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    unsigned short val2neg=0;
    if((val2 & NEG) >= 1){
        val2neg = 1;
        val2 = val2 & ~NEG;
    }
    //case 1: both positive.
    if(val1neg == 0 && val2neg == 0){
        return (!additionOverflow(val1, val2)) ? (val1 + val2) : SHIFT;
    }
    //case 2: both negative
    else if(val1neg == 1 && val2neg == 1){
        return (!additionOverflow(val1, val2)) ? ((val1 + val2) | NEG) : SHIFT;
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
        return (((int64_t)val1 - (int64_t)val2) < 0) ? ((val2 - val1) | NEG) : val1 - val2;
    }
}
/**
 * @brief function for master cache to subtract two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for subtraction
 */
cachedInt cached_int_sub(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    if((val2 & NEG) >= 1){
        return cached_int_add(mstr, val1, (val2 & ~NEG));
    }
    else if(val2 == 0){
        return val1;
    }
    else if(val1 == 0){
        return (val2 | NEG);
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
cachedInt cached_int_mul(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    if(val1 == NaN || val2 == NaN){
        return NaN;
    }
    
    if(val1 == 0 || val2 == 0){
        return 0;
    }
    
    uint64_t result;
    
    //check for infinities
    // inf*(sign)x = (sign)inf, -inf*(sign)x = -(sign)inf
    
    //at least one number is infinity
    if((val1 == PLUS_INFINITY) || (val2 == PLUS_INFINITY) || (val1 == MINUS_INFINITY) || (val2 == MINUS_INFINITY)){
        //both are negative
        if(((val1 & NEG) > 0) && ((val2 & NEG) > 0)){
            return PLUS_INFINITY;
        }
        
        if(((val1 & NEG) > 0) || ((val2 & NEG) > 0)){
            return MINUS_INFINITY;
        }
        return PLUS_INFINITY;
    }
    
    
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        //printf("direct mul: c=%"PRIu64" d=%"PRIu64"\n", val1, val2);
        result = direct_mul(val1, val2);
        if(result != SHIFT){
            return result;
        }
        
        //in case of overflow go on to cached multiplication
    }
    
    /*printf("mul1: %" PRIu64 "\n",val1);
    printf("mul1-: %" PRIu64 "\n",(val1 & ~NEG));
    printf("mul1-s: %" PRIu64 "\n",((val1 & ~NEG) & ~SHIFT));
    printf("mul2: %" PRIu64 "\n",val2);
    printf("mul2: %" PRIu64 "\n",val2);*/
  //else: directly cache mul
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);

    result = cached_mpz_mul(mstr->_integers->cache, op1, op2);
//printf("mulres: %" PRIu64 "\n",result);
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
    
    if(multiplicationOverflow(val1, val2) < 1){
        if(val1neg != val2neg)
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
cachedInt cached_int_tdiv(const MasterCache* mstr, cachedInt divident, cachedInt divisor, cachedInt* rest){
    if(divident == NaN || divisor == NaN){
        return NaN;
    }
    
    assert(divisor != 0);
    
    if(divident == 0){
        *rest = (uint64_t)0;
        return (uint64_t)0;
    }
    
    if(divisor == 1){
        *rest = (uint64_t)0;
        return divident;
    }
    
    //check for inifinity on divident
    if(((divident == PLUS_INFINITY) || (divident == MINUS_INFINITY)) && ((divisor != PLUS_INFINITY) && (divisor != MINUS_INFINITY))){
        return divident;
    }
    if(((divident == PLUS_INFINITY) || (divident == MINUS_INFINITY)) && ((divisor == PLUS_INFINITY) || (divisor == MINUS_INFINITY))){
        printf("Error: ------------ NaN!--------------6\n");
        return NaN;
    }
    //only infinity on divisor -> 0
    if((divisor == PLUS_INFINITY) || (divisor == MINUS_INFINITY)){
        return 0;
    }
    
    cachedInt result;
    cachedInt mod;
    if(((divident & SHIFT) == 0) && ((divisor & SHIFT) == 0)){
        result = direct_div(divident, divisor);
        if(result != SHIFT){
            mod = direct_mod(divident, divisor);
            *rest = mod;
            //printf("div result: %" PRIu64 "\n", result);
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
 * (for internal use only!) no check if divisor 0
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_div(cachedInt val1, cachedInt val2){
    unsigned short val1neg=0;
    if((val1 & NEG) >= 1){
        val1neg = 1;
        val1 = val1 & ~NEG;
    }
    unsigned short val2neg=0;
    if((val2 & NEG) >= 1){
        val2neg = 1;
        val2 = val2 & ~NEG;
    }
    
    return (val1neg != val2neg) ? ((val1 / val2) | NEG) : (val1 / val2);
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
cachedInt cached_int_mod(const MasterCache* mstr, cachedInt number, cachedInt n){
    assert((n!=0)&& ((number != PLUS_INFINITY) && (number != MINUS_INFINITY)) && ((n != PLUS_INFINITY) && (n != MINUS_INFINITY)) && (number != NaN && n != NaN));
    
    if(number == 0){
        return 0;
    }
    
    if(((number & SHIFT) == 0) && ((n & SHIFT) == 0)){
        return direct_mod(number, n);
        //as the integer division rest is always smaller equals the number, it cannot overflow
    }
    
  //else: directly cache mod
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    
    get_mpz_from_id(mstr, number, op1);
    get_mpz_from_id(mstr, n, op2);
   
    return cached_mpz_mod(mstr->_integers->cache, op1, op2);
}


/**
 * @brief function for master cache to calculate the greatest common divisor of two cached values and cache the result if large.
 * @param mstr MasterCache pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return cachedInt returns caching id or result for gcd
 */
cachedInt cached_int_gcd(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    assert(((val1 != PLUS_INFINITY) && (val1 != MINUS_INFINITY)) && ((val2 != PLUS_INFINITY) && (val2 != MINUS_INFINITY)) && (val1 != NaN && val2 != NaN));
    //printf("gcd1: %" PRIu64 "\n",val1);
    //printf("gcd2: %" PRIu64 "\n",val2);
    
    if(val1 == 0){
        return val2 & ~NEG;
    }
    else if(val2 == 0){
        return val1 & ~NEG;
    }
    else if(val1 == 0 && val2 == 0){
        return 0;
    }
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        return direct_gcd(val1, val2);
        
        //as gcd is always smaller equals the operands, it cannot overflow in direct calculation
    }
    
  //else: directly cache mod
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    //printf("gcd1a: %" PRIu64 "\n",val1);
    //printf("gcd2a: %" PRIu64 "\n",val2);
    get_mpz_from_id(mstr, val1, op1);
    get_mpz_from_id(mstr, val2, op2);
    return cached_mpz_gcd(mstr->_integers->cache, op1, op2);
}
/**
 * (for internal use only!)
 * @param val1
 * @param val2
 * @return cachedInt result
 */
cachedInt direct_gcd_slow(cachedInt val1, cachedInt val2){
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

cachedInt direct_gcd(cachedInt val1, cachedInt val2){
    while(val2) val2 ^= val1 ^= val2 ^= val1 %= val2;
    return val1;
}

/**
 * @brief function for master cache to calculate the least common multiple of two cached values and cache the result if large.
 * @param mstr MasterCaceh pointer
 * @param val1 id of the first operand
 * @param val2 id of the second operand
 * @return result id
 */
cachedInt cached_int_lcm(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    assert(((val1 != PLUS_INFINITY) && (val1 != MINUS_INFINITY)) && ((val2 != PLUS_INFINITY) && (val2 != MINUS_INFINITY)) && (val1 != NaN && val2 != NaN));
    
    if(val1 == 0 || val2 == 0){
        return 0;
    }
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        uint64_t result;
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
   
    return cached_mpz_lcm(mstr->_integers->cache, op1, op2);
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
        cachedInt result = direct_div(mul, direct_gcd(val1, val2));
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
int cached_int_invert(const MasterCache* mstr, cachedInt val1, cachedInt val2, cachedInt* result){
    assert((val2 != 0) && ((val1 != PLUS_INFINITY) && (val1 != MINUS_INFINITY)) && ((val2 != PLUS_INFINITY) && (val2 != MINUS_INFINITY)) && val1 != NaN && val2 != NaN);
    
    if(val1 == 0){
        *result = 0;
        return 0;
    }
    
    if(((val1 & SHIFT) == 0) && ((val2 & SHIFT) == 0)){
        *result = direct_invert(val1, val2);
        //check for overflow
        if(*result != SHIFT)
            return (*result != 0) ? 1 : 0;
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

/**
 * check if a cachedInt is a number or points to a cache
 * @param val
 * @return true if the cachedInt is an ID to the cache
 */
int cached_int_isID(cachedInt val){
    return ((val & SHIFT) == 0) ? 0 : 1;
}

/**
 * comparison function for cachedInts
 * @param mstr MasterCache
 * @param val1
 * @param val2
 * @return 1 if val1 > val2, 0 if equals, -1 if val2 > val2
 */
int cached_int_cmp(const MasterCache* mstr, cachedInt val1, cachedInt val2){
    assert(val1 != NaN && val2 != NaN);
    if(val1 == PLUS_INFINITY && val2 == MINUS_INFINITY){
        return 1;
    }
    else if(val1 == MINUS_INFINITY && val2 == PLUS_INFINITY){
        return -1;
    }
    else if(val1 == PLUS_INFINITY && val2 != PLUS_INFINITY && val2 != MINUS_INFINITY){
        return 1;
    }
    else if(val1 == MINUS_INFINITY && val2 != PLUS_INFINITY && val2 != MINUS_INFINITY){
        return -1;
    }
    else if(val2 == PLUS_INFINITY && val1 != PLUS_INFINITY && val1 != MINUS_INFINITY){
        return -1;
    }
    else if(val2 == MINUS_INFINITY && val1 != PLUS_INFINITY && val1 != MINUS_INFINITY){
        return 1;
    }
    else if(val1 == PLUS_INFINITY && val2 == PLUS_INFINITY){
        return 0;
    }
    else if(val1 == MINUS_INFINITY && val2 == MINUS_INFINITY){
        return 0;
    }
    
    cachedInt diff = cached_int_sub(mstr, val1, val2);
    if((diff & NEG) >= 1 && ((diff & ~NEG) != 0) && (diff!=0)){
        return -1;
    }
    else if((diff & ~NEG) == 0){
        return 0;
    }
    else{
        return 1;
    }
    
}

/**
 * compare cachedInt with int
 * @param mstr
 * @param val1 cachedInt
 * @param val2 int
 * @return 1 if val1 > val2, 0 if equals and -1 if val2 > val1
 */
int cached_int_cmp_i(const MasterCache* mstr, cachedInt val1, int val2){
    if(cached_int_isID(val1))
        return 1;
    
    uint64_t convert;
    if(val2 < 0){
        val2 = val2 * (-1);
        convert = (uint64_t) val2 | NEG;
    }
    return cached_int_cmp(mstr, val1, convert);
}

/**
 * compare cachedInt with double
 * @param mstr
 * @param val1 cachedInt
 * @param val2 double
 * @return 1 if val1 > val2, 0 if equals and -1 if val2 > val1
 */
int cached_int_cmp_d(const MasterCache* mstr, cachedInt val1, double val2){
    double d = cached_int_get_d(mstr, val1);
    double diff = d - val2;
    if(diff > 0){
        return 1;
    }
    else if(diff < 0){
        return -1;
    }
    else{
        return 0;
    }
}
