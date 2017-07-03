 /**
  * @file cachedInt.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedInts
  */

#include "master-cache-integer.h"
#include "mastercache.h"

namespace gmp-caching{

  class CachedInt
  {
    private:
      cachedInt value;
      Mastercache* cache;

    public:
      /*
        Constructors
      */

      CachedInt(const mpz_t& z, Mastercache& cache);

      CachedInt(const int& i, Mastercache& cache);

      CachedInt(const long& l, Mastercache& cache);

      CachedInt(const CachedInt& ci);

      CachedInt(cachedInt val, Mastercache& cache);

      ~CachedInt();

      MasterCache& getCache();

      /*
        Operators and Functions
      */

      CachedInt& operator=(const CachedInt& ci);

      CachedInt& operator=(const mpz_t& z);

      CachedInt& operator=(const int& i);

      CachedInt& operator=(const long& l);

      CachedInt operator+(const CachedInt& i) const;

      CachedInt operator-(const CachedInt& i) const;

      CachedInt operator*(const CachedInt& i) const;

      CachedInt operator/(const CachedInt& i) const;

      CachedInt operator%(const CachedInt& i) const;

      CachedInt& invert(const CachedInt& m);
      CachedInt& gcd(const CachedInt& i);
      CachedInt& lcm(const CachedInt& i);
      CachedInt& abs();
      CachedInt& neg();
      int sign();

      explicit operator double() const;

      cachedInt getValue();
  }
}
