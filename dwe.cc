#include "dwe.h"
#include <string>

Dwe::Dwe(){
  this->SetMaxBlockNum(3);
  this->setName("DWE");
  this->setPurchaseCost(140);
  this->setImprovCost(100);
  this->setFaculty("Eng");
  this->getTuitionFee()[0] = 10;
  this->getTuitionFee()[1] = 50;
  this->getTuitionFee()[2] = 150;
  this->getTuitionFee()[3] = 450;
  this->getTuitionFee()[4] = 625;
  this->getTuitionFee()[5] = 750;
}

Dwe::~Dwe(){}


