 /**
  * @file gmpcachingxx.h
  * @author Sandra Hicks
  * @brief header for Master Cache functions
  */


#ifndef GMPCACHINGXX_H
#define GMPCACHINGXX_H

#include "mastercache.h"
namespace gmpcaching{
    
    extern MasterCache* globalcache = NULL;
    
    class GMPCaching{
    public:
        //MasterCache methods
        static void init_MasterCache(uint64_t size){
            cache_init(&globalcache, size);
        }
    
        static void delete_MasterCache(){
            cache_clear(globalcache);
        }
    };
}


#endif /* GMPCACHINGXX_H */

