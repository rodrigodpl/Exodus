#ifndef __STRING_H__
#define __STRING_H__


#include "globals.h"
#include <stdio.h>

class string{

public:

	void strcpy(char* src, char* dst){

		while (*(src + 1) != 0){
			*dst = *src;
			dst++, src++;
		}

		*(dst + 1) = 0;

	}

	char* stringsplit(char* nounbuffer){

		int i, j, k, z = 0;
		char* auxbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];



		for (i = 0; i < VERB_AND_NOUN_BUFFER_LEN; i++){


			//extract the first word
			if (nounbuffer[i + 1] == EOF){

				return(ERROR);
			}

			else if (nounbuffer[i + 1] == SPACE_KEY){

				nounbuffer[i + 1] = EOF;


				//ignore the preposition
				for (j = i; j < VERB_AND_NOUN_BUFFER_LEN; j++){

					if (nounbuffer[j + 1] == EOF){

						return(ERROR);
					}

					else if (nounbuffer[j + 1] == SPACE_KEY){

						//exctract the second word
						for (k = j; k < VERB_AND_NOUN_BUFFER_LEN && nounbuffer[k] != EOF; k++){

							auxbuffer[z] = nounbuffer[k];
							z++;

						}

						return(auxbuffer);

					}
				}

				


			}
		}

		return(ERROR);

	}

			

	union object{

		int num;
		item* itempointer;
		room* roompointer;


	}obj;

	int solveobject(object& obj, char* objectname){


		if (objectname == "north" || objectname == "n"){
			obj.num = (int) NORTH;
			return(DIR_OUTPUT);
		}

		if (objectname == "east" || objectname == "e"){
			obj.num = (int) EAST;
			return(DIR_OUTPUT);
		}

		if (objectname == "south" || objectname == "s"){
			obj.num = (int) SOUTH;
			return(DIR_OUTPUT);
		}

		if (objectname == "west" || objectname == "w"){
			obj.num = (int) WEST;
			return(DIR_OUTPUT);
		}


		if (objectname == "around"){

			obj.roompointer = (room*)playerp->currentroom;
			return(ROOM_OUTPUT);
		}
		

		
		int i;
		for (i = 0; i < CONTAINER_LEN; i++){

			if (objectname == playerp->content[i]->name){

				obj.itempointer = (item*)playerp->content[i];
				return(ITEM_OUTPUT);
			}
			else if (objectname == playerp->currentroom->content[i]->name){

				obj.itempointer = (item*)playerp->currentroom->content[i];
				return(ITEM_OUTPUT);
			}
		}

		if (objectname[0] == EOF){
			return(NULL_OUTPUT);

		}

		else{
			return(ERROR_OUTPUT);
		}



	}


	int readcommand(char* command){

		char* verbbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		verbbuffer[0] = EOF;
		char* nounbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		nounbuffer[0] = EOF;

		int i = 0, j = 0;

		while (command[i + 1] != EOF){

			verbbuffer[i] = command[i];

			if (command[i + 1] != SPACE_KEY){

				i += 2;

				while (command[i + 1] != EOF){

					nounbuffer[j] = command[i];
					i++, j++;
				}
				j++;
				nounbuffer[j] = 0;
			}

			i++;
		}

		i++;
		verbbuffer[i] = 0;







		if (verbbuffer == "move"){

			switch (solveobject(obj, nounbuffer)){

			case DIR_OUTPUT:

				playerp->move(obj.num);
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

			switch (solveobject(obj, nounbuffer)){

			case DIR_OUTPUT:

				if (playerp->currentroom->roomexitp[obj.num] != NULL){

					playerp->currentroom->roomexitp[obj.num]->look;
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

			switch (solveobject(obj, nounbuffer)){

			case ITEM_OUTPUT:

				playerp.pick(obj.itempointer);
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

			switch (solveobject(obj, nounbuffer)){

			case ITEM_OUTPUT:

				playerp.drop(obj.itempointer);
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

			object container;


			char* secondnoun = stringsplit(nounbuffer);

			switch (solveobject(obj, nounbuffer)){

			case ITEM_OUTPUT:

				switch (solveobject(container, secondnoun)){

				case ITEM_OUTPUT:

					if (container.itempointer->iscontainer){

						container.itempointer->insert(obj.itempointer);
					}

					break;

				case NULL_OUTPUT:

					printf("insert %s into what?(try typing 'insert -object- into -container-)", obj.itempointer->name);
					break;

				case ERROR_OUTPUT:

					printf("I just understood you as far as you want to insert %s into something", obj.itempointer->name);
					break;

				default:

					printf("that's not a container!");
				}

			case NULL_OUTPUT:

				printf("\nInsert what? (try typing an item name)");
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



#endif //__STRING_H__