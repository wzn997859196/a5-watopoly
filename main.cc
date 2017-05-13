#include "textdisplay.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, const char * argv[]){
	Game * g = new Game();
	if (argc == 1){
		g->NewGamePlay();
	}
	else if (argc == 2){
		if (strcmp(argv[1],"-testing")){
			cout << "Usage1: ./program_name : to start a new game" << endl;
			cout << "Usage2: ./program_name -testing : to test a new game"<< endl;
			cout << "Usage3: ./program_name -load file : to play a load file" <<endl;
			cout << "Usage4: ./program_name -load file -testing : to test the loaded file" << endl;
		}
		else {
			g->SetTesting(true);
			g->NewGamePlay();
		}
	}
	else if (argc == 3){
		if (strcmp(argv[1],"-load")){
			cout << "Usage1: ./program_name : to start a new game" << endl;
			cout << "Usage2: ./program_name -testing : to test a new game" << endl;
			cout << "Usage3: ./program_name -load file : to play a load file" <<endl;
			cout << "Usage4: ./program_name -load file -testing : to test the loaded file" << endl;
		}
		else {
			string a = argv[2];
			g->LoadFilePlay(a);
		}
	}
	else if (argc == 4){
		if (strcmp(argv[1],"-load")){
			cout << "Usage1: ./program_name : to start a new game" << endl;
			cout << "Usage2: ./program_name -testing : to test a new game" << endl;
			cout << "Usage3: ./program_name -load file : to play a load file" <<endl;
			cout << "Usage4: ./program_name -load file -testing : to test the loaded file" << endl;
		}
		else {
			string a = argv[2];
			g->SetTesting(true);
			g->LoadFilePlay(a);
		}
	}
}
