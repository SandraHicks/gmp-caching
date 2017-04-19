 /**
  * @file hashtable.c
  * @author Sandra Hicks
  * @brief hash table implementation
  */
#include "hashtable.h"
#include "defines.h"
#include "hashing.h"
#include <stdint.h>
#include <stdlib.h>

void create_hashtable(Hashtable* ht, int size){
    ht->size = size;
    cachedIntList l[size];
    ht->lists = l;
    int c[size];
    ht->counter = c;
    
    //init counter array with 0?
}

void insert_element(Hashtable* ht, uint64_t id, uint64_t* hashes){
    //get all hashes mod size
    int i;
    int64_t h[NUMBER_HF];
    for(i=0; i<NUMBER_HF; ++i){
        h[i] = hashes[i];
        h[i] = h[i] % ht->size;
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
            cachedIntElement* curr = list->head;
            if(ht->counter[h[i]] == 0){
                list->head = this;
                list->tail = this;
            }
            else{
                list->tail->prev->next = this;
                list->tail = this;
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
}

bool exists_element(Hashtable* ht, uint64_t* hashes){
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
        if(globalfound == 1)
            return 1;
        
        
        curr_min = curr_min->next;
    }
    return 0;
}

uint64_t* get_k_hashes(mpz_t val, uint64_t* hashes){
    int number = (NUMBER_HF);
    switch(number){
        case 1: ;
            uint64_t h_temp1[1];
            h_temp1[0] = get_FNV1a_hash(val);
            hashes = h_temp1;
            return hashes;
            break;
        case 2: ;
            uint64_t h_temp2[2];
            h_temp2[0] = get_FNV1a_hash(val);
            h_temp2[1] = get_Murmur_hash(val);
            hashes = h_temp2;
            return hashes;
            break;
        case 3: ;
            uint64_t h_temp3[3];
            h_temp3[0] = get_FNV1a_hash(val);
            h_temp3[1] = get_Murmur_hash(val);
            h_temp3[2] = get_CRC_hash(val);
            hashes = h_temp3;
            return hashes;
            break;
        case 4: ;
            uint64_t h_temp4[4];
            h_temp4[0] = get_FNV1a_hash(val);
            h_temp4[1] = get_Murmur_hash(val);
            h_temp4[2] = get_CRC_hash(val);
            h_temp4[3] = get_Jenkins_hash(val);
            hashes = h_temp4;
            return hashes;
            break;
        case 5: ;
            uint64_t h_temp5[5];
            h_temp5[0] = get_FNV1a_hash(val);
            h_temp5[1] = get_Murmur_hash(val);
            h_temp5[2] = get_CRC_hash(val);
            h_temp5[3] = get_Jenkins_hash(val);
            h_temp5[4] = get_Sip_hash(val);
            hashes = h_temp5;
            return hashes;
            break;
        default:
            //ERROR
            break;
    }
}