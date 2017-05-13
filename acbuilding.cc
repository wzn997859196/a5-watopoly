#include "acbuilding.h"
#include "player.h"
#include "building.h"
#include <string>
#include <iostream>

AcBuilding::AcBuilding(){
  MaxBlockNum = 0;
  improvCost = 0;
  improved = 0;
}

AcBuilding::~AcBuilding(){
}

void AcBuilding::improve(){
	improved += 1;
	this->getowner()->LoseMoney(improvCost);
}

int AcBuilding::GetMaxBlockNum(){
	return MaxBlockNum;
}

void AcBuilding::SetMaxBlockNum(int BlockNum){
	MaxBlockNum = BlockNum;
}
int AcBuilding::charges(){
	int NormalCharge = this->getTuitionFee()[improved];
	if (this->getowner()->Monopoly(this)){
		NormalCharge *=2;
	}
	return NormalCharge;
}
int AcBuilding::getImprovCost(){
  return improvCost;
}
void AcBuilding::setImprovCost(int Improvecost){
	improvCost = Improvecost;
}

void AcBuilding::setImproved(int newImproved){
  improved = newImproved;
}

int AcBuilding::getImproved(){
  return improved;
}


