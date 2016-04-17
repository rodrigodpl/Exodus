#ifndef _TURNCOUNER_H_
#define _TURNCOUNTER_H_

#include "Data.h"
#include "World.h"

#define DOOR_TO_CLOSE 0
#define EVENT_NUM 5

class turn_counter{

public:

	uint turn;
	bool has_happened[EVENT_NUM];

public:

	void Init(){
		
		uint i;

		turn = 0;
		for (i = 0; i < EVENT_NUM; i++){
			has_happened[i] = false;
		}
	

		
	}

	void checkevents(world& main_world){

		if (turn > 10 && !has_happened[CLOSE_DOOR]){
			has_happened[CLOSE_DOOR] = true;
			main_world.exitp[DOOR_TO_CLOSE].isopen = false;
			main_world.exitp[DOOR_TO_CLOSE].islocked = true;
			return;
		}
		else if (turn > 30 && !has_happened[EXAMPLE_EVENT]){

			//{...}//

		}
		//{...}//

		
	}


	enum events{

		CLOSE_DOOR,
		EXAMPLE_EVENT,
		//{...}//


	};

};





#endif