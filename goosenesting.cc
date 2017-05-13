#include "goosenesting.h"
#include <string>
#include <iostream>
gooseNesting::gooseNesting(){
  this->setName("GOOSE NESTING");
}

void gooseNesting::arrive(Player *arriver){
	cout << "You are attacked by goose." << endl;
}
