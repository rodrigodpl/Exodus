#ifndef __ENTITY_H__
#define __ENTITY_H__


#include "globals.h"
#include "player.h"
#include "item.h"
#include "room.h"
#include <stdio.h>


class entity{

public:


	char* name = new char[NAME_LEN];
	char* desc = new char[DESCRIPTION_LEN];
	bool iscontainer;
	entity* content = new entity[CONTAINER_LEN];


public:



	void look(){

		printf("%s, %s", this->name, this->desc);

	}




	void insert(item*& item){

		int i;


		if (this->iscontainer){

			for (i = 0; i < CONTAINER_LEN; i++){

				if (this->(content + i) == NULL){

					container->(content + i) = this;

				}
				containerp++;

			}

		}

		else{

			printf("\nThat's not a container!");

		}
	}



}

#endif //_ENTITY_H_