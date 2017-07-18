#include <gmpxx.h>
#include <gmp.h>
#include <cstdint>
#include <cstdio>

#include "foo.h"

extern "C" {


  typedef struct FOO { int a; } Bla;

  void gnaaa(int a)
  { 
    mpz_t y;
    mpz_init_set_si(y, 19); 
    printf("x\n");
  }

}

int main()
{
  gnaaa(1);
  return 0;
}
