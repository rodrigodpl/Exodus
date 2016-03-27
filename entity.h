#ifndef __ENTITY_H__
#define __ENTITY_H__


#include "globals.h"
#include "player.h"
#include "item.h"
#include "room.h"
#include "string.h"
#include <stdio.h>



class entity{

public:

	char* name;
	char* desc;
	entity* content;
	bool iscontainer;


public:



	void look(){


		printf("\n%s, %s", this->name, this->desc);

	}


	int getobjectcode(char* objname){

		int i;

		for (i = 0; i < CONTAINER_LEN; i++){

			if (stringmanager.strcmp(this->content[i].name, objname)){

				return(i);

			}
		}

		return(-1);

	}


	int searchemptyspace(){

		int i;
		entity* entityp = this->content;

		for (i = 0; i < CONTAINER_LEN; i++){

			if (entityp == NULL){

				return(i);
			}

			entityp++;

		}

		return(-1);
	}



	bool safeput(item* object, int objcode){

		if (objcode != -1){


			this->content += objcode;
			this->content = object;
			this->content -= objcode;

			return(SUCCESS);

		}
		else{

			return(ERROR);
		}

	}

	bool safeerase(int objcode){

		if (objcode != -1){

			this->content += objcode;
			this->content = NULL;
			this->content -= objcode;


			return(SUCCESS);
		}
		else{

			return(ERROR);
		}

	}



	void moveitem(item* obj, entity* oldcontainer, int objcode){

		if (this->safeput(obj, searchemptyspace())){

			if (oldcontainer->safeerase(objcode)){

				printf("\nOperation done!");
				return;
			}

			printf("Error erasing item!");
			return;

		}

		printf("\nFull container! Try emptying it before");
		return;

	}

}


#endif //_ENTITY_H_