 /**
  * @file cachedInt.cpp
  * @author Sandra Hicks
  * @brief wrapper class for cachedInts
  */

#include "master-cache-integer.h"

namespace gmp-caching{

  class CachedInt
  {
    private:
      cachedInt value;

    public:
      CachedInt& operator=(const CachedInt& ci);

      CachedInt& operator=(const mpz_t& z);

      CachedInt& operator=(const int& i);

      CachedInt& operator=(const long& l);

      CachedInt operator+(const CachedInt& i) const;

      CachedInt operator-(const CachedInt& i) const;

      CachedInt operator*(const CachedInt& i) const;

      CachedInt operator/(const CachedInt& i) const;

      CachedInt operator%(const CachedInt& i) const;

      CachedInt& invert(const CachedInt& i, const CachedInt& m);

      CachedInt& gcd(const CachedInt& i, const CachedInt& m);

      CachedInt& lcm(const CachedInt& i, const CachedInt& m);
  }

}
