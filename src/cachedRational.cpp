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


namespace gmpcaching{

/*
constructors
*/
CachedRational::CachedRational(const MasterCache* cache){
    this->cache = NULL;
    cachedRational val;
    val.counter = 0;
    val.denominator = 0;
    this->value = val;
}

CachedRational::CachedRational(const int i, const MasterCache* cache){
    
    cachedRational val;
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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

CachedRational::CachedRational(mpq_t q, const MasterCache* cache){
    cachedRational val;
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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
  //how to check if c1 and c2 have same cache? NOT
    cachedRational val;
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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
                GMPCaching.init_MasterCache(GMPCACHING_CACHESIZE);
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

CachedRational& CachedRational::operator=(mpq_t& q){
  if(!this->cache){
      throw new RationalCacheNotSetException(this->value.counter, this->value.denominator);
  }
  this->value = cached_rational_set_mpq(this->cache, q);
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<mpz_t&, mpz_t&> mpzts){
  assert(this->cache != NULL);
  this->value = cached_rational_set(this->cache, mpzts.first, mpzts.second);
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<int, int> ints){
  assert(this->cache != NULL);
  this->value = cached_rational_set_cached(this->cache, (uint64_t)ints.first, (uint64_t)ints.second);
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<long, long> longs){
  assert(this->cache != NULL);
  this->value = cached_rational_set_cached(this->cache, (uint64_t)longs.first, (uint64_t)longs.second);
  return *this;
}

CachedRational& CachedRational::operator=(const long double &r){
    assert(this->cache != NULL);
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, double(r));
    this->value = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    return *this;
}

CachedRational& CachedRational::operator=(const double &r){
    assert(this->cache != NULL);
    mpq_t value;
    mpq_init(value);
    mpq_set_d(value, r);
    this->value = cached_rational_set_mpq(this->cache, value);
    mpq_clear(value);
    return *this;
}

CachedRational& CachedRational::operator=(const int &i){
    assert(this->cache != NULL);
    this->value = cached_rational_set_cached(this->cache, (uint64_t)i, (uint64_t)0);
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
    assert(r.cache == s.cache);
    assert(this->cache == r.cache);
    cachedRational product = cached_rational_mul(r.cache, r.value, s.getValue());
    cachedRational sum = cached_rational_add(this->cache, this->value, product);
    this->value = sum;
    return *this;
}

CachedRational& CachedRational::subProduct(const CachedRational& r, const CachedRational& s){
    assert(r.cache == s.cache);
    assert(this->cache == r.cache);
    cachedRational product = cached_rational_mul(r.cache, r.value, s.getValue());
    cachedRational sub = cached_rational_sub(this->cache, this->value, product);
    this->value = sub;
    return *this;
}

CachedRational& CachedRational::addQuotient(const CachedRational& r, const CachedRational& s){
    assert(r.cache == s.cache);
    assert(this->cache == r.cache);
    cachedRational product = cached_rational_div(r.cache, r.value, s.getValue());
    cachedRational sum = cached_rational_add(this->cache, this->value, product);
    this->value = sum;
    return *this;
}

CachedRational& CachedRational::subQuotient(const CachedRational& r, const CachedRational& s){
    assert(r.cache == s.cache);
    assert(this->cache == r.cache);
    cachedRational product = cached_rational_div(r.cache, r.value, s.getValue());
    cachedRational sub = cached_rational_sub(this->cache, this->value, product);
    this->value = sub;
    return *this;
}


CachedRational CachedRational::reduce(){
  cachedRational result = cached_rational_reduce(this->cache, this->value);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::invert(){
  cachedRational result = cached_rational_inv(this->cache, this->value);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational spxAbs(const CachedRational& r){
  cachedRational result = cached_rational_abs(r.cache, r.value);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::neg(){
  cachedRational result = cached_rational_neg(this->cache, this->value);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
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

bool CachedRational::hasSameCache(CachedRational& i) const{
    if(this->cache == i.cache){
        return true;
    }
    else{
        return false;
    }
}

/// Negation.
CachedRational operator-(const CachedRational& r)
{
   cachedRational val = cached_rational_neg(r.getCache(), r.getValue());
   CachedRational res = r;
   res.setValue(val);
   return res;
}

CachedRational& CachedRational::powRound(){
    //not implemented in rational
    return *this;
}

  /*
   * COMPARISONS
   */

bool CachedRational::isAdjacentTo(const double& d) const{
    return double(*this) == d;
}

bool CachedRational::isNextTo(const double& d){
    return *this == d;
}



int compareRational(const CachedRational& r, const CachedRational& s){
    return cached_rational_cmp(r.cache, s.value, s.value);
}

bool operator!=(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, s.value, s.value);
    return cmp != 0;
}
      
bool operator==(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == 0;
}

bool operator<(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == -1;
}

bool operator<=(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp <= 0;
}

bool operator>(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp == 1;
}

bool operator>=(const CachedRational& r, const CachedRational& s){
    int cmp = cached_rational_cmp(r.cache, r.value, s.value);
    return cmp >= 0;
    //attention: this function also returns true if NaN or bad inifinities are given
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
    
    cachedRational result = cached_rational_sub(r.cache, r.value, val);
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
    
    cachedRational result = cached_rational_div(r.cache, r.value, val);
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
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_add(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational operator-(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_sub(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational operator*(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_mul(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational operator/(const int& d, const CachedRational& r){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_div(r.cache, r.value, intval);
  CachedRational returnValue;
  returnValue.cache = r.cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator+(const int& d) const{
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_add(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator-(const int& d) const{
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_sub(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator*(const int& d) const{
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_mul(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator/(const int& d) const{
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_div(this->cache, this->value, intval);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}
CachedRational CachedRational::operator+=(const int& d){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_add(this->cache, this->value, intval);
  this->value = result;
  return *this;
}
CachedRational CachedRational::operator-=(const int& d){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_sub(this->cache, this->value, intval);
  this->value = result;
  return *this;
}
CachedRational CachedRational::operator*=(const int& d){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_mul(this->cache, this->value, intval);
  this->value = result;
  return *this;
}
CachedRational CachedRational::operator/=(const int& d){
    cachedRational intval;
    if(d <= 0){
        intval = {((uint64_t)(d * (-1)) | NEG), (uint64_t)1};
    }
    else{
       intval = {(uint64_t)d, (uint64_t)1}; 
    }
  cachedRational result = cached_rational_div(this->cache, this->value, intval);
  this->value = result;
  return *this;
}

//string out
std::ostream& operator<<(std::ostream& os, const CachedRational& r)
{
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

std::string rationalToString(const CachedRational& r, const int precision){
    //TODO
    return "";
}
bool readStringRational(const char* s, CachedRational& value){
    //TODO
    return 1;
}

#define MAX_STR_LEN 10000
bool CachedRational::readString(const char* s){
    assert(s != 0);
    assert(strlen(s) <= MAX_STR_LEN);
    mpq_t rational;
    
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


/// provides read-only access to underlying mpq_t
const mpq_t* CachedRational::getMpqPtr() const {
   mpz_t d;
   mpz_t c;
   mpz_init(c);
   mpz_init(d);
   cached_int_get(this->cache, this->value.counter, c);
   cached_int_get(this->cache, this->value.denominator, d);
   mpq_t value;
   mpz_set(&(value->_mp_den), d);
   mpz_set(&(value->_mp_num), c);
   return &(value);
}



/// provides read-only access to underlying mpq_t
const mpq_t& CachedRational::getMpqRef() const {
   mpz_t d;
   mpz_t c;
   mpz_init(c);
   mpz_init(d);
   cached_int_get(this->cache, this->value.counter, c);
   cached_int_get(this->cache, this->value.denominator, d);
   mpq_t value;
   mpz_set(&(value->_mp_den), d);
   mpz_set(&(value->_mp_num), c);
   return value;
}



/// provides write access to underlying mpq_t; use with care
mpq_t* CachedRational::getMpqPtr_w() const {
   mpz_t d;
   mpz_t c;
   mpz_init(c);
   mpz_init(d);
   cached_int_get(this->cache, this->value.counter, c);
   cached_int_get(this->cache, this->value.denominator, d);
   mpq_t value;
   mpz_set(&(value->_mp_den), d);
   mpz_set(&(value->_mp_num), c);
   return &(value);
}



/// provides write access to underlying mpq_t; use with care
mpq_t& CachedRational::getMpqRef_w() const {
   mpz_t d;
   mpz_t c;
   mpz_init(c);
   mpz_init(d);
   cached_int_get(this->cache, this->value.counter, c);
   cached_int_get(this->cache, this->value.denominator, d);
   mpq_t value;
   mpz_set(&(value->_mp_den), d);
   mpz_set(&(value->_mp_num), c);
   return value;
}


}
