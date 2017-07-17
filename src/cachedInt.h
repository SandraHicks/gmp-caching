 /**
  * @file cachedInt.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedInts
  */

#include "master_cache_integer.h"
#include "mastercache.h"

namespace gmpcaching{

  class CachedInt
  {
    private:
      cachedInt value;
      const MasterCache* cache;

    public:
      /*
        Constructors
      */

      CachedInt(mpz_t z, const MasterCache* cache);

      CachedInt(int i, const MasterCache* cache);

      CachedInt(long l, const MasterCache* cache);

      CachedInt(const CachedInt& ci);

      CachedInt(cachedInt val, const MasterCache* cache);

      ~CachedInt();

      const MasterCache* getCache() const;

      /*
        Operators and Functions
      */

      CachedInt& operator=(const CachedInt& ci);

      CachedInt& operator=(mpz_t& z);

      CachedInt& operator=(int i);

      CachedInt& operator=(long l);

      CachedInt operator+(const CachedInt& i);

      CachedInt operator-(const CachedInt& i);

      CachedInt operator*(const CachedInt& i);

      CachedInt operator/(const CachedInt& i);

      CachedInt operator%(const CachedInt& i);

      int invert(CachedInt* res, CachedInt& m);
      CachedInt gcd(CachedInt& i);
      CachedInt lcm(CachedInt& i);
      CachedInt abs();
      CachedInt neg();
      int sign();

      explicit operator double();

      cachedInt getValue() const;
  };
}
