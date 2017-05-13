#ifndef _RESIDENCE_H_
#define _RESIDENCE_H_
#include <string>
#include "property.h"
class Residence: public Property{
 public:
  Residence();
  ~Residence();
  int charges() override;
};

#endif

