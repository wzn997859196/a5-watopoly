#ifndef AUCTION_H_
#define AUCTION_H_
#include <string>
class Auction{
	int InitialSize;
	int Size;
	std::string *Player;
	int turn;
	int price;
	int inTurn;
 public:
	Auction();
	~Auction();
	std::string Winner();
	int Price();
	void doAuction();
	void quitAuction();
	void setSize(int size);
	void inName(std::string name);
};



#endif /* AUCTION_H_ */
