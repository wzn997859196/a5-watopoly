#include "esc.h"
#include <string>

Esc::Esc(){
  this->SetMaxBlockNum(3);
  this->setName("ESC");
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

Esc::~Esc(){}


