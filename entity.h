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


	char* name = new char[NAME_LEN];
	char* desc = new char[DESCRIPTION_LEN];
	entity* content = new entity[CONTAINER_LEN];


public:



	void look(){

		printf("%s, %s", this->name, this->desc);

	}


	int getobjectcode(char* objname){

		int i; 
		
		for (i = 0; i < CONTAINER_LEN; i++){

			if (strcmp(this->content[i].name, objname, NAME_LEN)){

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

			return(ERROR)
		}

	}



}

#endif //_ENTITY_H_