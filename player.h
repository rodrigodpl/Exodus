#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "globals.h"

class player : public entity{

public:

	room* currentroom;



public:


	void move(int dir){

		if (playerp->currentroom->roomexitp[dir] != NULL){
			playerp->currentroom == playerp->currentroom->roomexitp[dir]->dst;
		}
		else{
			printf("\nthere's no exit in that direction");
		}

	}



	template <typename temp>

	void look(temp obj){

		printf("\n%s", obj.desc);

	}


	void pick(item* obj){

		int i, j;
		for (i = 0; i < CONTAINER_LEN; i++){

			//puting the item in inventory
			if (playerp->content[i] == NULL){
				playerp->content[i] = obj;
				
				//erasing the item from the room
				for (j = 0; j < CONTAINER_LEN; j++){
					if (playerp->currentroom->content[j] == obj){
						playerp->currentroom->content[j] = NULL;
						return;
					}
				}
			}
		}

		printf("\nyou have no space in inventory! Try dropping something before");
		return;

	}

	void drop(item* obj){

		int i, j;
		for (i = 0; i < CONTAINER_LEN; i++){

			//puting the item in the room
			if (playerp->currentroom->content[i] == NULL){
				playerp->currentroom->content[i] = obj;

				//erasing the item from the inventory
				for (j = 0; j < CONTAINER_LEN; j++){
					if (playerp->content[j] == obj){
						playerp->content[j] = NULL;
						return;
					}
				}
			}
		}

		printf("\nyou have no space in the room! Try picking something before");
		return;


	}








};


#endif //_PLAYER_H_