 /**
  * @file gmpcachingxx.h
  * @author Sandra Hicks
  * @brief header for Master Cache functions
  */


#ifndef GMPCACHINGXX_H
#define GMPCACHINGXX_H

#include "mastercache.h"
#include "cachedRational.h"
namespace gmpcaching{
    
    /**
     * global MasterCache pointer
     */
    extern MasterCache* globalcache;
    /**
     * global size of the global MasterCache
     */
    extern uint64_t globalcache_size;
    
    
    /**
     * class for global MasterCache interface
     */
    class GMPCaching{
    public:
        static void init_MasterCache(){
            cache_init(&globalcache, globalcache_size);
            printf("Initialized global cache of size %" PRIu64 "... \n", globalcache_size);
        }
        /**
         * Initialization method for global MasterCache
         * @param size
         */
        static void init_MasterCache(uint64_t size){
            cache_init(&globalcache, size);
            printf("Initialized cache of size %" PRIu64 "... \n", size);
        }
        static void setGlobalCacheSize(uint64_t size){
            globalcache_size=size;
        }
        /**
         * deletion of global MasterCache
         */
        static void delete_MasterCache(){
            cache_clear(globalcache);
            printf("Deleted global cache...\n");
        }
        
    };
}


#endif /* GMPCACHINGXX_H */

