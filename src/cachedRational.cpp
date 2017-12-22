 /**
  * @file cachedRational.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedRationals
  */

#include "cachedRational.h"
#include "gmpcachingxx.h"

#include <cassert>
#include <cstdint>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <string.h>
#include <cinttypes>
#include <cstdio>


namespace gmpcaching{
/*
constructors
*/  

CachedRational::CachedRational(const MasterCache* cache){
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    cachedRational val;
    val.counter = 0;
    val.denominator = 1;
    this->value = val;
    
    
}

CachedRational::CachedRational(const int i, const MasterCache* cache){
    cachedRational val;
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        val = cached_rational_set_i(this->cache, i);
    }
    else{
        this->cache = cache;
        val = cached_rational_set_i(this->cache, i);
    }
    this->value = val;
    
}

CachedRational::CachedRational(const double& r, const MasterCache* cache){
    cachedRational val;
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        mpq_t value;
        mpq_init(value);
        mpq_set_d(value, r);
        val = cached_rational_set_mpq(this->cache, value);
        mpq_clear(value);
    }
    else{
        this->cache = cache;
        mpq_t value;
        mpq_init(value);
        mpq_set_d(value, r);
        val = cached_rational_set_mpq(this->cache, value);
        mpq_clear(value);
    }
    this->value = val;
    
}

CachedRational::CachedRational(const long double& r, const MasterCache* cache){
    cachedRational val;
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        mpq_t value;
        mpq_init(value);
        mpq_set_d(value, double(r));
        val = cached_rational_set_mpq(this->cache, value);
        mpq_clear(value);
    }
    else{
        this->cache = cache;
        mpq_t value;
        mpq_init(value);
        mpq_set_d(value, double(r));
        val = cached_rational_set_mpq(this->cache, value);
        mpq_clear(value);
    }
    this->value = val;
    
}

CachedRational::CachedRational(const mpq_t& q, const MasterCache* cache){
    cachedRational val;
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        val = cached_rational_set_mpq(this->cache, q);
    }
    else{
        this->cache = cache;
        val = cached_rational_set_mpq(this->cache, q);
        
    }
    this->value = val;
    
}

CachedRational::CachedRational(mpz_t z1, mpz_t z2, const MasterCache* cache){
    cachedRational val;
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        val = cached_rational_set(this->cache, z1, z2);
    }
    else{
        this->cache = cache;
        val = cached_rational_set(this->cache, z1, z2);
        
    }
    this->value = val;
    
}

CachedRational::CachedRational(cachedInt c1, cachedInt c2, const MasterCache* cache){
    cachedRational val;
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
        val = cached_rational_set_cached(this->cache, c1, c2);
    }
    else{
        this->cache = cache;
        val = cached_rational_set_cached(this->cache, c1, c2);
        
    }
    this->value = val;
    
}

CachedRational::CachedRational(const CachedInt& c1, const CachedInt& c2, const MasterCache* cache){
    assert(c1.getCache() == c2.getCache());
    this->cache = c1.getCache();
    if(this->cache == NULL){
        throw new RationalCacheNotSetException(c1.getValue(), c2.getValue());
    }
        
    this->value = cached_rational_set_cached(this->cache, c1.getValue(), c2.getValue());
    
}

CachedRational::CachedRational(const cachedRational val, const MasterCache* cache){
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = val;
    
}

CachedRational::CachedRational(const CachedRational& val){
  this->cache = val.getCache();
  this->value = val.getValue();
}

CachedRational::~CachedRational(){

}

/*
assignments
*/

CachedRational& CachedRational::operator=(const CachedRational& ci){
  this->cache = ci.getCache();
  this->value = ci.getValue();
  
  return *this;
}

CachedRational& CachedRational::operator=(const mpq_t& q){
  if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
  this->value = cached_rational_set_mpq(this->cache, q);
  
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<mpz_t&, mpz_t&> mpzts){
  if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
  this->value = cached_rational_set(this->cache, mpzts.first, mpzts.second);
  
  
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<int, int> ints){
  if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
  
 
  bool isNeg1 = false;
    if(ints.first < 0){
        isNeg1 = true;
    }
  bool isNeg2 = false;
    if(ints.second < 0){
        isNeg2 = true;
    }
    
    this->value = cached_rational_set_cached(this->cache, isNeg1 ? ((uint64_t)(ints.first*(-1)) | NEG) : ((uint64_t)ints.first), 
            isNeg2 ? ((uint64_t)(ints.second*(-1)) | NEG) : ((uint64_t)ints.second));
  
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<long, long> longs){
  if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
  
  bool isNeg1 = false;
    if(longs.first < 0){
        isNeg1 = true;
    }
  bool isNeg2 = false;
    if(longs.second < 0){
        isNeg2 = true;
    }
    
    this->value = cached_rational_set_cached(this->cache, isNeg1 ? ((uint64_t)(longs.first*(-1)) | NEG) : ((uint64_t)longs.first), 
            isNeg2 ? ((uint64_t)(longs.second*(-1)) | NEG) : ((uint64_t)longs.second));
  
  return *this;
}

CachedRational& CachedRational::operator=(const long double &r){
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, double(r));
    this->value = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    return *this;
}

CachedRational& CachedRational::operator=(const double &r){
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, r);
    this->value = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    return *this;
}

CachedRational& CachedRational::operator=(const int &i){
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new RationalCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    
    bool isNeg = false;
    if(i < 0){
        isNeg = true;
    }
    
    this->value = cached_rational_set_cached(this->cache, isNeg ? ((uint64_t)(i*(-1)) | NEG) : ((uint64_t)i), (uint64_t)1);
    
    return *this;
}

/*
operators
*/
CachedRational CachedRational::operator+(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_add(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;

  return returnValue;
}

CachedRational CachedRational::operator+=(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_add(this->cache, this->value, i.getValue());

  this->value = result;
  
  return *this;
}

CachedRational CachedRational::operator-(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_sub(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;

  return returnValue;
}

CachedRational CachedRational::operator-=(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_sub(this->cache, this->value, i.getValue());

  this->value = result;
  
  return *this;
}

CachedRational CachedRational::operator*(const CachedRational& i) const{

  assert(this->cache == i.cache);
  cachedRational result = cached_rational_mul(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;

  return returnValue;
}

CachedRational CachedRational::operator*=(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_mul(this->cache, this->value, i.getValue());

  this->value = result;
  
  return *this;
}

CachedRational CachedRational::operator/(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_div(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;

  return returnValue;
}
CachedRational CachedRational::operator/=(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_div(this->cache, this->value, i.getValue());

  this->value = result;
  
  return *this;
}


CachedRational& CachedRational::addProduct(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedRational product = cached_rational_mul(r.cache, r.value, s.getValue());
    cachedRational sum = cached_rational_add(this->cache, this->value, product);
    this->value = cached_rational_reduce(this->cache, sum);
    return *this;
}

CachedRational& CachedRational::subProduct(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedRational product = cached_rational_mul(r.cache, r.value, s.getValue());
    cachedRational sub = cached_rational_sub(this->cache, this->value, product);
    this->value = cached_rational_reduce(this->cache, sub);
    return *this;
}

CachedRational& CachedRational::addQuotient(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    assert(this->cache == r.cache);
    cachedRational product = cached_rational_div(r.cache, r.value, s.getValue());
    cachedRational sum = cached_rational_add(this->cache, this->value, product);
    this->value = cached_rational_reduce(this->cache, sum);
    return *this;
}

CachedRational& CachedRational::subQuotient(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedRational product = cached_rational_div(r.cache, r.value, s.getValue());
    cachedRational sub = cached_rational_sub(this->cache, this->value, product);
    this->value = cached_rational_reduce(this->cache, sub);
    return *this;
}


CachedRational& CachedRational::reduce(){
  cachedRational result = cached_rational_reduce(this->cache, this->value);
  this->value = result;
  return *this;
}

CachedRational& CachedRational::invert(){
  cachedRational result = cached_rational_inv(this->cache, this->value);
  this->value = result;
  return *this;
}

CachedRational spxAbs(const CachedRational& r){
  cachedRational result = cached_rational_abs(r.cache, r.value);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational& CachedRational::neg(){
  cachedRational result = cached_rational_neg(this->cache, this->value);
  this->value = result;
  return *this;
}

int sign(const CachedRational& r){
  return cached_rational_sgn(r.cache, r.value);
}

CachedRational::operator double() const{
  return cached_rational_get_d(this->cache, this->value);
}

CachedRational::operator long double() const{
    double val = cached_rational_get_d(this->cache, this->value);
    long double nval = static_cast<long double>(val);
    return nval;
}

const MasterCache* CachedRational::getCache() const{
  return this->cache;
}

cachedRational CachedRational::getValue() const{
  return this->value;
}

void CachedRational::setValue(cachedRational val){
   this->value = val;
}

bool CachedRational::hasSameCache(const CachedRational& i) const{
    if(this->cache == NULL || i.cache == NULL){
        throw new RationalCacheNotSetException();
    }
    if(this->cache == i.cache){
        return true;
    }
    else{
        return false;
    }
}

/// Negation.
CachedRational operator-(const CachedRational& r){
   cachedRational val = cached_rational_neg(r.getCache(), r.getValue());
   return CachedRational(val, r.getCache());
}

CachedRational& CachedRational::powRound(){
    //not implemented in soplex::Rational
    return *this;
}

  /*
   * COMPARISONS
   */

bool CachedRational::isAdjacentTo(const double& d) const{
    return double(*this) == d;
}

bool CachedRational::isNextTo(const double& d){
    return double(*this) == d;
}



int compareRational(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    return cached_rational_cmp(r.cache, s.value, s.value);
}

bool operator!=(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, s.value, s.value);
    return cmp != 0;
}
      
bool operator==(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == 0;
}

bool operator<(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == -1;
}

bool operator<=(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp <= 0;
}

bool operator>(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == 1;
}

bool operator>=(const CachedRational& r, const CachedRational& s){
    assert(r.hasSameCache(s));
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp >= 0;
}

bool operator!=(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp != 0);
}
bool operator==(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp == 0);
}
bool operator<(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp < 0);
}
bool operator<=(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp <= 0);
}
bool operator>(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp > 0);
}
bool operator>=(const CachedRational& r, const double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp >= 0);
}

bool operator!=(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp > 0);
}
bool operator<=(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp < 0);
}
bool operator>=(const double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp <= 0);
}

bool operator!=(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp != 0);
}
bool operator==(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp == 0);
}
bool operator<(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp < 0);
}
bool operator<=(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp <= 0);
}
bool operator>(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp > 0);
}
bool operator>=(const CachedRational& r, const long double& s){
    int cmp = cached_rational_cmp_d(r.cache, r.value, s);
    return (cmp >= 0);
}

bool operator!=(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp > 0);
}
bool operator<=(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp < 0);
}
bool operator>=(const long double& r, const CachedRational& s){
    int cmp = cached_rational_cmp_d(s.cache, s.value, r);
    return (cmp <= 0);
}

CachedRational operator+(const double& d, const CachedRational& r){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(r.cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_add(r.cache, r.value, val);
    CachedRational returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    
    return returnValue;
}
CachedRational operator-(const double& d, const CachedRational& r){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(r.cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_sub(r.cache, val, r.value);
    CachedRational returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational operator*(const double& d, const CachedRational& r){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(r.cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_mul(r.cache, r.value, val);
    CachedRational returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational operator/(const double& d, const CachedRational& r){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(r.cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_div(r.cache, val, r.value);
    CachedRational returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational CachedRational::operator+(const double& d) const{
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_add(this->cache, this->value, val);
    CachedRational returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    
    return returnValue;
}
CachedRational CachedRational::operator-(const double& d) const{
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_sub(this->cache, this->value, val);
    CachedRational returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational CachedRational::operator*(const double& d) const{
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_mul(this->cache, this->value, val);
    CachedRational returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational CachedRational::operator/(const double& d) const{
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_div(this->cache, this->value, val);
    CachedRational returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedRational CachedRational::operator+=(const double& d){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_add(this->cache, this->value, val);
    this->value = result;
    
    return *this;
}
CachedRational CachedRational::operator-=(const double& d){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_sub(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedRational CachedRational::operator*=(const double& d){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_mul(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedRational CachedRational::operator/=(const double& d){
    cachedRational val;
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, d);
    val = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    
    cachedRational result = cached_rational_div(this->cache, this->value, val);
    this->value = result;
    return *this;
}

bool operator!=(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp != 0);
}
bool operator==(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp == 0);
}
bool operator<(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp < 0);
}
bool operator<=(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp <= 0);
}
bool operator>(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp > 0);
}
bool operator>=(const CachedRational& r, const int& s){
    int cmp = cached_rational_cmp_i(r.cache, r.value, s);
    return (cmp >= 0);
}

bool operator!=(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp > 0);
}
bool operator<=(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp < 0);
}
bool operator>=(const int& r, const CachedRational& s){
    int cmp = cached_rational_cmp_i(s.cache, s.value, r);
    return (cmp <= 0);
}


CachedRational operator+(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};                          
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_add(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  
  return returnValue;
}
CachedRational operator-(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_sub(r.cache, intval, r.value);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational operator*(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_mul(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational operator/(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_div(r.cache, intval, r.value);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator+(const int& d) const{
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_add(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  
  return returnValue;
}
CachedRational CachedRational::operator-(const int& d) const{
    //printf("-int\n");
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_sub(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator*(const int& d) const{
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_mul(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator/(const int& d) const{
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_div(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator+=(const int& d){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_add(this->cache, this->value, intval);
  this->value = result;

  return *this;
}
CachedRational CachedRational::operator-=(const int& d){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_sub(this->cache, this->value, intval);
  this->value = result;
  return *this;
}
CachedRational CachedRational::operator*=(const int& d){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_mul(this->cache, this->value, intval);
  this->value = result;
  return *this;
}
CachedRational CachedRational::operator/=(const int& d){
    cachedRational intval;
    if(d < 0){
        intval = {(uint64_t)1, (uint64_t)1};
        intval.counter = (uint64_t)(d * (-1)) | NEG;
        intval.denominator = 1;
    }
    else{
       intval = {(uint64_t)1, (uint64_t)1};
       intval.counter = (uint64_t)d;
       intval.denominator = 1;
    }
  cachedRational result = cached_rational_div(this->cache, this->value, intval);
  this->value = result;
  return *this;
}

//string out
std::ostream& operator<<(std::ostream& os, const CachedRational& r){
   char* buffer;
   mpz_t d;
   mpz_t c;
   mpz_init(c);
   mpz_init(d);
   cached_int_get(r.cache, r.value.counter, c);
   cached_int_get(r.cache, r.value.denominator, d);
   mpq_t value;
   mpz_set(&(value->_mp_den), d);
   mpz_set(&(value->_mp_num), c);
   buffer = (char*) malloc (mpz_sizeinbase(mpq_numref(value), 10) + mpz_sizeinbase(mpq_denref(value), 10) + 3);
   char* str = mpq_get_str(buffer, 10, value);
   os << str;
   free(buffer);
   return os;
}


///@TODO
#define MAX_STR_LEN 10000
bool CachedRational::readString(const char* s){
    assert(s != 0);
    assert(strlen(s) <= MAX_STR_LEN);
    mpq_t rational;
    mpq_init(rational);
    
    const char* pos;
    
    // if there is a slash or there is no dot and exponent (i.e. we
   // have an integer), we may simply call GMP's string reader
    if( strchr(s, '/') != 0 || strpbrk(s, ".eE") == 0 )
   {
      pos = (*s == '+') ? s + 1 : s;
      if( mpq_set_str(rational, pos, 10) == 0 )
      {
         mpq_canonicalize(rational);
         this->value = cached_rational_set_mpq(this->cache, rational);
         mpq_clear(rational);
         return true;
      }
      else
         mpq_clear(rational);
         return false;
   }

   bool has_digits = false;
   bool has_emptyexponent = false;
   long int exponent = 0;
   long int decshift = 0;
   mpz_t shiftpower;
   mpz_init(shiftpower);
   mpq_t shiftpowerRational;
   mpq_init(shiftpowerRational);
   char* t;
   char tmp[MAX_STR_LEN];

   pos = s;

   // 1. sign
   if( (*pos == '+') || (*pos == '-') )
      pos++;

   // 2. Digits before the decimal dot
   while( (*pos >= '0') && (*pos <= '9') )
   {
      has_digits = true;
      pos++;
   }

   // 3. Decimal dot
   if( *pos == '.' )
   {
      pos++;

      // 4. If there was a dot, possible digit behind it
      while( (*pos >= '0') && (*pos <= '9') )
      {
         has_digits = true;
         pos++;
      }
   }

   // 5. Exponent
   if( tolower(*pos) == 'e' )
   {
      has_emptyexponent = true;
      pos++;

      // 6. Exponent sign
      if( (*pos == '+') || (*pos == '-') )
         pos++;

      // 7. Exponent digits
      while( (*pos >= '0') && (*pos <= '9') )
      {
         has_emptyexponent = false;
         pos++;
      }
   }

   if( has_emptyexponent || !has_digits ){
       //printf("readString() end3\n");
      return false;
   }

   //read up to dot recording digits
   t = tmp;
   pos = s;

   if( *pos == '+' )
      pos++;

   while( ((*pos >= '0') && (*pos <= '9') ) || *pos == '+' || *pos == '-'  )
   {
      *t++ = *pos;
      pos++;
   }
   //record digits after dot, recording positions
   decshift = 0;
   if( *pos == '.' )
   {
      pos++;
      while( (*pos >= '0') && (*pos <= '9') )
      {
         *t++ = *pos;
         decshift++;
         pos++;
      }
   }
   *t = '\0';

   if( mpq_set_str(rational, tmp, 10) != 0){
      return false;
   }
   mpq_canonicalize(rational);

   //record exponent and update final result
   exponent = -decshift;
   if( tolower(*pos) == 'e' )
   {
      pos++;
      for( t = tmp; *pos != '\0'; pos++ )
         *t++ = *pos;
      *t = '\0';
      exponent += atol(tmp);
   }
   if( exponent > 0 )
   {
      mpz_ui_pow_ui(shiftpower, 10, exponent);
      mpq_set_z(shiftpowerRational, shiftpower);
      mpq_mul(rational, rational, shiftpowerRational);
   }
   else if( exponent < 0 )
   {
      mpz_ui_pow_ui(shiftpower, 10, -exponent);
      mpq_set_z(shiftpowerRational, shiftpower);
      mpq_div(rational, rational, shiftpowerRational);
   }

   mpq_canonicalize(rational);
   this->value = cached_rational_set_mpq(this->cache, rational);
   mpq_clear(rational);
   mpz_clear(shiftpower);
   mpq_clear(shiftpowerRational);
   return true;
}

std::string rationalToString(const CachedRational& r, const int precision){
#if defined(_WIN32) || defined(_WIN64) || defined(__APPLE__)
    std::stringstream sstream;
    sstream << r;
    return sstream.str();
#else
    char cstring[64];
    cached_rational_get_str(r.cache, r.value, cstring, precision);
    std::string retString = std::string(cstring);
    
    return retString;
#endif
}

///@TODO
bool readStringRational(const char* s, CachedRational& value){
    //TODO
    return 1;
}

//@todo
//as we use cached gmp numbers, it should be infinite.
int CachedRational::precision()
{
   return sizeof(long double);
}

//this is also not correct for gmp numbers
int CachedRational::sizeInBase(const int base) const
{
   return precision();
}


void CachedRational::set_den(mpz_t den){
    mpq_t temp;
    mpq_init(temp);
    cached_rational_get_mpq(this->cache, this->value, temp);
    mpq_set_den(temp, den);
    this->value = cached_rational_set_mpq(this->cache, temp);
    mpq_clear(temp);
}

void CachedRational::set_num(mpz_t num){
    mpq_t temp;
    mpq_init(temp);
    cached_rational_get_mpq(this->cache, this->value, temp);
    mpq_set_num(temp, num);
    this->value = cached_rational_set_mpq(this->cache, temp);
    mpq_clear(temp);
}

void CachedRational::copy_mpq(mpq_t& copy) const{
    cached_rational_get_mpq(this->cache, this->value, copy);
}

void CachedRational::set_num_den(mpz_t num, mpz_t den){
    this->value = cached_rational_set(this->cache, num, den);
}

void CachedRational::canonicalize(){
    mpq_t temp;
    mpq_init(temp);
    cached_rational_get_mpq(this->cache, this->value, temp);
    mpq_canonicalize(temp);
    this->value = cached_rational_set_mpq(this->cache, temp);
    mpq_clear(temp);
}


//those functions are empty in soplex as well, just their existence is required
void CachedRational::enableListMem()
{
   // because list memory is not used when SOPLEX_WITH_GMP is not defined, there is nothing to do here
}

void CachedRational::freeListMem()
{
   // because list memory is not used when SOPLEX_WITH_GMP is not defined, there is nothing to do here
}

void CachedRational::disableListMem()
{
   // because list memory is not used when SOPLEX_WITH_GMP is not defined, there is nothing to do here
}

/// Total size of rational vector.
int totalSizeRational(const CachedRational* vector, const int length, const int base)
{
   assert(vector != 0);
   assert(length >= 0);
   assert(base >= 0);

   int size = 0;

   for( int i = 0; i < length; i++ )
      size += vector[i].sizeInBase(base);

   return size;
}



/// Size of least common multiple of denominators in rational vector.
int dlcmSizeRational(const CachedRational* vector, const int length, const int base)
{
   assert(vector != 0);
   assert(length >= 0);
   assert(base >= 0);

   return 0;
}



/// Size of largest denominator in rational vector.
int dmaxSizeRational(const CachedRational* vector, const int length, const int base)
{
   assert(vector != 0);
   assert(length >= 0);
   assert(base >= 0);

   return 0;
}

}
