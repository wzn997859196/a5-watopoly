
#include <string>
#include <iostream>
#include "auction.h"
using namespace std;

Auction::Auction(){
	Size = 0;
	Player = new string[8];
	InitialSize = 0;
	turn = 0;
	price = 0;
	inTurn = 0;
}


Auction::~Auction(){
	delete Player;
}


string Auction::Winner(){
	return Player[0];
}


int Auction::Price(){
	return price;
}
void Auction::doAuction(){
	Size = inTurn;
	while (Size != 1) {
		cout << "now is " << Player[turn] << "'s turn to call price." << endl;
		cout << "the highest price now is " << price <<"." << endl;
		cout << "Do you want to buy this building with a higher price?" << endl;
		cout << "Please enter y for yes, n for no." << endl;
		string input;
		while(cin >> input){
			if (input == "n"){
				quitAuction();
				++turn;
				break;
			}
			else if (input == "y") {
				cout << "Please enter your price." << endl;
				int P;
				cin >> P;
				if (P > price){
					cout << "Good Price." << endl;
					price = P;
					++turn;
				}
				else{
					cout << "Bad Price." << endl;
					quitAuction();
					++turn;
				}
				if (turn >= InitialSize){
					turn = 0;
				}
				break;
			}
			else{
				cout << "Wrong Command!" << "Please enter y for yes, n for no." << endl;
			}
		}
	}
	return;
}
void Auction::quitAuction(){
	for (int i = turn; i < Size-1; ++i){
		Player[turn] = Player[turn+1];
	}
	--Size;
}
void Auction::setSize(int size){
	Size = size;
	InitialSize = size;
}

void Auction::inName(std::string name){
	Player[inTurn] = name;
	++inTurn;
}
