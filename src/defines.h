/**
  * @file defines.h
  * @author Sandra Hicks
  * @brief general defines for the caching process
  */

#ifndef DEFINES_H
#define DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

/*! maximum size of a cachedInt */
#define cachedInt_MAX ((int64_t)1 << 62)-2
/*! minimum size of a cachedInt */
#define cachedInt_MIN (((int64_t)1 << 62)-2)*(-1)

/*! bitmask to get sign position of cachedInt */
#define cachedInt_SIGN 63
/*! bitmask to get the position of cachedInt indicating if it is an ID or number*/
#define cachedInt_IsID 62

/*! ratio of the size of the hashtable compared to size of cache */
#define hashtable_RATIO 0.4

/*! number of hash functions */
#define NUMBER_HF 3

/*! macro to detect the bit in a cachedInt which defines if it is an id or a number, also used as an error code if returned as number */
#define SHIFT ((uint64_t)1 << cachedInt_IsID)
/*! macro to detect the bit in a cachedInt which defines if it is positive or negative */
#define NEG ((uint64_t)1 << cachedInt_SIGN)

/*! macro to express positive infinity*/
#define PLUS_INFINITY (SHIFT + 1)
/*! macro to express negative infinity*/
#define MINUS_INFINITY ((SHIFT | NEG) + 1)
    
#define CACHE_START_ID 2
    
#define GMPCACHING_ERROR SHIFT
#define NaN (SHIFT | NEG)
    
#ifdef __cplusplus
}
#endif

#endif /* DEFINES_H */