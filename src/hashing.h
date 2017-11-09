 /**
  * @file hashing.h
  * @author Sandra Hicks
  * @brief header for implementation of hash functions on mpz_t's
  */

#ifndef HASHING_H
#define HASHING_H

#include <stdint.h>
#include <gmp.h>

uint64_t get_FNV1a_hash(mpz_t myval);
uint64_t get_Jenkins_hash(mpz_t myval);
uint64_t get_lookup3_hash(mpz_t myval);
uint64_t get_Sip_hash(mpz_t myval);
uint64_t get_Murmur_hash(mpz_t myval);
uint64_t get_CRC_hash(mpz_t myval);
uint64_t get_adler_hash(mpz_t myval);
void Cantor_pairing_function_mpz(mpz_t v1, mpz_t v2, mpz_t res);
uint64_t Cantor_pairing_function_int64(uint64_t v1, uint64_t v2);
#endif /* HASHING_H */

