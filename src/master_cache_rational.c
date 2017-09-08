 /**
  * @file master_cache_rational.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Rational operations in gmp
  */
#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>

#include "master_cache_rational.h"


/**
 *  set cachedRational from mpz_t tuple
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @return cachedRational
 */
cachedRational cached_rational_set(const MasterCache* mstr, mpz_t counter, mpz_t denominator){
    cachedRational val;
    val.counter = cached_int_set(mstr, counter);
    double inter = mpz_get_d(counter);
    //printf("set: %lf to %" PRIu64 "\n", inter, val.counter);
    int cmp = mpz_cmp_si(denominator, 0);
    if(cmp == 0){
        val.denominator = (uint64_t)1;
    }
    else{
        val.denominator = cached_int_set(mstr, denominator);
    }
    
    return val;
}
/**
 * set cachedRational from integer value
 * @param mstr
 * @param i
 * @return 
 */
cachedRational cached_rational_set_i(const MasterCache* mstr, int i){
    cachedRational val;
    if(i>0){
            val.counter = (uint64_t)i;
            val.denominator = 1;
    }
    else{
        val.counter = (uint64_t)(i*-1) | NEG;
        val.denominator = 1;
    }

    return val;
}

/**
 *  set cachedRational from mpq_t
 * @param mstr MasterCache pointer
 * @param number
 * @return cachedRational
 */
cachedRational cached_rational_set_mpq(const MasterCache* mstr, const mpq_t number){
    mpz_t num;
    mpz_t den;
    mpz_init(num);
    mpz_init(den);
    mpq_get_num(num, number);
    mpq_get_den(den, number);
    cachedRational val = cached_rational_set(mstr, num, den);
    mpz_clear(num);
    mpz_clear(den);
    return val;
}

/**
 * set cachedRational from cachedInt tuple
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @return cachedRational
 */
cachedRational cached_rational_set_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator){
    cachedRational val;
    val.counter = counter;
    if(denominator != 0){
        val.denominator = denominator;
    }
    else{
        val.denominator = 1;
    }
    
    return val;
}

/**
 * 
 * @param mstr
 * @param denominator
 * @return 
 */
void cached_rational_reset_den(const MasterCache* mstr, mpz_t denominator, cachedRational* value){
    int cmp = mpz_cmp_si(denominator, 0);
    if(cmp != 0){
        value->denominator = cached_int_set(mstr, denominator);
    }
    else{
        value->denominator = 1;
    }
}

void cached_rational_reset_num(const MasterCache* mstr, mpz_t num, cachedRational* value){
    value->counter = cached_int_set(mstr, num);
}

/**
 * reset an initialized cachedRational from mpz_t tuple
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @param value
 */
void cached_rational_reset(const MasterCache* mstr, mpz_t counter, mpz_t denominator, cachedRational* value){
    int cmp = mpz_cmp_si(denominator, 0);
    value->counter = cached_int_set(mstr, counter);
    if(cmp != 0){
        value->denominator = cached_int_set(mstr, denominator);
    }
    else{
        value->denominator = 1;
    }
    cached_rational_reduce_inplace(mstr, value);
}
/**
 * reset an initialized cachedRational from mpq_t
 * @param mstr MasterCache pointer
 * @param number
 * @param value
 */
void cached_rational_reset_mpq(const MasterCache* mstr, const mpq_t number, cachedRational* value){
    mpz_t num;
    mpz_t den;
    mpz_init(num);
    mpz_init(den);
    mpq_get_num(num, number);
    mpq_get_den(den, number);
    cached_rational_reset(mstr, num, den, value);
    mpz_clear(num);
    mpz_clear(den);
}

/**
 * reset an initialized cachedRational from cachedInt tuple
 * @param mstr MasterCache pointer
 * @param counter
 * @param denominator
 * @param value
 */
void cached_rational_reset_cached(const MasterCache* mstr, cachedInt counter, cachedInt denominator, cachedRational* value){
    value->counter = counter;
    if(denominator != 0){
        value->denominator = denominator;
    }
    else{
        value->denominator = 1;
    }
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
    if(id.denominator == 0){
        id.denominator = 1;
    }   
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
    //printf("set_num get c: %" PRIu64 " d:%" PRIu64 "\n", id.counter, id.denominator);
    mpq_set_num(number, num);
    mpq_set_den(number, den);
    //printf("set done\n");
    mpz_clear(num);
    mpz_clear(den);
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
 * get string representation of cachedRational
 * @param mstr MasterCache pointer
 * @param id
 * @param str
 * @return 
 */
void cached_rational_get_str(const MasterCache* mstr, cachedRational id, char* str, int precision){
    mpf_t tmpFloat;
    FILE* tmpStream;
    mpq_t gmpval;
    mpq_init(gmpval);
    //printf("get str\n");
    cached_rational_get_mpq(mstr, id, gmpval);
    
    tmpStream = fmemopen(str, 63, "w");
    mpf_init2(tmpFloat, 256);
    mpf_set_q(tmpFloat, gmpval);
    mpf_out_str(tmpStream, 10, precision, tmpFloat);
    mpf_clear(tmpFloat);
    mpq_clear(gmpval);

    fflush(tmpStream);
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
    cachedRational res;
    if(val1.denominator == 1 && val2.denominator == 1){
        res.counter = cached_int_add(mstr, val1.counter, val2.counter);
        res.denominator = 1;
        return res;
    }
    
    cachedInt lcm = cached_int_lcm(mstr, val1.denominator, val2.denominator);
    
    cachedInt rest;
    cachedInt f_1 = cached_int_tdiv(mstr, lcm, val1.denominator, &rest);
    cachedInt f_2 = cached_int_tdiv(mstr, lcm, val2.denominator, &rest);
    
    cachedInt n1 = cached_int_mul(mstr, val1.counter, f_1);
    cachedInt n2 = cached_int_mul(mstr, val2.counter, f_2);
    
    //add counters
    cachedInt added_ctr = cached_int_add(mstr, n1, n2);
   
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
    if(val->counter == val->denominator){
        val->counter = 1;
        val->denominator = 1;
        return;
    }
    else if((val->counter & ~NEG) == val->denominator){
        val->counter = 1 | NEG;
        val->denominator = 1;
        return;
    }
    else if(val->counter == (val->denominator & ~NEG)){
        val->counter = 1 | NEG;
        val->denominator = 1;
        return;
    }
    //gcd of counter/denominator
    cachedInt in_ctr = val->counter;
    cachedInt in_den = val->denominator;
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
    cachedRational res;
    if(val1.denominator == 1 && val2.denominator == 1){
        res.counter = cached_int_mul(mstr, val1.counter, val2.counter);
        res.denominator = 1;
        return res;
    }
    
    //printf("mul: c1=%"PRIu64" d1=%"PRIu64" c2=%"PRIu64" d2=%"PRIu64"\n", val1.counter, val1.denominator, val2.counter, val2.denominator);
    cachedInt ctr = cached_int_mul(mstr, val1.counter, val2.counter);
    cachedInt den = cached_int_mul(mstr, val1.denominator, val2.denominator);
    //printf("mul: c=%"PRIu64" d=%"PRIu64"\n", ctr, den);
    
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

int cached_rational_cmp(const MasterCache* mstr, cachedRational val1, cachedRational val2){
//bring to same denominator
    if(val1.denominator == 1 && val2.denominator == 1){
        return cached_int_cmp(mstr, val1.counter, val2.counter);;
    }
    
    cachedInt lcm = cached_int_lcm(mstr, val1.denominator, val2.denominator);
    cachedInt rest;
    cachedInt f_1 = cached_int_tdiv(mstr, lcm, val1.denominator, &rest);
    cachedInt f_2 = cached_int_tdiv(mstr, lcm, val2.denominator, &rest);
    
    cachedInt n1 = cached_int_mul(mstr, val1.counter, f_1);
    cachedInt n2 = cached_int_mul(mstr, val2.counter, f_2);
    
    //compare counters
    int cmp = cached_int_cmp(mstr, n1, n2);
    return cmp;
}

int cached_rational_cmp_d(const MasterCache* mstr, cachedRational val1, double val2){
//bring to same denominator
    int cmp;
    double c = cached_int_get_d(mstr, val1.counter);
    double d = cached_int_get_d(mstr, val1.denominator);
    double frac = c/d;
    double diff = frac - val2;
    printf("compare: %f / %f < %f, frac=%f, diff=%f\n", c, d, val2, frac, diff);
    if(diff > 0){
        return 1;
    }
    else if(diff < 0){
        return -1;
    }
    else{
        return 0;
    }
    
    return cmp;
}

int cached_rational_cmp_i(const MasterCache* mstr, cachedRational val1, int val2){
//bring to same denominator
    uint64_t convert;
    if(val2 < 0){
        val2 = val2 * (-1);
        convert = (uint64_t) val2 | NEG;
    }
    else{
        convert = (uint64_t) val2;
    }
    cachedRational v2 = {convert, (uint64_t)1};
    printf("compare: %" PRIu64 "/%" PRIu64 " c %d = %" PRIu64 "/%" PRIu64 " \n", val1.counter, val1.denominator, val2, v2.counter, v2.denominator);
    return cached_rational_cmp(mstr, val1, v2);
}

/**
 * todo make efficient
 * @param mstr
 * @param val
 * @return 
 */
cachedRational cached_rational_canonicalize(const MasterCache* mstr, cachedRational val){
    mpz_t counter;
    mpz_t denominator;
    mpz_init(counter);
    mpz_init(denominator);
    cached_int_get(mstr, val.counter, counter);
    cached_int_get(mstr, val.denominator, denominator);
    mpq_t result;
    mpq_init(result);
    //printf("set_num can\n");
    mpq_set_num(result, counter);
    mpq_set_den(result, denominator);
    mpz_clear(counter);
    mpz_clear(denominator);
    mpq_canonicalize(result);
    return cached_rational_set_mpq(mstr, result);
}
