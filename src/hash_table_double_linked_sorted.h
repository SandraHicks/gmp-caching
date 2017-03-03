/*
 *
 */

/* 
 * File:   hash_table_double_linked_sorted.h
 * Author: sandra
 *
 * Created on March 3, 2017, 10:15 AM
 */
#include <gmp.h>
#include "hashing.h"
#include <math.h>

#ifndef HASH_TABLE_DOUBLE_LINKED_SORTED_H
#define HASH_TABLE_DOUBLE_LINKED_SORTED_H

enum Operator {addition, substraction, multiplication, division, gcd, inverse, factional, absolute};


void init(hash_table& table);
long insert_single_value(hash_table& table, mpz_t value);
mpz_t* lookup_mpz(hash_table& table, long hash);
double lookup_d(hash_table& table, long hash);

#endif /* HASH_TABLE_DOUBLE_LINKED_SORTED_H */