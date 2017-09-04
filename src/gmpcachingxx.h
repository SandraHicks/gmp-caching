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
    extern int globalcache_size;
    
    
    /**
     * class for global MasterCache interface
     */
    class GMPCaching{
    public:
        static void init_MasterCache(){
            cache_init(&globalcache, globalcache_size);
            printf("Initialized global cache...\n");
        }
        /**
         * Initialization method for global MasterCache
         * @param size
         */
        static void init_MasterCache(uint64_t size){
            cache_init(&globalcache, size);
        }
        /**
         * deletion of global MasterCache
         */
        static void delete_MasterCache(){
            cache_clear(globalcache);
            printf("Deleted global cache...\n");
            printf("used cachedInts %d, cached %d, additions %d\n", CachedRational::global_cached_int_counter, CachedRational::global_cached, CachedRational::global_additions);
        }
        
    };
}


#endif /* GMPCACHINGXX_H */

