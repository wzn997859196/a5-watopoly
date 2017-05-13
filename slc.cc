#include "slc.h"
#include <string>
#include <time.h>
slc::slc(){
  this->setName("SLC");
}

void slc::arrive(Player *arriver){
	cout << "You arrive at SLC" << endl;
	srand((unsigned) time(0));
	int dice1 = std::rand() % 100 + 1;
	if (arriver->GetNumOfCup() < 4){
		if (dice1 == 2){
			arriver->SetNumOfCup(arriver->GetNumOfCup()+1);
		}
	}
	int dice2 = std::rand() % 24 + 1;
	if (dice2 < 4){
		cout << "you need to move 3 steps backward." << endl;
		arriver->move(-3);
	}
	else if (dice2 < 8){
		cout << "you need to move 2 steps backward." << endl;
		arriver->move(-2);
	}
	else if (dice2 < 12){
		cout << "you need to move 1 steps backward." << endl;
		arriver->move(-1);
	}
	else if (dice2 < 15){
		cout << "you need to move 1 steps forward." << endl;
		arriver->move(1);
	}
	else if (dice2 < 19){
		cout << "you need to move 2 steps forward." << endl;
		arriver->move(2);
	}
	else if (dice2 < 23){
		cout << "you need to move 3 steps forward." << endl;
		arriver->move(3);
	}
	else if (dice2 < 24){
		cout << "you are sent to Tims Line." << endl;
		arriver->SetTimLine(true);
		arriver->playerMove(10);
	}
	else if (dice2 < 25){
		cout << "you get 200." << endl;
		arriver->GetMoney(200);
	}
}
