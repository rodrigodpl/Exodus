#include "World.h"


world::~world(){

	delete[] itemp;
	delete[] map;
	delete[] playerp;
	delete[] exitp;

}


void world::Init(){

	itemp = new item[ITEM_NUM];
	map = new room[ROOM_NUM];
	exitp = new exit[EXIT_NUM];
	playerp = new player;


	uint index;

	for (index = 0; index < ITEM_NUM; index++){

		itemp[index].Init(index);

	}

	for (index = 0; index < EXIT_NUM; index++){

		exitp[index].Init(index);


	}

	for (index = 0; index < ROOM_NUM; index++){

		map[index].Init(index);

	}

	playerp->Init();
	playerp->currentroom = &(map[INITIAL_ROOM]);

}


bool world::executecommand(string player_input){

	string action_str(player_input.split());
	string subject_str(player_input.split());

	int action = action_str.readaction();
	int subject = subject_str.readsubject();

	if (action == -1){
		printf("\nI didn't understood what you want to do. Check help if in doubt.");
	}
	else if (subject == -1){
		printf("\nI just understood you as fas as you want to %s", action_str.str);

	}

	else{
		switch (action){
		case MOVE:

			playerp->move(searchexit(playerp->currentroom, subject));
			break;

		case LOOK:

			look(subject, subject_str.str);
			break;

		case PICK:

			if (subject == ROOM_ITEM){
				playerp->getitem(playerp->currentroom, subject_str);
				break;
			}

		case DROP:

			if (subject == PLAYER_ITEM){
				playerp->currentroom->getitem(playerp, subject_str);
				break;
			}

		case INSERT:

			playerp->insert(player_input, subject, subject_str);
			break;

		case EXTRACT:

			playerp->extract(player_input, subject_str);
			break;

		case HELP:

			printf("help. -------");
			break;

		case QUIT:

			return(false);

		}

	}
		return(true);
}


exit* world::searchexit(room* src, int direction){

	uint i;
	for (i = 0; i < EXIT_NUM; i++){
		if (exitp[i].src == src && worldp->exitp[i].dir == direction){

			return(&exitp[i]);
		}
	}

	return(NULL);
}

void world::look(int origin, string name){

	entity* subject = NULL;

	if (origin == NORTH){
		subject = (entity*)searchexit(playerp->currentroom, NORTH);
	}
	else if (origin == EAST){
		subject = (entity*)searchexit(playerp->currentroom, EAST);
	}
	else if (origin == SOUTH){
		subject = (entity*)searchexit(playerp->currentroom, SOUTH);
	}
	else if (origin == WEST){
		subject = (entity*)searchexit(playerp->currentroom, WEST);
	}
	else if (origin == PLAYER_ITEM){
		uint i;
		for (i = 0; i < playerp->content->num_elem; i++){

			if (name.str_cmp_S(playerp->content->buffer[i].name->str)){
				subject = &(playerp->content->buffer[i]);
			}
		}
	}
	else if (origin == ROOM_ITEM){
		uint i;
		for (i = 0; i < playerp->currentroom->content->num_elem; i++){

			if (name.str_cmp_S(playerp->currentroom->content->buffer[i].name->str)){
				subject = &(playerp->currentroom->content->buffer[i]);
			}
		}
	}
	else if (origin == CURRENT_ROOM){
		subject = (entity*)playerp->currentroom;
	}

	if (subject != NULL){

		printf("\n%s, %s", subject->name, subject->desc);
	}
	else{
		printf("\nThere's no such thing!");
	}


}