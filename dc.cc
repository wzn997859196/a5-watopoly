#include "dc.h"
#include <string>

Dc::Dc(){
  this->SetMaxBlockNum(2);
  this->setName("DC");
  this->setPurchaseCost(400);
  this->setImprovCost(200);
  this->setFaculty("Math");
  this->getTuitionFee()[0] = 50;
  this->getTuitionFee()[1] = 200;
  this->getTuitionFee()[2] = 600;
  this->getTuitionFee()[3] = 1400;
  this->getTuitionFee()[4] = 1700;
  this->getTuitionFee()[5] = 2000;
}

Dc::~Dc(){}


