#include "gmpcachingxx.h"

namespace gmpcaching{
MasterCache* globalcache;
#ifdef GMPCACHING_CACHESIZE
int globalcache_size = GMPCACHING_CACHESIZE;
#endif
}
