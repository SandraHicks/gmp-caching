/*
 * Master Cache for caching Rational values in mpq
 *
 */
#include <gmp.h>
#include <stdlib.h>

#include "defines.h"
#include "mastercache.h"
#include "master_cache_rational.h"
#include "master_cache_integer.h"


/**
 * 
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @param value
 */
void cached_rational_set(MasterCache* mstr, mpz_t counter, mpz_t denominator, cachedRational* value){
    
    
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param number
 * @param value
 */
void cached_rational_set_mpq(MasterCache* mstr, mpq_t number, cachedRational* value){
    cached_rational_set(mstr, &(number->_mp_num), &(number->_mp_den), value);
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param id
 * @param counter
 * @param denominator
 */
void cached_rational_get(MasterCache* mstr, cachedRational* id, mpz_t counter, mpz_t denominator){
    
}
/**
 * 
 * @param mstr MasterCache pointer
 * @param id
 * @param number
 */
void cached_rational_get_mpq(MasterCache* mstr, cachedRational* id, mpq_t number){
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
double cached_rational_get_d(MasterCache* mstr, cachedRational* id){
    return 0;
}

/**
 * Addition
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result
 */
void cached_rational_add(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result){
    //bring to same denominator
    
    cachedInt lcm = cached_int_lcm(mstr, val1->denominator, val2->denominator);
    
    cachedInt rest;
    cachedInt f_1 = cached_int_tdiv(mstr, lcm, val1->denominator, &rest);
    cachedInt f_2 = cached_int_tdiv(mstr, lcm, val2->denominator, &rest);
    
    cachedInt n1 = cached_int_mul(mstr, val1->counter, f_1);
    cachedInt n2 = cached_int_mul(mstr, val2->counter, f_2);
    
    //add counters
    cachedInt added_ctr = cached_int_add(mstr, n1, n2);
    
    //result = malloc(sizeof(cachedRational));
    result->counter = added_ctr;
    result->denominator = lcm;
    
    //reduce before returning
    cached_rational_reduce(mstr, result);
}

/**
 * reduce a rational
 * @param mstr MasterCache pointer
 * @param val value to reduce
 */
void cached_rational_reduce(MasterCache* mstr, cachedRational* val){
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
 * Subtraction
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result
 */
void cached_rational_sub(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result){
    cached_rational_neg(mstr, val2);
    cached_rational_add(mstr, val1, val2, result);
}

/**
 * Multiplication 
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result 
 */
void cached_rational_mul(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result){
    cachedInt ctr = cached_int_mul(mstr, val1->counter, val2->counter);
    cachedInt den = cached_int_mul(mstr, val1->denominator, val2->denominator);
    
    result->counter = ctr;
    result->denominator = den;
}

/**
 * Division
 * @param mstr MasterCache pointer
 * @param val1
 * @param val2
 * @param result 
 */
void cached_rational_div(MasterCache* mstr, cachedRational* val1, cachedRational* val2, cachedRational* result){
    cachedInt ctr = cached_int_mul(mstr, val1->counter, val2->denominator);
    cachedInt den = cached_int_mul(mstr, val1->denominator, val2->counter);
    
    result->counter = ctr;
    result->denominator = den;
}

/**
 * @brief absolute value of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 * @param result pointer for result
 */
void cached_rational_abs(MasterCache* mstr, cachedRational* val, cachedRational* result){
    cachedInt ctr = cached_int_abs(mstr, val->counter);
    cachedInt den = cached_int_abs(mstr, val->denominator);
    
    result->counter = ctr;
    result->denominator = den;
}
/**
 * @brief inverse of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 */
void cached_rational_inv(MasterCache* mstr, cachedRational* val){
    cachedInt temp = val->denominator;
    val->denominator = val->counter;
    val->counter = temp;
}
/**
 * @brief negation of cachedRational
 * @param mstr MasterCache pointer
 * @param val cachedRational value
 */
void cached_rational_neg(MasterCache* mstr, cachedRational* val){
    if((val->counter & NEG) >= 1)
        val->counter & ~NEG;
    else
        val->counter | NEG;
}