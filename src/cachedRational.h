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
      CachedRational(const MasterCache* cache = NULL);
      
      /**
       * @brief Constructs the CachedRational from int.
       *
       * Constructs the CachedRational from int and sets the MasterCache.
       */
      CachedRational(const int i, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedRational from double.
       *
       * Constructs the CachedRational from double and sets the MasterCache.
       */
      CachedRational(const double& r, const MasterCache* cache = NULL);
      
      /**
       * @brief Constructs the CachedRational from long double.
       *
       * Constructs the CachedRational from long double and sets the MasterCache.
       */     
      CachedRational(const long double& r, const MasterCache* cache = NULL);
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
      CachedRational(const CachedInt& c1, const CachedInt& c2, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedRational from cachedRational.
       *
       * Constructs the CachedRational from cachedRational and sets the MasterCache.
       */
      CachedRational(const cachedRational val, const MasterCache* cache = NULL);

      /**
       * @brief Copy Constructor.
       *
       * Copy Constructor.
       */
      CachedRational(const CachedRational& val);

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
     
      /// assignment operator from long double
      CachedRational& operator=(const long double &r);

      /// assignment operator from double
      CachedRational& operator=(const double &r);

      /// assignment operator from int
      CachedRational& operator=(const int &i);

      /*
       calculations
       */
      CachedRational operator+(const CachedRational& i) const;
      CachedRational operator+=(const CachedRational& i);

      CachedRational operator-(const CachedRational& i) const;
      CachedRational operator-=(const CachedRational& i);

      CachedRational operator*(const CachedRational& i) const;
      CachedRational operator*=(const CachedRational& i);

      CachedRational operator/(const CachedRational& i) const;
      CachedRational operator/=(const CachedRational& i);
      
      CachedRational operator+(const double& d) const;
      CachedRational operator-(const double& d) const;
      CachedRational operator*(const double& d) const;
      CachedRational operator/(const double& d) const;
      CachedRational operator+=(const double& d);
      CachedRational operator-=(const double& d);
      CachedRational operator*=(const double& d);
      CachedRational operator/=(const double& d);
      
      CachedRational operator+(const int& d) const;
      CachedRational operator-(const int& d) const;
      CachedRational operator*(const int& d) const;
      CachedRational operator/(const int& d) const;
      CachedRational operator+=(const int& d);
      CachedRational operator-=(const int& d);
      CachedRational operator*=(const int& d);
      CachedRational operator/=(const int& d);
      
      /// add product of two rationals
      CachedRational& addProduct(const CachedRational& r, const CachedRational& s);

      /// subtract product of two rationals
      CachedRational& subProduct(const CachedRational& r, const CachedRational& s);

      /// add quotient of two rationals, r divided by s
      CachedRational& addQuotient(const CachedRational& r, const CachedRational& s);

      /// subtract quotient of two rationals, r divided by s
      CachedRational& subQuotient(const CachedRational& r, const CachedRational& s);
      
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
      friend CachedRational spxAbs(const CachedRational& r);
      
      /**
       * Function to get the negative value of a fraction.
       * @return negative rational
       */
      CachedRational neg();
      /**
       * Function to get sign of a fraction.
       * @return 1 if positive, 0 if negative
       */
      friend int sign(const CachedRational& r);

      explicit operator double() const;
      explicit operator long double() const;
      
      //operator double() const;
      //operator long double() const;
      
      //*******************************************************//
      //Cache related
      const MasterCache* getCache() const;

      cachedRational getValue() const;
      void setValue(cachedRational val);
      
      bool hasSameCache(CachedRational& i) const;
      //*******************************************************//
      
      
      
      //*******************************************************//
      //rational interface methods
      friend CachedRational operator-(const CachedRational& r);
      
      //precision
      static int precision();
      /// Size in specified base (bit size for base 2)
      int sizeInBase(const int base = 2) const;
      /// checks if \p d is the closest number that can be represented by double
      bool isNextTo(const double& d);

      /// checks if \p d is exactly equal to the Rational and if not, if it is one of the two adjacent doubles
      bool isAdjacentTo(const double& d) const;
      
      CachedRational& powRound();
      //*******************************************************//
      
      
      
      
      //*******************************************************//
      //String conversions
      bool readString(const char* s);

      friend std::string rationalToString(const CachedRational& r, const int precision);
      friend bool readStringRational(const char* s, CachedRational& value);
      friend std::ostream& operator<<(std::ostream& os, const CachedRational& q);
      //*******************************************************//
      
      
      //*******************************************************//
      /// provides read-only access to underlying mpq_t
      const mpq_t* getMpqPtr() const;

      /// provides read-only access to underlying mpq_t
      const mpq_t& getMpqRef() const;

      /// provides write access to underlying mpq_t; use with care
      mpq_t* getMpqPtr_w() const;

      /// provides write access to underlying mpq_t; use with care
      mpq_t& getMpqRef_w() const;
      //*******************************************************//
      
      
      
      
      //*******************************************************//
      //friend comparisons and operators
      friend int compareRational(const CachedRational& r, const CachedRational& s);
      friend bool operator!=(const CachedRational& r, const CachedRational& s);
      friend bool operator==(const CachedRational& r, const CachedRational& s);
      friend bool operator<(const CachedRational& r, const CachedRational& s);
      friend bool operator<=(const CachedRational& r, const CachedRational& s);
      friend bool operator>(const CachedRational& r, const CachedRational& s);
      friend bool operator>=(const CachedRational& r, const CachedRational& s);

      friend bool operator!=(const CachedRational& r, const double& s);
      friend bool operator==(const CachedRational& r, const double& s);
      friend bool operator<(const CachedRational& r, const double& s);
      friend bool operator<=(const CachedRational& r, const double& s);
      friend bool operator>(const CachedRational& r, const double& s);
      friend bool operator>=(const CachedRational& r, const double& s);

      friend bool operator!=(const double& r, const CachedRational& s);
      friend bool operator==(const double& r, const CachedRational& s);
      friend bool operator<(const double& r, const CachedRational& s);
      friend bool operator<=(const double& r, const CachedRational& s);
      friend bool operator>(const double& r, const CachedRational& s);
      friend bool operator>=(const double& r, const CachedRational& s);

      friend bool operator!=(const CachedRational& r, const long double& s);
      friend bool operator==(const CachedRational& r, const long double& s);
      friend bool operator<(const CachedRational& r, const long double& s);
      friend bool operator<=(const CachedRational& r, const long double& s);
      friend bool operator>(const CachedRational& r, const long double& s);
      friend bool operator>=(const CachedRational& r, const long double& s);

      friend bool operator!=(const long double& r, const CachedRational& s);
      friend bool operator==(const long double& r, const CachedRational& s);
      friend bool operator<(const long double& r, const CachedRational& s);
      friend bool operator<=(const long double& r, const CachedRational& s);
      friend bool operator>(const long double& r, const CachedRational& s);
      friend bool operator>=(const long double& r, const CachedRational& s);

      friend CachedRational operator+(const double& d, const CachedRational& r);
      friend CachedRational operator-(const double& d, const CachedRational& r);
      friend CachedRational operator*(const double& d, const CachedRational& r);
      friend CachedRational operator/(const double& d, const CachedRational& r);

      friend bool operator!=(const CachedRational& r, const int& s);
      friend bool operator==(const CachedRational& r, const int& s);
      friend bool operator<(const CachedRational& r, const int& s);
      friend bool operator<=(const CachedRational& r, const int& s);
      friend bool operator>(const CachedRational& r, const int& s);
      friend bool operator>=(const CachedRational& r, const int& s);

      friend bool operator!=(const int& r, const CachedRational& s);
      friend bool operator==(const int& r, const CachedRational& s);
      friend bool operator<(const int& r, const CachedRational& s);
      friend bool operator<=(const int& r, const CachedRational& s);
      friend bool operator>(const int& r, const CachedRational& s);
      friend bool operator>=(const int& r, const CachedRational& s);

      friend CachedRational operator+(const int& d, const CachedRational& r);
      friend CachedRational operator-(const int& d, const CachedRational& r);
      friend CachedRational operator*(const int& d, const CachedRational& r);
      friend CachedRational operator/(const int& d, const CachedRational& r);
      //*******************************************************//
      
      //*******************************************************//
      //not sure if required
      
      //static void enableListMem();
      
      //static void freeListMem();
      
      //static void disableListMem();
      
      //*******************************************************//
  };

  class RationalCacheNotSetException: public std::exception{
  private:
      cachedInt counter;
      cachedInt denominator;
  public:
      RationalCacheNotSetException(){
          this->counter = 0;
          this->denominator = 0;
      }
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
  CachedRational operator/(const CachedRational& r, const int& d);
  CachedRational operator/(const CachedRational& r, const double& d);
   /// Negation.
   CachedRational operator-(const CachedRational& r);
   CachedRational spxAbs(const CachedRational& r);
   int sign(const CachedRational& r);
   
   //compare
    int compareRational(const CachedRational& r, const CachedRational& s);
    bool operator!=(const CachedRational& r, const CachedRational& s);
    bool operator==(const CachedRational& r, const CachedRational& s);
    bool operator<(const CachedRational& r, const CachedRational& s);
    bool operator<=(const CachedRational& r, const CachedRational& s);
    bool operator>(const CachedRational& r, const CachedRational& s);
    bool operator>=(const CachedRational& r, const CachedRational& s);

    bool operator!=(const CachedRational& r, const double& s);
    bool operator==(const CachedRational& r, const double& s);
    bool operator<(const CachedRational& r, const double& s);
    bool operator<=(const CachedRational& r, const double& s);
    bool operator>(const CachedRational& r, const double& s);
    bool operator>=(const CachedRational& r, const double& s);

    bool operator!=(const double& r, const CachedRational& s);
    bool operator==(const double& r, const CachedRational& s);
    bool operator<(const double& r, const CachedRational& s);
    bool operator<=(const double& r, const CachedRational& s);
    bool operator>(const double& r, const CachedRational& s);
    bool operator>=(const double& r, const CachedRational& s);

    bool operator!=(const CachedRational& r, const long double& s);
    bool operator==(const CachedRational& r, const long double& s);
    bool operator<(const CachedRational& r, const long double& s);
    bool operator<=(const CachedRational& r, const long double& s);
    bool operator>(const CachedRational& r, const long double& s);
    bool operator>=(const CachedRational& r, const long double& s);

    bool operator!=(const long double& r, const CachedRational& s);
    bool operator==(const long double& r, const CachedRational& s);
    bool operator<(const long double& r, const CachedRational& s);
    bool operator<=(const long double& r, const CachedRational& s);
    bool operator>(const long double& r, const CachedRational& s);
    bool operator>=(const long double& r, const CachedRational& s);

    CachedRational operator+(const double& d, const CachedRational& r);
    CachedRational operator-(const double& d, const CachedRational& r);
    CachedRational operator*(const double& d, const CachedRational& r);
    CachedRational operator/(const double& d, const CachedRational& r);

    bool operator!=(const int& r, const CachedRational& s);
    bool operator==(const int& r, const CachedRational& s);
    bool operator<(const int& r, const CachedRational& s);
    bool operator<=(const int& r, const CachedRational& s);
    bool operator>(const int& r, const CachedRational& s);
    bool operator>=(const int& r, const CachedRational& s);

    CachedRational operator+(const int& d, const CachedRational& r);
    CachedRational operator-(const int& d, const CachedRational& r);
    CachedRational operator*(const int& d, const CachedRational& r);
    CachedRational operator/(const int& d, const CachedRational& r);
    
    /// convert rational number to string
   std::string rationalToString(const CachedRational& r, const int precision = 32);

   /// read Rational from string
   bool readStringRational(const char* s, CachedRational& value);

   /// print Rational
   std::ostream& operator<<(std::ostream& os, const CachedRational& r);
   
   /// Total size of rational vector.
   int totalSizeRational(const CachedRational* vector, const int length, const int base = 2);

   /// Size of least common multiple of denominators in rational vector.
   int dlcmSizeRational(const CachedRational* vector, const int length, const int base = 2);

   /// Size of largest denominator in rational vector.
   int dmaxSizeRational(const CachedRational* vector, const int length, const int base = 2);
}