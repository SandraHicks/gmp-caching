 /**
  * @file cachedRational.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedRationals
  */

#include "cachedRational.h"

namespace gmp-caching{

/*
constructors
*/


CachedRational::CachedRational(mpq_t q, Mastercache& cache){
  this->value = cached_rational_set_mpq(cache, q);
  this->cache = cache;
}

CachedRational::CachedRational(mpz_t z1, mpz_t z2, Mastercache& cache){
  this->value = cached_rational_set(cache, z1, z2);
  this->cache = cache;
}

CachedRational::CachedRational(cachedInt c1, cachedInt c2, Mastercache& cache){
  this->value = cached_rational_set_cached(cache, c1, c2);
  this->cache = cache;
}

CachedRational::CachedRational(CachedInt* c1, CachedInt* c2, Mastercache& cache){
  this->value = cached_rational_set_cached(cache, c1.getValue(), c2.getValue());
  this->cache = cache;
}

CachedRational::CachedRational(cachedRational* val, Mastercache& cache){
  this->cache = cache;
  this->value = *val;
}

CachedRational::CachedRational(CachedRational* val){
  this->cache = val.getCache();
  this->value = val.getValue();
}

CachedRational::~CachedRational(){

}

/*
assignments
*/

CachedRational& CachedRational::operator=(const CachedRational& ci){
  this->value = ci.getValue();
  this->cache = ci.getCache();
}

CachedRational& CachedRational::operator=(const mpq_t& q){
  this->value = cached_rational_set_mpq(this->cache, q);
}

CachedRational& CachedRational::operator=(std::pair<const mpz_t, const mpz_t> z){
  this->value = cached_rational_set(this->cache, z.first, z.second);
}

CachedRational& CachedRational::operator=(std::pair<const int, const int> i){
  this->value = cached_rational_set_cached(this->cache, (uint64_t)i.first, (uint64_t)i.second);
}

CachedRational& CachedRational::operator=(std::pair<const long, const long> l){
  this->value = cached_rational_set_cached(this->cache, (uint64_t)l.first, (uint64_t)l.second);
}

/*
operators
*/
CachedRational CachedRational::operator+(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_add(this->cache, &(this->value), &(i.getValue()));
  return CachedRational(result, this->cache);
}

CachedRational CachedRational::operator-(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_sub(this->cache, &(this->value), &(i.getValue()));
  return CachedRational(result, this->cache);
}

CachedRational CachedRational::operator*(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_mul(this->cache, &(this->value), &(i.getValue()));
  return CachedRational(result, this->cache);
}

CachedRational CachedRational::operator/(const CachedRational& i) const{
  assert(this->cache == i.cache);
  cachedRational result = cached_rational_div(this->cache, &(this->value), &(i.getValue()));
  return CachedRational(result, this->cache);
}

CachedRational& CachedRational::reduce(){
  cachedRational result = cached_rational_reduce(this->cache, this->value);
  return CachedRational(result, this->cache);
}

CachedRational& CachedRational::inv(){
  cachedRational result = cached_rational_inv(this->cache, this->value);
  return CachedRational(result, this->cache);
}

CachedRational& CachedRational::abs(){
  cachedRational result = cached_rational_abs(this->cache, this->value);
  return CachedRational(result, this->cache);
}

CachedRational& CachedRational::neg(){
  cachedRational result = cached_rational_neg(this->cache, &(this->value));
  return CachedRational(result, this->cache);
}

int CachedRational::sign(){
  return cached_rational_sgn(this->cache, this->value);
}

explicit operator CachedRational::double() const{
  return cached_rational_get_d(this->cache, this->value);
}

MasterCache& CachedRational::getCache(){
  return this->cache;
}

cachedRational CachedRational::getValue(){
  return this->value;
}

}
