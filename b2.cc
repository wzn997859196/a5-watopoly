#include "b2.h"
#include "building.h"
#include <string>

B2::B2(){
  this->SetMaxBlockNum(3);
  this->setName("B2");
  this->setPurchaseCost(280);
  this->setImprovCost(150);
  this->setFaculty("Sci1");
  this->getTuitionFee()[0] = 24;
  this->getTuitionFee()[1] = 120;
  this->getTuitionFee()[2] = 360;
  this->getTuitionFee()[3] = 850;
  this->getTuitionFee()[4] = 1025;
  this->getTuitionFee()[5] = 1200;
}

B2::~B2(){}

