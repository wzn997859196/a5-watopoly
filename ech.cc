#include "ech.h"
#include <string>

Ech::Ech(){
  this->SetMaxBlockNum(3);
  this->setName("ECH");
  this->setPurchaseCost(100);
  this->setImprovCost(50);
  this->setFaculty("Arts2");
  this->getTuitionFee()[0] = 6;
  this->getTuitionFee()[1] = 30;
  this->getTuitionFee()[2] = 90;
  this->getTuitionFee()[3] = 270;
  this->getTuitionFee()[4] = 400;
  this->getTuitionFee()[5] = 550;
}

Ech::~Ech(){}

