 /**
  * @file cachedInt.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedInts
  */


#include "cachedInt.h"
#include "assert.h"
#include <stdint>

namespace gmp-caching{

/*
constructors
*/
CachedInt::CachedInt(){
  this->value = (uint64_t)0;
}

CachedInt::CachedInt(cachedInt val, MasterCache& cache){
  this->value = val;
  this->cache = cache;
}

CachedInt::CachedInt(const mpz_t& z, MasterCache& cache){
  this->value = cached_int_set();
  this->cache = cache;
}

CachedInt::CachedInt(const int& i, MasterCache& cache){
  this->value = (uint64_t)i;
  this->cache = cache;
}

CachedInt::CachedInt(const long& l, MasterCache& cache){
  this->value = (uint64_t)l;
  this->cache = cache;
}

CachedInt::CachedInt(const CachedInt& ci);
  this->value = ci.getValue();
  this->cache = ci.getCache();
}

CachedInt::~CachedInt(){

}

MasterCache& CachedInt::getCache(){
  return this->cache;
}

/*
assignment
*/
CachedInt& CachedInt::operator=(const CachedInt& ci){
  assert(this->cache == i.getCache());

  this->value = ci.getValue();

  return *this;
}

CachedInt& CachedInt::operator=(const mpz_t& z){
  this->value = cached_int_set(this->cache, *z);;

  return *this;
}

CachedInt& CachedInt::operator=(const int& i){
  this->value = (uint64_t)i;

  if(i < 0)
    this->value = cached_int_neg(this->cache, this->value);

  return *this;
}

CachedInt& CachedInt::operator=(const long& l){
  this->value = (uint64_t)l;

  if(l < 0)
    this->value = cached_int_neg(this->cache, this->value);

  return *this;
}

/*
operators
*/

CachedInt::operator double() const{
  return cached_int_get_d(this->cache, this->value);
}


CachedInt CachedInt::operator+(const CachedInt& i) const{
  assert(this->cache == i.getCache());

  cachedInt result = cached_int_add(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

CachedInt CachedInt::operator-(const CachedInt& i) const{
  assert(this->cache == i.getCache());

  cachedInt result = cached_int_sub(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

CachedInt CachedInt::operator*(const CachedInt& i) const{
  assert(this->cache == i.getCache());

  cachedInt result = cached_int_mul(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

CachedInt CachedInt::operator/(const CachedInt& i) const{
  assert(this->cache == i.getCache());
  cachedInt* rest;
  cachedInt result = cached_int_tdiv(this->cache, this->value, i.getValue(), rest);
  return CachedInt(result, this->cache);
}

CachedInt CachedInt::operator%(const CachedInt& i) const{
  assert(this->cache == i.getCache());

  cachedInt result = cached_int_mod(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

int CachedInt::invert(CachedInt* res, const CachedInt& m){
  assert(this->cache == m.getCache());

  cachedInt result;
  int hasInverse = cached_int_invert(this->cache, this->value, m.getValue(), &result);
  if(hasInverse > 0){
    res = CachedInt(result, this->cache);
    return 1;
  }
  else{
    return 0;
  }
}

CachedInt& CachedInt::gcd(const CachedInt& i){
  assert(this->cache == i.getCache());
  assert(this->cache == m.getCache());

  cachedInt result = cached_int_gcd(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

CachedInt& CachedInt::lcm(const CachedInt& i){
  assert(this->cache == i.getCache());
  assert(this->cache == m.getCache());

  cachedInt result = cached_int_lcm(this->cache, this->value, i.getValue());
  return CachedInt(result, this->cache);
}

CachedInt& CachedInt::abs()
  cachedInt result = cached_int_abs(this->cache, this->value);
  return CachedInt(result, this->cache);
}

CachedInt& CachedInt::neg()
  cachedInt result = cached_int_neg(this->cache, this->value);
  return CachedInt(result, this->cache);
}

int CachedInt::sign()
  return cached_int_sgn(this->cache, this->value);
}

cachedInt CachedInt::getValue(){
  return this->value;
}

}
