 /**
  * @file cachedInt.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedInts
  */


#include "cachedInt.h"
#include <cassert>
#include <cstdint>

namespace gmpcaching{

/*
constructors
*/

CachedInt::CachedInt(cachedInt val, const MasterCache* cache){
  this->value = val;
  this->cache = cache;
}

CachedInt::CachedInt(mpz_t z, const MasterCache* cache){
  this->value = cached_int_set(cache, z);
  this->cache = cache;
}

CachedInt::CachedInt(int i, const MasterCache* cache){
  this->value = (uint64_t)i;
  this->cache = cache;
}

CachedInt::CachedInt(long l, const MasterCache* cache){
  this->value = (uint64_t)l;
  this->cache = cache;
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

/*
assignment
*/
CachedInt& CachedInt::operator=(const CachedInt& ci){
  assert(this->cache == ci.getCache());

  this->value = ci.getValue();

  return *this;
}

CachedInt& CachedInt::operator=(mpz_t& z){
  this->value = cached_int_set(this->getCache(), z);

  return *this;
}

CachedInt& CachedInt::operator=(int i){
  this->value = (uint64_t)i;

  if(i < 0){
    this->value = cached_int_neg(this->getCache(), this->value);
  }

  return *this;
}

CachedInt& CachedInt::operator=(long l){
  this->value = (uint64_t)l;

  if(l < 0){
    this->value = cached_int_neg(this->getCache(), this->value);
  }

  return *this;
}

/*
operators
*/

CachedInt::operator double(){
  return cached_int_get_d(this->getCache(), this->value);
}


CachedInt CachedInt::operator+(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt op = i.getValue();

  cachedInt result = cached_int_add(this->getCache(), this->value, op);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator-(const CachedInt& i){
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_sub(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator*(const CachedInt& i){
  assert(this->getCache() == i.getCache());

  cachedInt result = cached_int_mul(this->getCache(), this->value, i.getValue());
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator/(const CachedInt& i){
  assert(this->getCache() == i.getCache());
  cachedInt rest;
  cachedInt result = cached_int_tdiv(this->getCache(), this->value, i.getValue(), &rest);
  const MasterCache* cache = this->getCache();
  CachedInt res = CachedInt(result, cache);
  return res;
}

CachedInt CachedInt::operator%(const CachedInt& i){
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

}
