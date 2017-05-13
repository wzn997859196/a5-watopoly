#include "residence.h"
#include <string>
#include <iostream>

Residence::Residence(){
  this->setFaculty("residence");
}

Residence::~Residence(){}

int Residence::charges(){
	int OwnedNum = this->getowner()->NumOfStateOwn(this->getFaculty());
	int rescharge = 25;
	for (int i = 1; i < OwnedNum; ++i){
		rescharge *= 2;
	}
	return rescharge;
}
