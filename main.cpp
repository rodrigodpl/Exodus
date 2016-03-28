
#include "world.h"
#include "globals.h"
#include "string.h"

int main(void){

	world* worldp = new world;
	char* command = new char[VERB_AND_NOUN_BUFFER_LEN * 2];

	worldp->playerp->currentroom->look();


	do {

		worldp->playerp->currentroom->look();

		fgets(command, VERB_AND_NOUN_BUFFER_LEN * 2, stdin);
		stringmanager.readcommand(command);


	} while (worldp->executecommand(stringmanager.verbbuffer, stringmanager.nounbuffer));


	delete[] worldp;
	delete[] command;

	return(0);

}