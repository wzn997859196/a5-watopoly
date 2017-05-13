#include "ev1.h"
#include <string>

Ev1::Ev1(){
  this->SetMaxBlockNum(3);
  this->setName("EV1");
  this->setPurchaseCost(220);
  this->setImprovCost(150);
  this->setFaculty("Env");
  this->getTuitionFee()[0] = 18;
  this->getTuitionFee()[1] = 90;
  this->getTuitionFee()[2] = 250;
  this->getTuitionFee()[3] = 700;
  this->getTuitionFee()[4] = 875;
  this->getTuitionFee()[5] = 1050;
}

Ev1::~Ev1(){}

