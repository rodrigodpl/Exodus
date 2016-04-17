#include "World.h"
#include "Entity.h"
#include "TurnCounter.h"
#include <cstdio>



int main(void){

	world main_world;
	turn_counter main_counter;

	main_world.Init();
	main_counter.Init();

	while (true){

		main_world.recurrent_look();
		char gameplay_buffer[MAX_BUFFER_LEN];
		fgets(gameplay_buffer, MAX_BUFFER_LEN, stdin);
		string player_input(gameplay_buffer);

		if (main_world.executecommand(player_input) == QUIT_GAME){
			break;
		}

		main_counter.turn++;
		main_counter.checkevents(main_world);
		printf("\nCurrent turn: %d", main_counter.turn);
	} 
	return(1);

}