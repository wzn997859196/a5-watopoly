#include "pas.h"
#include <string>

Pas::Pas(){
  this->SetMaxBlockNum(3);
  this->setName("PAS");
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

Pas::~Pas(){}

