/*
 * Hash table with Array implementation
 * 
 */
#include <gmp.h>


struct hash_table{
  mpz_t* table;
};

void init(hash_table t, long size){
    //initialize array and set it to the table pointer
    mpz_t tab[size];
}

long insert(hash_table t, mpz_t element){
    
}

void extend(hash_table t, long new_size){
    
}