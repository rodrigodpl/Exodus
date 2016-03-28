#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "globals.h"
#include "entity.h"

class room;
class item;
class passage;

class player : public entity{

public:

	room* currentroom;
	item** equippeditems;


	player(){

		int i;

		name = NULL;
		desc = NULL;

		iscontainer = true;

		containerlen = PLAYER_INIT_INVSIZE;

		equippeditems = new item*[MAX_EQUIP_SLOTS];

		for (i = 0; i < MAX_EQUIP_SLOTS; i++){

			equippeditems[i] = NULL;
			
		}

		content = new item*[PLAYER_INIT_INVSIZE];

		for (i = 0; i < PLAYER_INIT_INVSIZE; i++){

			content[i] = NULL;

		}

	}

	~player(){

		delete currentroom;
		delete[] equippeditems;
		delete[] content;

	}

public:


	void move(passage* passagepointer){

		if (passagepointer != NULL){

			currentroom = passagepointer->dst;
		}

	}

	


};


#endif //_PLAYER_H_