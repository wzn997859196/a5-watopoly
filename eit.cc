#include "eit.h"
#include <string>

Eit::Eit(){
  this->SetMaxBlockNum(3);
  this->setName("EIT");
  this->setPurchaseCost(300);
  this->setImprovCost(200);
  this->setFaculty("Sci2");
  this->getTuitionFee()[0] = 26;
  this->getTuitionFee()[1] = 130;
  this->getTuitionFee()[2] = 390;
  this->getTuitionFee()[3] = 900;
  this->getTuitionFee()[4] = 1100;
  this->getTuitionFee()[5] = 1275;
}

Eit::~Eit(){}

