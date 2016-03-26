#ifndef __WORLD_H__
#define __WORLD_H__


#include "entity.h"
#include "string.h"


class world{

public:


	player* playerp = new player;
	room* map = new room[ROOM_NUM];
	exit* exitp = new exit[EXIT_NUM];
	string stringmanager;

public:

	union object{

		int num;
		item* itempointer;
		room* roompointer;


	}obj, obj2;

	void init(){






	int solveobject(object& obj, object& obj2, char* objectname){


		if (objectname == "north" || objectname == "n"){
			obj.num = (int)NORTH;
			return(DIR_OUTPUT);
		}

		if (objectname == "east" || objectname == "e"){
			obj.num = (int)EAST;
			return(DIR_OUTPUT);
		}

		if (objectname == "south" || objectname == "s"){
			obj.num = (int)SOUTH;
			return(DIR_OUTPUT);
		}

		if (objectname == "west" || objectname == "w"){
			obj.num = (int)WEST;
			return(DIR_OUTPUT);
		}


		if (objectname == "around"){

			obj.roompointer = (room*)playerp->currentroom;
			return(ROOM_OUTPUT);
		}


		int playercode, roomcode;

		playercode = playerp->getobjectcode(objectname);

		if (playercode != -1){

			entity* entityp = playerp->content;
			obj.itempointer = (item*)(entityp + playercode);
			obj2.num = playercode;
			return(ITEM_FROMPLAYER_OUTPUT);

		}
		
		roomcode = playerp->currentroom->getobjectcode(objectname);

		if (roomcode != -1){

			entity* entityp = playerp->currentroom->content;
			obj.itempointer = (item*)(entityp + roomcode);
			obj2.num = roomcode;
			return(ITEM_FROMROOM_OUTPUT);

		}


		if (objectname[0] == EOF){
			return(NULL_OUTPUT);

		}

		else{
			return(ERROR_OUTPUT);
		}



	}





	int executecommand(char* verbbuffer, char* nounbuffer){


		if (verbbuffer == "move"){

			switch (solveobject(obj, obj2, nounbuffer)){

			case DIR_OUTPUT:

				playerp->move(&(playerp->currentroom->roomexitp[obj.num]));
				break;

			case NULL_OUTPUT:
				printf("\nPlease, specify the direction you want to go to (north, east, south or west)");
				break;


			case ERROR_OUTPUT:
				printf("\nI just understood you as far you want to move");
				break;

			default:
				printf("\nThat's not a direction");
				break;

			}
		}




		else if (verbbuffer == "look"){

			switch (solveobject(obj, obj2, nounbuffer)){

			case DIR_OUTPUT:

				exit* exitp = playerp->currentroom->roomexitp;

				if ((exitp + obj.num) != NULL){

					playerp->currentroom->roomexitp[obj.num].look;
					break;
				}
				else{
					printf("\nThere's nothing in that direction");
				}
				break;

			case ROOM_OUTPUT:

				obj.roompointer->look;
				break;

			case ITEM_OUTPUT:

				obj.itempointer->look;
				break;

			case NULL_OUTPUT:
				printf("\nPlease, specify the direction or the item you want to look at (north, east, south or west, 'around' for the current room or an item name)");
				break;

			case ERROR_OUTPUT:
				printf("\nI just understood you as far you want to look");
				break;


			}

		}


		else if (verbbuffer == "help"){

			printf("\nhelp display ------------------------------------------------");
		}

		else if (verbbuffer == "pick"){

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMROOM_OUTPUT:

				playerp->pick(obj.itempointer, obj2.num);
				break;

			case ITEM_FROMPLAYER_OUTPUT:

				printf("\nThat's already in your inventory!");
				break;

			case NULL_OUTPUT:

				printf("\nplease, specify what are you trying to pick (type an nearby item name)");
				break;

			case ERROR_OUTPUT:

				printf("\nI just understood you as far you want to pick something");
				break;

			default:

				printf("\nThat's not an item!");

			}

		}


		else if (verbbuffer == "drop"){

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMPLAYER_OUTPUT:

				playerp->drop(obj.itempointer, obj2.num);
				break;

			case ITEM_FROMROOM_OUTPUT:

				printf("\nYou must be carrying an item in order to drop it");
				break;

			case NULL_OUTPUT:

				printf("\nplease, specify what are you trying to drop (type an inventory stored item name)");
				break;

			case ERROR_OUTPUT:

				printf("\nI just understood you as far you want to drop something");
				break;

			default:

				printf("\nthat's not an item!");

			}

		}


		else if (verbbuffer == "insert"){

			object newcontainer;

			char* secondnoun = stringmanager.stringsplit(nounbuffer);

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMPLAYER_OUTPUT:

				int inventoryposition = obj2.num;

				switch (solveobject(newcontainer, obj2, secondnoun)){
					
				case ITEM_FROMPLAYER_OUTPUT:

					newcontainer->insert(obj.itempointer, playerp, inventoryposition);

					break;
				
				case ITEM_FROMROOM_OUTPUT:

					newcontainer->insert(obj.itempointer, playerp, inventoryposition);

					break;

				case NULL_OUTPUT:

					printf("insert %s into what?(try typing 'insert -object- into -container-)", obj.itempointer->name);
					break;

				case ERROR_OUTPUT:

					printf("I just understood you as far as you want to insert %s into something", obj.itempointer->name);
					break;

				default:

					printf("that's not an item!");
					break;


			case NULL_OUTPUT:

				printf("\nInsert what? (try typing an item name)");
				break;

			case ITEM_FROMROOM_OUTPUT:

				int roomposition = obj2.num;

				switch (solveobject(newcontainer, obj2, secondnoun)){

				case ITEM_FROMPLAYER_OUTPUT:

					newcontainer->insert(obj.itempointer, playerp->currentroom, roomposition);

					break;

				case ITEM_FROMROOM_OUTPUT:

					newcontainer->insert(obj.itempointer, playerp->currentroom, roomposition);

					break;

				case NULL_OUTPUT:

					printf("insert %s into what?(try typing 'insert -object- into -container-)", obj.itempointer->name);
					break;

				case ERROR_OUTPUT:

					printf("I just understood you as far as you want to insert %s into something", obj.itempointer->name);
					break;

				default:

					printf("that's not an item!");
					break;

			case ERROR_OUTPUT:

				printf("\nI you just understood you as far as you want to insert something");
				break;

			default:

				printf("\That's not an item!");

			}

			delete[] secondnoun;

		}




		else if (verbbuffer == "quit"){

			delete[] nounbuffer;
			delete[] verbbuffer;

			return(0);

		}

		else{

			printf("\nI didn't understand what do you want to do now");
		}

		delete[] nounbuffer;
		delete[] verbbuffer;

		return(1);

	}


};

#endif //_WORLD_H_