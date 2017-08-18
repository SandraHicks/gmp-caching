 /**
  * @file cachedInt.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedInts
  */


#include "cachedInt.h"
#include "gmpcachingxx.h"
#include <cassert>
#include <cstdint>

namespace gmpcaching{

/*
constructors
*/
CachedInt::CachedInt(const MasterCache* cache){
  this->value = 0;
  this->cache = cache;
}
    
CachedInt::CachedInt(cachedInt val, const MasterCache* cache){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = val;
}

CachedInt::CachedInt(const mpz_t &z, const MasterCache* cache){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = cached_int_set(this->cache, z);
}

CachedInt::CachedInt(const int &i, const MasterCache* cache){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = (uint64_t)i;
}

CachedInt::CachedInt(const long &l, const MasterCache* cache){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = (uint64_t)l;
}

CachedInt::CachedInt(const double &d, const MasterCache* cache){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    this->value = val;
}

CachedInt::CachedInt(const CachedInt& ci){
  this->value = ci.getValue();
  this->cache = ci.getCache();
}

CachedInt::~CachedInt(){

}

const MasterCache* CachedInt::getCache() const{
	//return address to cache
  return this->cache;
}

bool CachedInt::hasSameCache(const CachedInt &i) const{
    if(this->cache == i.cache){
        return true;
    }
    else{
        return false;
    }
}

/*
assignment
*/
CachedInt& CachedInt::operator=(const CachedInt& ci){
  assert(this->cache == ci.getCache());

  this->value = ci.getValue();

  return *this;
}

CachedInt& CachedInt::operator=(const mpz_t& z){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = cached_int_set(this->getCache(), z);

    return *this;
}

CachedInt& CachedInt::operator=(const int &i){
  //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = (uint64_t)i;

    if(i < 0){
      this->value = cached_int_neg(this->getCache(), this->value);
    }

    return *this;
}

CachedInt& CachedInt::operator=(const long &l){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    this->value = (uint64_t)l;

    if(l < 0){
      this->value = cached_int_neg(this->getCache(), this->value);
    }

    return *this;
}

CachedInt& CachedInt::operator=(const double &d){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    this->value = val;
    return *this;
}

CachedInt& CachedInt::operator=(const long double &d){
    //check for NULL cache
    if(cache == NULL){
        if(globalcache == NULL){
            #ifdef GMPCACHING_CACHESIZE
                GMPCaching::init_MasterCache(GMPCACHING_CACHESIZE);
            #else
                throw new IntegerCacheNotSetException();
            #endif
        }
        this->cache = globalcache;
    }
    else{
        this->cache = cache;
    }
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, double(d));
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    this->value = val;
    return *this;
}

/// Negation.
CachedInt operator-(const CachedInt& r)
{
   cachedInt val = cached_int_neg(r.getCache(), r.getValue());
   CachedInt res = r;
   res.setValue(val);
   return res;
}

CachedInt& CachedInt::addProduct(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedInt product = cached_int_mul(r.cache, r.value, s.getValue());
    cachedInt sum = cached_int_add(this->cache, this->value, product);
    this->value = sum;
    return *this;
}

CachedInt& CachedInt::subProduct(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedInt product = cached_int_mul(r.cache, r.value, s.getValue());
    cachedInt sub = cached_int_sub(this->cache, this->value, product);
    this->value = sub;
    return *this;
}

CachedInt& CachedInt::addQuotient(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedInt rest;
    cachedInt product = cached_int_tdiv(r.cache, r.value, s.getValue(), &rest);
    cachedInt sum = cached_int_add(this->cache, this->value, product);
    this->value = sum;
    return *this;
}

CachedInt& CachedInt::subQuotient(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    assert(this->hasSameCache(r));
    cachedInt rest;
    cachedInt product = cached_int_tdiv(r.cache, r.value, s.getValue(), &rest);
    cachedInt sub = cached_int_sub(this->cache, this->value, product);
    this->value = sub;
    return *this;
}

/*
operators
*/

CachedInt::operator double() const{
  return cached_int_get_d(this->getCache(), this->value);
}

CachedInt::operator long double() const{
  double val = cached_int_get_d(this->getCache(), this->value);
  long double nval = static_cast<long double>(val);
  return nval;
}


CachedInt CachedInt::operator+(const CachedInt& i) const{
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt result = cached_int_add(this->getCache(), this->value, op);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator+=(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt result = cached_int_add(this->getCache(), this->value, op);
  this->value = result;
  return *this;
}

CachedInt CachedInt::operator-(const CachedInt& i) const{
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_sub(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator-=(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt result = cached_int_sub(this->getCache(), this->value, op);
  this->value = result;
  return *this;
}

CachedInt CachedInt::operator*(const CachedInt& i) const{
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_mul(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator*=(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt result = cached_int_mul(this->getCache(), this->value, op);
  this->value = result;
  return *this;
}

CachedInt CachedInt::operator/(const CachedInt& i) const{
  assert(this->getCache() == i.getCache());
  cachedInt rest;
  cachedInt result = cached_int_tdiv(this->getCache(), this->value, i.getValue(), &rest);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator/=(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt rest;
  cachedInt result = cached_int_tdiv(this->getCache(), this->value, op, &rest);
  this->value = result;
  return *this;
}

CachedInt CachedInt::operator%(const CachedInt& i) const{
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_mod(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  return CachedInt(result, cache);
}

int CachedInt::invert(CachedInt* res, CachedInt& m){
  assert(this->getCache() == m.getCache());

  cachedInt result;
  int hasInverse = cached_int_invert(this->getCache(), this->value, m.getValue(), &result);
  if(hasInverse > 0){
    const MasterCache* cache = this->getCache();
    CachedInt r = CachedInt(result, cache);
    res = &r;
    return 1;
  }
  else{
    return 0;
  }
}

CachedInt CachedInt::operator+(const double& d) const{
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_add(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator-(const double& d) const{
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_sub(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator*(const double& d) const{
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_mul(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator/(const double& d) const{
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt rest;
    cachedInt result = cached_int_tdiv(this->cache, this->value, val, &rest);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator+=(const double& d){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_add(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator-=(const double& d){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_sub(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator*=(const double& d){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_mul(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator/=(const double& d){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(this->cache, value);
    mpz_clear(value);
    
    cachedInt rest;
    cachedInt result = cached_int_tdiv(this->cache, this->value, val, &rest);
    this->value = result;
    return *this;
}
      
CachedInt CachedInt::operator+(const int& d) const{
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_add(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator-(const int& d) const{
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_sub(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator*(const int& d) const{
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_mul(this->cache, this->value, val);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator/(const int& d) const{
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt rest;
    cachedInt result = cached_int_tdiv(this->cache, this->value, val, &rest);
    CachedInt returnValue;
    returnValue.cache = this->cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt CachedInt::operator+=(const int& d){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_add(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator-=(const int& d){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_sub(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator*=(const int& d){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_mul(this->cache, this->value, val);
    this->value = result;
    return *this;
}
CachedInt CachedInt::operator/=(const int& d){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt rest;
    cachedInt result = cached_int_tdiv(this->cache, this->value, val, &rest);
    this->value = result;
    return *this;
}

CachedInt CachedInt::gcd(CachedInt& i){
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_gcd(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt resultWrapper = CachedInt(result, cache);
  return resultWrapper;
}

CachedInt CachedInt::lcm(CachedInt& i){
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_lcm(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::abs(){
  cachedInt result = cached_int_abs(this->getCache(), this->value);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::neg(){
  cachedInt result = cached_int_neg(this->getCache(), this->value);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

int CachedInt::sign(){
  return cached_int_sgn(this->getCache(), this->value);
}

cachedInt CachedInt::getValue() const{
  return this->value;
}
void CachedInt::setValue(cachedInt val){
    if(this->cache == NULL){
        throw new IntegerCacheNotSetException(val);
    }
    this->value = val;
}


int compareInt(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    return cached_int_cmp(r.cache, r.value, s.value);
}
bool operator!=(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp != 0);
}
bool operator==(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp == 0);
}
bool operator<(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp == -1);
}
bool operator<=(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp <= 0);
}
bool operator>(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp == 1);
}
bool operator>=(const CachedInt& r, const CachedInt& s){
    assert(r.hasSameCache(s));
    int cmp = cached_int_cmp(r.cache, r.value, s.value);
    return (cmp >= 0);
}

bool operator!=(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp != 0);
}
bool operator==(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == 0);
}
bool operator<(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == -1);
}
bool operator<=(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp <= 0);
}
bool operator>(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == 1);
}
bool operator>=(const CachedInt& r, const double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp >= 0);
}

bool operator!=(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == 1);
}
bool operator<=(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == -1);
}
bool operator>=(const double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp <= 0);
}

bool operator!=(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp != 0);
}
bool operator==(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == 0);
}
bool operator<(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == -1);
}
bool operator<=(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp <= 0);
}
bool operator>(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp == 1);
}
bool operator>=(const CachedInt& r, const long double& s){
    int cmp = cached_int_cmp_d(r.cache, r.value, s);
    return (cmp >= 0);
}

bool operator!=(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == 1);
}
bool operator<=(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp == -1);
}
bool operator>=(const long double& r, const CachedInt& s){
    int cmp = cached_int_cmp_d(s.cache, s.value, r);
    return (cmp <= 0);
}
    

CachedInt operator+(const double& d, const CachedInt& r){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(r.cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_add(r.cache, val, r.value);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator-(const double& d, const CachedInt& r){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(r.cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_sub(r.cache, val, r.value);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator*(const double& d, const CachedInt& r){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(r.cache, value);
    mpz_clear(value);
    
    cachedInt result = cached_int_mul(r.cache, val, r.value);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator/(const double& d, const CachedInt& r){
    mpz_t value;
    mpz_init(value);
    mpz_set_d(value, d);
    cachedInt val = cached_int_set(r.cache, value);
    mpz_clear(value);
    
    cachedInt rest;
    cachedInt result = cached_int_tdiv(r.cache, val, r.value, &rest);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}

bool operator!=(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp != 0);
}
bool operator==(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp == 0);
}
bool operator<(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp == 1);
}
bool operator<=(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp >= 0);
}
bool operator>(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp == -1);
}
bool operator>=(const int& r, const CachedInt& s){
    int cmp = cached_int_cmp_i(s.cache, s.value, r);
    return (cmp <= 0);
}

CachedInt operator+(const int& d, const CachedInt& r){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_add(r.cache, r.value, val);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator-(const int& d, const CachedInt& r){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_sub(r.cache, r.value, val);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator*(const int& d, const CachedInt& r){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt result = cached_int_mul(r.cache, r.value, val);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}
CachedInt operator/(const int& d, const CachedInt& r){
    cachedInt val;
    if(d < 0){
        val = ((uint64_t)(d * (-1)) | NEG);
    }
    else{
        val = (uint64_t)d;
    }
    cachedInt rest;
    cachedInt result = cached_int_tdiv(r.cache, r.value, val, &rest);
    CachedInt returnValue;
    returnValue.cache = r.cache;
    returnValue.value = result;
    return returnValue;
}

}
