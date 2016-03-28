#ifndef __WORLD_H__
#define __WORLD_H__


#include "string.h"
#include "room.h"
#include "passage.h"
#include "player.h"
#include "item.h"


class world{

public:


	player* playerp;
	room* map;
	passage* exitp;

	world(){



		playerp = new player;
		map = new room[ROOM_NUM];
		exitp = new passage[PASSAGE_NUM];


		int i;
		for (i = 0; i < PASSAGE_NUM; i++){

			exitp[i].initpassages(map, i);

		}

	}

	~world(){

		delete playerp;
		delete[] map;
		delete[] exitp;


	}


public:



	union object{

		int num;
		item* itempointer;
		room* roompointer;


	}obj, obj2;


	int solveobject(object& obj, object& obj2, char* objectname){


		if (stringmanager.strcmp(objectname, "north") || stringmanager.strcmp(objectname, "n")){

			obj.num = (int)NORTH;
			return(DIR_OUTPUT);
		}

		if (stringmanager.strcmp(objectname, "east") || stringmanager.strcmp(objectname, "e")){

			obj.num = (int)EAST;
			return(DIR_OUTPUT);
		}

		if (stringmanager.strcmp(objectname, "south") || stringmanager.strcmp(objectname, "s")){

			obj.num = (int)SOUTH;
			return(DIR_OUTPUT);
		}

		if (stringmanager.strcmp(objectname, "west") || stringmanager.strcmp(objectname, "w")){
			obj.num = (int)WEST;
			return(DIR_OUTPUT);
		}


		if (stringmanager.strcmp(objectname, "around")){

			obj.roompointer = playerp->currentroom;
			return(ROOM_OUTPUT);
		}


		int playercode, roomcode;

		playercode = playerp->getobjectcode(objectname);

		if (playercode != -1){

			obj.itempointer = playerp->content[playercode];
			obj2.num = playercode;
			return(ITEM_FROMPLAYER_OUTPUT);

		}
		
		roomcode = playerp->currentroom->getobjectcode(objectname);

		if (roomcode != -1){

			playerp->currentroom->content[roomcode];
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


		if ((stringmanager.strcmp(verbbuffer, "move")) || (stringmanager.strcmp(verbbuffer, "north"))
			|| (stringmanager.strcmp(verbbuffer, "east")) || (stringmanager.strcmp(verbbuffer, "south"))
			|| (stringmanager.strcmp(verbbuffer, "west")) || (stringmanager.strcmp(verbbuffer, "n"))
			|| (stringmanager.strcmp(verbbuffer, "e")) || (stringmanager.strcmp(verbbuffer, "s"))
			|| (stringmanager.strcmp(verbbuffer, "s"))){

			if (!(stringmanager.strcmp(verbbuffer, "move"))){

				stringmanager.strcpy(verbbuffer, nounbuffer);
			}

			switch (solveobject(obj, obj2, nounbuffer)){


			case DIR_OUTPUT:

				playerp->move(exitp->searchpassage(playerp->currentroom, obj.num));				
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




		else if ((stringmanager.strcmp(verbbuffer, "look"))){

			switch (solveobject(obj, obj2, nounbuffer)){

			case DIR_OUTPUT:

				passage* auxexitp;

				auxexitp = exitp->searchpassage(playerp->currentroom, obj.num);
				if (auxexitp != NULL){
					auxexitp->look();
				}
				else{
					printf("there's no exit in that direction");
				}
				break;

			case ROOM_OUTPUT:

				obj.roompointer->look();
				break;

			case ITEM_FROMPLAYER_OUTPUT:

				obj.itempointer->look();
				break;

			case ITEM_FROMROOM_OUTPUT:

				obj.itempointer->look();
				break;

			case NULL_OUTPUT:
				printf("\nPlease, specify the direction or the item you want to look at (north, east, south or west, 'around' for the current room or an item name)");
				break;

			case ERROR_OUTPUT:
				printf("\nI just understood you as far you want to look");
				break;


			}

		}


		else if ((stringmanager.strcmp(verbbuffer, "help"))){

			printf("\nhelp display ------------------------------------------------");
		}

		else if ((stringmanager.strcmp(verbbuffer, "pick"))){

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMROOM_OUTPUT:

				playerp->moveitem(obj.itempointer, playerp->currentroom, obj2.num);
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


		else if ((stringmanager.strcmp(verbbuffer, "drop"))){

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMPLAYER_OUTPUT:

				playerp->currentroom->moveitem(obj.itempointer, playerp, obj2.num);
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


		else if ((stringmanager.strcmp(verbbuffer, "insert"))){

			object newcontainer;
			int roomposition;
			int inventoryposition;

			char* secondnoun = stringmanager.stringsplit(nounbuffer);

			switch (solveobject(obj, obj2, nounbuffer)){

			case ITEM_FROMPLAYER_OUTPUT:

				inventoryposition = obj2.num;

				switch (solveobject(newcontainer, obj2, secondnoun)){

				case ITEM_FROMPLAYER_OUTPUT:

					newcontainer.itempointer->moveitem(obj.itempointer, playerp, inventoryposition);

					break;

				case ITEM_FROMROOM_OUTPUT:

					newcontainer.itempointer->moveitem(obj.itempointer, playerp, inventoryposition);

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

				}


			case NULL_OUTPUT:

				printf("\nInsert what? (try typing an item name)");
				break;

			case ITEM_FROMROOM_OUTPUT:

				roomposition = obj2.num;

				switch (solveobject(newcontainer, obj2, secondnoun)){

				case ITEM_FROMPLAYER_OUTPUT:

					newcontainer.itempointer->moveitem(obj.itempointer, playerp->currentroom, roomposition);

					break;

				case ITEM_FROMROOM_OUTPUT:

					newcontainer.itempointer->moveitem(obj.itempointer, playerp->currentroom, roomposition);

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

				}

			case ERROR_OUTPUT:

				printf("\nI you just understood you as far as you want to insert something");
				break;

			default:

				printf("\nThat's not an item!");

			}

			delete[] secondnoun;

		}




		else if ((stringmanager.strcmp(verbbuffer, "quit"))){


			return(0);

		}

		else{

			printf("\nI didn't understand what do you want to do now");
		}

		return(1);

	}


};



#endif //_WORLD_H_