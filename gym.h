#ifndef _GYM_H_
#define _GYM_H_
#include <string>
#include "property.h"
class Gym: public Property{
 public:
  Gym();
  ~Gym();
  int charges() override;
};

#endif

