#ifndef _SLC_H_
#define _SLC_H_
#include "nonproperty.h"
#include <string>

class slc: public nonProperty{
 public:
  slc();
  void arrive(Player *arriver) override;
};

#endif

