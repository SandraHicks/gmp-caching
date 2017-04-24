/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mpz_caching.h
 * Author: sandra
 *
 * Created on March 24, 2017, 12:51 PM
 */

#ifndef MPZ_CACHING_H
#define MPZ_CACHING_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <gmp.h>

    
    //cached mpz_t
    typedef struct cached_mpz_t {
        mpz_t integer;
        double fp;
    } cached_mpz_t;

    //cache object
    typedef struct mpz_t_cache {
        //cache
        cached_mpz_t* cache;
        //next free ID
        uint64_t next_id;
        uint64_t size;
    } mpz_t_cache;
    
    void init_mpz_cache(mpz_t_cache* cache, uint64_t size);
    int64_t insert_mpz(mpz_t_cache* cache, mpz_t val);
    void printEntry(mpz_t_cache* cache, uint64_t i);
    void get_mpz(mpz_t_cache* cache, uint64_t i, mpz_t val);
    double get_double(mpz_t_cache* cache, uint64_t i);
#ifdef __cplusplus
}
#endif

#endif /* MPZ_CACHING_H */

