#ifndef _TUITION_H_
#define _TUITION_H_
#include "nonproperty.h"
#include <string>

class tuition: public nonProperty{
 public:
  tuition();
  void arrive(Player *arriver) override;
};

#endif

