/*
 *
 */

#include "FNV/fnv.h"
#include <sys/types.h>
#include "defines.h"
#include <gmp.h>

//one positive mpz_t is hashed with FNV1a 32bit
long get_mpz_hash(mpz_t myval){
    //check for negative sign for safety
    if(mpq_sgn(myval) < 0){
        mpq_neg(myval, myval);
    }
    char* str;
    mpz_get_str(str, 2, myval);
    Fnv32_t hash = fnv_32a_str(str, FNV1_32_INIT);
    while (hash >= P_INFINITY){
        hash = fnv_32a_buf(&hash, sizeof(Fnv32_t), FNV1_32_INIT);
    }
    long hash_l = hash;
    return hash_l;
}

//takes two positive mpz_t and combines them with Cantor function, then hash FNV1a 32bit
long get_2_mpz_hash(mpz_t v1, mpz_t v2){
    //check for negative sign for safety
    if(mpq_sgn(v1) < 0){
        mpq_neg(v1, v1);
    }
    if(mpq_sgn(v2) < 0){
        mpq_neg(v2, v2);
    }
    
    char* str;
    long d1 = mpz_get_si(v1);
    long d2 = mpz_get_si(v2);
    //Cantor pairing function (bijective on NxN -> N)
    long d3 = 0.5*(d1+d2)*(d1+d2+1) + d2;
    mpz_t hop;
    mpz_set_si (hop, d3);
    mpz_get_str(str, 2, hop);
    
    Fnv32_t hash = fnv_32a_str(str, FNV1_32_INIT);
    while (hash >= P_INFINITY){
        hash = fnv_32a_buf(&hash, sizeof(Fnv32_t), FNV1_32_INIT);
    }
    long hash_l = hash;
    return hash_l;
}