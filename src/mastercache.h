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
    
//Master Cache typedef and instance
typedef struct MasterCache {
    //LookUp Table instances
} MasterCache;

//Master Cache bit mask version
typedef int64_t cachedInt; //max: 1073741823 (2^62 - 2)

//Master Cache struct version
typedef uint64_t u_cachedInt;

typedef struct cachedInt_ {
    u_cachedInt number;
    bool sign;
    bool isIndex;
} cachedInt_;

typedef struct cached_rational {
    u_cachedInt counter;
    u_cachedInt denominator;
    bool sign;
    bool isIndex;
} cached_rational;
//oder
typedef struct cachedInt__ {
    u_cachedInt number;
    uint8_t info; //include information about sign and isIndex
} cachedInt__;


#ifdef __cplusplus
}
#endif

#endif /* MASTERCACHE_H */

