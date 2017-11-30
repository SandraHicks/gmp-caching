 /**
  * @file master_cache_rational.c
  * @author Sandra Hicks
  * @brief Master Cache functions for caching Rational operations in gmp
  */
#include <gmp.h>
#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <assert.h>

#include "master_cache_rational.h"

//debug
void cached_rational_print(cachedRational c){
    int64_t ct;
    int64_t d;
    if((c.counter & NEG) >= 1){
        ct = (c.counter & (~NEG)) * (-1);
        
    }
    else{
        ct = c.counter;
    }
    if((c.denominator & NEG) >= 1){
        d = (c.denominator & (~NEG)) * (-1);
    }
    else{
        d = c.denominator;
    }
    int id_c = (c.counter & SHIFT) > 0;
    int id_d = (c.denominator & SHIFT) > 0;
    if(id_d && id_c){
        printf(" %" PRId64 " (id: %" PRId64 ") / %" PRId64 " (id: %" PRId64 ") ", ct, c.counter & ~(SHIFT | NEG), d, c.denominator & ~(SHIFT | NEG));
        return;
    }
    if(id_c){
        printf(" %" PRId64 " (id: %" PRId64 ") / %" PRId64 " ", ct, c.counter & ~(SHIFT | NEG), d);
        return;
    }
    if(id_d){
        printf(" %" PRId64 " / %" PRId64 " (id: %" PRId64 ") ", ct, d, c.denominator & ~(SHIFT | NEG));
        return;
    }
    
    if(!id_c && !id_d){
        printf(" %" PRId64 " / %" PRId64 " ", ct, d);
        return;
    }
    
    
}
//debug
void cached_int_print(cachedInt c){
    int64_t d;
    if((c & NEG) >= 1){
        d = (c & (~NEG)) * (-1);
    }
    else{
        d = c;
    }
    if((c & SHIFT) >= 1){
        printf(" %" PRId64 " (id: %" PRIu64 ") ", d, c & ~(SHIFT | NEG));
        return;
    }
    printf(" %" PRId64 " ", d);
}

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

    int cmp = mpz_cmp_si(denominator, 0);
    assert(cmp != 0);
    val.denominator = cached_int_set(mstr, denominator);

    val = cached_rational_reduce(mstr, val);
assert(val.denominator != 0);
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
    val = cached_rational_reduce(mstr, val);
    assert(val.denominator != 0);
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

    val = cached_rational_reduce(mstr, val);
    
    mpz_clear(num);
    mpz_clear(den);
    
    assert(val.denominator != 0);
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
    assert(denominator != 0);
    cachedRational val;
    val.counter = counter;
    val.denominator = denominator;

    val = cached_rational_reduce(mstr, val);
    
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
    assert(cmp != 0);
    value->denominator = cached_int_set(mstr, denominator);
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
    assert(cmp != 0);
    cachedRational temp;
    temp.counter = cached_int_set(mstr, counter);
    temp.denominator = cached_int_set(mstr, denominator);

    *value = cached_rational_reduce(mstr, temp);
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
    assert(value->denominator != 0);
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
    assert(denominator != 0);
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
    if(val1.denominator == val2.denominator){
        res.counter = cached_int_add(mstr, val1.counter, val2.counter);
        res.denominator = val1.denominator;
        return res;
    }
    /*printf("add1: %" PRIu64 "\n",val1.counter);
    printf("add2: %" PRIu64 "\n",val1.denominator);
    printf("add3: %" PRIu64 "\n",val2.counter);
    printf("add3-: %" PRIu64 "\n",(val2.counter & ~NEG));
    printf("add3-s: %" PRIu64 "\n",((val2.counter & ~NEG) & ~SHIFT));
    printf("add4: %" PRIu64 "\n",val2.denominator);*/
    
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
    res = cached_rational_reduce(mstr, res);
    
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
    
    if(val->counter == NaN || val->denominator == NaN){
        return;
    }
    
    if(val->counter == 0){
        val->denominator = 1;
        return;
    }
    
    //gcd of counter/denominator
    cachedInt gcd = cached_int_gcd(mstr, val->counter, val->denominator);
    //divide with gcd
    cachedInt rest;
    cachedInt ctr = cached_int_tdiv(mstr, val->counter, gcd, &rest);
    cachedInt den = cached_int_tdiv(mstr, val->denominator, gcd, &rest);
    
    //return new cachedRational
    val->counter = ctr;
    val->denominator = den;
    
    if(ctr == 0 || (ctr & ~NEG) == 0){
        val->denominator = 1;
    }
}
/**
 * reduce a rational
 * @param mstr MasterCache pointer
 * @param val value to reduce
 */
cachedRational cached_rational_reduce(const MasterCache* mstr, cachedRational val){
    if(val.counter == NaN || val.denominator == NaN){
        return val;
    }
    
    if(val.counter == 0){
        val.denominator = 1;
        return val;
    }
    
    //printf("reduce1: %" PRIu64 "\n",val.counter);
    //printf("reduce2: %" PRIu64 "\n",val.denominator);
    
    //gcd of counter/denominator
    cachedInt gcd = cached_int_gcd(mstr, val.counter, val.denominator);
    //divide with gcd
    cachedInt rest;
    cachedInt ctr = cached_int_tdiv(mstr, val.counter, gcd, &rest);
    cachedInt den = cached_int_tdiv(mstr, val.denominator, gcd, &rest);
    
    cachedRational res;
    
    res.counter = ctr;
    res.denominator = den;
    if(ctr == 0 || (ctr & ~NEG) == 0 ){
        res.denominator = 1;
    }
    
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
    
        cachedInt ctr = cached_int_mul(mstr, val1.counter, val2.counter);
        cachedInt den = cached_int_mul(mstr, val1.denominator, val2.denominator);
    
    res.counter = ctr;
    res.denominator = den;
    
    res = cached_rational_reduce(mstr, res);
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
    cachedRational res;
    if(val2.counter == 0){
        res.counter = NaN;
        res.denominator = NaN;
        return res;
    }
    cachedInt ctr = cached_int_mul(mstr, val1.counter, val2.denominator);
    cachedInt den = cached_int_mul(mstr, val1.denominator, val2.counter);
    
    
    
    
    res.counter = ctr;
    res.denominator = den;
    if(ctr == 0){
        res.denominator = 1;
    }
    res = cached_rational_reduce(mstr, res);
    
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
    res = cached_rational_reduce(mstr, res);
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
    if(val.counter == 0){
        res.counter = NaN;
        res.denominator = NaN;
        return res;
    }
    res.denominator = val.counter;
    res = cached_rational_reduce(mstr, res);
    
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
        res.counter = val.counter | NEG;
    res.denominator = val.denominator;
    
    return res;
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
    
    int cmp = 1;
    cachedRational diff = cached_rational_sub(mstr, val1, val2);
    if(cached_rational_sgn(mstr, diff) == 0){
        cmp = -1;
    }
    else if(diff.counter == 0){
        cmp = 0;
    }
    else{
        cmp = 1;
    }
    
    return cmp;
}

int cached_rational_cmp_d(const MasterCache* mstr, cachedRational val1, double val2){
//bring to same denominator
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, val2);
    val = cached_rational_set_mpq(mstr, value);
    mpq_clear(value);
    
    return cached_rational_cmp(mstr, val1, val);
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
    cachedRational v2 = {(uint64_t)1, (uint64_t)1};
    v2.counter = convert;
    v2.denominator = (uint64_t)1;
    //printf("int cmp:\n");
    int cmp = cached_rational_cmp(mstr, val1, v2);
    //printf("compare: %" PRIu64 "/%" PRIu64 " c %d = %" PRIu64 "/%" PRIu64 " cmp: %d \n", val1.counter, val1.denominator, val2, v2.counter, v2.denominator, cmp);
    return cmp;
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
    mpq_set_num(result, counter);
    mpq_set_den(result, denominator);
    
    mpq_canonicalize(result);
    
    //gmp_printf("cached_rational_canonicalize: %Zd / %Zd = %Qd", counter, denominator, result);
    
    mpz_clear(counter);
    mpz_clear(denominator);
    cachedRational res = cached_rational_set_mpq(mstr, result);
    mpq_clear(result);
    return res;
}
