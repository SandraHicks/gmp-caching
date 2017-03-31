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

//Master Cache typedef and instance
struct MasterCache {
    //LookUp Table instances
};

//Master Cache bit mask version
typedef int64_t cachedInt; //max: 1073741823 (2^62 - 2)

//Master Cache struct version
typedef uint64_t u_cachedInt;

struct cachedInt_ {
    u_cachedInt number;
    bool sign;
    bool isIndex;
};

struct cached_rational {
    u_cachedInt counter;
    u_cachedInt denominator;
    bool sign;
    bool isIndex;
};
//oder
struct cachedInt__ {
    u_cachedInt number;
    uint8_t info; //include information about sign and isIndex
};


#ifdef __cplusplus
}
#endif

#endif /* MASTERCACHE_H */

