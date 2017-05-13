#include "tuition.h"
#include <string>

tuition::tuition(){
  this->setName("TUITION");
}

void tuition::arrive(Player *arriver){
	cout << "Please choose to pay 300 or 10 percent of your total asset." << endl << "enter: 300 or 10" << endl;
	std::string input;
	while(cin >> input){
		if (input == "300"){
			cout << "You choose to pay 300." << endl;
			arriver->LoseMoney(300);
			return;
		}
		else if (input == "10"){
			cout << "You choose to pay 10 percents of your total asset." << endl;
			int asset = arriver->totalAsset();
			cout << asset*0.1 << " is paid" << endl;
			arriver->LoseMoney(asset * 0.1);
			return;
		}
		else{
			this->errorCommend();
			cout << "Please choose to pay 300 or 10 percent of your total asset." << endl << "enter: 300 or 10" << endl;
		}
   }
}
