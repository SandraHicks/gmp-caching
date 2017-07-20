#include "master_cache_integer.h"
#include "master_cache_rational.h"

#include <gmp.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>

#include <assert.h>
//void assert(int expression)

/*
  Tests for checking the functionality of the master cache
*/
#define SIZE_C 1000

/*
Test definitions Integer
*/
void Test101(MasterCache* cache, 
cachedInt* very_small, cachedInt* small, cachedInt* large_uncached, cachedInt* large_uncached_neg, cachedInt* large_cached, cachedInt* large_cached_neg, cachedInt* very_large_cached, 
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached);

void Test102(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test103(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test104(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test105(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test106(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test107(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test108(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test109(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test110(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

/*
Test definitions recaching
*/

void Test301(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached,
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached);

void Test302(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

void Test303(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached);

/*
Test definitions Rational
*/
void Test201(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1,
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached);

void Test202(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test203(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test204(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test205(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test206(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test207(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

void Test208(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1);

/*
Main Test
*/
int main(int argc, char** argv) {
  //init cache
  MasterCache* cache;
  cache_init(&cache, SIZE_C);

  //init test values
  mpz_t m_very_small;
  mpz_t m_small;
  mpz_t m_large_uncached;
  mpz_t m_large_uncached_neg;
  mpz_t m_large_cached;
  mpz_t m_large_cached_neg;
  mpz_t m_very_large_cached;

  mpz_init(m_very_small);
  mpz_init(m_small);
  mpz_init(m_large_uncached);
  mpz_init(m_large_uncached_neg);
  mpz_init(m_large_cached);
  mpz_init(m_large_cached_neg);
  mpz_init(m_very_large_cached);

  //set test values
  mpz_set_si(m_very_small, 2l);
  mpz_set_si(m_small, 1234l);

  unsigned long l_large_uncached = ((unsigned long)1 << 62)-3;
  long l_large_uncached_neg = (((long)1 << 62)-3)*(-1);
  mpz_set_ui(m_large_uncached, l_large_uncached);
  mpz_set_si(m_large_uncached_neg, l_large_uncached_neg);

  unsigned long l_large_cached = LONG_MAX;
  long l_large_cached_neg = LONG_MAX * (-1);
  mpz_set_ui(m_large_cached, l_large_cached);
  mpz_set_si(m_large_cached_neg, l_large_cached_neg);

  mpz_set_si(m_very_large_cached, l_large_cached);
  int a = 0;
  for(a = 0; a < 10; a++){
    mpz_add_ui(m_very_large_cached, m_very_large_cached, l_large_cached);
  }

  //ids
  cachedInt very_small;
  cachedInt small;
  cachedInt large_uncached;
  cachedInt large_uncached_neg;
  cachedInt large_cached;
  cachedInt large_cached_neg;
  cachedInt very_large_cached;

  //run int tests
  Test101(cache, 
&very_small, &small, &large_uncached, &large_uncached_neg, &large_cached, &large_cached_neg, &very_large_cached, 
m_very_small, m_small, m_large_uncached, m_large_uncached_neg, m_large_cached, m_large_cached_neg, m_very_large_cached);

  Test102(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test103(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test104(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test105(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

//TODO Test 106

  Test107(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test108(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test109(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  Test110(cache, 
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached);

  //ids
  cachedRational s1;
  cachedRational s2;
  cachedRational l1;
  cachedRational l2;
  cachedRational n1;

  //run rational tests
  Test201(cache, &s1, &s2, &l1, &l2, &n1, m_very_small, m_small, m_large_uncached, m_large_uncached_neg, m_large_cached, m_large_cached_neg, m_very_large_cached);

  Test202(cache, &s1, &s2, &l1, &l2, &n1);

  Test203(cache, &s1, &s2, &l1, &l2, &n1);
  
  Test204(cache, &s1, &s2, &l1, &l2, &n1);

  Test205(cache, &s1, &s2, &l1, &l2, &n1);

  Test206(cache, &s1, &s2, &l1, &l2, &n1);

  Test207(cache, &s1, &s2, &l1, &l2, &n1);

  Test208(cache, &s1, &s2, &l1, &l2, &n1);


  //run recaching tests
  Test301(cache,
very_small, small, large_uncached, large_uncached_neg, large_cached, large_cached_neg, very_large_cached,
m_very_small, m_small, m_large_uncached, m_large_uncached_neg, m_large_cached, m_large_cached_neg, m_very_large_cached);


  mpz_clear(m_very_small);
  mpz_clear(m_small);
  mpz_clear(m_large_uncached);
  mpz_clear(m_large_uncached_neg);
  mpz_clear(m_large_cached);
  mpz_clear(m_large_cached_neg);
  mpz_clear(m_very_large_cached);

  //clear cache
  cache_clear(cache);
  cache = NULL;
  return 0;
}

void Test101(MasterCache* cache, 
cachedInt* very_small, cachedInt* small, cachedInt* large_uncached, cachedInt* large_uncached_neg, cachedInt* large_cached, cachedInt* large_cached_neg, cachedInt* very_large_cached, 
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached){

  printf("\n--Test 101 Results (Caching):--\n");
  *very_small = cached_int_set(cache, m_very_small);
  *small = cached_int_set(cache, m_small);
  *large_uncached = cached_int_set(cache, m_large_uncached);
  *large_uncached_neg = cached_int_set(cache, m_large_uncached_neg);
  *large_cached = cached_int_set(cache, m_large_cached);
  *large_cached_neg = cached_int_set(cache, m_large_cached_neg);
  *very_large_cached = cached_int_set(cache, m_very_large_cached);

  printf("very_small: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *very_small, (*very_small & ~SHIFT), (*very_small & ~NEG), ((*very_small & ~NEG) & ~SHIFT));
  printf("small: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *small, (*small & ~SHIFT), (*small & ~NEG), ((*small & ~NEG) & ~SHIFT));
  printf("large_uncached: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *large_uncached, (*large_uncached & ~SHIFT), (*large_uncached & ~NEG), ((*large_uncached & ~NEG) & ~SHIFT));
  printf("large_uncached_neg: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *large_uncached_neg, (*large_uncached_neg & ~SHIFT), (*large_uncached_neg & ~NEG), ((*large_uncached_neg & ~NEG) & ~SHIFT));
  printf("large_cached: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *large_cached, (*large_cached & ~SHIFT), (*large_cached & ~NEG), ((*large_cached & ~NEG) & ~SHIFT));
  printf("large_cached_neg: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *large_cached_neg, (*large_cached_neg & ~SHIFT), (*large_cached_neg & ~NEG), ((*large_cached_neg & ~NEG) & ~SHIFT));
  printf("very_large_cached: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", *very_large_cached, (*very_large_cached & ~SHIFT), (*very_large_cached & ~NEG), ((*very_large_cached & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?
}

void Test102(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){

  printf("\n--Test 102 Results (add):--\n");
  cachedInt a1 = cached_int_add(cache, small, small);
  cachedInt a2 = cached_int_add(cache, large_uncached, small);
  cachedInt a3 = cached_int_add(cache, large_uncached, large_uncached);
  cachedInt a4 = cached_int_add(cache, very_large_cached, small);
  cachedInt a5 = cached_int_add(cache, very_large_cached, large_cached);
  cachedInt a6 = cached_int_add(cache, large_uncached, large_uncached_neg);

  printf("a1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a1, (a1 & ~SHIFT), (a1 & ~NEG), ((a1 & ~NEG) & ~SHIFT));
  printf("a2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a2, (a2 & ~SHIFT), (a2 & ~NEG), ((a2 & ~NEG) & ~SHIFT));
  printf("a3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a3, (a3 & ~SHIFT), (a3 & ~NEG), ((a3 & ~NEG) & ~SHIFT));
  printf("a4: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a4, (a4 & ~SHIFT), (a4 & ~NEG), ((a4 & ~NEG) & ~SHIFT));
  printf("a5: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a5, (a5 & ~SHIFT), (a5 & ~NEG), ((a5 & ~NEG) & ~SHIFT));
  printf("a6: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", a6, (a6 & ~SHIFT), (a6 & ~NEG), ((a6 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test103(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){

  printf("\n--Test 103 Results (mul):--\n");
  cachedInt m1 = cached_int_mul(cache, small, small);
  cachedInt m2 = cached_int_mul(cache, large_uncached, small);
  cachedInt m3 = cached_int_mul(cache, large_uncached, large_uncached);
  cachedInt m4 = cached_int_mul(cache, very_large_cached, small);
  cachedInt m5 = cached_int_mul(cache, very_large_cached, large_cached);
  cachedInt m6 = cached_int_mul(cache, large_uncached, large_uncached_neg);

  printf("m1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m1, (m1 & ~SHIFT), (m1 & ~NEG), ((m1 & ~NEG) & ~SHIFT));
  printf("m2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m2, (m2 & ~SHIFT), (m2 & ~NEG), ((m2 & ~NEG) & ~SHIFT));
  printf("m3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m3, (m3 & ~SHIFT), (m3 & ~NEG), ((m3 & ~NEG) & ~SHIFT));
  printf("m4: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m4, (m4 & ~SHIFT), (m4 & ~NEG), ((m4 & ~NEG) & ~SHIFT));
  printf("m5: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m5, (m5 & ~SHIFT), (m5 & ~NEG), ((m5 & ~NEG) & ~SHIFT));
  printf("m6: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m6, (m6 & ~SHIFT), (m6 & ~NEG), ((m6 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test104(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){

  printf("\n--Test 104 Results (tdiv):--\n");
  cachedInt r1;
  cachedInt r2;
  cachedInt r3;
  cachedInt r4;
  cachedInt r5;
  cachedInt r6;

  cachedInt m1 = cached_int_tdiv(cache, large_uncached, small, &r1);
  cachedInt m2 = cached_int_tdiv(cache, small, large_uncached, &r2);
  cachedInt m3 = cached_int_tdiv(cache, large_cached, large_uncached, &r3);
  cachedInt m4 = cached_int_tdiv(cache, large_cached, small, &r4);
  cachedInt m5 = cached_int_tdiv(cache, large_uncached, large_uncached_neg, &r5);

  printf("m1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m1, (m1 & ~SHIFT), (m1 & ~NEG), ((m1 & ~NEG) & ~SHIFT));
  printf("r1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", r1, (r1 & ~SHIFT), (r1 & ~NEG), ((r1 & ~NEG) & ~SHIFT));

  printf("m2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m2, (m2 & ~SHIFT), (m2 & ~NEG), ((m2 & ~NEG) & ~SHIFT));
  printf("r2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", r2, (r2 & ~SHIFT), (r2 & ~NEG), ((r2 & ~NEG) & ~SHIFT));

  printf("m3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m3, (m3 & ~SHIFT), (m3 & ~NEG), ((m3 & ~NEG) & ~SHIFT));
  printf("r3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", r3, (r3 & ~SHIFT), (r3 & ~NEG), ((r3 & ~NEG) & ~SHIFT));

  printf("m4: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m4, (m4 & ~SHIFT), (m4 & ~NEG), ((m4 & ~NEG) & ~SHIFT));
  printf("r4: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", r4, (r4 & ~SHIFT), (r4 & ~NEG), ((r4 & ~NEG) & ~SHIFT));

  printf("m5: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m5, (m5 & ~SHIFT), (m5 & ~NEG), ((m5 & ~NEG) & ~SHIFT));
  printf("r5: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", r5, (r5 & ~SHIFT), (r5 & ~NEG), ((r5 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test105(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){

  printf("\n--Test 105 Results (gcd):--\n");
  cachedInt m1 = cached_int_gcd(cache, small, very_small);
  cachedInt m2 = cached_int_gcd(cache, large_uncached, small);
  cachedInt m3 = cached_int_gcd(cache, large_cached, very_large_cached);

  printf("m1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m1, (m1 & ~SHIFT), (m1 & ~NEG), ((m1 & ~NEG) & ~SHIFT));
  printf("m2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m2, (m2 & ~SHIFT), (m2 & ~NEG), ((m2 & ~NEG) & ~SHIFT));
  printf("m3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", m3, (m3 & ~SHIFT), (m3 & ~NEG), ((m3 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?

}

void Test106(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 106 Results (inv):--\n");

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test107(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 107 Results (lcm):--\n");

  cachedInt l1 = cached_int_lcm(cache, small, small);
  cachedInt l2 = cached_int_lcm(cache, large_uncached, very_small);

  printf("l1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l1, (l1 & ~SHIFT), (l1 & ~NEG), ((l1 & ~NEG) & ~SHIFT));
  printf("l2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l2, (l2 & ~SHIFT), (l2 & ~NEG), ((l2 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test108(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 108 Results (abs):--\n");
  cachedInt l1 = cached_int_abs(cache, large_uncached);
  cachedInt l2 = cached_int_abs(cache, large_uncached_neg);
  cachedInt l3 = cached_int_abs(cache, large_cached_neg);
 

  printf("l1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l1, (l1 & ~SHIFT), (l1 & ~NEG), ((l1 & ~NEG) & ~SHIFT));
  printf("l2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l2, (l2 & ~SHIFT), (l2 & ~NEG), ((l2 & ~NEG) & ~SHIFT));
  printf("l3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l3, (l3 & ~SHIFT), (l3 & ~NEG), ((l3 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

}


void Test109(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 109 Results (sgn):--\n");
  int l1 = cached_int_sgn(cache, large_uncached);
  int l2 = cached_int_sgn(cache, large_uncached_neg);
  int l3 = cached_int_sgn(cache, large_cached_neg);

  printf("Sign 1: %d, Sign 2: %d, Sign 3: %d\n", l1, l2, l3);

  //which signs should be returned?
}

void Test110(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 110 Results (neg):--\n");
  cachedInt l1 = cached_int_neg(cache, large_uncached);
  cachedInt l2 = cached_int_neg(cache, large_uncached_neg);
  cachedInt l3 = cached_int_neg(cache, large_cached_neg);
 

  printf("l1: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l1, (l1 & ~SHIFT), (l1 & ~NEG), ((l1 & ~NEG) & ~SHIFT));
  printf("l2: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l2, (l2 & ~SHIFT), (l2 & ~NEG), ((l2 & ~NEG) & ~SHIFT));
  printf("l3: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", l3, (l3 & ~SHIFT), (l3 & ~NEG), ((l3 & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?
}

void Test201(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1,
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached){
  printf("\n--Test 201 Results (Caching):--\n");

  *s1 = cached_rational_set(cache, m_very_small, m_small);
  *s2 = cached_rational_set(cache, m_small, m_large_uncached);
  *l1 = cached_rational_set(cache, m_small, m_large_cached);
  *l2 = cached_rational_set(cache, m_large_cached, m_very_large_cached);
  *n1 = cached_rational_set(cache, m_large_uncached_neg, m_small);
  printf("All Rationals set\n");

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?
}

void Test202(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 202 Results (add):--\n");
  cachedRational s1s1;
  cachedRational s1s2;
  cachedRational l1l2;
  cachedRational l1n1;

  s1s1 = cached_rational_add(cache, *s1, *s1);
  s1s2 = cached_rational_add(cache, *s1, *s2);
  l1l2 = cached_rational_add(cache, *l1, *l2);
  l1n1 = cached_rational_add(cache, *l1, *n1);

  printf("s1s1.c: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", s1s1.counter, (s1s1.counter & ~SHIFT), (s1s1.counter & ~NEG), ((s1s1.counter & ~NEG) & ~SHIFT));
  printf("s1s1.d: %" PRIu64 " without id bit: %" PRIu64 " without sign bit: %" PRIu64 " without both: %" PRIu64 "\n", s1s1.denominator, (s1s1.denominator & ~SHIFT), (s1s1.denominator & ~NEG), ((s1s1.denominator & ~NEG) & ~SHIFT));

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test203(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 203 Results (mul):--\n");
  cachedRational s1s1;
  cachedRational l1l2;
  cachedRational l1n1;
  s1s1 = cached_rational_mul(cache, *s1, *s1);
  l1l2 = cached_rational_mul(cache, *l1, *l2);
  l1n1 = cached_rational_mul(cache, *l1, *n1);

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test204(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 204 Results (inv):--\n");
  cachedRational rs1;
  cachedRational rl2;

  rs1 = cached_rational_reduce(cache, *s1);
  rl2 = cached_rational_reduce(cache, *l2);

  //which NEG bits were expected to be set?

  //which ID bits were expected to be set?

  //which IDs should be given?

  //what numerical results should we have?
}

void Test206(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 206 Results (abs):--\n");
  cachedRational as1;

  as1 = cached_rational_inv(cache, *s1);

  //what numerical results should we have?
}

void Test205(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 205 Results (abs):--\n");
  cachedRational as1;
  cachedRational an1;

  as1 = cached_rational_abs(cache, *s1);
  an1 = cached_rational_abs(cache, *n1);

  //which NEG bits were expected to be set?
}

void Test207(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 207 Results (neg):--\n");
  cachedRational as1;
  cachedRational an1;

  as1 = cached_rational_neg(cache, *s1);
  an1 = cached_rational_neg(cache, *n1);

  //which NEG bits were expected to be set?
}

void Test208(MasterCache* cache, 
cachedRational* s1, cachedRational* s2, cachedRational* l1, cachedRational* l2, cachedRational* n1){
  printf("\n--Test 207 Results (sgn): 1 pos, 0 neg--\n");
  int as1;
  int an1;

  as1 = cached_rational_sgn(cache, *s1);
  an1 = cached_rational_sgn(cache, *n1);

  printf("s1: %d\n",as1);
  printf("n1: %d\n",an1);

  //which signs should be returned?
}

void Test301(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached,
mpz_t m_very_small, mpz_t m_small, mpz_t m_large_uncached, mpz_t m_large_uncached_neg, mpz_t m_large_cached, mpz_t m_large_cached_neg, mpz_t m_very_large_cached){
  printf("\n--Test 301 Results (recache int):--\n");
  cachedInt lc = cached_int_set(cache, m_large_cached);
  cachedInt lcn = cached_int_set(cache, m_large_cached_neg);
  cachedInt vlc = cached_int_set(cache, m_very_large_cached);

  printf("new %" PRIu64 " old: %" PRIu64 "\n", lc, large_cached);

  //which IDs should be given?
  assert(lc == large_cached);
  assert(lcn == large_cached_neg);
  assert(vlc == very_large_cached);
}

void Test302(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 302 Results (recache int add):--\n");

  //which IDs should be given?
}

void Test303(MasterCache* cache, 
cachedInt very_small, cachedInt small, cachedInt large_uncached, cachedInt large_uncached_neg, cachedInt large_cached, cachedInt large_cached_neg, cachedInt very_large_cached){
  printf("\n--Test 303 Results (recache rational): 1--\n");

  //which IDs should be given?
}
