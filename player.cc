#include "player.h"
#include "Game.h"
#include "textdisplay.h"
#include "property.h"
#include "building.h"
#include <string>
#include <vector>

using namespace std;


Player::Player (Game *game, const string name, const char character, int NumOfCup, int money, int position, bool TimLine, int TimDice): game(game), TimLine(TimLine), name(name), character(character), money(money), position(position), NumOfCup(NumOfCup),  TimDice(TimDice){
	BankRupt = false;
	NumOfProperty = 0;
	properties = new int[28];
}

Player::~Player(){
	delete properties;
}

string Player::GetName(){
	return name;
}	

char Player::GetCharacter(){
	return character;
}

int Player::GetPosition(){
	return position;
}

int Player::GetNumOfCup(){
	return NumOfCup;
}

bool Player::GetTimLine(){
	return TimLine;
}

int Player::GetTimDice(){
	return TimDice;
}

int Player::ShowMoney(){
	return money;
}

void Player::SetPosition(int pos){
	position = pos;
}

void Player::SetBankrupt(){
	BankRupt = true;
}

void Player::SetTimLine(bool b){
	TimLine = b;
}

void Player::SetTimDine(int t){
	TimDice = t;
}

void Player::SetNumOfCup(int n){
	NumOfCup = n;
}

void Player::LoseMoney(int amount){
	while (amount > money){
		cout << "You have no money. You must declare bankrupt or sell something." << endl;
		cout << "If you choose to mortgage all your building and improvements, you can get " << totalMAsset()<< "." << endl;
		cout << "enter y for sell, n for bankrupt." << endl;
		std::string inp;
		cin >> inp;
		if(inp == "n"){
			cout << "Please enter bankrupt." << endl;
		}
		else{
			game->NoMoneymortgage(this);
			cin >> inp;
			if (inp == "pay"){continue;}
			else if (inp == "y"){
				cout << "Please enter bankrupt." << endl;
			}
		}
		string in2;
		cin >> in2;
		if (in2 == "bankrupt"){
			this->SetBankrupt();
			cout << this->GetName() << " declared bankrupt." << endl;
			game->LosePlayer();
			break;
		}
	}
	money -= amount;
}

void Player::GetMoney(int amount){
	money += amount;
}

void Player::AddProperty(int PosOfProperty){
	properties[NumOfProperty] = PosOfProperty;
	++NumOfProperty;
}

void Player::LoseProperty(int PosOfProperty){
	int posi = PostionOfProperty(PosOfProperty);
	for (int i = posi; i < NumOfProperty; ++i){
		properties[i] = properties[i+1];
	}
	--NumOfProperty;
}

bool Player::IsBankrupt(){
	return BankRupt;
}

void Player::Asset(){
	cout << "Player: " << name << "(" << character << ")" << " has: " << endl;
	cout << "Cash: " << money << endl;
	for (int i = 0; i < NumOfProperty; ++i){
		cout << "owns: " << endl;
		game->Getproperty(properties[i])->displayinformation();
	}
}

void Player::move(int step){
	position += step;
	if (position > 39){
		position -= 40;
		money += 200;
	}
	game->Getproperty(position)->arrive(this);
}

bool Player::SamePerson(Player *player1, Player *player2){
	return player1->GetName() == player2->GetName();
}

bool Player::Monopoly(Building *check){
	return check->GetMaxBlockNum() == NumOfStateOwn(check->GetFaculty());
}

int Player::totalAsset(){
	int totalasset = money;
	for (int i = 0; i < NumOfProperty; ++i){
		int buildingPrice = game->Getproperty(properties[i])->getPurchaseCost() + game->Getproperty(properties[i])->getImprovCost() * game->Getproperty(properties[i])->getImproved();
		totalasset += buildingPrice;
	}
	return totalasset;
}

int Player::NumOfStateOwn(string state){
	int count = 0;
	for (int i=0; i<NumOfProperty; ++i){
		Building *prop = game->Getproperty(properties[i]);
		if (prop->GetFaculty() == state){
			++count;
		}
	}
	return count;
}

int Player::PostionOfProperty(int property){
	int pos;
	for(int i = 0; i < NumOfProperty; ++i){
		if (properties[i] == property){
			pos = i;
		}
	}
	return pos;
}

void Player::playerMove(int pos){
	game->getDisplay()->notifyMove(character, position, pos);
	position = pos;
	game->setDice();
}

int Player::totalMAsset(){
	int totalasset = 0;
		for (int i = 0; i < NumOfProperty; ++i){
			int buildingPrice = game->Getproperty(properties[i])->getPurchaseCost() + game->Getproperty(properties[i])->getImprovCost() * game->Getproperty(properties[i])->getImproved();
			totalasset += buildingPrice;
		}
		return totalasset*0.5;
	}

Game *Player::getGame(){
	return game;
}
