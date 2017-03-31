/*
 *
 */

#include "FNV/fnv.h"
#include <sys/types.h>
#include "defines.h"
#include <gmp.h>

//one positive mpz_t is hashed with FNV1a 32bit
/*long get_mpz_hash(mpz_t myval){
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
}*/

//FNV1a
uint64_t get_FNV1a_hash(mpz_t myval){
    //check for negative sign for safety
    if(mpq_sgn(myval) < 0){
        mpq_neg(myval, myval);
    }
    char* str;
    mpz_get_str(str, 2, myval);
    Fnv32_t hash = fnv_32a_str(str, FNV1_32_INIT);
    while (hash >= cachedInt_MAX){
        hash = fnv_32a_buf(&hash, sizeof(Fnv32_t), FNV1_32_INIT);
    }
    uint64_t hash_l = hash;
    return hash_l;
}
//Jenkins, Spookyhash
uint64_t get_Jenkins_hash(mpz_t myval){
    
} 
//Siphash
uint64_t get_Sip_hash(mpz_t myval){
    
}
//Murmurhash needs key, seed, length
uint64_t get_Murmur_hash(mpz_t myval, uint64_t key){
    
}
//CRC
uint64_t get_CRC_hash(mpz_t myval){
    
}

uint64_t Cantor_pairing_function_int(uint64_t v1, uint64_t v2){
    uint64_t result = 0.5*(v1+v2)*(v1+v2+1) + v2;
    return result;
}

void Cantor_pairing_function_mpz(mpz_t v1, mpz_t v2, mpz_t res){
    
    //v1+v2
    mpz_t v1_v2;
    mpz_add(v1_v2, v1, v2);
    
    //v1+v2+1
    mpz_t v1_v2_1;
    mpz_add_ui(v1_v2_1, v1_v2, 1);
    
    //(v1+v2)*(v1+v2+1)
    mpz_t mul;
    mpz_mul(mul, v1_v2, v1_v2_1);
    
    //multiply with 0.5
    //0.5*(v1+v2)*(v1+v2+1)
    mpz_t div;
    mpz_tdiv_q_ui(div, mul, 2);
    
    //add v2
    //0.5*(v1+v2)*(v1+v2+1) + v2
    mpz_add(res, div, v2);
}