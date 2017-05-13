#include "cph.h"
#include <string>

Cph::Cph(){
  this->SetMaxBlockNum(3);
  this->setName("CPH");
  this->setPurchaseCost(160);
  this->setImprovCost(100);
  this->setFaculty("Eng");
  this->getTuitionFee()[0] = 12;
  this->getTuitionFee()[1] = 60;
  this->getTuitionFee()[2] = 180;
  this->getTuitionFee()[3] = 500;
  this->getTuitionFee()[4] = 700;
  this->getTuitionFee()[5] = 900;
}

Cph::~Cph(){}

