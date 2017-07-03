 /**
  * @file cachedRational.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedRationals
  */

#include "master-cache-rational.h"

namespace gmp-caching{

  class CachedRational
  {
    private:
      cachedRational value;
      Mastercache* cache;

    public:

      CachedRational(mpq_t q, Mastercache& cache);

      CachedRational(mpz_t z1, mpz_t z2, Mastercache& cache);

      CachedRational(cachedInt c1, cachedInt c2, Mastercache& cache);

      CachedRational(CachedInt* c1, CachedInt* c2, Mastercache& cache);

      CachedRational(cachedRational* val, Mastercache& cache);

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

      explicit operator double() const;

      MasterCache& getCache();

      cachedRational getValue();
  }

}
