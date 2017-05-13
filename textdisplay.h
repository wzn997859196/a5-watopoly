#ifndef _TEXTDISPLAY_H_
#define _TEXTDISPLAY_H_
#include <iostream>
#include <string>

class textDisplay{
  std::string squares[40];
  char playerPos[40][8];
  int improv[40];
 public:
  textDisplay();
  ~textDisplay();
  void notifyJoin(char player);
  void notifyMove(char player, int curPos, int newPos);
  void notifyImprov(int pos, bool buy);
  void print() const;
};

#endif
