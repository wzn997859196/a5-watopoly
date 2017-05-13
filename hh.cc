#include "hh.h"
#include <string>

Hh::Hh(){
  this->SetMaxBlockNum(3);
  this->setName("HH");
  this->setPurchaseCost(120);
  this->setImprovCost(50);
  this->setFaculty("Arts2");
  this->getTuitionFee()[0] = 8;
  this->getTuitionFee()[1] = 40;
  this->getTuitionFee()[2] = 100;
  this->getTuitionFee()[3] = 300;
  this->getTuitionFee()[4] = 450;
  this->getTuitionFee()[5] = 600;
}

Hh::~Hh(){}

