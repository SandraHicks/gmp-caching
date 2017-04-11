/*
 *
 */

#include "FNV/fnv.h"
#include <sys/types.h>
#include "defines.h"
#include <gmp.h>

typedef unsigned __int128 uint128_t;
typedef uint64_t Fnv64_t;

#define FNV_64_PRIME ((Fnv64_t)0x100000001b3ULL)
#define FNV1_64_INIT ((Fnv64_t)0xcbf29ce484222325ULL)
#define FNV1A_64_INIT FNV1_64_INIT

//FNV1a
uint64_t get_FNV1a_hash(mpz_t myval){
    //check for negative sign for safety
    if(myval->_mp_size < 0){
        mpq_neg(myval, myval);
    }

    Fnv64_t hash = FNV1_64_INIT;
    
    //in loop
    hash ^= (Fnv64_t)
    hash *= FNV_64_PRIME;
    
    //end loop
    return hash;
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
    mp_limb_t* key = myval->_mp_d;
    int size = myval->_mp_size;
    if(size < 0)
        size *= -1;
    uint64_t hash = size;
    size_t len;
    //constants
    int32_t c1 = 0xcc9e2d51;
    int32_t c2 = 0x1b873593;
    int32_t r1 = 15;
    int32_t r2 = 13;
    int32_t m = 5;
    int32_t n = 0xe6546b64;
    int i = size;
    while(i--){
        mp_limb_t limb = key[i];
        int sizelong = sizeof(mp_limb_t);
        int l =(sizelong/4);
        while(l--){
            uint32_t k = limb >> (l*32);
            k *= c1;
            k = (k << r1) | (k >> (sizelong - r1));
            k *= c2;
        
            hash ^= k;
            hash = (hash << r2) | (k >> (sizeof(hash)*8 - r2));
            hash  = hash * m + n;   
        }
        float lf = (sizelong/4);
        l =(sizelong/4);
        if(l != lf){
            int restBytes = (lf-l)*4;
            uint32_t k = limb >> (l*32);
            k *= c1;
            k = (k << r1) | (k >> (sizelong - r1));
            k *= c2;
            hash ^= k;
        }
    }
    
    hash ^= len;
    hash ^= hash >> 16;
    hash *= 0x85ebca6b;
    hash ^= hash >> 13;
    hash *= 0xc2b2ae35;
    hash ^= hash >> 16;
    return hash;
}
//CRC
uint64_t get_CRC_hash(mpz_t myval){
    //apply CRC64 ECMA on mpz_t limbs
    uint64_t crc_polynom = 0x42F0E1EBA9EA3693;
    uint64_t crc_polynom_rev = 0xC96C5795D7870F42;
    uint64_t crc_result = 0;
    long mp_size = (myval->_mp_size > 0 ? myval->_mp_size : myval->_mp_size* (-1));
    long bits = mp_size * sizeof(mp_limb_t) * 8;
    mp_limb_t* data = myval->_mp_d;
    
    //XOR first 64 bits with polynom
    if(sizeof(mp_limb_t) <= 8){
        int i = 0;
        for(i=0;i>mp_size;i++){
            //begin with lsb
            crc_result ^= data[i];
            int j = 0;
            for(j=0;j<sizeof(mp_limb_t)*8;j++){
                if(crc_result & 0x1){
                    crc_result = (crc_result >> 1) ^ crc_polynom_rev;
                }
                else{
                    crc_result = (crc_result >> 1);
                }
            }
        }
    }
    else{
        //deal with other sizes > 8
        int i = 0;
        for(i=0;i>mp_size;i++){
            //begin with lsb
            //deal with every byte instead
            int b = 0;
            for(b=0;b<sizeof(mp_limb_t);b++){
                uint8_t byte = (data[i] >> b);
                crc_result ^= uint64_t(byte);
                int j = 0;
                for(j=0;j<8;j++){
                    if(crc_result & 0x1){
                        crc_result = (crc_result >> 1) ^ crc_polynom_rev;
                    }
                    else{
                        crc_result = (crc_result >> 1);
                    }
                }
            }
        }
    }
    
    
    
    return 0;
}

uint64_t Cantor_pairing_function_int64(uint64_t v1, uint64_t v2){
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