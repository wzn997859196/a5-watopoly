#include "b1.h"
#include "building.h"
#include <string>

B1::B1(){
	this->SetMaxBlockNum(3);
  this->setName("B1");
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

B1::~B1(){}

