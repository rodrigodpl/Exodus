#include "World.h"
#include "Dyn_Array.h"


world::~world(){

	delete[] itemp;
	delete[] map;
	delete playerp;
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

	for (index = 0; index < ROOM_NUM; index++){

		map[index].Init(index, itemp);

	}

	for (index = 0; index < EXIT_NUM; index++){

		exitp[index].Init(index, map);


	}

	

	playerp->Init();
	playerp->currentroom = &(map[INITIAL_ROOM]);

}


bool world::executecommand(string& player_input){

	dyn_array<string*>* player_inp_tokenized = player_input.tokenize();
	int word_number = player_inp_tokenized->num_elem;

	if (word_number >= 2){

		string action_str(player_inp_tokenized->buffer[0]->str);
		string subject_str(player_inp_tokenized->buffer[1]->str);

		int action = action_str.readaction();
		int subject = subject_str.readsubject(this);

		if (action == -1){
			printf("\nI didn't understood what you want to do. Check help if in doubt.\n");
		}
		else if (subject == -1 && action != EXTRACT){  // action != EXTRACT because of further item search in extract case// 
			printf("\nI just understood you as fas as you want to %s\n", action_str.str);

		}

		else{
			exit* exit_to_open;
			exit* exit_to_close;
			switch (action){
			case MOVE:

				playerp->move(searchexit(playerp->currentroom, subject));
				break;

			case LOOK:

				look(subject, subject_str.str);
				break;

			case OPEN:

				exit_to_open = searchexit(playerp->currentroom, subject);
				if (exit_to_open != NULL){
					exit_to_open->open();
				}
				else{
					printf("\nno exit in that direction");
				}
				break;

			case CLOSE:

				exit_to_close = searchexit(playerp->currentroom, subject);
				if (exit_to_close != NULL){
					exit_to_close->close();
				}
				else{
					printf("\nno exit in that direction");
				}
				break;

			case PICK:

				if (subject == ROOM_ITEM){
					playerp->getitem(playerp->currentroom, subject_str);
				}
				break;

			case DROP:

				if (subject == PLAYER_ITEM){
					playerp->currentroom->getitem(playerp, subject_str);
				}
				break;

			case EQUIP:

				if (subject == PLAYER_ITEM || subject == ROOM_ITEM){
					playerp->equip(subject_str, subject);
				}
				break;

			case UNEQUIP:

				if (subject == PLAYER_EQUIPPED_ITEM){
					playerp->unequip(subject_str);
				}
				break;

			case INSERT:

				if (word_number >= 4){
					playerp->insert(player_inp_tokenized->buffer[3]->str, subject, subject_str, this);
				}
				else{
					printf("\n I just understood you as far as you want to insert %s into something", subject_str.str);
				}

				break;

			case EXTRACT:

				if (word_number >= 4){
					playerp->extract(player_inp_tokenized->buffer[3]->str, subject_str, this);
				}
				else{
					printf("\n I just understood you as far as you want to exctract %s from something", subject_str.str);
				}

				break;

			case HELP:

				printf("help. -------");
				break;

			case QUIT:

				delete player_inp_tokenized;
				return(QUIT_GAME);


			}

		}
	}
	else{
		string action_str(player_inp_tokenized->buffer[0]->str);
		int action = action_str.readaction();
		int direction = action_str.readsubject(this);

		if (direction == NORTH || direction == EAST || direction == SOUTH || direction == WEST){
			playerp->move(searchexit(playerp->currentroom, direction));
		}
		else if (action == HELP){
			printf("help:----------");
		}
		else if (action == QUIT){
			return (QUIT_GAME);
		}
		else{
			printf("\nI didn't understood what you want to do.\n");
		}
	}
		delete player_inp_tokenized;
		return(CONTINUE);


}


exit* world::searchexit(room* src, int direction){

	uint i;
	for (i = 0; i < EXIT_NUM; i++){
		if (exitp[i].src == src && exitp[i].dir == direction){

			return(&exitp[i]);
		}
	}

	return(NULL);
}

void world::look(int origin, string name){

	entity* subject = NULL;
	uint i;

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

		subject = playerp->searchitem(name);
	}
	else if (origin == ROOM_ITEM){

		subject = playerp->currentroom->searchitem(name);
		
	}
	else if (origin == CURRENT_ROOM){
		subject = (entity*)playerp->currentroom;
	}
	else if (origin == INVENTORY){

		if (playerp->content->num_elem){
			printf("It contains %d elements: ", playerp->content->num_elem);
			for (i = 0; i < playerp->content->num_elem; i++){
				printf("\n%s, %s\n", playerp->content->buffer[i]->name->str, playerp->content->buffer[i]->desc->str);
			}
		}
		else{
			printf("\nemptyinventory\n");
			
		}
		return;
	}
	else if (origin == PLAYER_EQUIP){
		printf("\n HEAD SLOT: %s\n", playerp->equippeditems[HEAD_SLOT] == NULL ? "nothing" : playerp->equippeditems[HEAD_SLOT]->name->str);
		printf("\n SHOULDER SLOT: %s", playerp->equippeditems[SHOULDER_SLOT] == NULL ? "nothing" : playerp->equippeditems[SHOULDER_SLOT]->name->str);
		printf("\n RIGHT_HAND_SLOT: %s", playerp->equippeditems[RIGHT_HAND_SLOT] == NULL ? "nothing" : playerp->equippeditems[RIGHT_HAND_SLOT]->name->str);
		printf("\n LEFT_HAND_SLOT: %s", playerp->equippeditems[LEFT_HAND_SLOT] == NULL ? "nothing" : playerp->equippeditems[LEFT_HAND_SLOT]->name->str);
		printf("\n CHEST_SLOT: %s", playerp->equippeditems[CHEST_SLOT] == NULL ? "nothing" : playerp->equippeditems[CHEST_SLOT]->name->str);
		printf("\n BELT_SLOT: %s", playerp->equippeditems[BELT_SLOT] == NULL ? "nothing" : playerp->equippeditems[BELT_SLOT]->name->str);
		printf("\n LEG_SLOT: %s", playerp->equippeditems[LEG_SLOT] == NULL ? "nothing" : playerp->equippeditems[LEG_SLOT]->name->str);
		printf("\n FOOT_SLOT: %s", playerp->equippeditems[FOOT_SLOT] == NULL ? "nothing" : playerp->equippeditems[FOOT_SLOT]->name->str);
		return;
	}
	else if (origin == PLAYER_EQUIPPED_ITEM){

		for (i = 0; i < MAX_EQUIP_SLOTS; i++){

			if (playerp->equippeditems[i] != NULL){
				if (name.str_cmp_S(playerp->equippeditems[i]->name->str)){
					printf("\n%s, %s\n", playerp->equippeditems[i]->name->str, playerp->equippeditems[i]->desc->str);
					return;
				}
			}
		}
	}

	
	if (subject != NULL){

		printf("\n%s, %s\n", subject->name->str, subject->desc->str);

		if (subject->content != NULL){
			if (subject->content->num_elem){
				printf("It contains %d elements: ", subject->content->num_elem);
				for (i = 0; i < subject->content->num_elem; i++){
					printf("\n%s, %s\n", subject->content->buffer[i]->name->str, subject->content->buffer[i]->desc->str);
				}
			}
		}
	}
	else{
		printf("\nThere's no such thing!");
	}
}

void world::recurrent_look(){

	uint i;

	printf("\n%s, %s\n", playerp->currentroom->name->str, playerp->currentroom->desc->str);

	if (playerp->currentroom->content->num_elem){
		printf("It contains %d elements: ", playerp->currentroom->content->num_elem);
		for (i = 0; i < playerp->currentroom->content->num_elem; i++){
			printf("\n%s\n", playerp->currentroom->content->buffer[i]->name->str);
		}
	}

}
