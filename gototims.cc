#include "gototims.h"
#include <string>

goToTims::goToTims(){
  this->setName("GO TO TIMS");
}

void goToTims::arrive(Player *arriver){
	cout << "Sorry, you are sent to Tims Line." << endl;
	arriver->SetTimLine(true);
	arriver->playerMove(10);
}
