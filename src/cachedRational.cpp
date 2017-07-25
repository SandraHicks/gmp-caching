 /**
  * @file cachedRational.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedRationals
  */

#include "cachedRational.h"

#include <cassert>
#include <cstdint>


namespace gmpcaching{

/*
constructors
*/
CachedRational::CachedRational(){
    this->cache = NULL;
    cachedRational val;
    val.counter = 0;
    val.denominator = 0;
    this->value = val;
}

CachedRational::CachedRational(int i, const MasterCache* cache){
    this->cache = cache;
    cachedRational val;
    if(cache == NULL){
        if(i>0){
            val.counter = (uint64_t)i;
            val.denominator = 0;
        }
        else{
            val.counter = (uint64_t)(i*-1);
            val.counter |= (uint64_t)1 << 63;
            val.denominator = 0;
        }
    }
    else{
        val = cached_rational_set_i(cache, i);
    }
    this->value = val;
}

CachedRational::CachedRational(mpq_t q, const MasterCache* cache){
    if(cache == NULL){
        cachedRational val;
        val.counter = 0;
        val.denominator = 0;
        this->value = val;
        this->cache = NULL;
    }
    else{
        this->value = cached_rational_set_mpq(cache, q);
        this->cache = cache;
    }
}

CachedRational::CachedRational(mpz_t z1, mpz_t z2, const MasterCache* cache){
    if(cache == NULL){
        cachedRational val;
        val.counter = 0;
        val.denominator = 0;
        this->value = val;
        this->cache = NULL;
    }
    else{
        this->value = cached_rational_set(cache, z1, z2);
        this->cache = cache;
    }
}

CachedRational::CachedRational(cachedInt c1, cachedInt c2, const MasterCache* cache){
  //how to check if c1 and c2 have same cache?
    if(cache == NULL){
        cachedRational val;
        val.counter = 0;
        val.denominator = 0;
        this->value = val;
        this->cache = NULL;
    }
    else{
        this->value = cached_rational_set_cached(cache, c1, c2);
        this->cache = cache;
    }
}

CachedRational::CachedRational(CachedInt& c1, CachedInt& c2, const MasterCache* cache){
    if(cache == NULL){
        cachedRational val;
        val.counter = 0;
        val.denominator = 0;
        this->value = val;
        this->cache = NULL;
    }
    else{
        assert(c1.getCache() == c2.getCache());
        this->value = cached_rational_set_cached(cache, c1.getValue(), c2.getValue());
        this->cache = cache;
    }
}

CachedRational::CachedRational(cachedRational val, const MasterCache* cache){
  this->cache = cache;
  this->value = val;
}

CachedRational::CachedRational(CachedRational& val){
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
  this->value = cached_rational_set(this->cache, mpzts.first, mpzts.second);
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<int, int> ints){
  this->value = cached_rational_set_cached(this->cache, (uint64_t)ints.first, (uint64_t)ints.second);
  return *this;
}

CachedRational& CachedRational::operator=(std::pair<long, long> longs){
  this->value = cached_rational_set_cached(this->cache, (uint64_t)longs.first, (uint64_t)longs.second);
  return *this;
}

/*
operators
*/
CachedRational CachedRational::operator+(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_add(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::operator-(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_sub(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::operator*(const CachedRational& i){
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

CachedRational CachedRational::operator/(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_div(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
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


bool CachedRational::operator==(const CachedRational& i) const{
    //TODO implement comparison function in gmp-caching
    return 0;
}
      
bool CachedRational::operator==(int i) const{
    cachedRational reduced = cached_rational_reduce(this->cache, this->value);
    if(!cached_rational_isID(reduced)){
        return ((int64_t)i == (int64_t)reduced.counter) && ((int64_t)reduced.denominator == 0);
    }
    return 0;
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

CachedRational CachedRational::abs(){
  cachedRational result = cached_rational_abs(this->cache, this->value);
  CachedRational returnValue;
  returnValue.cache = this->cache;
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

int CachedRational::sign(){
  return cached_rational_sgn(this->cache, this->value);
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

bool CachedRational::hasSameCache(CachedRational& i) const{
    if(this->cache == i.cache){
        return true;
    }
    else{
        return false;
    }
}

}
