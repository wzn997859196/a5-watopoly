#include "rch.h"
#include <string>

Rch::Rch(){
	this->SetMaxBlockNum(3);
  this->setName("RCH");
  this->setPurchaseCost(140);
  this->setImprovCost(100);
  this->setFaculty("Eng");
  this->getTuitionFee()[0] = 10;
  this->getTuitionFee()[1] = 50;
  this->getTuitionFee()[2] = 150;
  this->getTuitionFee()[3] = 450;
  this->getTuitionFee()[4] = 625;
  this->getTuitionFee()[5] = 750;
}

Rch::~Rch(){}


