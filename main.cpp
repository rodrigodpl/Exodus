#include "World.h"
#include "Entity.h"
#include <cstdio>

int main(void){

	world main_world;
	main_world.Init();

	char buffer[200];
	fgets(buffer, 200, stdin);
	string player_input(buffer);

	main_world.look(CURRENT_ROOM, player_input); //player input should a void string//

	while (main_world.executecommand(player_input)){

		char buffer[200];
		fgets(buffer, 200, stdin);
		string player_input(buffer);
	} 

	return(0);

}