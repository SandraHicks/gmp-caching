 /**
  * @file hashtable.c
  * @author Sandra Hicks
  * @brief hash table implementation
  */
#include "hashtable.h"
#include "hashing.h"
#include "mpz_caching.h"
#include <stdint.h>
#include <stdlib.h>

//Debug
#include <stdio.h>
#include <inttypes.h>

static unsigned int collisions_counter;
static unsigned int inserted;

/**
 * @brief initialization of the hash table
 * @param ht pointer to hash table
 * @param size of the hash table
 */
void init_hashtable(Hashtable* ht, uint64_t size){
    ht->size = size;
    
    cachedIntList* l = malloc(sizeof(cachedIntList)*(size));
    ht->lists = l;
    
    ht->counter = malloc(sizeof(int)*size);
    //init counter array with 0
    unsigned int i = size;
    while(i--){
        ht->counter[i] = 0;
    }
    collisions_counter=0;
    inserted=0;
    printf("ht-size: %" PRIu64 "\n", size);
}

/**
 * @brief deletion of the hash table and all its underlying data structures
 * @param ht pointer to hash table
 */
void delete_hashtable(Hashtable* ht){
    unsigned int i = 0;
    uint64_t size = ht->size;
    int maxlength=0;
    for(i=0; i<ht->size; ++i){
        int templength=1;
        cachedIntList* curr_list = &(ht->lists[i]);
        cachedIntElement* curr = curr_list->head;
        while(curr != curr_list->tail){
            cachedIntElement* next = curr->next;
            free(curr);
            curr = next;
            templength++;
        }
        free(curr_list->tail);
        if(templength > maxlength)
            maxlength=templength;
    }
    free(ht->counter);
    free(ht->lists);
    ht->counter = NULL;
    ht->lists = NULL;
    
    printf("Collisions: %d Inserted: %d Collided Elements: %d, cache size: %" PRIu64 ", ht size: %" PRIu64 " maxlength = %d\n", collisions_counter, inserted, collisions_counter / NUMBER_HF, size * (uint64_t)(1/hashtable_RATIO), size, maxlength);
}

/**
 * @brief insertion method for an element in the hash table
 * @param ht pointer to hash table
 * @param id id of the mpz_t in the singleton cache
 * @param hashes array of hash values of the mpz_t
 */
void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes){
    //get all hashes mod size
    int64_t* h;
    unsigned int number_hf = NUMBER_HF;
    h = malloc(sizeof(int64_t)*number_hf);
    
    uint64_t uh_temp1 = hashes[0];
    int64_t h_temp1 = (int64_t)uh_temp1;
    h[0] = h_temp1;
    
    
    unsigned int i;
    for(i=0; i<number_hf; ++i){
        uint64_t uh_temp = hashes[i];
        int64_t h_temp = (int64_t)uh_temp;
        if(h_temp > ht->size){
            if(ht->size > 0)
                h_temp = (int64_t)(h_temp % (int64_t)ht->size);
        }
        h[i] = h_temp;
        
    }
    
    //check if any hash was doubled, set doubled to -1
    for(i=0; i<NUMBER_HF; ++i){
        int j;
        for(j=0;j<NUMBER_HF; ++j){
            if(i!=j){
                h[j] = (h[i] != h[j]) ? h[j]: -1;
            }
        }
    }
    inserted++;
    //insert id into all hashed positions in hashtable
    for(i=0; i<NUMBER_HF; ++i){
        if(h[i]>=0){
            //create new element
            cachedIntElement* this = malloc(sizeof(cachedIntElement));
            this->id = id;
            this->hash = hashes[i];
            this->next = NULL;
            //insert in sorted List, sort by id. can attach to last pointer because ids are fortlaufend
            cachedIntList* list = &(ht->lists[h[i]]);
            int curr_count = ht->counter[h[i]];
            if(curr_count == 0){
                list->head = this;
                list->tail = this;
            }
            else{
                collisions_counter++;
                cachedIntElement* last = list->tail;
                last->next = this;
                this->prev = last;
                list->tail = this;
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
    free(h);
    h = NULL;
}


/**
 * @brief check existence of an element
 * @param ht pointer to hash table
 * @param hashes array of hash values for the element
 * @param element mpz_t to search for, not negative!
 * @param cache pointer to singleton cache
 * @return id if existent, if not return 0
 */
uint64_t exists_element(Hashtable* ht, uint64_t* hashes, mpz_t element, mpz_t_cache* cache){
    //check if counter at hash position >= 1 if not, return
    cachedIntElement* statefulPointer[NUMBER_HF];
    unsigned int min=0;
    unsigned int i;
    for(i=0; i < NUMBER_HF; ++i){
        if(ht->counter[(hashes[i] % ht->size)] < 1){
            return SHIFT;
        }
        if(ht->counter[(hashes[i] % ht->size)] 
                < ht->counter[(hashes[min] % ht->size)]){
            min = i;
        }
        int index = (hashes[i] % ht->size);
        cachedIntList* curr_list = &(ht->lists[index]);
        statefulPointer[i] = curr_list->head;
        
    }
    //exists one element in all lists
    
    //1. find list of minimal size (previous loop)
    //2. find elements of minimal list in other lists
    
    
    //sequential search, later binary search
    unsigned int index = (hashes[min] % ht->size);
    cachedIntList* curr_list = &(ht->lists[index]);
    cachedIntElement* curr_min = curr_list->head;
    while(curr_min){
        uint64_t curr_id = curr_min->id;
        int globalfound = 0;
        int i;
        for(i=0;i<NUMBER_HF; ++i){
            //check all lists except for minimal sized one
            if(i!=min){
                cachedIntElement* curr_list = statefulPointer[i];
                int listfound = 0;
                //search for id of element in minimal list
                while(curr_list){
                    if(curr_list->id == curr_id){
                        listfound = 1;
                        globalfound = 1;
                        statefulPointer[i] = curr_list;
                        break;
                    }
                    curr_list = curr_list->next;
                }
                
                //if the element was not found in the list, go to next element in minimal list
                if(listfound == 0){
                    globalfound = 0;
                    break;
                }
            }
        }
        //after searching all lists, check if found
        if(globalfound == 1){
            mpz_t cached_val;
            mpz_init(cached_val);
            if((curr_id & SHIFT) > 0){
                get_cached_mpz(cache, (curr_id & ~SHIFT), cached_val);
            }
            else{
                unsigned long l[4];
                if(sizeof(long) < 8){
                    //TODO
                    l[0] = curr_id;
                }
                else{
                    l[0] = curr_id;
                }
                mpz_import(cached_val, 1, 1, sizeof(int64_t), 0, 0, l);
            }
            int cmp = mpz_cmpabs(cached_val, element);
            if(cmp == 0)
                return curr_id;
        }
        
        curr_min = curr_min->next;
    }
    return SHIFT;
}

/**
 * @brief function to calculate the multiple hash values for an mpz_t element
 * @param val mpz_t value to hash
 * @param hashes pointer to array of hashes to fill
 */
void get_k_hashes(mpz_t val, uint64_t* hashes){
    unsigned int number = (NUMBER_HF);
    switch(number){
        case 1: 
            hashes[0] = get_FNV1a_hash(val);
            break;
        case 2: 
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            break;
        case 3: 
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            hashes[2] = get_CRC_hash(val);
            break;
        case 4: 
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            hashes[2] = get_CRC_hash(val);
            hashes[3] = get_adler_hash(val);
            break;
        case 5: 
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            hashes[2] = get_CRC_hash(val);
            hashes[3] = get_adler_hash(val);
            hashes[4] = get_Jenkins_hash(val);
            break;
        case 6:
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            hashes[2] = get_CRC_hash(val);
            hashes[4] = get_Jenkins_hash(val);
            hashes[5] = get_Sip_hash(val);
        default:
            //ERROR
            break;
    }
}

/**
 * @brief function to calculate multiple hashes for a tupel of mpz_t's after applying Cantor Pairing function
 * @param val1 first mpz_t
 * @param val2 second mpz_t
 * @param hashes array of hashes to fill
 */
void get_k_hashes_cpf(mpz_t val1, mpz_t val2, uint64_t* hashes){
    
    mpz_t op1;
    mpz_t op2;
    mpz_init(op1);
    mpz_init(op2);
    mpz_set(op1, val1);
    mpz_set(op2, val2);
    op1->_mp_size = (op1->_mp_size >= 0) ? op1->_mp_size : op1->_mp_size*(-1);
    op2->_mp_size = (op2->_mp_size >= 0) ? op2->_mp_size : op2->_mp_size*(-1);
    uint64_t* hashes1;
    hashes1 = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(op1, hashes1);

    
    uint64_t* hashes2;
    hashes2 = malloc(sizeof(uint64_t)*NUMBER_HF);

    get_k_hashes(op2, hashes2);
  
    unsigned int i;
    for(i=0;i<NUMBER_HF;++i){
        hashes[i] = Cantor_pairing_function_int64(hashes1[i], hashes2[i]);
    }
    free(hashes1);
    hashes1 = NULL;
    free(hashes2);
    hashes2 = NULL;
    mpz_clear(op1);
    mpz_clear(op2);
}


/**
 * @brief initialization of a hashtable for (mpz_t x mpz_t) -> mpz_t
 * @param ht pointer to hash table
 * @param size size of hash table
 */
void init_hashtable_binary(Hashtable_binary* ht, uint64_t size){
    ht->size = size;
    
    cachedIntList_binary* l = malloc(sizeof(cachedIntList_binary)*(size));
    ht->lists = l;
    
    ht->counter = malloc(sizeof(int)*size);
    //init counter array with 0
    unsigned int i = size;
    while(i--){
        ht->counter[i] = 0;
    }
}

/**
 * @brief deletion of hash table and all underlying data structures
 * @param ht pointer to hash table
 */
void delete_hashtable_binary(Hashtable_binary* ht){
    unsigned int i = 0;
    for(i=0; i<ht->size; ++i){
        cachedIntList_binary* curr_list = &(ht->lists[i]);
        cachedIntElement_binary* curr = curr_list->head;
        while(curr != curr_list->tail){
            cachedIntElement_binary* next = curr->next;
            free(curr);
            curr = next;
        }
        free(curr_list->tail);
    }
    free(ht->counter);
    ht->counter = NULL;
    free(ht->lists);
    ht->lists = NULL;
}
/**
 * @brief insert a mapping (mpz_t x mpz_t) -> mpz_t in hashtable 
 * @param ht pointer to hash table
 * @param id_op1 id to first operand in singleton cache
 * @param id_op2 id to second operand in singleton cache
 * @param id_res id to result in singleton cache
 * @param extra_info id to extra info in singleton cache (e.g. division rest)
 * @param hashes array of hashes
 */
void insert_element_binary(Hashtable_binary* ht, uint64_t id_op1, uint64_t id_op2, uint64_t id_res, uint64_t* extra_info, uint64_t* hashes){
    //get all hashes mod size
    int64_t* h;
    unsigned int number_hf = NUMBER_HF;
    h = malloc(sizeof(int64_t)*number_hf);
    
    uint64_t uh_temp1 = hashes[0];
    int64_t h_temp1 = (int64_t)uh_temp1;
    h[0] = h_temp1;
    
    unsigned int i;
    for(i=0; i<number_hf; ++i){
        
        uint64_t uh_temp = hashes[i];
        int64_t h_temp = (int64_t)uh_temp;
        if(h_temp > ht->size){
            if(ht->size > 0)
                h_temp = (int64_t)(h_temp % (int64_t)ht->size);
        }
        h[i] = h_temp;
        
    }
    //check if any hash was doubled, set doubled to -1
    for(i=0; i<NUMBER_HF; ++i){
        int j;
        for(j=0;j<NUMBER_HF; ++j){
            if(i!=j){
                h[j] = (h[i] != h[j]) ? h[j]: -1;
            }
        }
    }
    //insert id into all hashed positions in hashtable
    for(i=0; i<NUMBER_HF; ++i){
        if(h[i]>=0){
            //create new element
            cachedIntElement_binary* this = malloc(sizeof(cachedIntElement_binary));

            this->op1 = id_op1;
            this->op2 = id_op2;
            this->result = id_res;
            this->next = NULL;
            if(extra_info != NULL)
                this->extra_info = *extra_info;
            this->hash = hashes[i];
            //insert in sorted List, sort by id. can attach to last pointer because ids are fortlaufend
            cachedIntList_binary* list = &(ht->lists[h[i]]);
            int curr_count = ht->counter[h[i]];
            if(curr_count == 0){
                list->head = this;
                list->tail = this;
            }
            else{
                cachedIntElement_binary* last = list->tail;
                last->next = this;
                this->prev = last;
                list->tail = this;
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
    free(h);
    h=NULL;
}

/**
 * @brief function to check if a mapping (mpz_t x mpz_t) -> mpz_t exists in the hash table
 * @param ht pointer to hash table
 * @param hashes array of hashes
 * @param op1 first operator not neg
 * @param op2 second operator not neg
 * @param cache pointer to singleton mpz_t cache
 * @param extra_info id of extra info of found element, stays null if none exists
 * @return id if found, 0 if not existent
 */
uint64_t exists_element_binary(Hashtable_binary* ht, uint64_t* hashes, mpz_t op1, mpz_t op2, mpz_t_cache* cache, uint64_t* extra_info){
    //check if counter at hash position >= 1 if not, return
    cachedIntElement_binary* statefulPointer[NUMBER_HF];
    unsigned int min=0;
    unsigned int i;
    for(i=0; i < NUMBER_HF; ++i){
        if(ht->counter[(hashes[i] % ht->size)] < 1){
            return SHIFT;
        }
        if(ht->counter[(hashes[i] % ht->size)] 
                < ht->counter[(hashes[min] % ht->size)]){
            min = i;
        }
        int index = (hashes[i] % ht->size);
        cachedIntList_binary* curr_list = &(ht->lists[index]);
        statefulPointer[i] = curr_list->head;
        
    }
    //exists one element in all lists
    
    //1. find list of minimal size (previous loop)
    //2. find elements of minimal list in other lists
    
    //sequential search, later binary search
    unsigned int index = (hashes[min] % ht->size);
    cachedIntList_binary* curr_list = &(ht->lists[index]);
    cachedIntElement_binary* curr_min = curr_list->head;
    while(curr_min){
        uint64_t curr_id = curr_min->result;
        int globalfound = 0;
        int i;
        for(i=0;i<NUMBER_HF; ++i){
            //check all lists except for minimal sized one
            if(i!=min){
                cachedIntElement_binary* curr_list = statefulPointer[i];
                int listfound = 0;
                //search for id of element in minimal list
                while(curr_list){
                    if(curr_list->result == curr_id){
                        listfound = 1;
                        globalfound = 1;
                        statefulPointer[i] = curr_list;
                        //printf("result: %"PRIu64" op1: %"PRIu64" op2: %"PRIu64" hash: %"PRIu64"\n", curr_list->result, curr_list->op1, curr_list->op2, curr_list->hash);
                        break;
                    }
                    curr_list = curr_list->next;
                }
                //if the element was not found in the list, go to next element in minimal list
                if(listfound == 0){
                    globalfound = 0;
                    break;
                }
            }
        }
        //after searching all lists, check if found
        if(globalfound == 1){
            mpz_t cached_val;
            mpz_init(cached_val);
            if((curr_min->op1 & SHIFT) > 0){
                get_cached_mpz(cache, (curr_min->op1 & ~SHIFT), cached_val);
            }
            else{
                unsigned long l[4];
                if(sizeof(long) < 8){
                    //TODO
                    l[0] = curr_min->op1;
                }
                else{
                    l[0] = curr_min->op1;
                }
                mpz_import(cached_val, 1, 1, sizeof(int64_t), 0, 0, l);
            }
            int cmp1 = mpz_cmpabs(cached_val, op1);
            mpz_init(cached_val);
            if((curr_min->op2 & SHIFT) > 0){
                get_cached_mpz(cache, (curr_min->op2 & ~SHIFT), cached_val);
            }
            else{
                unsigned long l[4];
                if(sizeof(long) < 8){
                    //TODO
                    l[0] = curr_min->op2;
                }
                else{
                    l[0] = curr_min->op2;
                }
                mpz_import(cached_val, 1, 1, sizeof(int64_t), 0, 0, l);
            }
            int cmp2 = mpz_cmpabs(cached_val, op2);
            if(cmp1 == 0 && cmp2 == 0){
                if(extra_info != NULL){
                    *extra_info = (curr_min->extra_info);
                }
                return curr_id;
            }
        }
        if(curr_min->next != NULL){
            curr_min = curr_min->next;
        }
        else{
            break;
        }
    }
    return SHIFT;
}