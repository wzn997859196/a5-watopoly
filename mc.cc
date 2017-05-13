#include "mc.h"
#include <string>

Mc::Mc(){
  this->SetMaxBlockNum(2);
  this->setName("MC");
  this->setPurchaseCost(350);
  this->setImprovCost(200);
  this->setFaculty("Math");
  this->getTuitionFee()[0] = 35;
  this->getTuitionFee()[1] = 175;
  this->getTuitionFee()[2] = 500;
  this->getTuitionFee()[3] = 1100;
  this->getTuitionFee()[4] = 1300;
  this->getTuitionFee()[5] = 1500;
}

Mc::~Mc(){}


