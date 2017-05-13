#include "al.h"
#include "building.h"
#include <string>

Al::Al(){
  this->SetMaxBlockNum(2);
  this->setName("AL");
  this->setPurchaseCost(40);
  this->setImprovCost(50);
  this->setFaculty("Arts1");
  this->getTuitionFee()[0] = 2;
  this->getTuitionFee()[1] = 10;
  this->getTuitionFee()[2] = 30;
  this->getTuitionFee()[3] = 90;
  this->getTuitionFee()[4] = 160;
  this->getTuitionFee()[5] = 250;
}

Al::~Al(){}
