/*
 *
 *
 */
#include "defines.h"


typedef long cache_mpq;
typedef unsigned long u_cache_mpq;

//Master Cache typedef and instance
struct MasterCacheInteger {
    
};
//Master Cache bitmask version

//Master Cache struct version

struct Rational {
    u_cache_mpq counter;
    u_cache_mpq denominator;
    bool sign;
    bool isIndex;
};