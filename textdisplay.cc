#include "textdisplay.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

textDisplay::textDisplay(){
  squares[0] = " ";
  squares[1] = "AL";
  squares[2] = " ";
  squares[3] = "ML";
  squares[4] = " ";
  squares[5] = " ";
  squares[6] = "ECH";
  squares[7] = " ";
  squares[8] = "PAS";
  squares[9] = "HH";
  squares[10] = " ";
  squares[11] = "RCH";
  squares[12] = " ";
  squares[13] = "DWE";
  squares[14] = "CPH";
  squares[15] = " ";
  squares[16] = "LHI";
  squares[17] = " ";
  squares[18] = "BMH";
  squares[19] = "OPT";
  squares[20] = " ";
  squares[21] = "EV1";
  squares[22] = " ";
  squares[23] = "EV2";
  squares[24] = "EV3";
  squares[25] = " ";
  squares[26] = "PHYS";
  squares[27] = "B1";
  squares[28] = " ";
  squares[29] = "B2";
  squares[30] = " ";
  squares[31] = "EIT";
  squares[32] = "ESC";
  squares[33] = " ";
  squares[34] = "C2";
  squares[35] = " ";
  squares[36] = " ";
  squares[37] = "MC";
  squares[38] = " ";
  squares[39] = "DC";
  for (int i = 0; i < 40; i++){
    for(int j = 0; j < 8; j++){
      playerPos[i][j] = ' ';
    }
  }
  for (int i = 0; i < 40; i++){
    improv[i] = 0;
  }
}

textDisplay::~textDisplay(){}

void textDisplay::notifyJoin(char newplayer){
  if(newplayer == 'G') { playerPos[0][0] = newplayer; }
  else if (newplayer == 'B') { playerPos[0][1] = newplayer; }
  else if (newplayer == 'D') { playerPos[0][2] = newplayer; }
  else if (newplayer == 'P') { playerPos[0][3] = newplayer; }
  else if (newplayer == 'S') { playerPos[0][4] = newplayer; }
  else if (newplayer == '$') { playerPos[0][5] = newplayer; }
  else if (newplayer == 'L') { playerPos[0][6] = newplayer; }
  else if (newplayer == 'T') { playerPos[0][7] = newplayer; }
}

void textDisplay::notifyMove(char player, const int curPos, const int newPos){
  int player_ind;
  if(player == 'G') { player_ind = 0; }
  else if (player == 'B') { player_ind = 1; }
  else if (player == 'D') { player_ind = 2; }
  else if (player == 'P') { player_ind = 3; }
  else if (player == 'S') { player_ind = 4; }
  else if (player == '$') { player_ind = 5; }
  else if (player == 'L') { player_ind = 6; }
  else if (player == 'T') { player_ind = 7; }
  playerPos[curPos][player_ind] = ' ';
  playerPos[newPos][player_ind] = player;
}

void textDisplay::notifyImprov(int pos, bool action){ // ture is buy. false is sell
  if(action) ++improv[pos];
  else --improv[pos];
}

void textDisplay::print() const{
//first line
  cout.fill('_');
  cout.width(100);
  cout << "";
  cout << endl;
  for(int i = 20; i < 31; i++){
    cout << "|";
    cout.fill(' ');
    cout.width(8);
    if(i == 20) { cout << left << "GOOSE"; }
    else if(i == 22) { cout << left << "NEEDLES"; }
    else if(i == 25) { cout << left << "V1"; }
    else if(i == 28) { cout << left << "CIF"; }
    else if(i == 30) { cout << left << "GO TO"; }
    else {
      string improvments = "";
      for(int j = 0; j < improv[i]; j++){
        improvments.append("I");
      }
      cout.fill(' ');
      cout.width(8);
      cout << left << improvments;
      }
  }
  cout << "|" << endl;
  for(int i = 20; i < 31; i++){
    cout << "|";
    cout.fill(' ');
    cout.width(8);
    if (i == 20) { cout << left << "NESTING"; }
    else if(i == 22) { cout << left << "HALL"; }
    else if(i == 25) { cout << left << ""; }
    else if(i == 28) { cout << left << ""; }
    else if(i == 30) { cout << left << "TIMS"; }
    else { cout << "--------"; }
  }
  cout << "|" << endl;
  for(int i = 20; i < 31; i++){
    cout << "|";
    cout.fill(' ');
    cout.width(8);
    cout << left << squares[i];
  }
  cout << "|" << endl;
// player position in first line
  for(int i = 20; i < 31; i++){
    cout << "|";
    //cout.fill(' ');//add
    //cout.width(7);//add
    for(int j = 0; j < 8; j++){
      cout << playerPos[i][j];
    }
  }
  cout << "|" << endl;
  for(int i = 20; i < 31; i++){
    cout << "|________";
  }
  cout << "|" << endl;
//second part
  int leftside,rightside;
  for(int line = 1; line < 10; line++){
    leftside = 20 - line;
    rightside = 30 + line;
    for(int i = 0; i < 11; i++){
      if(i == 0){
        if(squares[leftside] == " "){
          if(leftside == 17){
            cout << left << "|SLC     ";
          } else if(leftside == 15){
            cout << left << "|UWP     ";
          } else if(leftside == 12){
            cout << left << "|SLC     ";
          }
        } else{
          cout << "|";
          string improvments = "";
          for(int j = 0; j < improv[leftside]; i++){
            improvments.append("I");
          }
          cout.fill(' ');
          cout.width(8);
          cout << left << improvments;
        }
      } else if(i == 1) {
        cout << "|        ";
      } else if(i == 9) {
        cout << "         |";
      } else if(i == 10) {
        if(squares[rightside] == " "){
          if(rightside == 33) {
            cout << left << "SLC     ";
          } else if(rightside == 35){
            cout << left << "REV     ";
          } else if(rightside == 36){
            cout << left << "NEEDLES ";
          } else if(rightside == 38){
            cout << left << "COOP    ";
          }
          cout << "|";
      } else{
        string improvments = "";
        for(int j = 0; j < improv[rightside]; j++){
          improvments.append("I");
        }
        cout.fill(' ');
        cout.width(8);
        cout << left << improvments;
        cout << "|";
      }
    } else{
      cout << "         ";
    }
  }
    cout << endl;
    for(int i = 0; i < 11; i++){
      if(i == 0){
        if((leftside == 17) || (leftside == 15) || (leftside == 12)){
          cout << "|";
          cout.fill(' ');
          cout.width(8);
          cout << "";
        } else{
          cout << "|";
          cout.fill('-');
          cout.width(8);
          cout << "";
        }
      } else if(i == 1){
        cout << "|        ";
      } else if(i == 9){
        cout << "         |";
      } else if(i == 10){
        if(squares[rightside] == " "){
          if(rightside == 36){
            cout.fill(' ');
            cout.width(8);
            cout << left << "HALL";
            cout << "|";
          } else if(rightside == 38){
            cout.fill(' ');
            cout.width(8);
            cout << left << "FEE";
            cout << "|";
          } else{
            cout.fill(' ');
            cout.width(9);
            cout << right << "|";
          }
        } else{
          cout.fill('-');
          cout.width(9);
          cout << right << "|";
        }
      } else{
        cout << "         ";
      }
    }
    cout << endl;
    for(int i = 0; i < 11; i++){
      if(i == 0){
        cout << "|";
        cout.fill(' ');
        cout.width(8);
        cout << left << squares[leftside];
      } else if(i == 1){
        cout << "|        ";
      } else if(i == 9){
        cout << "         |";
      } else if(i == 10){
        cout.fill(' ');
        cout.width(8);
        cout << left << squares[rightside];
        cout << "|";
      } else {
        cout << "         ";
      }
    }
    cout << endl;
    for(int i = 0; i < 11; i++){
      if(i == 0){
        cout << "|";
	//cout.fill(' ');//add
	//cout.width(7);//add
        for(int j = 0; j < 8; j++){
          cout << playerPos[leftside][j];
        }
        //cout << " ";
      } else if(i == 1){
        cout << "|        ";
      } else if(i == 9){
        cout << "         |";
      } else if(i == 10){
        //cout << " ";
	//cout.fill(' ');//add
	//cout.width(7);//add
        for(int j = 0; j < 8; j++){ 
          cout << playerPos[rightside][j];
        }
        cout << "|";
      } else{
        cout << "         ";
      }
    }
    cout << endl; 
    for(int i = 0; i < 11; i++){
      if(i == 0){
        cout << "|________";
      } else if(i == 1){
        if (line == 9){
          cout << "|________";
        } else {
          cout << "|        ";
        }
      } else if(i == 9){
        if (line == 9){
          cout << "_________|";
        } else {
          cout << "         |";
        }
      } else if(i == 10){
        cout.fill('_');
        cout.width(8);
        cout << "";
        cout << "|";
      } else{
        if (line == 9){
          cout << "_________";
        } else {
          cout << "         ";
        }
      }
    }
    cout << endl;
  }
//last line
  for (int i = 10; i > -1; i--){
    cout << "|";
    cout.fill(' ');
    cout.width(8);
    if(i == 10){ cout << left << "DC TIMS"; }
    else if(i == 7) { cout << left << "NEEDLES"; }
    else if(i == 5) { cout << left << "MKV"; }
    else if(i == 4) { cout << left << "TUITION"; }
    else if(i == 2) { cout << left << "SLC"; }
    else if(i == 0) { cout << left << "COLLECT"; }
    else {
      string improvments = "";
      for(int j = 0; j < improv[i]; j++){
        improvments.append("I");
      }
      cout.fill(' ');
      cout.width(8);
      cout << left << improvments;
    }
  }
  cout << "|" << endl;
  for(int i = 10; i > -1; i--){
  cout << "|";
  cout.fill(' ');
  cout.width(8);
  if (i == 10) { cout << left << "LINE"; }
  else if(i == 7) { cout << left << "HALL"; }
  else if(i == 5) { cout << left << ""; }
  else if(i == 4) { cout << left << ""; }
  else if(i == 2) { cout << left << ""; }
  else if(i == 0) { cout << left << "OSAP"; }
  else { cout << "--------"; }
  }
  cout << "|" << endl;
  for(int i = 10; i > -1; i--){
    cout << "|";
    cout.fill(' ');
    cout.width(8);
    cout << left << squares[i];
  }
  cout << "|" << endl;
// player position in last line
  for(int i = 10; i > -1; i--){
    cout << "|";
    //cout.fill(' ');//add
    //cout.width(7);//add
    for(int j = 0; j < 8; j++){
      cout << playerPos[i][j];
    }
  }
  cout << "|" << endl;
  for(int i = 10; i > -1; i--){
    cout << "|________";
  }
  cout << "|" << endl;
}
