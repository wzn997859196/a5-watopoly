#include "c2.h"
#include "building.h"
#include <string>

C2::C2(){
  this->SetMaxBlockNum(3);
  this->setName("C2");
  this->setPurchaseCost(320);
  this->setImprovCost(200);
  this->setFaculty("Sci2");
  this->getTuitionFee()[0] = 28;
  this->getTuitionFee()[1] = 150;
  this->getTuitionFee()[2] = 450;
  this->getTuitionFee()[3] = 1000;
  this->getTuitionFee()[4] = 1200;
  this->getTuitionFee()[5] = 1400;
}

C2::~C2(){}

