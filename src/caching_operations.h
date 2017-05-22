/**
  * @file caching_operations.h
  * @author Sandra Hicks
  * @brief header for caching operations if numbers are large and not directly used
  */

#ifndef CACHING_OPERATIONS_H
#define CACHING_OPERATIONS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "hashtable.h"
#include "mpz_caching.h"
#include "defines.h"

    /*! identifiers for operations applied to mpz_t's*/
    enum Operation {
        /*! addition*/          ADD, 
        /*! subtraction*/       SUB, 
        /*! multiplication*/    MUL, 
        /*! integer division*/  TDIV,
        /*! modulo*/            MOD, 
        /*! greatest common divisor*/       GCD,
        /*! modular multiplicative inverse*/INV
    };

    
    /**
     * @brief lookup table for mpz_t
     */
    typedef struct lookup_table{
        Hashtable* ht;          /**< hash table for mpz_t*/
        mpz_t_cache* cache;     /**< pointer to singleton mpz_t cache*/
    } lookup_table;
    
    /**
     * @brief lookup table for binary operations mpz_t x mpz_t -> mpz_t
     */
    typedef struct lookup_table_binary{
        Hashtable_binary* ht;       /**< hash table for (mpz_t x mpz_t)*/
        mpz_t_cache* cache;         /**< pointer to singleton mpz_t cache*/
    } lookup_table_binary;
    
    /**
     * @brief collection of lookup tables for the required operations
     */
    typedef struct lookup{
        lookup_table* lkup;         /**< lookup table for mpz_t*/
        lookup_table_binary* add;   /**< lookup table for mpz_t addition*/
        lookup_table_binary* sub;   /**< lookup table for mpz_t subtraction*/
        lookup_table_binary* mul;   /**< lookup table for mpz_t multiplication*/
        lookup_table_binary* tdiv;  /**< lookup table for mpz_t integer division*/
        lookup_table_binary* mod;   /**< lookup table for mpz_t modulo*/
        lookup_table_binary* gcd;   /**< lookup table for mpz_t greatest common divisor*/
        lookup_table_binary* inv;   /**< lookup table for mpz_t modular multiplicative inverse*/
    } lookup;
    
    /* CACHING SETUP */
    void init_cache(lookup* cache, uint64_t cachesize);
    void delete_cache(lookup* cache);
    /* INTEGER CACHING */
    
    /* Direct Data Caching
     */
    void get_mpz(lookup* cache, uint64_t id, mpz_t val);
    double get_double(lookup* cache, uint64_t id);
    uint64_t cache_insert_mpz(lookup* lu, mpz_t val);
    
    //later local only
    uint64_t cache_exists_mpz(lookup* lu, mpz_t val);
    uint64_t cache_exists_mpz_binary(lookup* cache, mpz_t op1, mpz_t op2, uint64_t* extra_info, int op);
    
    /* +/- Caching
     */
    
    uint64_t cached_mpz_add(lookup* cache, mpz_t op1_in, mpz_t op2_in);
    uint64_t cached_mpz_sub(lookup* cache, mpz_t op1, mpz_t op2);
    
    /* Mult/Div/mod Caching
     */
    uint64_t cached_mpz_mul(lookup* cache, mpz_t op1, mpz_t op2);
    uint64_t cached_mpz_tdiv(lookup* cache, uint64_t* rest, mpz_t op1, mpz_t op2);
    uint64_t cached_mpz_mod(lookup* cache, mpz_t op, mpz_t mod);
    
    /* ggT, invert
     */
    
    uint64_t cached_mpz_gcd(lookup* cache, mpz_t op1, mpz_t op2);
    uint64_t cached_mpz_invert(lookup* cache, mpz_t op, mpz_t mod);
    
    
    /* RATIONAL CACHING */

#ifdef __cplusplus
}
#endif

#endif /* CACHING_OPERATIONS_H */

