#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "globals.h"


class player : public entity{

public:

	room* currentroom;



public:


	void move(exit* dir){

		if (dir != NULL){

			this->currentroom = dir->dst;
		}
		else{
			printf("\nthere's no exit in that direction");
		}

	}




	void pick(item* obj, int objectcode){

		if (this->safeput(obj, searchemptyspace())){

			if (this->currentroom->safeerase(objectcode)){

				printf("\n%s picked!", obj->name);
				return;
			}

			printf("Error erasing item!");
			return;

		}

		printf("\nInventory full! Try dropping something before");
		return;

		

	}



	void drop(item* obj, int objectcode){

		if (this->currentroom->safeput(obj, searchemptyspace())){

			if (this->safeerase(objectcode)){

				printf("\n%s dropped!", obj->name);
				return;

			}

			printf("Error erasing item!");
			return;

		}
		
		printf("Full room! Try picking or inserting something before!");
		return;


	}








};


#endif //_PLAYER_H_