#include "master_cache.h"

MasterCache::MasterCache(){
  int cachesize = 2000;
  this.mstr = malloc(sizeof(MasterCache));
  cache_init(this.mstr, cachesize);
}

MasterCache::MasterCache(int cachesize){
  this.mstr = malloc(sizeof(MasterCache));
  cache_init(this.mstr, cachesize);
}

MasterCache::~MasterCache(){
  cache_clear();
}

