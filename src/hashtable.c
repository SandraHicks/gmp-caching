 /**
  * @file hashtable.c
  * @author Sandra Hicks
  * @brief hash table implementation
  */
#include "hashtable.h"
#include "defines.h"
#include "hashing.h"
#include "mpz_caching.h"
#include <stdint.h>
#include <stdlib.h>

//Debug
#include <stdio.h>
#include <inttypes.h>

void init_hashtable(Hashtable* ht, uint64_t size){
    ht->size = size;
    
    cachedIntList* l = malloc(sizeof(cachedIntList)*(size));
    ht->lists = l;
    
    ht->counter = malloc(sizeof(int)*size);
    //init counter array with 0
    int i = size;
    while(i--){
        ht->counter[i] = 0;
    }
}

void delete_hashtable(Hashtable* ht){
    int i = 0;
    for(i=0; i<ht->size; ++i){
        cachedIntList* curr_list = &(ht->lists[i]);
        cachedIntElement* curr = curr_list->head;
        while(curr != curr_list->tail){
            cachedIntElement* next = curr->next;
            free(curr);
            curr = next;
        }
        free(curr_list->tail);
    }
    free(ht->counter);
    free(ht->lists);
    ht->counter = NULL;
    ht->lists = NULL;
}

void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes){
    //get all hashes mod size
    int64_t* h;
    int number_hf = NUMBER_HF;
    h = malloc(sizeof(int64_t)*number_hf);
    
    uint64_t uh_temp1 = hashes[0];
    int64_t h_temp1 = (int64_t)uh_temp1;
    h[0] = h_temp1;
    
    
    int i;
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
            cachedIntElement* this = malloc(sizeof(cachedIntElement));
            this->id = id;
            this->hash = hashes[i];
            //insert in sorted List, sort by id. can attach to last pointer because ids are fortlaufend
            cachedIntList* list = &(ht->lists[h[i]]);
            int curr_count = ht->counter[h[i]];
            if(curr_count == 0){
                list->head = this;
                list->tail = this;
            }
            else{
                cachedIntElement* last = list->tail;
                last->next = this;
                list->tail = this;
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
    free(h);
    h = NULL;
}

uint64_t exists_element(Hashtable* ht, uint64_t* hashes, mpz_t element, mpz_t_cache* cache){
    //check if counter at hash position >= 1 if not, return
    cachedIntElement* statefulPointer[NUMBER_HF];
    int min=0;
    int i;
    for(i=0; i < NUMBER_HF; ++i){
        if(ht->counter[(hashes[i] % ht->size)] < 1){
            return 0;
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
    int index = (hashes[min] % ht->size);
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
            get_cached_mpz(cache, curr_id, cached_val);
            int cmp = mpz_cmpabs(cached_val, element);
            if(cmp == 0)
                return 1;
        }
        
        curr_min = curr_min->next;
    }
    return 0;
}

void get_k_hashes(mpz_t val, uint64_t* hashes){
    int number = (NUMBER_HF);
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
            hashes[3] = get_Jenkins_hash(val);
            break;
        case 5: 
            hashes[0] = get_FNV1a_hash(val);
            hashes[1] = get_Murmur_hash(val);
            hashes[2] = get_CRC_hash(val);
            hashes[3] = get_Jenkins_hash(val);
            hashes[4] = get_Sip_hash(val);
            break;
        default:
            //ERROR
            break;
    }
}

void get_k_hashes_cpf(mpz_t val1, mpz_t val2, uint64_t* hashes){
    uint64_t* hashes1;
    hashes1 = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val1, hashes1);
    
    uint64_t* hashes2;
    hashes2 = malloc(sizeof(uint64_t)*NUMBER_HF);
    get_k_hashes(val2, hashes2);
    
    int i;
    for(i=0;i<NUMBER_HF;++i){
        hashes[i] = Cantor_pairing_function_int64(hashes1[i], hashes2[i]);
    }
    free(hashes1);
    hashes1 = NULL;
    free(hashes2);
    hashes2 = NULL;
}



void init_hashtable_binary(Hashtable_binary* ht, uint64_t size){
    ht->size = size;
    
    cachedIntList_binary* l = malloc(sizeof(cachedIntList_binary)*(size));
    ht->lists = l;
    
    ht->counter = malloc(sizeof(int)*size);
    //init counter array with 0
    int i = size;
    while(i--){
        ht->counter[i] = 0;
    }
}

void delete_hashtable_binary(Hashtable_binary* ht){
    int i = 0;
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

void insert_element_binary(Hashtable_binary* ht, uint64_t id_op1, uint64_t id_op2, uint64_t id_res, uint64_t* hashes){
    //get all hashes mod size
    int64_t* h;
    int number_hf = NUMBER_HF;
    h = malloc(sizeof(int64_t)*number_hf);
    
    uint64_t uh_temp1 = hashes[0];
    int64_t h_temp1 = (int64_t)uh_temp1;
    h[0] = h_temp1;
    
    int i;
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
                list->tail = this;
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
    free(h);
    h=NULL;
}

uint64_t exists_element_binary(Hashtable_binary* ht, uint64_t* hashes, mpz_t op1, mpz_t op2, mpz_t_cache* cache){
    //check if counter at hash position >= 1 if not, return
    cachedIntElement_binary* statefulPointer[NUMBER_HF];
    int min=0;
    int i;
    for(i=0; i < NUMBER_HF; ++i){
        if(ht->counter[(hashes[i] % ht->size)] < 1){
            return 0;
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
    int index = (hashes[min] % ht->size);
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
            get_cached_mpz(cache, curr_min->op1, cached_val);
            int cmp1 = mpz_cmpabs(cached_val, op1);
            get_cached_mpz(cache, curr_min->op2, cached_val);
            int cmp2 = mpz_cmpabs(cached_val, op2);
            if(cmp1 == 0 && cmp2 == 0)
                return 1;
        }
        
        curr_min = curr_min->next;
    }
    return 0;
}