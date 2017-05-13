#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>
#include <vector>
#include "Game.h"
#include "building.h"
using namespace std;

class Player {
		Game *game;
		bool BankRupt;
		bool TimLine;
		const string name;
		const char character;
		int money;
		int NumOfProperty;
		int *properties;
		int position;
		int NumOfCup;
		int TimDice;
	public:
		Player();
		Player (Game *game, const string name, const char character, int NumOfCup, int money, int position, bool TimLine, int TimDice);
		~Player();
		string GetName();
		char GetCharacter();
		int GetPosition();
		int GetNumOfCup();
		bool GetTimLine();
		int GetTimDice();
		int ShowMoney();
		void SetPosition(int pos);
		void SetBankrupt();
		void SetTimLine(bool b);
		void SetTimDine(int t);
		void SetNumOfCup(int n);
		void LoseMoney(int amount);
		void GetMoney(int amount);
		void AddProperty(int PosOfProperty);
		void LoseProperty(int PosOfProperty);
		bool IsBankrupt();
		void Asset();
		void move(int step);
		bool SamePerson(Player *player1, Player *player2);
		bool Monopoly(Building *check);
		int totalAsset();
		int NumOfStateOwn(string state);
		int PostionOfProperty(int property);
		void playerMove(int pos);
		int totalMAsset();
		Game *getGame();
};
#endif
