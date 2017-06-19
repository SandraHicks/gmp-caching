#extern "C" {
#include "mastercache.h"
}
using namespace std;

class Mastercache {
  public:
    Mastercache();
    Mastercache(int cachesize);

    ~Mastercache();

  private:
    MasterCache* mstr;
};
