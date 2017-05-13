#ifndef _GOOSENESTING_H_
#define _GOOSENESTING_H_
#include "nonproperty.h"
#include <string>

class gooseNesting: public nonProperty{
 public:
  gooseNesting();
  void arrive(Player *arriver) override;
};

#endif

