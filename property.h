#ifndef _PROPERTY_H_
#define _PROPERTY_H_
#include <string>
#include"building.h"
class Auction;
class Player;
class Property: public Building{
  int purchaseCost;
  Auction *auction;
 public:
  Property();
  ~Property();
  void arrive(Player *arriver);
  void mortgage(bool Is);
  virtual int charges();
  void displayinformation();
  int getPurchaseCost();
  void setPurchaseCost(int cost);
};


#endif
