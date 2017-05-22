 /**
  * @file mpz_caching.h
  * @author Sandra Hicks
  * @brief header for cache for mpz_t
  */

#ifndef MPZ_CACHING_H
#define MPZ_CACHING_H

#ifdef __cplusplus
extern "C" {
#endif
#include <stdint.h>
#include <gmp.h>

    
    /**
     * @brief cached representation of an mpz_t
     */
    typedef struct cached_mpz_t {
        mpz_t integer;  /**< actual mpz_t*/
        double fp;      /**< mpz_t double representation*/
    } cached_mpz_t;

    /**
     * @brief cache implemented as an array (fast random access)
     */
    typedef struct mpz_t_cache {
        //cache
        cached_mpz_t* cache;    /**< array of cached_mpz_t*/
        //next free ID
        uint64_t next_id;       /**< next free id for fast insert*/
        uint64_t size;          /**< array size*/
    } mpz_t_cache;
    
    void init_mpz_cache(mpz_t_cache* cache, uint64_t size);
    void delete_mpz_cache(mpz_t_cache* cache);
    int64_t insert_mpz(mpz_t_cache* cache, mpz_t val);
    void printEntry(mpz_t_cache* cache, uint64_t i);
    void get_cached_mpz(mpz_t_cache* cache, uint64_t i, mpz_t val);
    double get_cached_double(mpz_t_cache* cache, uint64_t i);
#ifdef __cplusplus
}
#endif

#endif /* MPZ_CACHING_H */

