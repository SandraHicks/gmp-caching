/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mastercache.h
 * Author: sandra
 *
 * Created on March 24, 2017, 12:53 PM
 */

#ifndef MASTERCACHE_H
#define MASTERCACHE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "defines.h"
#include "caching_operations.h"
    typedef struct MasterCacheInt{
        lookup* cache;
    } MasterCacheInt;
    
    typedef struct MasterCacheRational{
        
    } MasterCacheRational;
//Master Cache typedef and instance
typedef struct MasterCache {
    MasterCacheInt* _integers;
    MasterCacheRational* _rationals;
} MasterCache;

//Master Cache bit mask version
typedef uint64_t cachedInt; //max: 1073741823 (2^62 - 2)

//Master Cache struct version
typedef uint64_t _cachedInt;

typedef struct cachedInt_ {
    cachedInt number;
    bool sign;
    bool isIndex;
} cachedInt_;

typedef struct cached_rational {
    cachedInt counter;
    cachedInt denominator;
    bool sign;
    bool isIndex;
} cached_rational;
//oder
typedef struct cachedInt__ {
    cachedInt number;
    uint8_t info; //include information about sign and isIndex
} cachedInt__;


#ifdef __cplusplus
}
#endif

#endif /* MASTERCACHE_H */

