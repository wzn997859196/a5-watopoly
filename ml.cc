#include "ml.h"
#include <string>

Ml::Ml(){
  this->SetMaxBlockNum(2);
  this->setName("ML");
  this->setPurchaseCost(60);
  this->setImprovCost(50);
  this->setFaculty("Arts1");
  this->getTuitionFee()[0] = 4;
  this->getTuitionFee()[1] = 20;
  this->getTuitionFee()[2] = 60;
  this->getTuitionFee()[3] = 180;
  this->getTuitionFee()[4] = 320;
  this->getTuitionFee()[5] = 450;
}

Ml::~Ml(){}

