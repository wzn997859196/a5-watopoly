#ifndef _GOTOTIMS_H_
#define _GOTOTIMS_H_
#include "nonproperty.h"
#include <string>

class goToTims: public nonProperty{
 public:
  goToTims();
  void arrive(Player *arriver) override;
};

#endif

