#include "phys.h"
#include <string>

Phys::Phys(){
  this->SetMaxBlockNum(3);
  this->setName("PHYS");
  this->setPurchaseCost(260);
  this->setImprovCost(150);
  this->setFaculty("Sci1");
  this->getTuitionFee()[0] = 22;
  this->getTuitionFee()[1] = 110;
  this->getTuitionFee()[2] = 330;
  this->getTuitionFee()[3] = 800;
  this->getTuitionFee()[4] = 975;
  this->getTuitionFee()[5] = 1150;
}

Phys::~Phys(){}


