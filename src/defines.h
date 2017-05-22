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
#define cachedInt_MAX (int64_t)2^62-2
/*! minimum size of a cachedInt */
#define cachedInt_MIN (int64_t)-(2^62-2)

/*! bitmask to get sign position of cachedInt */
#define cachedInt_SIGN 63
/*! bitmask to get the position of cachedInt indicating if it is an ID or number*/
#define cachedInt_IsID 62

/*! ratio of the size of the hashtable compared to size of cache */
#define hashtable_RATIO 0.4

/*! number of hash functions */
#define NUMBER_HF 3

/*! macro to detect the bit in a cachedInt which defines if it is an id or a number */
#define SHIFT ((uint64_t)1 << cachedInt_IsID)
/*! macro to detect the bit in a cachedInt which defines if it is positive or negative */
#define NEG ((uint64_t)1 << cachedInt_SIGN)

#ifdef __cplusplus
}
#endif

#endif /* DEFINES_H */