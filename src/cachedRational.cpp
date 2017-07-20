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
}

CachedRational::CachedRational(mpq_t q, const MasterCache* cache){
  this->value = cached_rational_set_mpq(cache, q);
  this->cache = cache;
}

CachedRational::CachedRational(mpz_t z1, mpz_t z2, const MasterCache* cache){
  this->value = cached_rational_set(cache, z1, z2);
  this->cache = cache;
}

CachedRational::CachedRational(cachedInt c1, cachedInt c2, const MasterCache* cache){
  this->value = cached_rational_set_cached(cache, c1, c2);
  this->cache = cache;
}

CachedRational::CachedRational(CachedInt& c1, CachedInt& c2, const MasterCache* cache){
  this->value = cached_rational_set_cached(cache, c1.getValue(), c2.getValue());
  this->cache = cache;
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
  assert(this->cache == ci.getCache());

  this->value = ci.getValue();
  return *this;
}

CachedRational& CachedRational::operator=(mpq_t& q){
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

CachedRational CachedRational::operator/(const CachedRational& i){
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_div(this->cache, this->value, i.getValue());
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::reduce(){
  cachedRational result = cached_rational_reduce(this->cache, this->value);
  CachedRational returnValue;
  returnValue.cache = this->cache;
  returnValue.value = result;
  return returnValue;
}

CachedRational CachedRational::inv(){
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

CachedRational::operator double(){
  return cached_rational_get_d(this->cache, this->value);
}

const MasterCache* CachedRational::getCache() const{
  return this->cache;
}

cachedRational CachedRational::getValue() const{
  return this->value;
}

}
