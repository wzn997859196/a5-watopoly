#include "ev3.h"
#include <string>

Ev3::Ev3(){
  this->SetMaxBlockNum(3);
  this->setName("EV3");
  this->setPurchaseCost(240);
  this->setImprovCost(150);
  this->setFaculty("Env");
  this->getTuitionFee()[0] = 20;
  this->getTuitionFee()[1] = 100;
  this->getTuitionFee()[2] = 300;
  this->getTuitionFee()[3] = 750;
  this->getTuitionFee()[4] = 925;
  this->getTuitionFee()[5] = 1100;
}

Ev3::~Ev3(){}

