 /**
  * @file cachedInt.h
  * @author Sandra Hicks
  * @brief wrapper class header for cachedInts
  */

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
      
      CachedInt operator+(const double& d) const;
      CachedInt operator-(const double& d) const;
      CachedInt operator*(const double& d) const;
      CachedInt operator/(const double& d) const;
      CachedInt operator+=(const double& d);
      CachedInt operator-=(const double& d);
      CachedInt operator*=(const double& d);
      CachedInt operator/=(const double& d);
      
      CachedInt operator+(const int& d) const;
      CachedInt operator-(const int& d) const;
      CachedInt operator*(const int& d) const;
      CachedInt operator/(const int& d) const;
      CachedInt operator+=(const int& d);
      CachedInt operator-=(const int& d);
      CachedInt operator*=(const int& d);
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
      CachedInt gcd(CachedInt& i);
      CachedInt lcm(CachedInt& i);
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
      IntegerCacheNotSetException(){
          this->data = 0;
      }
      IntegerCacheNotSetException(cachedInt i){
          this->data = i;
      }
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
    int compareInt(const CachedInt& r, const CachedInt& s);
    bool operator!=(const CachedInt& r, const CachedInt& s);
    bool operator==(const CachedInt& r, const CachedInt& s);
    bool operator<(const CachedInt& r, const CachedInt& s);
    bool operator<=(const CachedInt& r, const CachedInt& s);
    bool operator>(const CachedInt& r, const CachedInt& s);
    bool operator>=(const CachedInt& r, const CachedInt& s);

    bool operator!=(const CachedInt& r, const double& s);
    bool operator==(const CachedInt& r, const double& s);
    bool operator<(const CachedInt& r, const double& s);
    bool operator<=(const CachedInt& r, const double& s);
    bool operator>(const CachedInt& r, const double& s);
    bool operator>=(const CachedInt& r, const double& s);

    bool operator!=(const double& r, const CachedInt& s);
    bool operator==(const double& r, const CachedInt& s);
    bool operator<(const double& r, const CachedInt& s);
    bool operator<=(const double& r, const CachedInt& s);
    bool operator>(const double& r, const CachedInt& s);
    bool operator>=(const double& r, const CachedInt& s);

    bool operator!=(const CachedInt& r, const long double& s);
    bool operator==(const CachedInt& r, const long double& s);
    bool operator<(const CachedInt& r, const long double& s);
    bool operator<=(const CachedInt& r, const long double& s);
    bool operator>(const CachedInt& r, const long double& s);
    bool operator>=(const CachedInt& r, const long double& s);

    bool operator!=(const long double& r, const CachedInt& s);
    bool operator==(const long double& r, const CachedInt& s);
    bool operator<(const long double& r, const CachedInt& s);
    bool operator<=(const long double& r, const CachedInt& s);
    bool operator>(const long double& r, const CachedInt& s);
    bool operator>=(const long double& r, const CachedInt& s);

    CachedInt operator+(const double& d, const CachedInt& r);
    CachedInt operator-(const double& d, const CachedInt& r);
    CachedInt operator*(const double& d, const CachedInt& r);
    CachedInt operator/(const double& d, const CachedInt& r);

    bool operator!=(const int& r, const CachedInt& s);
    bool operator==(const int& r, const CachedInt& s);
    bool operator<(const int& r, const CachedInt& s);
    bool operator<=(const int& r, const CachedInt& s);
    bool operator>(const int& r, const CachedInt& s);
    bool operator>=(const int& r, const CachedInt& s);

    CachedInt operator+(const int& d, const CachedInt& r);
    CachedInt operator-(const int& d, const CachedInt& r);
    CachedInt operator*(const int& d, const CachedInt& r);
    CachedInt operator/(const int& d, const CachedInt& r);
}
