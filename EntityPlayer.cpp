#include "EntityPlayer.h"
#include "EntityRoom.h"
#include "EntityExit.h"



void player::Init(){

	name = NULL;
	desc = NULL;

	nature = PLAYER;

	content = new dyn_array<entity>(PLAYER_INIT_INVSIZE);

}

player::~player(){


	delete content;

}

void player::move(exit* direction){

	if (direction != NULL){

		currentroom = direction->dst;
	}

}

void player::extract(string player_input, string subject_str){

	player_input.split(); // Discard preposition//
	string old_container_str(player_input.split());
	int old_container_class = old_container_str.readsubject();

	if (old_container_class != -1){
		if (old_container_class == PLAYER_ITEM){
			getitem(searchitem(old_container_str), subject_str);
		}
		else if (old_container_class == ROOM_ITEM){
			getitem(currentroom->searchitem(old_container_str), subject_str);
		}
	}
	else{
		printf("I just understood you as far as you want to extract %s from something", subject_str);
	}
}

void player::insert(string player_input, int subject, string subject_str){

	player_input.split(); // Discard preposition//
	string new_container_str(player_input.split());
	int new_container_class = new_container_str.readsubject();
	entity* new_container;


	if (new_container_class != -1){
		if (subject == PLAYER_ITEM){
			if (new_container_class == PLAYER_ITEM){
				new_container = searchitem(new_container_str);
				new_container->getitem(this, new_container_str);
			}
			else if ((new_container_class == ROOM_ITEM)){
				new_container = currentroom->searchitem(new_container_str);
				new_container->getitem(this, new_container_str);
			}

		}
		else if (subject == ROOM_ITEM){
			if (new_container_class == PLAYER_ITEM){
				new_container = searchitem(new_container_str);
				new_container->getitem((entity*)currentroom, new_container_str);
			}
			else if ((new_container_class == ROOM_ITEM)){
				new_container = currentroom->searchitem(new_container_str);
				new_container->getitem((entity*)currentroom, new_container_str);
			}
		}
	}
	else{
		printf("I just understood you as far as you want to insert %s into something", subject_str);
	}

}
