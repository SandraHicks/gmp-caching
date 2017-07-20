 /**
  * @file cachedRational.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedRationals
  */

#include "master_cache_rational.h"
#include "mastercache.h"
#include "cachedInt.h"

#include <utility>

namespace gmpcaching{

  class CachedRational
  {
    private:
      cachedRational value;
      const MasterCache* cache;

    public:

      CachedRational();

      CachedRational(mpq_t q, const MasterCache* cache);

      CachedRational(mpz_t z1, mpz_t z2, const MasterCache* cache);

      CachedRational(cachedInt c1, cachedInt c2, const MasterCache* cache);

      CachedRational(CachedInt& c1, CachedInt& c2, const MasterCache* cache);

      CachedRational(cachedRational val, const MasterCache* cache);

      CachedRational(CachedRational& val);

      ~CachedRational();

      CachedRational& operator=(const CachedRational& ci);

      CachedRational& operator=(mpq_t& q);

      CachedRational& operator=(std::pair<mpz_t&, mpz_t&> mpzts);

      CachedRational& operator=(std::pair<int, int> ints);

      CachedRational& operator=(std::pair<long, long> longs);

      CachedRational operator+(const CachedRational& i);

      CachedRational operator-(const CachedRational& i);

      CachedRational operator*(const CachedRational& i);

      CachedRational operator/(const CachedRational& i);

      CachedRational reduce();
      CachedRational inv();
      CachedRational abs();
      CachedRational neg();
      int sign();

      operator double();

      const MasterCache* getCache() const;

      cachedRational getValue() const;
  };

}
