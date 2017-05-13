#include "gym.h"
#include "building.h"
#include <string>
#include <iostream>
#include <time.h>
Gym::Gym(){
  this->setFaculty("gym");
}

Gym::~Gym(){}

int Gym::charges(){
	srand((unsigned) time(0));
	int dice1 = std::rand() % 6 + 1;
	int dice2 = std::rand() % 6 + 1;
	int sum = dice1 + dice2;
	int NumOwned = this->getowner()->NumOfStateOwn(this->getFaculty());
	if (NumOwned == 1){
		return sum * 4;
	}
	else{
		return sum * 10;
	}
}
