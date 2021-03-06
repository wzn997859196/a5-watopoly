#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "building.h"
#include "textdisplay.h"
#include "Game.h"
#include "player.h"
#include "collectosap.h"
#include "al.h"
#include "slc.h"
#include "ml.h"
#include "tuition.h"
#include "mkv.h"
#include "ech.h"
#include "pas.h"
#include "needleshall.h"
#include "phys.h"
#include "b1.h"
#include "hh.h"
#include "dctimsline.h"
#include "rch.h"
#include "pac.h"
#include "dwe.h"
#include "cph.h"
#include "uwp.h"
#include "lhi.h"
#include "bmh.h"
#include "opt.h"
#include "goosenesting.h"
#include "ev1.h"
#include "ev2.h"
#include "ev3.h"
#include "v1.h"
#include "cif.h"
#include "b2.h"
#include "gototims.h"
#include "eit.h"
#include "esc.h"
#include "c2.h"
#include "rev.h"
#include "mc.h"
#include "dc.h"
#include "coopfee.h"

using namespace std;

Game::Game(){
	testing = false;
	Board[0] = new collectOsap();
	Board[1] = new Al();
	Board[2] = new slc();
	Board[3] = new Ml();
	Board[4] = new tuition();
	Board[5] = new Mkv();
	Board[6] = new Ech();
	Board[7] = new needlesHall();
	Board[8] = new Pas();
	Board[9] = new Hh();
	Board[10] = new dcTimsLine();
	Board[11] = new Rch();
	Board[12] = new Pac();
	Board[13] = new Dwe();
	Board[14] = new Cph();
	Board[15] = new Uwp();
	Board[16] = new Lhi();
	Board[17] = new slc();
	Board[18] = new Bmh();
	Board[19] = new Opt();
	Board[20] = new gooseNesting();
	Board[21] = new Ev1();
	Board[22] = new needlesHall();
	Board[23] = new Ev2();
	Board[24] = new Ev3();
	Board[25] = new V1();
	Board[26] = new Phys();
	Board[27] = new B1();
	Board[28] = new Cif();
	Board[29] = new B2();
	Board[30] = new goToTims();
	Board[31] = new Eit();
	Board[32] = new Esc();
	Board[33] = new slc();
	Board[34] = new C2();
	Board[35] = new Rev();
	Board[36] = new needlesHall();
	Board[37] = new Mc();
	Board[38] = new coopFee();
	Board[39] = new Dc();
	dice1 = 0;
	dice2 = 0;
	PlayerNumber = 0;
	TotalPlayer = 0;
	Display = new textDisplay();
	for(int i = 0; i < 8; i++){
		players[i] = NULL;
	}
	DoubleCount=0;
	OriPlayerNum=0;
	ifdiced = false;
};

Game::~Game(){

}

void Game::LoadFilePlay(std::string file){
	string line;
	ifstream lf;
	lf.open(file);
	if (lf.fail()){
		cout << "there is no such file!" << endl;
		return;
	}
	getline(lf,line);
	cout << line << endl;
	istringstream(line) >> OriPlayerNum;
	int j = 0;
	for(int i = 0; i < OriPlayerNum; i++){
		getline(lf,line);
		cout << line << endl;
		string player;
		char chara;
		int cups, money, pos;
		bool IfDc = false;
		int IfInDc = 0,TimeInDc = 0;
		istringstream(line) >> player >> chara >> cups >> money >> pos >> IfInDc >> TimeInDc;
		/*
		if (pos == 10) {
			istringstream(line) >> IfInDc >> TimeInDc;
		}
		*/
		if(IfInDc == 0){
			IfDc = false;
		}
		else if (IfInDc == 1){
			IfDc = true;
		}
		TotalPlayer = j;
		players[j] = new Player(this,player,chara,cups,money,pos,IfDc,TimeInDc);
		j++;
		Display->notifyJoin(chara);
		Display->notifyMove(chara,0,pos);
	}
	while(getline(lf,line)){
		cout << line << endl;
		string building,owner;
		int improvements;
		istringstream(line) >> building >> owner >> improvements;
		int ind = GetProInd(building);
		int playind;
		for (int i = 0; i < OriPlayerNum; i++){
			if (players[i]->GetName() == owner){
				players[i]->AddProperty(ind);
				playind = i;
			}
		}
		Board[ind]->setOwner(players[playind]);
		Board[ind]->setImproved(improvements);
		/*
		if(improvements < 0){
			Display->notifyImprov(ind,false);
		}
		*/
		if(improvements > 0){
			for (int j = 0; j < improvements; j++){
				Display->notifyImprov(ind,true);
			}
		}
	}
	Display->print();
	int i = 0;
	int z = 0;
	while (i < OriPlayerNum){
		if (!players[i]->IsBankrupt()){
			z++;
			PlayerNumber = i;
			if (players[i]->GetTimLine()){
				Board[10]->arrive(players[i]);
				cout << "Please enter another command.";
				continu();
			}
			else{
				string name = players[i]->GetName();
				cout << name << ":" << endl;
				continu();
			}
		}
		++i;
		if (z == TotalPlayer){
			i = 0;
			z = 0;
		}
	}
}

void Game::NewGamePlay(){
	cout << "How many players?" << endl;
	int NumPlay;
	cin >> NumPlay;
	while(NumPlay < 1 || NumPlay > 8) {
		cout << "re-enter the number" << endl;
		cin >> NumPlay;
	}
	OriPlayerNum = NumPlay;
	bool goose =false;
	bool grt =false;
	bool thd =false;
	bool pro =false;
	bool stu =false;
	bool money =false;
	bool laptop =false;
	bool pink =false;
	for (int i = 0; i < OriPlayerNum; i++){
		string playername,playerchar;
		cout << "please enter your name" << endl;
		cin >> playername;
		cout << "please enter your character" << endl;
		cout << "those are the character you can choose:" << endl;
		if (goose == false){
			cout << "==[Goose]:G for Goose==" << endl;
		}
		if (grt == false){
			cout << "==[GRT]:B for GRT Bus==" << endl;
		}
		if (thd == false){
			cout << "==[Tim]:D for Tim Hortons=="<< endl;
		}
		if (pro == false){
			cout << "==[Professor]:P for Professor=="<< endl;
		}
		if (stu == false){
			cout << "==[Student]:S for Student=="<< endl;
		}
		if (money == false){
			cout << "==[Money]:$ for Money=="<< endl;
		}
		if (laptop == false){
			cout << "==[Laptop]:L for Laptop=="<< endl;
		}
		if (pink == false){
			cout << "==[Pink tie]:T for Pink tie=="<< endl;
		}
		cin >> playerchar;
		while (!charNotValid(playerchar, goose, grt, thd, pro, stu, money, laptop, pink)){
			cout <<"Please enter a valid character!" << endl;
			cin >> playerchar;
		}
		if (playerchar == "Goose") {
			goose = true;
		}
		if (playerchar == "GRT") {
			grt = true;
		}
		if (playerchar == "Tim"){
			thd = true;
		}
		if (playerchar == "Professor"){
			pro = true;
		}
		if (playerchar == "Student"){
			stu = true;
		}
		if (playerchar == "Money"){
			money = true;
		}
		if (playerchar == "Laptop"){
			laptop = true;
		}
		if (playerchar == "Pink"){
			pink = true;
		}
		char a = GetChar(playerchar);
		int j = TotalPlayer;
		players[j] = new Player(this,playername,a,0,1500,0,false,0);
		TotalPlayer++;
		Display->notifyJoin(a);
	}

	cout << "Done Registing" << endl;
	Display->print();
	cout << endl << "GAME START" << endl;

	int i = 0;
	int z = 0;
	while (i < OriPlayerNum){
		if (!players[i]->IsBankrupt()){
			z++;
			if (players[i]->GetTimLine()){
				Board[10]->arrive(players[i]);
				PlayerNumber = i;
				continu();
			}
			else{
				PlayerNumber = i;
				string name = players[i]->GetName();
				cout << name << ":" << endl;
				continu();
			}
		}
		++i;
		if(z == TotalPlayer){
			i = 0;
			z = 0;
		}
	}
}

void Game::continu(){
	string command ="";
	while (command != "save"|| TotalPlayer !=1){
		cout << "the available commands are:" << endl;
		cout << "====[roll]===[next]===[trade]==="
				"[improve]===[mortgage]===[unmortgage]"
				"===[assets]===[all]==="
				"[save]====" << endl;
		cout << "if you have not rolled yet, please roll dice first"<<endl;
		cin >> command;
		if(command == "roll"){
			if (ifdiced) {
				cout << "you have already rolled" <<endl;
				cout << "please enter other command" << endl;
			}
			else{
				if (testing){
					cin >> dice1 >> dice2;
					ifdiced = true;
				}
				else{
					Roll();
					cout << "you rolled " << dice1 << " and " << dice2 << endl;
					ifdiced = true;
				}
				bool doubles = CheckDoubles();
				if (doubles){
					DoubleCount++;
					if (DoubleCount != 3){
						ifdiced = false;
						cout << "you rolled double dice" << endl;
						cout << "please roll again" << endl;
					}
					else if (DoubleCount == 3){
						cout << "you have to go to DC Tims Line" << endl;
						players[PlayerNumber]->SetTimLine(true);
						players[PlayerNumber]->playerMove(10);
						DoubleCount = 0;
						cout << "Please enter another command" << endl;
					}
				}
				else{
					int pos = players[PlayerNumber]->GetPosition();
					players[PlayerNumber]->move(dice1+dice2);
					Display->notifyMove(players[PlayerNumber]->GetCharacter(),pos,players[PlayerNumber]->GetPosition());
					Display->print();
					cout << "Please enter other command:" << endl;
					DoubleCount = 0;
				}
			}
		}


		else if(command == "next"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			else{
				ifdiced = false;
				break;
			}
		}


		else if(command == "trade"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			string name,pro1,pro2,ifagree, check;
			int money;
			cin >> name;
			int ind = GetPlayInd(name);
			cin >> check;
			if (istringstream ( check ) >> money){
				cin >> pro1;
				cout << players[PlayerNumber]->GetName();
				cout << " want to exchange " << money << " with ";
				cout << name << "'s " <<pro1 << endl;
				cout << "does " <<name << " accept?" << endl;
				cout << "if yes type 'yes', if no type 'no'" << endl;
				cin >> ifagree;
				if (ifagree == "yes"){
					trade1(ind,money,pro1);
					cout << "trade succeeds. Please enter another command." << endl;
				}
				else{
					cout << "trade denied. Please enter another command." << endl;
				}
			}
			else{
				pro1 = check;
				cin >> check;
				if (istringstream ( check ) >> money){
					cout << players[PlayerNumber]->GetName();
					cout << " want to exchange " << pro1 << " with ";
					cout << name << "'s " << money << endl;
					cout << "does " <<name << " accept?" << endl;
					cout << "if yes type 'yes', if no type 'no'" << endl;
					cin >> ifagree;
					if (ifagree == "yes"){
						trade3(ind,pro1,money);
						cout << "trade succeeds. Please enter another command." << endl;
					}
					else{
						cout << "trade denied. Please enter another command." << endl;
					}
				}
				else{
					pro2 = check;
					cout << players[PlayerNumber]->GetName();
					cout << " want to exchange " << pro1 << " with ";
					cout << name << "'s " << pro2 << endl;
					cout << "does " <<name << " accept?" << endl;
					cout << "if yes type 'yes', if no type 'no'" << endl;
					cin >> ifagree;
					if (ifagree == "yes"){
						trade2(ind,pro1,pro2);
						cout << "trade succeeds. Please enter another command." << endl;
					}
					else{
						cout << "trade denied. Please enter another command." << endl;
					}
				}
			}
		}


		else if(command == "improve"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			cout << "enter the property you want to improve" << endl;
			cout << "enter 'buy' or 'sell' for purpose" << endl;
			string pro,pur;
			cin >> pro >> pur;
			improve(pro,pur);
		}


		else if(command == "mortgage" || command == "unmortgage"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			string pro;
			bool bol = (command == "mortgage");
			cout << "enter the property you want to mortgage/unmortgage" << endl;
			cin >> pro;
			int proind = GetProInd(pro);
			while (Board[proind]->getOwner()!=players[PlayerNumber]->GetCharacter()){
				cout << "you are not the owner of the building." << endl;
				cout << "continue with another building? enter the name of it." << endl;
				cout << "stop mortgage/unmortgage? enter n" << endl;
				cin >> pro;
				if (pro == "n"){
					break;
				}
			}
			if (pro != "n"){
				int proind = GetProInd(pro);
				Board[proind]->mortgage(bol);
			}
			cout << "Please enter another command." << endl;
		}
		else if(command == "assets"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			players[PlayerNumber]->Asset();
			cout << "Please enter another command!" << endl;
		}
		else if(command == "all"){
			if (!ifdiced){
				cout << "you have to roll dices first" << endl;
				continue;
			}
			AllAssets();
			cout << "Please enter another command!" << endl;
		}
		else if(command == "save"){
			Save();
		}
		else{
			cout << "please enter the command again " << endl;
		}
	}
	if (TotalPlayer == 1){
		string name;
		for (int i = 0; i < OriPlayerNum; i++){
			if (!players[i]->IsBankrupt()){
				name = players[i]->GetName();
			}
		}
		cout << "Game ends" << endl;
		cout << "the winner is " << name << endl;
		exit(0);
	}
}

void Game::SetNumplay(int n){
	OriPlayerNum = n;
}

bool Game::CheckDoubles(){
	if (dice1 == dice2){
		return true;
	}
	else{
		return false;
	}
}

void Game::Roll(){
	srand((unsigned) time(0));
	int dic1 = std::rand() % 6 + 1;
	int dic2 = std::rand() % 6 + 1;
	dice1 = dic1;
	dice2 = dic2;
}


void Game::trade1(int ind, int money, string property){
	players[PlayerNumber]->LoseMoney(money);
	int proind = GetProInd(property);
	players[PlayerNumber]->AddProperty(proind);
	players[ind]->GetMoney(money);
	players[ind]->LoseProperty(proind);
	Board[proind]->setOwner(players[PlayerNumber]);
}

void Game::trade2(int ind, string pro1, string pro2){
	int pro1ind = GetProInd(pro1);
	int pro2ind = GetProInd(pro2);
	players[PlayerNumber]->LoseProperty(pro1ind);
	players[PlayerNumber]->AddProperty(pro2ind);
	players[ind]->AddProperty(pro1ind);
	players[ind]->LoseProperty(pro2ind);
	Board[pro1ind]->setOwner(players[ind]);
	Board[pro2ind]->setOwner(players[PlayerNumber]);
}

void Game::trade3(int ind, string pro, int money){
	int proind = GetProInd(pro);
	players[PlayerNumber]->LoseProperty(proind);
	players[PlayerNumber]->GetMoney(money);
	players[ind]->LoseMoney(money);
	players[ind]->AddProperty(proind);
	Board[proind]->setOwner(players[ind]);
}

void Game::improve(string pro, string pur){
	int ind = GetProInd(pro);
	int imp = Board[ind]->getImproved();
	if (pur == "buy"){
		if (players[PlayerNumber]->Monopoly(Board[ind])){
			players[PlayerNumber]->LoseMoney(Board[ind]->getImprovCost());
			while(!players[PlayerNumber]->IsBankrupt()){
				Board[ind]->setImproved(imp+1);
				Display->notifyImprov(ind,true);
				Display->print();
				cout << "Improve Success! Please enter another command:" << endl;
			}
		}
		else{
			Display->notifyImprov(ind,false);
			cout << "you didn't buy all the properties in the monopoly "
					<< "you cannot buy improvement of this building" << endl;
			cout << "Improve failed! Please enter another command:" << endl;
		}
	}
	else if (pur == "sell"){
		players[PlayerNumber]->GetMoney(Board[ind]->getImprovCost()*0.5);
		Board[ind]->setImproved(imp-1);
		Display->notifyImprov(ind,false);
		Display->print();
		cout << "Improve Success! Please enter another command:" << endl;
	}
}


void Game::AllAssets(){
	for (int i = 0; i < OriPlayerNum; i++){
		if (!players[i]->IsBankrupt()){
			players[i]->Asset();
		}
		else {
			cout << players[i]->GetName() << " is bankrupted" << endl;
		}
	}
}


void Game::Save(){
	cout << "enter the filename you want to save as:"<< endl;
	string file;
	cin >> file;
	ofstream output;
	output.open(file);
	output << TotalPlayer << endl;
	//testing
	cout << TotalPlayer << endl;

	for(int i = 0; i < OriPlayerNum; i++){
		if (!players[i]->IsBankrupt()){
			string name;
			char chara;
			bool intim;
			int timcups,money,pos,ifintim,numintim;
			name = players[i]->GetName();
			chara = players[i]->GetCharacter();
			timcups = players[i]->GetNumOfCup();
			money = players[i]->ShowMoney();
			pos = players[i]->GetPosition();
			intim = players[i]->GetTimLine();
			numintim = players[i]->GetTimDice();
			cout << name << chara << timcups << money << pos << intim << numintim << endl;
			if (intim){
				ifintim = 1;
			}
			else if (!intim){
				ifintim = 0;
			}
			if (pos == 10){
				if (ifintim == 1){
					output << name << " "
							<< chara << " "
							<< timcups << " "
							<< money << " "
							<< pos << " "
							<< ifintim << " "
							<< numintim << " " <<endl;
				}
				else if (ifintim == 0){
					output << name << " "
							<< chara << " "
							<< timcups << " "
							<< money << " "
							<< pos << " "
							<< ifintim << " " << endl;
				}
			}
			else{
				output << name << " "
						<< chara << " "
						<< timcups << " "
						<< money << " "
						<< pos << " " << endl;
			}
		}
	}
	for(int j = 0; j < 40; j++){
		if (ifacbuild(j)){
			string name,owner;
			int improv;
			name = Board[j]->getName();
			owner = Board[j]->getowner()->GetName();
			improv = Board[j]->getImproved();
			output << name << " " << owner << " " << improv << endl;
			//testing
			cout << name << " " << owner << " " << improv << endl;
		}
	}
	output.close();
	cout << "Done saving" <<endl;
	exit(0);
}


char Game::GetChar(string chara){
	char a = 'a';
	if (chara == "Goose"){
		a = 'G';
	}
	else if (chara == "GRT"){
		a = 'B';
	}
	else if (chara == "Tim"){
		a = 'D';
	}
	else if (chara == "Professor"){
		a = 'P';
	}
	else if (chara == "Student"){
		a = 'S';
	}
	else if (chara == "Money"){
		a = '$';
	}
	else if (chara == "Laptop"){
		a = 'L';
	}
	else if (chara == "Pink"){
		a = 'T';
	}
	return a;
}

int Game::GetPlayInd(string name){
	int a;
	for (int i = 0; i < OriPlayerNum; i++){
		if (players[i]->GetName() == name){
			a = i;
		}
	}
	return a;
}

int Game::GetProInd(string name){
	int a;
	for(int i = 0; i < 40; i++){
		if (Board[i]->getName() == name){
			a = i;
		}
	}
	return a;
}

Player* Game::Getplayer(int i){
	return players[i];
}

Building* Game::Getproperty(int i){
	return Board[i];
}


void Game::AddPlayer(Player* tem){
	int i = TotalPlayer;
	players[i] = tem;
	TotalPlayer++;
}

bool Game::charNotValid(std::string playerchar, bool goose, bool grt, bool thd, bool pro, bool stu, bool money, bool laptop, bool pink){
		bool result = false;
		if (playerchar == "Goose") {
			result = !goose;
		}
		if (playerchar == "GRT") {
			result = !grt;
		}
		if (playerchar == "Tim"){
			result = !thd;
		}
		if (playerchar == "Professor"){
			result = !pro;
		}
		if (playerchar == "Student"){
			result = !stu;
		}
		if (playerchar == "Money"){
			result = !money;
		}
		if (playerchar == "Laptop"){
			result = !laptop;
		}
		if (playerchar == "Pink"){
			result = !pink;
		}
		return result;
}


void Game::errorMessage(){
	cout << "Wrong command!" << endl;
	cout << "Please check and enter a right one." << endl;
}

textDisplay *Game::getDisplay(){
	return Display;
}

void Game::NoMoneymortgage(Player *P){
			cout << "Please enter mortgage, improve or trade for getting more money."<< endl;
			string command;
			cin >> command;
			if(command == "mortgage" || command == "unmortgage"){
				string pro;
				bool bol = (command == "mortgage");
				cout << "enter the property you want to mortgage/unmortgage" << endl;
				cin >> pro;
				int proind = GetProInd(pro);
				while (Board[proind]->getOwner()!=P->GetCharacter()){
					cout << "you are not the owner of the building." << endl;
					cout << "continue with another building? enter the name of it." << endl;
					cout << "stop mortgage/unmortgage? enter n" << endl;
					cin >> pro;
					if (pro == "n"){
						break;
					}
				}
				if (pro != "n"){
					int proind = GetProInd(pro);
					Board[proind]->mortgage(bol);
				}
			}
			else if (command == "improve"){
				std::string pro;
				cin >> pro;
				int ind = GetProInd(pro);
				std::string sell;
				cin >> sell;
				int imp = Board[ind]->getImproved();
				P->GetMoney(Board[ind]->getImprovCost()*0.5);
				Board[ind]->setImproved(imp-1);
				Display->notifyImprov(ind,false);
				Display->print();
			}
			else if(command == "trade"){
						string name,pro1,pro2,ifagree, check;
						int money;
						cin >> name;
						int ind = GetPlayInd(name);
						cin >> check;
						if (istringstream ( check ) >> money){
							cin >> pro1;
							cout << P->GetName();
							cout << " want to exchange " << money << " with ";
							cout << name << "'s " <<pro1 << endl;
							cout << "does " <<name << " accept?" << endl;
							cout << "if yes type 'yes', if no type 'no'" << endl;
							cin >> ifagree;
							if (ifagree == "yes"){
								trade1(ind,money,pro1);
								cout << "trade succeeds." << endl;
							}
							else{
								cout << "trade denied." << endl;
							}
						}
						else{
							pro1 = check;
							cin >> check;
							if (istringstream ( check ) >> money){
								cout << P->GetName();
								cout << " want to exchange " << pro1 << " with ";
								cout << name << "'s " << money << endl;
								cout << "does " <<name << " accept?" << endl;
								cout << "if yes type 'yes', if no type 'no'" << endl;
								cin >> ifagree;
								if (ifagree == "yes"){
									trade3(ind,pro1,money);
									cout << "trade succeeds." << endl;
								}
								else{
									cout << "trade denied." << endl;
								}
							}
							else{
								pro2 = check;
								cout << P->GetName();
								cout << " want to exchange " << pro1 << " with ";
								cout << name << "'s " << pro2 << endl;
								cout << "does " <<name << " accept?" << endl;
								cout << "if yes type 'yes', if no type 'no'" << endl;
								cin >> ifagree;
								if (ifagree == "yes"){
									trade2(ind,pro1,pro2);
									cout << "trade succeeds." << endl;
								}
								else{
									cout << "trade denied." << endl;
								}
							}
						}
					}
			cout << "Please enter pay for paying or y for bankrupt." << endl;
		}

bool Game::ifacbuild(int i){
	bool a;
	if (i != 0 && i != 10 && i != 30 && i != 20 && i != 4 && i != 38 && i != 17 && i != 7 && i != 2 && i != 33 && i != 22 && i != 36){
		a = true;
	}
	else{
		a = false;
	}
	return a;
}

void Game::SetTesting(bool iftest){
	testing = iftest;
}

int Game::GetTotalPlayer(){
	return TotalPlayer;
}
void Game::LosePlayer(){
	--TotalPlayer;
}

void Game::setDice(){
	ifdiced = true;
}
