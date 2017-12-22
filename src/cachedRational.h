 /**
  * @file cachedRational.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedRationals
  * This class is compatible to the soplex::Rational class in the SoPlex project and can replace this class entirely.
  */
#ifndef CACHED_RATIONAL_H
#define CACHED_RATIONAL_H

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
        static int global_cached_int_counter;
    static int global_cached;
    static int global_additions;

      /**
       * @brief Constructs the CachedRational.
       *
       * Constructs the CachedRational without setting properties.
       * @param cache
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
      CachedRational(const mpq_t& q, const MasterCache* cache = NULL);

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
      
      /**
       * assignment operator from CachedRational
       * @param ci
       * @return 
       */
      CachedRational& operator=(const CachedRational& ci);

      /**
       * assignment operator from mpq_t
       * @param q
       * @return 
       */
      CachedRational& operator=(const mpq_t& q);

      /**
       * assignment operator from pair of mpz_t
       * @param mpzts
       * @return 
       */
      CachedRational& operator=(std::pair<mpz_t&, mpz_t&> mpzts);
      /**
       * assignment operator from pair of int
       * @param ints
       * @return 
       */
      CachedRational& operator=(std::pair<int, int> ints);

      /**
       * assignment operator from pair of long
       * @param longs
       * @return 
       */
      CachedRational& operator=(std::pair<long, long> longs);
     
      /**
       * assignment operator from long double
       * @param r
       * @return 
       */
      CachedRational& operator=(const long double &r);

      /**
       * assignment operator from double
       * @param r
       * @return 
       */
      CachedRational& operator=(const double &r);

      /**
       * assignment operator from int
       * @param i
       * @return 
       */
      CachedRational& operator=(const int &i);

      /*
       calculations
       */
      /// CachedRational addition
      CachedRational operator+(const CachedRational& i) const;
      /// CachedRational inplace addition
      CachedRational operator+=(const CachedRational& i);

      /// CachedRational subtraction
      CachedRational operator-(const CachedRational& i) const;
      /// CachedRational inplace subtraction
      CachedRational operator-=(const CachedRational& i);

      /// CachedRational multiplication
      CachedRational operator*(const CachedRational& i) const;
      /// CachedRational inplace multiplication
      CachedRational operator*=(const CachedRational& i);

      ///CachedRational division
      CachedRational operator/(const CachedRational& i) const;
      ///CachedRational inplace division
      CachedRational operator/=(const CachedRational& i);
      
      /// double addition
      CachedRational operator+(const double& d) const;
      /// double subtraction
      CachedRational operator-(const double& d) const;
      /// double multiplication
      CachedRational operator*(const double& d) const;
      /// double division
      CachedRational operator/(const double& d) const;
      /// double inplace addition
      CachedRational operator+=(const double& d);
      /// double inplace subtraction
      CachedRational operator-=(const double& d);
      /// double inplace multiplication
      CachedRational operator*=(const double& d);
      /// double inplace division
      CachedRational operator/=(const double& d);
      
      /// int addtion
      CachedRational operator+(const int& d) const;
      /// int subtraction
      CachedRational operator-(const int& d) const;
      /// int multiplication
      CachedRational operator*(const int& d) const;
      /// int division
      CachedRational operator/(const int& d) const;
      /// int inplace addition
      CachedRational operator+=(const int& d);
      /// int inplace subtraction
      CachedRational operator-=(const int& d);
      /// int inplace multiplication
      CachedRational operator*=(const int& d);
      /// int inplace division
      CachedRational operator/=(const int& d);
      
      friend CachedRational operator+(const double& d, const CachedRational& r);
      friend CachedRational operator-(const double& d, const CachedRational& r);
      friend CachedRational operator*(const double& d, const CachedRational& r);
      friend CachedRational operator/(const double& d, const CachedRational& r);
      
      friend CachedRational operator+(const int& d, const CachedRational& r);
      friend CachedRational operator-(const int& d, const CachedRational& r);
      friend CachedRational operator*(const int& d, const CachedRational& r);
      friend CachedRational operator/(const int& d, const CachedRational& r);
      
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
      CachedRational& reduce();
      
      /**
       * @brief Function to invert a fraction.
       * @return inverted rational
       */
      CachedRational& invert();
      
      /**
       * Function to get the absolute value of a fraction.
       * @return absolute rational
       */
      friend CachedRational spxAbs(const CachedRational& r);
      
      /**
       * Function to get the negative value of a fraction.
       * @return negative rational
       */
      CachedRational& neg();
      /**
       * Function to get the negative value of a fraction.
       * @param r CachedRational to negate
       * @return negative rational
       */
      friend CachedRational operator-(const CachedRational& r);
      /**
       * Function to get sign of a fraction.
       * @return 1 if positive, 0 if negative
       */
      friend int sign(const CachedRational& r);
      /**
       * double conversion
       * @return double representation
       */
      operator double() const;
      /**
       * long double conversion
       * @return long double representation
       */
      operator long double() const;
      
      //*******************************************************//
      //Cache related
      /**
       * getter for the associated cache
       * @return MasterCache pointer
       */
      const MasterCache* getCache() const;

      /**
       * getter for cachedRational struct
       * @return cachedRational struct
       */
      cachedRational getValue() const;
      /**
       * (re)set the value of the CachedRational
       * @param val cachedRational C-type
       */
      void setValue(cachedRational val);
      /**
       * 
       * @param i CachedRational
       * @return boolean true if same cache
       */
      bool hasSameCache(const CachedRational& i) const;
      //*******************************************************//
      
      
      //*******************************************************//
      //soplex::Rational interface methods
      
      /// precision
      static int precision();
      /// Size in specified base (bit size for base 2)
      int sizeInBase(const int base = 2) const;
      /// checks if \p d is the closest number that can be represented by double
      bool isNextTo(const double& d);

      /// checks if \p d is exactly equal to the Rational and if not, if it is one of the two adjacent doubles
      bool isAdjacentTo(const double& d) const;
      
      ///powRound soplex::Rational function
      CachedRational& powRound();
      //*******************************************************//
      
      //*******************************************************//
      // more soplex::Rational interface methods which should return the mpq_t, not yet working here
      /// provides read-only access to underlying mpq_t
      const mpq_t* getMpqPtr() const;

      /// provides read-only access to underlying mpq_t
      const mpq_t& getMpqRef() const;

      /// provides write access to underlying mpq_t; use with care
      mpq_t* getMpqPtr_w() const;

      /// provides write access to underlying mpq_t; use with care
      mpq_t& getMpqRef_w() const;
      
      //*******************************************************//
      void set_den(mpz_t den);
      void set_num(mpz_t num);
      void get_den(mpz_t& den) const;
      void get_num(mpz_t& num) const;
      
      void canonicalize();
      void copy_mpq(mpq_t& copy) const;
      void set_num_den(mpz_t num, mpz_t den);
      
      
      //*******************************************************//
      //String conversions
      ///read a cachedRational from a c-string
      bool readString(const char* s);

      friend std::string rationalToString(const CachedRational& r, const int precision);
      friend bool readStringRational(const char* s, CachedRational& value);
      friend std::ostream& operator<<(std::ostream& os, const CachedRational& q);
      //*******************************************************//
      
      
      
      
      //*******************************************************//
      //friend comparisons
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

      //*******************************************************//
      
      //*******************************************************//
      //functions from soplex::Rational interface which do nothing (here and there)
      //unfortunately they are required to make SoPlex compile
      
      ///does nothing, just for compatibility with soplex::Rational
      static void enableListMem();
      ///does nothing, just for compatibility with soplex::Rational
      static void freeListMem();
      ///does nothing, just for compatibility with soplex::Rational
      static void disableListMem();
      
      //*******************************************************//
  };

  /**
   * Exception class for the case that the Cache was not set before the number is initialized
   */
  class RationalCacheNotSetException: public std::exception{
  private:
      cachedInt counter;
      cachedInt denominator;
  public:
      /// Standard Constructor
      RationalCacheNotSetException(){
          this->counter = 0;
          this->denominator = 0;
      }
      /**
       * @brief Constructor with cachedInt tuple for location
       * @param i cachedInt
       * @param j cachedInt
       */
      RationalCacheNotSetException(cachedInt i, cachedInt j){
          this->counter = i;
          this->denominator = j;
      }
      /// get error message
    virtual const char* what() const throw(){
        std::string ret = "The Cache was not initialized for ";
        ret += std::to_string(this->counter);
        ret += "/";
        ret += std::to_string(this->denominator);
        ret += ".";
        return ret.c_str();
    }
  };
   /// Negation.
   CachedRational operator-(const CachedRational& r);
   /// absolute Value of CachedRational
   CachedRational spxAbs(const CachedRational& r);
   /// sign of CachedRational (either 0 or 1)
   int sign(const CachedRational& r);
   
   //compare
     /**
      * compare CachedRationals
      * @param r
      * @param s
      * @return 1 if r>s, 0 if equals, -1 if r<s
      */
    int compareRational(const CachedRational& r, const CachedRational& s);
    /// not equals CachedRationals
    bool operator!=(const CachedRational& r, const CachedRational& s);
    /// equals CachedRationals
    bool operator==(const CachedRational& r, const CachedRational& s);
    /// less than CachedRationals
    bool operator<(const CachedRational& r, const CachedRational& s);
    /// less than equals CachedRationals
    bool operator<=(const CachedRational& r, const CachedRational& s);
    /// greater than CachedRationals
    bool operator>(const CachedRational& r, const CachedRational& s);
    /// greater than equals CachedRationals
    bool operator>=(const CachedRational& r, const CachedRational& s);

    /// not equals CachedRational double
    bool operator!=(const CachedRational& r, const double& s);
    /// equals CachedRational double
    bool operator==(const CachedRational& r, const double& s);
    /// less than CachedRational double
    bool operator<(const CachedRational& r, const double& s);
    /// less than equals CachedRational double
    bool operator<=(const CachedRational& r, const double& s);
    /// greater than CachedRational double
    bool operator>(const CachedRational& r, const double& s);
    /// greater than equals CachedRational double
    bool operator>=(const CachedRational& r, const double& s);

    /// not equals double CachedRational
    bool operator!=(const double& r, const CachedRational& s);
    /// equals double CachedRational
    bool operator==(const double& r, const CachedRational& s);
    /// less than double CachedRational
    bool operator<(const double& r, const CachedRational& s);
    /// less than equals double CachedRational
    bool operator<=(const double& r, const CachedRational& s);
    /// greater than double CachedRational
    bool operator>(const double& r, const CachedRational& s);
    /// greater than equals double CachedRational
    bool operator>=(const double& r, const CachedRational& s);

    /// not equals CachedRational long double
    bool operator!=(const CachedRational& r, const long double& s);
    /// equals CachedRational long double
    bool operator==(const CachedRational& r, const long double& s);
    /// less than CachedRational long double
    bool operator<(const CachedRational& r, const long double& s);
    /// less than equals CachedRational long double
    bool operator<=(const CachedRational& r, const long double& s);
    /// greater than CachedRational long double
    bool operator>(const CachedRational& r, const long double& s);
    /// greater than equals CachedRational long double
    bool operator>=(const CachedRational& r, const long double& s);

    /// not equals long double CachedRational
    bool operator!=(const long double& r, const CachedRational& s);
    /// equals long double CachedRational
    bool operator==(const long double& r, const CachedRational& s);
    /// less than long double CachedRational
    bool operator<(const long double& r, const CachedRational& s);
    /// less than equals long double CachedRational
    bool operator<=(const long double& r, const CachedRational& s);
    /// greater than long double CachedRational
    bool operator>(const long double& r, const CachedRational& s);
    /// greater than equals long double CachedRational
    bool operator>=(const long double& r, const CachedRational& s);

    ///addition double CachedRational
    CachedRational operator+(const double& d, const CachedRational& r);
    ///subtraction double CachedRational
    CachedRational operator-(const double& d, const CachedRational& r);
    ///multiplication double CachedRational
    CachedRational operator*(const double& d, const CachedRational& r);
    ///division double CachedRational
    CachedRational operator/(const double& d, const CachedRational& r);

    /// not equals int CachedRational
    bool operator!=(const int& r, const CachedRational& s);
    /// equals int CachedRational
    bool operator==(const int& r, const CachedRational& s);
    /// less than int CachedRational
    bool operator<(const int& r, const CachedRational& s);
    /// less than equals int CachedRational
    bool operator<=(const int& r, const CachedRational& s);
    /// greater than int CachedRational
    bool operator>(const int& r, const CachedRational& s);
    /// greater than equals int CachedRational
    bool operator>=(const int& r, const CachedRational& s);

    ///addition int CachedRational
    CachedRational operator+(const int& d, const CachedRational& r);
    ///subtraction int CachedRational
    CachedRational operator-(const int& d, const CachedRational& r);
    ///multiplication int CachedRational
    CachedRational operator*(const int& d, const CachedRational& r);
    ///division int CachedRational
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
#endif /*CACHED_RATIONAL_H*/