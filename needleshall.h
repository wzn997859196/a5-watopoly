#ifndef _NEEDLESHALL_H_
#define _NEEDLESHALL_H_
#include "nonproperty.h"
#include <string>

class needlesHall: public nonProperty{
 public:
  needlesHall();
  void arrive(Player *arriver)override;
};

#endif
