#include "lhi.h"
#include <string>

Lhi::Lhi(){
  this->SetMaxBlockNum(3);
  this->setName("LHI");
  this->setPurchaseCost(180);
  this->setImprovCost(100);
  this->setFaculty("Health");
  this->getTuitionFee()[0] = 14;
  this->getTuitionFee()[1] = 70;
  this->getTuitionFee()[2] = 200;
  this->getTuitionFee()[3] = 550;
  this->getTuitionFee()[4] = 750;
  this->getTuitionFee()[5] = 950;
}

Lhi::~Lhi(){}

