#ifndef _ACBUILDING_H_
#define _ACBUILDING_H_
#include <string>
#include "property.h"
class AcBuilding: public Property{
	int improvCost;
	int improved;
	int MaxBlockNum;
 public:
  AcBuilding();
  ~AcBuilding();
  void improve();
  int charges() override;
  int GetMaxBlockNum();
  void SetMaxBlockNum(int BlockNum);
  int getImprovCost();
  void setImprovCost(int Improvecost);
  int getImproved();
  void setImproved(int newImproved);
};

#endif
