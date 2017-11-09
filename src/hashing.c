 /**
  * @file hashing.c
  * @author Sandra Hicks
  * @brief implementation of hash functions on mpz_t's
  */

#include <sys/types.h>
#include "defines.h"
#include <gmp.h>
#include <stdint.h>

//Debug
#include <inttypes.h>
#include <stdio.h>
#include "debug.h"

/*! need a uint128_t value*/
typedef unsigned __int128 uint128_t;
/*! use uint64_t for implementing the FNV1a algorithm*/
typedef uint64_t Fnv64_t;

/*! special prime for FNV1a*/
#define FNV_64_PRIME ((Fnv64_t)0x100000001b3ULL)
/*! init value for FNV1*/
#define FNV1_64_INIT ((Fnv64_t)0xcbf29ce484222325ULL)
/*! init value for FNV1a*/
#define FNV1A_64_INIT FNV1_64_INIT

//FNV1a
/**
 * @brief FNV1a hashing of an mpz_t to a 64 bit unsigned value.
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_FNV1a_hash(mpz_t myval){
    //check for negative sign for safety
    mp_limb_t* key = myval->_mp_d;
    int size = myval->_mp_size;
    Fnv64_t hash = FNV1_64_INIT;
    
    int i = size;
    while(i--){
        mp_limb_t limb = key[i];
        hash ^= (Fnv64_t)limb;
        hash *= FNV_64_PRIME;
    }
    
    uint64_t shift = 1;
    hash &= ~((shift << 63) | (shift << 62));

    return hash;
}
//Jenkins, Spookyhash (hashes 128bit values!)
/**
 * @brief (TODO) Jenkins Spookyhash hash of a mpz_t to a 64 bit unsigned value
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_Jenkins_hash(mpz_t myval){
    return 0;
} 

//Jenkins lookup3
/**
 * @brief (TODO) Jenkins lookup3 hash of a mpz_t to a 64 bit unsigned value
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_lookup3_hash(mpz_t myval){
    return 0;
} 
//Siphash
/**
 * @brief (TODO) Siphash hash of a mpz_t to a 64 bit unsigned value
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_Sip_hash(mpz_t myval){
    return 0;
}
//Murmurhash needs key, seed, length
/**
 * @brief Murmur hash of a mpz_t to a 64 bit unsigned value
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_Murmur_hash(mpz_t myval){
    //get key and seed for hash
    mp_limb_t* key = myval->_mp_d;
    int size = myval->_mp_size;
    if(size < 0)
        size *= -1;
    uint64_t hash = 0;
    size_t len = size;
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
            //int restBytes = (lf-l)*4;
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
    
    
    uint64_t shift = 1;
    hash &= ~((shift << 63) | (shift << 62));
    
    return hash;
}
//CRC
/**
 * @brief CRC hash of a mpz_t to a 64 bit unsigned value
 * @param myval mpz_t to be hashed
 * @return hash value
 */
uint64_t get_CRC_hash(mpz_t myval){
    //apply CRC64 ECMA on mpz_t limbs
    //uint64_t crc_polynom = 0x42F0E1EBA9EA3693;
    uint64_t crc_polynom_rev = 0xC96C5795D7870F42;
    uint64_t crc_result = 0;
    long mp_size = (myval->_mp_size > 0 ? myval->_mp_size : myval->_mp_size* (-1));
    //long bits = mp_size * sizeof(mp_limb_t) * 8;
    mp_limb_t* data = myval->_mp_d;
    
    //XOR first 64 bits with polynom
    if(sizeof(mp_limb_t) <= 8){
        int i = 0;
        for(i=0;i<mp_size;i++){
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
        for(i=0;i<mp_size;i++){
            //begin with lsb
            //deal with every byte instead
            int b = 0;
            for(b=0;b<sizeof(mp_limb_t);b++){
                uint8_t byte = (data[i] >> b);
                crc_result ^= (uint64_t)byte;
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
    
    //printtoBinary(crc_result);
    uint64_t shift = 1;
    crc_result &= ~((shift << 63) | (shift << 62));
    //printf("H %" PRIu64 "\n", crc_result);
    //printtoBinary(crc_result);
    return crc_result;
}

uint64_t get_adler_hash(mpz_t myval){
    //similar adler32
    long mp_size = (myval->_mp_size > 0 ? myval->_mp_size : myval->_mp_size* (-1));
    //long bits = mp_size * sizeof(mp_limb_t) * 8;
    mp_limb_t* data = myval->_mp_d;
    
    int i = 0;
    
    uint64_t s1 = 1;
    uint64_t s2 = 0;
    
    for(i=0;i<mp_size;i++){
            //begin with lsb
            //deal with every byte instead
            int b = 0;
            for(b=0;b<sizeof(mp_limb_t);b++){
                uint8_t tval = (data[i] >> b);
                s1 = (s1 + (uint64_t)tval) % 4294967295;
                s2 = (s2 + s1) % 4294967295;
            }
        }
    //printf("Hash: %" PRIu64 "\n", ((s2 << 32) | s1));
    return (s2 << 32) | s1;
}

/**
 * @brief apply Cantor pairing function to uint64_t
 * @param v1 operand 1
 * @param v2 operand 2
 * @return result
 */
uint64_t Cantor_pairing_function_int64(uint64_t v1, uint64_t v2){
    uint64_t add = v1 + v2;
    uint64_t add2 = v1 + v2 + 1;
    uint64_t intermediate = add * add2;
    uint64_t half = intermediate / 2;
    uint64_t result = half + v2;
    uint64_t shift = 1;
    result &= ~((shift << 63) | (shift << 62));
    return result;
}

/**
 * @brief apply Cantor pairing function to mpz_t
 * @param v1 operand 1
 * @param v2 operand 2
 * @param res resulting mpz_t
 */
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