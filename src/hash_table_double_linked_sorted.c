/*
 * Hash table double linked list sorted
 * only positive mpq_t are stored in the table
 * 
 */
#include "hash_table_double_linked_sorted.h"


/*
 * Lookup Table for large numbers
 */
struct hash_table{
  cached_element* head;
  cached_element* last;
  long median;
  cached_element* middle;
  unsigned long elements;
}LookupTable;

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

void empty(hash_table& table){
    
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
    cached_element* new = malloc(sizeof(cached_element));
    return _insert_for_operator(table, value, new);
}

long _insert_for_operator(hash_table& table, mpz_t value, cached_element& new){
    if(mpq_sgn(value) < 0){
        mpq_neg(value, value);
    }
    long hash = get_mpz_hash(value);
    
    new->index = hash;
    new->mpz_number = value;
    new->d_number = mpz_get_d(value);
    
    //test in which half the element must be inserted
    cached_element* current_ptr;
    if(index < table->median){
        //go forward through list
        current_ptr = table->head;
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
        current_ptr = table->last;
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
    update_median(table, new);
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

/*
 * Lookup Table for unary operations
 */
struct hash_table_un{
  unary_op_cached_element* head;
  unary_op_cached_element* last;
  long median;
  unary_op_cached_element* middle;
  unsigned long elements;
  Operator op;
  hash_table lookup;
}UnaryOperatorTable;

struct unary_op_cached_element{
  unary_op_cached_element* next;
  unary_op_cached_element* prev;
  long index;
  cached_element* number;
};

void init(hash_table_un& table, Operator o, hash_table tab){
    table->head = NULL;
    table->last = NULL;
    table->median = 0;
    table->middle = NULL;
    table->elements = 0;
    table->op = o;
    table->lookup = tab;
}

void empty(hash_table_un& table){
    
}

void update_median(hash_table_un& table, unary_op_cached_element& new){
    //if no median was set: set element
    if(table->middle == NULL){
        table->middle = new;
        table->median = new->index;
    }
    //set median at floor(n/2) element
    else{
        unsigned long middle = table->elements / 2;
        unsigned long i;
        unary_op_cached_element* current_ptr = table->head;
        for (i = 0; i < middle; ++i){
            current_ptr = current_ptr->next;
        }
        table->middle = current_ptr;
        table->median = current_ptr->index;
    }
}

long insert(hash_table_un& table, mpz_t op, mpz_t result){
    //insert single numbers in general lookup
    long hop = insert_single_value(table->lookup, op);
    cached_element* cached_result = malloc(sizeof(cached_element));
    long hres = _insert_for_operator(table->lookup, result, cached_result);
    
    //insert lookup in unary table
    long h_un = _insert_(table, hres, cached_result);
    return h_un;
}

void _insert_(hash_table_un& table, long hash, cached_element* cached_result){
    unary_op_cached_element* new = malloc(sizeof(unary_op_cached_element));
    new->index = hash;
    new->cached_element = cached_result;
    
        //test in which half the element must be inserted
    unary_op_cached_element* current_ptr;
    unary_op_cached_element* current_tmp;
    if(index < table->median){
        //go forward through list
        current_ptr = table->head;
        long current = table->head->index;
        while (current < index){
            current_ptr = current_ptr->next;
            current = current_ptr->index;
        }
        current_tmp = current_ptr->prev;
        current_ptr->prev = new;
        new->next = current_ptr;
        new->prev = current_tmp;
        current_tmp.next = new;
    }
    else{
        //go backwards through list
        current_ptr = table->last;
        long current = table->last->index;
        while (current > index){
            current_ptr = current_ptr->prev;
            current = current_ptr->index;
        }
        current_tmp = current_ptr->next;
        current_ptr->next = new;
        new->prev = current_ptr;
        new->next = current_tmp;
        current_tmp.prev = new;
    }
    table->elements = table->elements + 1;
    //update median
    update_median(table, new);
}

mpz_t* lookup_mpz(hash_table_un& table, long hash){
    
}

double lookup_d(hash_table_un& table, long hash){
    
}

/*
 * Lookup Table for binary operators
 */
struct hash_table_bin{
  binary_op_cached_element* head;
  binary_op_cached_element* last;
  long median;
  binary_op_cached_element* middle;
  unsigned long elements;
  Operator op;
  hash_table lookup;
}BinaryOperatorTable;

struct binary_op_cached_element{
  binary_op_cached_element* next;
  binary_op_cached_element* prev;
  long index;
  cached_element* number;
};

void init(hash_table_bin& table, Operator o, hash_table tab){
    table->head = NULL;
    table->last = NULL;
    table->median = 0;
    table->middle = NULL;
    table->elements = 0;
    table->op = o;
    table->lookup = tab;
}

void empty(hash_table_bin& table){
    
}

long insert(hash_table_bin& table, mpz_t op1, mpz_t op2, mpz_t result){
    //insert single numbers in general lookup
    long hop = insert_single_value(table->lookup, op1);
    long hop = insert_single_value(table->lookup, op2);
    cached_element* new = malloc(sizeof(cached_element));
    long hres = _insert_for_operator(table->lookup, result, new);
    
    //insert combined lookup in binary table
    binary_op_cached_element* new = malloc(sizeof(binary_op_cached_element));
    
    return 0;
}

mpz_t* lookup_mpz(hash_table_bin& table, long op1, long op2){
    
}

double lookup_d(hash_table_bin& table, long op1, long op2){
    
}