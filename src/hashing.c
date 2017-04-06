/*
 *
 */

#include "FNV/fnv.h"
#include <sys/types.h>
#include "defines.h"
#include <gmp.h>

typedef unsigned __int128 uint128_t;

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
//Jenkins, Spookyhash (hashes 128bit values!)
uint64_t get_Jenkins_hash(mpz_t myval){
    return 0;
} 

//Jenkins lookup3
uint64_t get_lookup3_hash(mpz_t myval){
    return 0;
} 
//Siphash
uint64_t get_Sip_hash(mpz_t myval){
    return 0;
}
//Murmurhash needs key, seed, length
uint64_t get_Murmur_hash(mpz_t myval){
    //get key and seed for hash
    uint32_t key = 0;
    uint128_t hash = uint128_t(myval);
    //constants
    int32_t c1 = 0xcc9e2d51;
    int32_t c2 = 0x1b873593;
    int32_t r1 = 15;
    int32_t r2 = 13;
    int32_t m = 5;
    int32_t n = 0xe6546b64;
    return 0;
}
//CRC
uint64_t get_CRC_hash(mpz_t myval){
    return 0;
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