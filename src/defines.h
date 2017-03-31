/* 
 * File:   defines.h
 * Author: sandra
 *
 * Created on March 24, 2017, 12:53 PM
 */

#ifndef DEFINES_H
#define DEFINES_H

#ifdef __cplusplus
extern "C" {
#endif

#define true 1
#define false 0
typedef int bool;

/*! maximum size of a cachedInt */
#define cachedInt_MAX 2^62-2
/*! minimum size of a cachedInt */
#define cachedInt_MIN -(2^62-2)

/*! bitmask to get sign position of cachedInt */
#define cachedInt_SIGN (1 << 63)
/*! bitmask to get the position of cachedInt indicating if it is an ID or number*/
#define cachedInt_IsID (1 << 62)

/*! ratio of the size of the hashtable compared to size of cache */
#define hashtable_RATIO 0.4

/*! number of hash functions */
#define NUMBER_HF

#ifdef __cplusplus
}
#endif

#endif /* DEFINES_H */