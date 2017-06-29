 /**
  * @file cachedRational.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedRationals
  */

#include "master-cache-rational.h"

namespace gmp-caching{

  class CachedRational
  {
    private:
      cachedRational* value;

    public:

      CachedRational& operator=(const CachedRational& ci);

      CachedRational& operator=(const mpq_t& q);

      CachedRational& operator=(const mpz_t& z1, const mpz_t z2);

      CachedRational& operator=(const int& i1, const int& i2);

      CachedRational& operator=(const long& l1, const long& l2);

      CachedRational operator+(const CachedRational& i) const;

      CachedRational operator-(const CachedRational& i) const;

      CachedRational operator*(const CachedRational& i) const;

      CachedRational operator/(const CachedRational& i) const;
  }

}
