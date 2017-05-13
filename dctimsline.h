#ifndef _DCTIMSLINE_H_
#define _DCTIMSLINE_H_
#include "nonproperty.h"
#include <string>

class dcTimsLine: public nonProperty{
 public:
  dcTimsLine();
  void arrive(Player *arriver) override;
};

#endif

