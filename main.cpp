#include "World.h"
#include "Entity.h"
#include <cstdio>

int main(void){

	world main_world;

	main_world.Init();

	while (true){

		main_world.recurrent_look();
		char gameplay_buffer[200];
		fgets(gameplay_buffer, 200, stdin);
		string player_input(gameplay_buffer);

		if (main_world.executecommand(player_input) == QUIT_GAME){
			break;
		}
	} 
	return(1);

}