 /**
  * @file cachedRational.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedRationals
  */

#include "master_cache_rational.h"
#include "mastercache.h"
#include "cachedInt.h"

#include <utility>
#include <exception>

namespace gmpcaching{  
    
  /**
   * C++ Wrapper Class for cachedRational type
   */
  class CachedRational
  {
    private:
      /// C-type value of cached Rational
      cachedRational value;
      ///link to cache
      const MasterCache* cache;

    public:

      /**
       * @brief Constructs the CachedRational.
       *
       * Constructs the CachedRational without setting properties.
       */
      CachedRational();
      
      /**
       * @brief Constructs the CachedRational from mpq_t.
       *
       * Constructs the CachedRational from int and sets the MasterCache.
       */
      CachedRational(int i, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedRational from mpq_t.
       *
       * Constructs the CachedRational from mpq_t and sets the MasterCache.
       */
      CachedRational(mpq_t q, const MasterCache* cache = NULL);

      /**
       * @rief Constructs the CachedRational from two mpz_t's.
       *
       * Constructs the CachedRational from two mpz_t's and sets the MasterCache.
       */
      CachedRational(mpz_t z1, mpz_t z2, const MasterCache* cache = NULL);
      
       /**
       * @brief Constructs the CachedRational from two cachedInt.
       *
       * Constructs the CachedRational from two cachedInt and sets the MasterCache.
       * User must make sure that both cachedInts result from the same cache.
       */
      CachedRational(cachedInt c1, cachedInt c2, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedRational from two CachedInt.
       *
       * Constructs the CachedRational from two CachedInt (C++ Wrapper for cachedInt C-type) and sets the MasterCache.
       */
      CachedRational(CachedInt& c1, CachedInt& c2, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedRational from cachedRational.
       *
       * Constructs the CachedRational from cachedRational and sets the MasterCache.
       */
      CachedRational(cachedRational val, const MasterCache* cache = NULL);

      /**
       * @brief Copy Constructor.
       *
       * Copy Constructor.
       */
      CachedRational(CachedRational& val);

      /**
       * @brief Destructor.
       *
       * Destructor.
       */
      ~CachedRational();

      /*
       assignments
       */
      CachedRational& operator=(const CachedRational& ci);

      CachedRational& operator=(mpq_t& q);

      CachedRational& operator=(std::pair<mpz_t&, mpz_t&> mpzts);

      CachedRational& operator=(std::pair<int, int> ints);

      CachedRational& operator=(std::pair<long, long> longs);

      /*
       calculations
       */
      CachedRational operator+(const CachedRational& i);

      CachedRational operator-(const CachedRational& i);

      CachedRational operator*(const CachedRational& i);
      CachedRational operator*=(const CachedRational& i);

      CachedRational operator/(const CachedRational& i);
      
      
      /// add product of two rationals
      CachedRational& addProduct(const CachedRational& r, const CachedRational& s);

      /// subtract product of two rationals
      CachedRational& subProduct(const CachedRational& r, const CachedRational& s);

      /// add quotient of two rationals, r divided by s
      CachedRational& addQuotient(const CachedRational& r, const CachedRational& s);

      /// subtract quotient of two rationals, r divided by s
      CachedRational& subQuotient(const CachedRational& r, const CachedRational& s);
      
      /*
       comparisons
       */
      
      bool operator==(const CachedRational& i) const;
      
      bool operator==(int i) const;

    /**
     * @brief Function to reduce the fraction of two cachedInt.
     * @return reduced rational
     */
      CachedRational reduce();

      /**
       * @brief Function to invert a fraction.
       * @return inverted rational
       */
      CachedRational invert();
      
      /**
       * Function to get the absolute value of a fraction.
       * @return absolute rational
       */
      CachedRational abs();
      
      /**
       * Function to get the negative value of a fraction.
       * @return negative rational
       */
      CachedRational neg();
      /**
       * Function to get sign of a fraction.
       * @return 1 if positive, 0 if negative
       */
      int sign();

      operator double();

      const MasterCache* getCache() const;

      cachedRational getValue() const;
      
      bool hasSameCache(CachedRational& i) const;
  };

  class RationalCacheNotSetException: public std::exception{
  private:
      cachedInt counter;
      cachedInt denominator;
  public:
      RationalCacheNotSetException(cachedInt i, cachedInt j){
          this->counter = i;
          this->denominator = j;
      }
    virtual const char* what() const throw(){
        std::string ret = "The Cache was not initialized for ";
        ret += std::to_string(this->counter);
        ret += "/";
        ret += std::to_string(this->denominator);
        ret += ".";
        return ret.c_str();
    }
  };
}