#include "coopfee.h"
#include "building.h"
#include <string>

coopFee::coopFee(){
  this->setName("COOP FEE");
}

void coopFee::arrive(Player *arriver){
	cout << "You paid 150 coopfee." << endl;
	arriver->LoseMoney(150);
}
