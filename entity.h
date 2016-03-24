#ifndef __ENTITY_H__
#define __ENTITY_H__


#include "globals.h"
#include "player.h"
#include "item.h"
#include "room.h"
#include <stdio.h>


class entity{

public:

	entity(){

		char* name = new char[NAME_LEN];
		char* desc = new char[DESCRIPTION_LEN];

	}

	entity(int n){

		char* name = new char[NAME_LEN];
		char* desc = new char[DESCRIPTION_LEN];
		entity* content = new entity[CONTAINER_LEN];
	}

public:

	

	void put(char* object){


		int i, objectcode = -1;
		char* buffer = new char[VERB_AND_NOUN_BUFFER_LEN];

		//checking if object is in inventory
		for (i = 0; i < CONTAINER_LEN; i++){

			if (object == playerp->content[i]->name){

				objectcode = i;
				break;
			}
		}

		if (objectcode == -1){

			printf("you are not carrying such a thing");
			return;
		}



		printf("\n put %s into what?\n", object);
		fgets(buffer, VERB_AND_NOUN_BUFFER_LEN, stdin);



		int i, j;
		bool notfound = 1;

		for (i = 0; i < 10; i++){

			//looking in the current room
			if (buffer == playerp->currentroom->content[i]->name){

				if (playerp->currentroom->content[i]->iscontainer){

					//a container is found
					for (j = 0; j < CONTAINER_LEN; j++){

						//there's an empty space
						if (playerp->currentroom->content[i]->content[j] == NULL){

							playerp->currentroom->content[i]->content[j] = &(playerp->content[objectcode]);
							playerp->content[objectcode] = NULL;

							notfound = 0;
							break;
						}
					}

					printf("\nthe container is already full");
					break;

				}

				else{

					printf("\nthat can't be inserted there");
					break;
				}

			}

			//looking at the inventory
			else if (buffer == playerp->content[i]->name){

				if (playerp->content[i]->iscontainer){

					//a container is found
					for (j = 0; j < CONTAINER_LEN; j++){

						//there's an empty space
						if (playerp->currentroom->content[i]->content[j] == NULL){

							playerp->currentroom->content[i]->content[j] = &(playerp->content[objectcode]);
							playerp->content[objectcode] = NULL;

							notfound = 0;
							break;
						}
					}

					printf("\nthe container is already full");
					break;

				}
				else{

					printf("\nthat can't be inserted there");
					break;
				}

			}
		}

		if (notfound){

			printf("\n there's no such thing around or in your inventory");
		}

	}




};

#endif //_ENTITY_H_