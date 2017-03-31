 /**
  * @file hashtable.c
  * @author Sandra Hicks
  * @brief hash table implementation
  */
#include "hashtable.h"
#include "defines.h"

void create_hashtable(Hashtable* ht, int size){
    ht->size = size;
    ht->lists = cachedIntList[size];
    ht->counter = int[size];
    
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
            
            //insert in sorted List, sort by original hash
            cachedIntList* list = ht->lists[h[i]];
            cachedIntElement* curr = list->head;
            if(ht->counter[h[i]] == 0){
                list->head = this;
                list->tail = this;
            }
            else{
                int j;
                for (j=0; j< ht->counter[h[i]]; j++){
                    if(curr->hash >= hashes[i]){
                        //insert before curr
                        curr->prev->next = this;
                        this->prev = curr->prev;
                        curr->prev = this;
                        this->next = curr;
                        break;
                    }
                    curr = curr->next;
                }
            }
            
            ht->counter[h[i]] = ht->counter[h[i]]+1;
        }
    }
}

bool exists_element(Hashtable* ht, uint64_t* hashes){
    //check if counter at hash position >= 1 if not, return
    int min=0;
    int i;
    for(i=0; i < NUMBER_HF; i++){
        if(ht->counter[(hashes[i] % ht->size)] < 1){
            return 0;
        }
        if(ht->counter[(hashes[i] % ht->size)] 
                < ht->counter[(hashes[min] % ht->size)]){
            min = i;
        }
        
    }
    //exists one element in all lists
    
    //1. find list of minimal size (previous loop)
    //2. find elements of minimal list in other lists
    
    cachedIntElement* curr_list = ht->lists[(hashes[0] % ht->size)]->head;
    
    //sequential search, later binary search
    cachedIntElement* curr_min = ht->lists[(hashes[min] % ht->size)]->head;
    for(i=0; i<ht->counter[(hashes[min] % ht->size)]; i++){
        
        
        curr_min = curr_min->next;
    }
    return 0;
}