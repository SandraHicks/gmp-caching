 /**
  * @file gmpcachingxx.h
  * @author Sandra Hicks
  * @brief header for Master Cache functions
  */


#ifndef GMPCACHINGXX_H
#define GMPCACHINGXX_H

#include "mastercache.h"
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
        }
        
    };
}


#endif /* GMPCACHINGXX_H */

