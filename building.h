#ifndef _BUILDING_H_
#define _BUILDING_H_
#include <string>
#include <iostream>
#include "player.h"

class Building{
  std::string name;
  Player *owner;
  std::string faculty;

  bool isMorgaged;
  
  int *tuitionFee;
 public:
  Building();
  virtual ~Building();
  void setName(std::string Name);
  bool HaveOwner();
  std::string getName();
  char getOwner();
  Player *getowner();
  void setOwner(Player *newOwner);
  std::string getFaculty();
  void setFaculty(std::string Faculty);
  bool getIsMortgaged();
  void setMortgaged(bool morgage);
  virtual int getPurchaseCost();
  virtual void setPurchaseCost(int cost);
  virtual int getImprovCost();
  int *getTuitionFee();
  virtual int getImproved();
  virtual void setImproved(int newImproved);
  virtual void arrive(Player *arriver);
  virtual void displayinformation();
  virtual int GetMaxBlockNum();
  virtual std::string GetFaculty();
  virtual void setImprovCost(int Improvecost);
  virtual void SetMaxBlockNum(int BlockNum);
  void errorCommend();
  virtual void mortgage(bool Is);
};

#endif 
