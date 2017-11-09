#include "gmpcachingxx.h"

namespace gmpcaching{
MasterCache* globalcache;
#ifdef GMPCACHING_CACHESIZE
uint64_t globalcache_size = GMPCACHING_CACHESIZE;
#endif
}
