#include "property.h"
#include "building.h"
#include "auction.h"
#include "player.h"
#include <string>
#include <iostream>
using namespace std;
Property::Property(){
	purchaseCost = 0;
	auction = new Auction();
}
Property::~Property(){
	delete auction;
}
void Property::arrive(Player *arriver){
	std::string build = this->getName();
	if (this->HaveOwner()){
		cout << "you are arriving at " << build << endl;
		cout << "If you want to buy this property, please enter : buy. Otherwise please enter : no." << endl;
		std::string input;
		while(cin >> input){
			if (input == "buy"){
				arriver->LoseMoney(purchaseCost);
				if (!arriver->IsBankrupt()){
					this->setOwner(arriver);
					arriver->AddProperty(arriver->getGame()->GetProInd(this->getName()));
					cout << arriver->GetName() << " Successfully bought " << this->getName() << endl;
					cout <<"Please enter another command." << endl;
				}
				break;
			}
			else if (input == "no"){
				cout << "Now start an auction for " << build << ", because " << arriver->GetCharacter() << " didn't buy it." << endl;
				int toal = arriver->getGame()->GetTotalPlayer();
				auction->setSize(toal-1);
				int size = 0;
				for (int i = 0; i < toal; ++i){
					Player *now = arriver->getGame()->Getplayer(i);
					if (now->IsBankrupt()||now->SamePerson(now,arriver)){}
					else {
						std::string a = now->GetName();
						cout << "Dose " << a << " want to join the auction?" << endl;
						cout << " enter y for join, n for not join." << endl;
						string input;
						while (cin >> input){
							if (input == "y"){
								auction->inName(a);
								++size;
								break;
							}
							else if (input == "n"){
								break;
							}
							else{
								cout << " Wrong Command. enter y for join, n for not join." << endl;
							}
						}
					}
				}
				auction->doAuction();
				string winner = auction->Winner();
				int price = auction->Price();
				cout << winner << " win the auction with price of " << price << endl;
				Player *Winner = arriver->getGame()->Getplayer(arriver->getGame()->GetPlayInd(winner));
				Winner->LoseMoney(price);
				if (!Winner->IsBankrupt()){
					Winner->AddProperty(arriver->getGame()->GetProInd(this->getName()));
					this->setOwner(arriver->getGame()->Getplayer(arriver->getGame()->GetPlayInd(winner)));
					cout << "Please enter another command." << endl;
				}
				break;
			}
			else{
				cout << "Wrong Command!" << endl;
				cout << "If you want to buy this property, please enter : buy. Otherwise please enter : no." << endl;
			}
		}
	}
	else{
		if (!this->getowner()->SamePerson(this->getowner(),arriver)){
			if (!getIsMortgaged()){
				cout << "You arrive at other people's property:" << build << ". Please enter pay to pay." << endl;
				std::string input;
				while (cin >> input){
					if (input == "pay"){
						int charge = this->charges();
						this->getowner()->GetMoney(charge);
						arriver->LoseMoney(charge);
						return;
					}
					else{
						cout << "wrong command, please enter pay." << endl;
					}
				}
			}
		}
		else{
			cout << "you arrive at your property. Nothing happens." << endl;
		}
	}
}


void Property::mortgage(bool Is){
	if (Is){
		if (this->getImproved() == 0){
			this->setMortgaged(true);
			this->getowner()->GetMoney(purchaseCost*0.5);
			this->getowner()->LoseProperty(this->getowner()->getGame()->GetProInd(this->getName()));
			cout << this->getName() << " is mortgaged." << endl;
		}
		else{
			cout << "Please sell all improvements before mortgage." << endl;
		}
	}
	else{
		if (this->getIsMortgaged()){
			this->getowner()->LoseMoney(purchaseCost*0.6);
			if(!this->getowner()->IsBankrupt()){
				this->setMortgaged(false);
				this->getowner()->AddProperty(this->getowner()->getGame()->GetProInd(this->getName()));
				cout << this->getName() << " is unmortgaged." << endl;
			}
		}
		else{
			cout << "this property is not mortgaged. You cannot unmortgage it." << endl;
		}
	}
}
void Property::displayinformation(){
	cout << this->getName() << "(" << this->getImproved() << "improvements" << ")" << endl;
}

int Property::getPurchaseCost(){
  return purchaseCost;
}

void Property::setPurchaseCost(int cost){
	purchaseCost = cost;
}
int Property::charges(){return 0;}

