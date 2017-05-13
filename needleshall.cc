#include "needleshall.h"
#include <string>
#include <time.h>
needlesHall::needlesHall(){
  this->setName("NEEDLES HALL");
}

void needlesHall::arrive(Player *arriver){
	cout << "You arrive at Needles Hall." << endl;
	srand((unsigned) time(0));
	int dice1 = std::rand() % 100 + 1;
	if (arriver->GetNumOfCup() < 4){
		if (dice1 == 2){
			arriver->SetNumOfCup(arriver->GetNumOfCup()+1);
		}
	}
	int dice2 = std::rand() % 18 + 1;
	if (dice2 < 2){
		cout << "You lose 200 for some reason." << endl;
		arriver->LoseMoney(200);
	}
	else if (dice2 < 4){
		cout << "You lose 100 for some reason." << endl;
		arriver->LoseMoney(100);
	}
	else if (dice2 < 7){
		cout << "You lose 50 for some reason." << endl;
		arriver->LoseMoney(50);
	}
	else if (dice2 < 13){
		cout << "You gain 25 for some reason." << endl;
		arriver->GetMoney(25);
	}
	else if (dice2 < 16){
		cout << "You gain 50 for some reason." << endl;
		arriver->GetMoney(50);
	}
	else if (dice2 < 18){
		cout << "You gain 100 for some reason." << endl;
		arriver->GetMoney(100);
	}
	else if (dice2 < 19){
		cout << "You gain 200 for some reason." << endl;
		arriver->GetMoney(200);
	}
}
