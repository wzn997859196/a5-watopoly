#include "building.h"
#include "player.h"
#include <string>
using namespace std;

Building::Building(){
  name = "";
  owner = nullptr;
  faculty = "";
  isMorgaged = false;
  tuitionFee = new int[6];
}

Building::~Building() {
	delete tuitionFee;
}

string Building::getName(){
  return name;
}

void Building::setName(std::string Name){
  name = Name;
}

bool Building::HaveOwner(){
	return owner == nullptr;
}
char Building::getOwner(){
  return owner->GetCharacter();
}

Player *Building::getowner(){
  return owner;
}

void Building::setOwner(Player *newOwner){
  owner = newOwner;  
}

string Building::getFaculty(){
  return faculty;
}

void Building::setFaculty(std::string Faculty){
	faculty = Faculty;
}
bool Building::getIsMortgaged(){
  return isMorgaged;
}

void Building::setMortgaged(bool morgaged){
  isMorgaged = morgaged;
}

int *Building::getTuitionFee(){
	return tuitionFee;
}

int Building::getPurchaseCost(){return 0;}
void Building::setPurchaseCost(int cost){}
int Building::getImprovCost(){return 0;}
int Building::getImproved(){return 0;}
void Building::setImproved(int newImproved){}
void Building::arrive(Player *arriver){}
void Building::displayinformation(){}
int Building::GetMaxBlockNum(){return 0;}
std::string Building::GetFaculty(){return faculty;}
void Building::setImprovCost(int Improvecost){}
void Building::SetMaxBlockNum(int BlockNum){}
void Building::mortgage(bool Is){}

void Building::errorCommend(){
		cout << "Wrong command." << endl;
}
