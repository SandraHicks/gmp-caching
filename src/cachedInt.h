 /**
  * @file cachedInt.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedInts
  */

#ifndef CACHED_INT_H
#define CACHED_INT_H

#include "master_cache_integer.h"
#include "mastercache.h"

#include <exception>
#include <cinttypes>
#include <string>


namespace gmpcaching{
  /**
   * C++ Wrapper Class for cachedInt type
   */
  class CachedInt
  {
    private:
      /// C-type value of cached Integer
      cachedInt value;
      ///link to cache
      const MasterCache* cache;

    public:
      /*
        Constructors
      */

      /**
       * @brief Constructs a CachedInt with default value 0
       * @param cache
       */
      CachedInt(const MasterCache* cache = NULL);
      
      /**
       * @brief Constructs the CachedInt from mpz_t
       * @param z
       * @param cache
       */
      CachedInt(const mpz_t &z, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedInt from int
       * @param i
       * @param cache
       */
      CachedInt(const int &i, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedInt from long
       * @param l
       * @param cache
       */
      CachedInt(const long &l, const MasterCache* cache = NULL);

      /**
       * @brief Constructs the CachedInt from double
       * @param d
       * @param cache
       */
      CachedInt(const double &d, const MasterCache* cache = NULL);
      /**
       * @brief Copy Constructor
       * @param ci
       */
      CachedInt(const CachedInt& ci);

      /**
       * @brief Constructs the CachedInt from cachedInt C-type
       * @param val
       * @param cache
       */
      CachedInt(cachedInt val, const MasterCache* cache = NULL);

      /**
       * @brief default Destructor
       */
      ~CachedInt();

      /*
       assignments
      */

      /**
       * assignment operator from CachedInt
       * @param ci
       * @return 
       */
      CachedInt& operator=(const CachedInt& ci);

      /**
       * assignment operator from mpz_t
       * @param z
       * @return 
       */
      CachedInt& operator=(const mpz_t& z);

      /**
       * assignment operator from int
       * @param i
       * @return 
       */
      CachedInt& operator=(const int &i);

      /**
       * assignment operator from long
       * @param l
       * @return 
       */
      CachedInt& operator=(const long &l);
      
      /**
       * assignment operator from double
       * @param r
       * @return 
       */
      CachedInt& operator=(const double &d);
      
      /**
       * assignment operator from long double
       * @param r
       * @return 
       */
      CachedInt& operator=(const long double &d);
      
      /*
       calculations
       */
      /**
       * addition
       * @param i
       * @return 
       */
      CachedInt operator+(const CachedInt& i) const;
      
      /**
       * inplace addition
       * @param i
       * @return 
       */
      CachedInt operator+=(const CachedInt& i);

      /**
       * subtraction
       * @param i
       * @return 
       */
      CachedInt operator-(const CachedInt& i) const;
      
      /**
       * inplace subtraction
       * @param i
       * @return 
       */
      CachedInt operator-=(const CachedInt& i);

      /**
       * multiplication
       * @param i
       * @return 
       */
      CachedInt operator*(const CachedInt& i) const;
      
      /**
       * inplace multiplication
       * @param i
       * @return 
       */
      CachedInt operator*=(const CachedInt& i);

      /**
       * division
       * @param i
       * @return 
       */
      CachedInt operator/(const CachedInt& i) const;
      
      /**
       * inplace division
       * @param i
       * @return 
       */
      CachedInt operator/=(const CachedInt& i);

      /**
       * modulo
       * @param i
       * @return 
       */
      CachedInt operator%(const CachedInt& i) const;
      ///double addition
      CachedInt operator+(const double& d) const;
      ///double subtraction
      CachedInt operator-(const double& d) const;
      ///double multiplication
      CachedInt operator*(const double& d) const;
      ///double division
      CachedInt operator/(const double& d) const;
      ///double inplace addition
      CachedInt operator+=(const double& d);
      ///double inplace subtraction
      CachedInt operator-=(const double& d);
      ///double inplace multiplication
      CachedInt operator*=(const double& d);
      ///double inplace division
      CachedInt operator/=(const double& d);
      
      ///int addition
      CachedInt operator+(const int& d) const;
      ///int subtraction
      CachedInt operator-(const int& d) const;
      ///int multiplication
      CachedInt operator*(const int& d) const;
      ///int division
      CachedInt operator/(const int& d) const;
      ///int inplace addition
      CachedInt operator+=(const int& d);
      ///int inplace subtraction
      CachedInt operator-=(const int& d);
      ///int inplace multiplication
      CachedInt operator*=(const int& d);
      ///int inplace division
      CachedInt operator/=(const int& d);
      
      friend CachedInt operator+(const double& d, const CachedInt& r);
      friend CachedInt operator-(const double& d, const CachedInt& r);
      friend CachedInt operator*(const double& d, const CachedInt& r);
      friend CachedInt operator/(const double& d, const CachedInt& r);
      
      friend CachedInt operator+(const int& d, const CachedInt& r);
      friend CachedInt operator-(const int& d, const CachedInt& r);
      friend CachedInt operator*(const int& d, const CachedInt& r);
      friend CachedInt operator/(const int& d, const CachedInt& r);

      /// add product of two rationals
      CachedInt& addProduct(const CachedInt& r, const CachedInt& s);

      /// subtract product of two rationals
      CachedInt& subProduct(const CachedInt& r, const CachedInt& s);

      /// add quotient of two rationals, r divided by s
      CachedInt& addQuotient(const CachedInt& r, const CachedInt& s);

      /// subtract quotient of two rationals, r divided by s
      CachedInt& subQuotient(const CachedInt& r, const CachedInt& s);
      
      /**
       * invert the CachedInt modulo m
       * @param res storage for the result
       * @param m 
       * @return 1 if invertible, 0 if not
       */
      int invert(CachedInt* res, CachedInt& m);
      ///greatest common divisor
      CachedInt gcd(CachedInt& i);
      ///least common multiple
      CachedInt lcm(CachedInt& i);
      ///absolute value
      CachedInt abs();
      /**
       * sign
       * @return 1 if positive, 0 if negative
       */
      int sign();
      
      /**
       * get the negated version of this CachedInt
       * @return 
       */
      CachedInt neg();

      /**
       * negation operator
       * @return 
       */
      friend CachedInt operator-(const CachedInt& r);

      /**
       * double conversion
       * @return 
       */
      operator double() const;
      /**
       * long double conversion
       * @return 
       */
      operator long double() const;

      //*******************************************************//
      //Cache related
      
      /**
       * getter for cachedInt C-type
       * @return 
       */
      cachedInt getValue() const;
      /**
       * (re)set the value of the CachedInt
       * @param val cachedInt C-type
       */
      void setValue(cachedInt val);
      
      /**
       * getter for associated cache
       * @return 
       */
      const MasterCache* getCache() const;
      
      /**
       * check if another CachedInt has the same cache
       * @param i
       * @return boolean true if same cache
       */
      bool hasSameCache(const CachedInt &i) const;
      //*******************************************************//
      
      //*******************************************************//
      //friend comparisons
      friend int compareInt(const CachedInt& r, const CachedInt& s);
      friend bool operator!=(const CachedInt& r, const CachedInt& s);
      friend bool operator==(const CachedInt& r, const CachedInt& s);
      friend bool operator<(const CachedInt& r, const CachedInt& s);
      friend bool operator<=(const CachedInt& r, const CachedInt& s);
      friend bool operator>(const CachedInt& r, const CachedInt& s);
      friend bool operator>=(const CachedInt& r, const CachedInt& s);

      friend bool operator!=(const CachedInt& r, const double& s);
      friend bool operator==(const CachedInt& r, const double& s);
      friend bool operator<(const CachedInt& r, const double& s);
      friend bool operator<=(const CachedInt& r, const double& s);
      friend bool operator>(const CachedInt& r, const double& s);
      friend bool operator>=(const CachedInt& r, const double& s);

      friend bool operator!=(const double& r, const CachedInt& s);
      friend bool operator==(const double& r, const CachedInt& s);
      friend bool operator<(const double& r, const CachedInt& s);
      friend bool operator<=(const double& r, const CachedInt& s);
      friend bool operator>(const double& r, const CachedInt& s);
      friend bool operator>=(const double& r, const CachedInt& s);

      friend bool operator!=(const CachedInt& r, const long double& s);
      friend bool operator==(const CachedInt& r, const long double& s);
      friend bool operator<(const CachedInt& r, const long double& s);
      friend bool operator<=(const CachedInt& r, const long double& s);
      friend bool operator>(const CachedInt& r, const long double& s);
      friend bool operator>=(const CachedInt& r, const long double& s);

      friend bool operator!=(const long double& r, const CachedInt& s);
      friend bool operator==(const long double& r, const CachedInt& s);
      friend bool operator<(const long double& r, const CachedInt& s);
      friend bool operator<=(const long double& r, const CachedInt& s);
      friend bool operator>(const long double& r, const CachedInt& s);
      friend bool operator>=(const long double& r, const CachedInt& s);

      friend bool operator!=(const CachedInt& r, const int& s);
      friend bool operator==(const CachedInt& r, const int& s);
      friend bool operator<(const CachedInt& r, const int& s);
      friend bool operator<=(const CachedInt& r, const int& s);
      friend bool operator>(const CachedInt& r, const int& s);
      friend bool operator>=(const CachedInt& r, const int& s);

      friend bool operator!=(const int& r, const CachedInt& s);
      friend bool operator==(const int& r, const CachedInt& s);
      friend bool operator<(const int& r, const CachedInt& s);
      friend bool operator<=(const int& r, const CachedInt& s);
      friend bool operator>(const int& r, const CachedInt& s);
      friend bool operator>=(const int& r, const CachedInt& s);

      //*******************************************************//
  };
  /**
   * Exception for the case that the Integer Cache was not set
   */
  class IntegerCacheNotSetException: public std::exception{
  private:
      cachedInt data;
  public:
      ///Standard Constructor
      IntegerCacheNotSetException(){
          this->data = 0;
      }
      /**
       * @brief constructor with cachedInt for location
       * @param i cachedInt
       */
      IntegerCacheNotSetException(cachedInt i){
          this->data = i;
      }
      /// get error message
    virtual const char* what() const throw(){
        std::string ret = "The Cache was not initialized for ";
        ret += std::to_string(this->data);
        ret += ".";
        return ret.c_str();
    }
  };
  
   /// Negation.
   CachedInt operator-(const CachedInt& r);
   
    //compare
   /**
    * compare CachedInts
    * @param r
    * @param s
    * @return 1 if r>s, 0 if equals, -1 if r<s
    */
    int compareInt(const CachedInt& r, const CachedInt& s);
    /// not equals CachedInts
    bool operator!=(const CachedInt& r, const CachedInt& s);
    /// equals CachedInts
    bool operator==(const CachedInt& r, const CachedInt& s);
    /// less than CachedInts
    bool operator<(const CachedInt& r, const CachedInt& s);
    /// less than equals CachedInts
    bool operator<=(const CachedInt& r, const CachedInt& s);
    /// greater than CachedInts
    bool operator>(const CachedInt& r, const CachedInt& s);
    /// greater than equals CachedInts
    bool operator>=(const CachedInt& r, const CachedInt& s);

    /// not equals CachedInt double
    bool operator!=(const CachedInt& r, const double& s);
    /// equals CachedInt double
    bool operator==(const CachedInt& r, const double& s);
    /// less than CachedInt double
    bool operator<(const CachedInt& r, const double& s);
    /// less than equals CachedInt double
    bool operator<=(const CachedInt& r, const double& s);
    /// greater than CachedInt double
    bool operator>(const CachedInt& r, const double& s);
    /// greater than equals CachedInt double
    bool operator>=(const CachedInt& r, const double& s);

    /// not equals double CachedInt
    bool operator!=(const double& r, const CachedInt& s);
    /// equals double CachedInt
    bool operator==(const double& r, const CachedInt& s);
    /// less than double CachedInt
    bool operator<(const double& r, const CachedInt& s);
    /// less than equals double CachedInt
    bool operator<=(const double& r, const CachedInt& s);
    /// greater than double CachedInt
    bool operator>(const double& r, const CachedInt& s);
    /// greater than equals double CachedInt
    bool operator>=(const double& r, const CachedInt& s);

    /// not equals CachedInt long double
    bool operator!=(const CachedInt& r, const long double& s);
    /// equals CachedInt long double
    bool operator==(const CachedInt& r, const long double& s);
    /// less than CachedInt long double
    bool operator<(const CachedInt& r, const long double& s);
    /// less than equals CachedInt long double
    bool operator<=(const CachedInt& r, const long double& s);
    /// greater than CachedInt long double
    bool operator>(const CachedInt& r, const long double& s);
    /// greater than equals CachedInt long double
    bool operator>=(const CachedInt& r, const long double& s);

    /// not equals long double CachedInt
    bool operator!=(const long double& r, const CachedInt& s);
    /// equals long double CachedInt
    bool operator==(const long double& r, const CachedInt& s);
    /// less than long double CachedInt
    bool operator<(const long double& r, const CachedInt& s);
    /// less than equals long double CachedInt
    bool operator<=(const long double& r, const CachedInt& s);
    /// greater than long double CachedInt
    bool operator>(const long double& r, const CachedInt& s);
    /// greater than equals long double CachedInt
    bool operator>=(const long double& r, const CachedInt& s);

    ///addition rhs double
    CachedInt operator+(const double& d, const CachedInt& r);
    ///subtraction rhs double
    CachedInt operator-(const double& d, const CachedInt& r);
    ///multiplication rhs double
    CachedInt operator*(const double& d, const CachedInt& r);
    ///division rhs double
    CachedInt operator/(const double& d, const CachedInt& r);

    /// not equals int CachedInt
    bool operator!=(const int& r, const CachedInt& s);
    /// equals int CachedInt
    bool operator==(const int& r, const CachedInt& s);
    /// less than int CachedInt
    bool operator<(const int& r, const CachedInt& s);
    /// less than equals int CachedInt
    bool operator<=(const int& r, const CachedInt& s);
    /// greater than int CachedInt
    bool operator>(const int& r, const CachedInt& s);
    /// greater than equals int CachedInt
    bool operator>=(const int& r, const CachedInt& s);

    ///addition rhs int
    CachedInt operator+(const int& d, const CachedInt& r);
    ///subtraction rhs int
    CachedInt operator-(const int& d, const CachedInt& r);
    ///multiplication rhs int
    CachedInt operator*(const int& d, const CachedInt& r);
    ///division rhs int
    CachedInt operator/(const int& d, const CachedInt& r);
}
#endif /*CACHED_INT_H*/