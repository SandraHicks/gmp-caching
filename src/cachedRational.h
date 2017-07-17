 /**
  * @file cachedRational.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedRationals
  */

#include "master_cache_rational.h"

namespace gmpcaching{

  class CachedRational
  {
    private:
      cachedRational value;
      MasterCache* cache;

    public:

      CachedRational(mpq_t q, const MasterCache& cache);

      CachedRational(mpz_t z1, mpz_t z2, const MasterCache& cache);

      CachedRational(cachedInt c1, cachedInt c2, const MasterCache& cache);

      CachedRational(CachedInt* c1, CachedInt* c2, const MasterCache& cache);

      CachedRational(cachedRational* val, const MasterCache& cache);

      CachedRational(CachedRational* val);

      ~CachedRational();

      CachedRational& operator=(const CachedRational& ci);

      CachedRational& operator=(const mpq_t& q);

      CachedRational& operator=(const mpz_t& z1, const mpz_t z2);

      CachedRational& operator=(const int& i1, const int& i2);

      CachedRational& operator=(const long& l1, const long& l2);

      CachedRational operator+(const CachedRational& i) const;

      CachedRational operator-(const CachedRational& i) const;

      CachedRational operator*(const CachedRational& i) const;

      CachedRational operator/(const CachedRational& i) const;

      CachedRational& reduce();
      CachedRational& inv();
      CachedRational& abs();
      CachedRational& neg();
      int sign();

      explicit operator double();

      MasterCache* getCache() const;

      cachedRational getValue() const;
  };

}
