/*
 * Hash table double linked list sorted
 * 
 */
#include "hash_table_double_linked_sorted.h"

struct hash_table{
  cached_element* head;
  cached_element* last;
  long median;
  cached_element* middle;
  unsigned long elements;
};

struct cached_element{
  cached_element* next;
  cached_element* prev;
  long index;
  mpz_t* mpz_number;
  double d_number;
};


void init(hash_table& table){
    table = malloc(sizeof(hash_table));
    table->head = NULL;
    table->last = NULL;
    table->median = 0;
    table->middle = NULL;
    table->elements = 0;
}

long update_median(hash_table& table, cached_element& new){
    //if no median was set: set element
    if(table->middle == NULL){
        table->middle = new;
        table->median = new->index;
    }
    //set median at floor(n/2) element
    else{
        unsigned long middle = table->elements / 2;
        unsigned long i;
        cached_element* current_ptr = table->head;
        for (i = 0; i < middle; ++i){
            current_ptr = current_ptr->next;
        }
        table->middle = current_ptr;
        table->median = current_ptr->index;
    }
}

long insert_single_value(hash_table& table, mpz_t value){
    if(mpq_sgn(value) < 0){
        mpq_neg(value, value);
    }
    long hash = get_mpz_hash(value);
    cached_element* new = malloc(sizeof(cached_element));
    
    new->index = hash;
    new->mpz_number = value;
    new->d_number = mpz_get_d(value);
    
    //test in which half the element must be inserted
    if(index < table->median){
        //go forward through list
        cached_element* current_ptr = table->head;
        long current = table->head->index;
        while (current < index){
            current_ptr = current_ptr->next;
            current = current_ptr->index;
        }
        cached_element* current_tmp = current_ptr->prev;
        current_ptr->prev = new;
        new->next = current_ptr;
        new->prev = current_tmp;
        current_tmp.next = new;
    }
    else{
        //go backwards through list
        cached_element* current_ptr = table->last;
        long current = table->last->index;
        while (current > index){
            current_ptr = current_ptr->prev;
            current = current_ptr->index;
        }
        cached_element* current_tmp = current_ptr->next;
        current_ptr->next = new;
        new->prev = current_ptr;
        new->next = current_tmp;
        current_tmp.prev = new;
    }
    table->elements = table->elements + 1;
    update_median(new);
}


mpz_t* lookup_mpz(hash_table& table, long hash){
    //find hash in table and return value
    cached_element* current_ptr;
    long current;
    if(hash < table->median){
        current_ptr = table->head;
        current = table->head->index;
        while (current < index){
            current_ptr = current_ptr->next;
            current = current_ptr->index;
        }
        if(current == index){
            return current_ptr->mpz_number;
        }
    }
    else if(hash == table->median){
        return table->middle->mpz_number;
    }
    else{
        current_ptr = table->last;
        current = table->last->index;
        while (current != index){
            current_ptr = current_ptr->prev;
            current = current_ptr->index;
        }
        if(current == index){
            return current_ptr->mpz_number;
        }
    }
}

double lookup_d(hash_table& table, long hash){
    cached_element* current_ptr;
    long current;
    //find hash in table and return value
    if(hash < table->median){
        current_ptr = table->head;
        current = table->head->index;
        while (current < index){
            current_ptr = current_ptr->next;
            current = current_ptr->index;
        }
        if(current == index){
            return current_ptr->d_number;
        }
    }
    else if(hash == table->median){
        return table->middle->d_number;
    }
    else{
        current_ptr = table->last;
        current = table->last->index;
        while (current != index){
            current_ptr = current_ptr->prev;
            current = current_ptr->index;
        }
        if(current == index){
            return current_ptr->mpz_number;
        }
    }
    return 0;
}