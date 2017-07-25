 /**
  * @file master_cache_rational.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Rational operations in gmp
  */
#include <gmp.h>
#include <stdlib.h>

#include "master_cache_rational.h"


/**
 * 
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @return cachedRational
 */
cachedRational cached_rational_set(const MasterCache* mstr, mpz_t counter, mpz_t denominator){
    cachedRational val;
    val.counter = cached_int_set(mstr, counter);
    val.denominator = cached_int_set(mstr, denominator);
    
    return val;
}
cachedRational cached_rational_set_i(const MasterCache* mstr, int i){
    cachedRational val;
    if(i>0){
            val.counter = (uint64_t)i;
            val.denominator = 0;
    }
    else{
        val.counter = (uint64_t)(i*-1);
        val.counter |= (uint64_t)1 << NEG;
        val.denominator = 0;
    }
    return val;
}

/**
 * 
 * @param mstr MasterCache pointer
 * @param number
 * @return cachedRational
 */
cachedRational cached_rational_set_mpq(const MasterCache* mstr, mpq_t number){
    return cached_rational_set(mstr, &(number->_mp_num), &(number->_mp_den));
}

/**
 * 
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @return cachedRational
 */
cachedRational cached_rational_set_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator){
    cachedRational val;
    val.counter = counter;
    val.denominator = denominator;
    
    return val;
}

/**
 * 
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @param value
 */
void cached_rational_reset(const MasterCache* mstr, mpz_t counter, mpz_t denominator, cachedRational* value){
    value->counter = cached_int_set(mstr, counter);
    value->denominator = cached_int_set(mstr, denominator);
    cached_rational_reduce_inplace(mstr, value);
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param number
 * @param value
 */
void cached_rational_reset_mpq(const MasterCache* mstr, mpq_t number, cachedRational* value){
    cached_rational_reset(mstr, &(number->_mp_num), &(number->_mp_den), value);
}

/**
 * 
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @param value
 */
void cached_rational_reset_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator, cachedRational* value){
    value->counter = counter;
    value->denominator = denominator;
}

/**
 * 
 * @param mstr MasterCache pointer
 * @param id
 * @param counter
 * @param denominator
 */
void cached_rational_get(const MasterCache* mstr, cachedRational id, mpz_t counter, mpz_t denominator){
    cached_int_get(mstr, id.counter, counter);
    cached_int_get(mstr, id.denominator, denominator);
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param id
 * @param number
 */
void cached_rational_get_mpq(const MasterCache* mstr, cachedRational id, mpq_t number){
    mpz_t num;
    mpz_t den;
    mpz_init(num);
    mpz_init(den);
    cached_rational_get(mstr, id, num, den);
    mpq_set_num(number, num);
    mpq_set_den(number, den);
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param id
 * @return 
 */
double cached_rational_get_d(const MasterCache* mstr, cachedRational id){
    double ctr = cached_int_get_d(mstr, id.counter);
    double den = cached_int_get_d(mstr, id.denominator);
    return ctr/den;
}

/**
 * Addition
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result
 */
cachedRational cached_rational_add(const MasterCache* mstr, cachedRational val1, cachedRational val2){
    //bring to same denominator
    
    cachedInt lcm = cached_int_lcm(mstr, val1.denominator, val2.denominator);
    
    cachedInt rest;
    cachedInt f_1 = cached_int_tdiv(mstr, lcm, val1.denominator, &rest);
    cachedInt f_2 = cached_int_tdiv(mstr, lcm, val2.denominator, &rest);
    
    cachedInt n1 = cached_int_mul(mstr, val1.counter, f_1);
    cachedInt n2 = cached_int_mul(mstr, val2.counter, f_2);
    
    //add counters
    cachedInt added_ctr = cached_int_add(mstr, n1, n2);
   
    cachedRational res;
    res.counter = added_ctr;
    res.denominator = lcm;
    
    //reduce before returning
    cached_rational_reduce_inplace(mstr, &res);
    return res;
}

/**
 * reduce a rational inplace
 * @param mstr MasterCache pointer
 * @param val value to reduce
 */
void cached_rational_reduce_inplace(const MasterCache* mstr, cachedRational* val){
    //gcd of counter/denominator
    cachedInt gcd = cached_int_gcd(mstr, val->counter, val->denominator);
    //divide with gcd
    cachedInt rest;
    cachedInt ctr = cached_int_tdiv(mstr, val->counter, gcd, &rest);
    cachedInt den = cached_int_tdiv(mstr, val->denominator, gcd, &rest);
    
    //return new cachedRational
    val->counter = ctr;
    val->denominator = den;
}
/**
 * reduce a rational
 * @param mstr MasterCache pointer
 * @param val value to reduce
 */
cachedRational cached_rational_reduce(const MasterCache* mstr, cachedRational val){
    //gcd of counter/denominator
    cachedInt gcd = cached_int_gcd(mstr, val.counter, val.denominator);
    //divide with gcd
    cachedInt rest;
    cachedInt ctr = cached_int_tdiv(mstr, val.counter, gcd, &rest);
    cachedInt den = cached_int_tdiv(mstr, val.denominator, gcd, &rest);
    
    cachedRational res;
    
    res.counter = ctr;
    res.denominator = den;
    
    return res;
}


/**
 * Subtraction
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result
 */
cachedRational cached_rational_sub(const MasterCache* mstr, cachedRational val1, cachedRational val2){
    cached_rational_neg_inplace(mstr, &val2);
    return cached_rational_add(mstr, val1, val2);
}

/**
 * Multiplication 
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result 
 */
cachedRational cached_rational_mul(const MasterCache* mstr, cachedRational val1, cachedRational val2){
    cachedInt ctr = cached_int_mul(mstr, val1.counter, val2.counter);
    cachedInt den = cached_int_mul(mstr, val1.denominator, val2.denominator);
    
    cachedRational res;
    
    res.counter = ctr;
    res.denominator = den;
    cached_rational_reduce_inplace(mstr, &res);
    
    return res;
}

/**
 * Division
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result 
 */
cachedRational cached_rational_div(const MasterCache* mstr, cachedRational val1, cachedRational val2){
    cachedInt ctr = cached_int_mul(mstr, val1.counter, val2.denominator);
    cachedInt den = cached_int_mul(mstr, val1.denominator, val2.counter);
    
    cachedRational res;
    
    res.counter = ctr;
    res.denominator = den;
    cached_rational_reduce_inplace(mstr, &res);
    
    return res;
}

/**
 * @brief absolute value of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 * @param result pointer for result
 */
cachedRational cached_rational_abs(const MasterCache* mstr, cachedRational val){
    cachedInt ctr = cached_int_abs(mstr, val.counter);
    cachedInt den = cached_int_abs(mstr, val.denominator);
    
    cachedRational res;
    
    res.counter = ctr;
    res.denominator = den;
    cached_rational_reduce_inplace(mstr, &res);
    
    return res;
}
/**
 * @brief inverse of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 */
cachedRational cached_rational_inv(const MasterCache* mstr, cachedRational val){
    cachedRational res;
    
    res.counter = val.denominator;
    res.denominator = val.counter;
    cached_rational_reduce_inplace(mstr, &res);
    
    return res;
}
/**
 * @brief negation of cachedRational inplace
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 */
void cached_rational_neg_inplace(const MasterCache* mstr, cachedRational* val){
    if((val->counter & NEG) >= 1)
        val->counter = val->counter & ~NEG;
    else
        val->counter = val->counter | NEG;
}

/**
 * @brief negation of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 */
cachedRational cached_rational_neg(const MasterCache* mstr, cachedRational val){
    cachedRational res;
    if((val.counter & NEG) >= 1)
        res.counter = val.counter & ~NEG;
    else
        res.denominator = val.counter | NEG;
}
/**
 * @brief get the sign of the cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 * @return 1 if positive, 0 if negative
 */
int cached_rational_sgn(const MasterCache* mstr, cachedRational val){
    if((val.counter & NEG) >= 1 && (val.denominator & NEG) >= 1){
        return 1;
    }
    else if((val.counter & NEG) == 0 && (val.denominator & NEG) == 0){
        return 1;
    }
    else{
        return 0;
    }
}

int cached_rational_isID(cachedRational val){
    if((val.counter & SHIFT) == 0 && (val.denominator & SHIFT) == 0)
        return 0;
    else
        return 1;
}