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

    typedef struct cached_mpz_t {
        mpz_t* integer;
        double fp;
    } cached_mpz_t;

    void init_mpz_cache(int64_t size, cached_mpz_t* result);
#ifdef __cplusplus
}
#endif

#endif /* MPZ_CACHING_H */

