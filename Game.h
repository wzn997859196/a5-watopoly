#ifndef GAME_H_
#define GAME_H_
class Building;
class Player;
class textDisplay;

class Game{
private:
	Building* Board[40];
	Player* players[8];
	textDisplay* Display;
	int PlayerNumber;
	int dice1;
	int dice2;
	int TotalPlayer;
	int OriPlayerNum;
	bool ifdiced;
	int DoubleCount;
	bool testing;
public:
	Game();
	~ Game();
	void LoadFilePlay(std::string file);
	void NewGamePlay();
	void continu();
	void SetNumplay(int n);
	bool CheckDoubles();
	void Roll();
	void trade1(int ind,int money,std::string property);
	void trade2(int ind,std::string pro1, std::string pro2);
	void trade3(int ind,std::string pro, int money);
	void improve(std::string pro, std::string pur);
	bool Finish();
	char GetChar(std::string chara);
	void AllAssets();
	void Save();
	int GetPlayInd(std::string name);
	int GetProInd(std::string name);
	Player* Getplayer(int i);
	Building* Getproperty(int i);
	void AddPlayer(Player* tem);
	bool charNotValid(std::string playerchar, bool goose, bool grt, bool thd, bool pro, bool stu, bool money, bool laptop, bool pink);
	void errorMessage();
	textDisplay *getDisplay();
	void NoMoneymortgage(Player *P);
	bool ifacbuild(int i);
	void SetTesting(bool iftest);
	int GetTotalPlayer();
	void LosePlayer();
	void setDice();
};




#endif /* GAME_H_ */
