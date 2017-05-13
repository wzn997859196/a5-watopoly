#include "opt.h"
#include <string>

Opt::Opt(){
  this->SetMaxBlockNum(3);
  this->setName("OPT");
  this->setPurchaseCost(200);
  this->setImprovCost(100);
  this->setFaculty("Health");
  this->getTuitionFee()[0] = 16;
  this->getTuitionFee()[1] = 80;
  this->getTuitionFee()[2] = 220;
  this->getTuitionFee()[3] = 600;
  this->getTuitionFee()[4] = 800;
  this->getTuitionFee()[5] = 1000;
}

Opt::~Opt(){}


