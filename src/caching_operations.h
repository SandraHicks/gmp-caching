/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   caching_operations.h
 * Author: sandra
 *
 * Created on April 24, 2017, 11:39 AM
 */

#ifndef CACHING_OPERATIONS_H
#define CACHING_OPERATIONS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "hashtable.h"
#include "mpz_caching.h"
#include "defines.h"
    
    
    typedef struct lookup_table{
        Hashtable* ht;
        mpz_t_cache* cache;
    } lookup_table;
    
    typedef struct lookup_table_binary{
        Hashtable_binary* ht;
        mpz_t_cache* cache;
    } lookup_table_binary;
    
    /* CACHING SETUP */
    void init_cache(lookup_table* cache, lookup_table_binary* cache_binary, uint64_t cachesize);
    void delete_cache(lookup_table* cache, lookup_table_binary* cache_binary);
    /* INTEGER CACHING */
    
    /* Direct Data Caching
     */
    void get_mpz(lookup_table* cache, uint64_t id, mpz_t val);
    double get_double(lookup_table* cache, uint64_t id);
    uint64_t cache_insert_mpz(lookup_table* cache, mpz_t val);
    
    //later local only
    uint64_t cache_exists_mpz(lookup_table* cache, mpz_t val);
    uint64_t cache_exists_mpz_binary(lookup_table_binary* cache, mpz_t op1, mpz_t op2);
    
    /* +/- Caching
     */
    
    uint64_t add_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2);
    uint64_t substract_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2);
    
    /* Mult/Div/mod Caching
     */
    void multiplicate_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2, uint64_t result);
    void divide_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2, uint64_t result);
    void modulo_cached_mpz(lookup_table_binary* cache, mpz_t op, mpz_t mod, uint64_t result);
    
    /* ggT, invert
     */
    
    void gcd_cached_mpz(lookup_table_binary* cache, mpz_t op1, mpz_t op2, uint64_t result);
    void invert_mod_cached_mpz_t(lookup_table_binary* cache, mpz_t op, mpz_t mod, uint64_t result);
    
    
    /* RATIONAL CACHING */

#ifdef __cplusplus
}
#endif

#endif /* CACHING_OPERATIONS_H */

