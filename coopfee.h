#ifndef _COOPFEE_H_
#define _COOPFEE_H_
#include "nonproperty.h"
#include <string>

class coopFee: public nonProperty{
 public:
  coopFee();
  void arrive(Player *arriver) override;
};

#endif

