#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "globals.h"


class player : public entity{

public:

	room* currentroom;
	item* equippeditems;

	player(){

		equippeditems = new item[MAX_EQUIP_SLOTS];


	}

	~player(){

		delete currentroom;

	}

public:


	void move(exit* exitpointer){

		if (exitpointer != NULL){

			this->currentroom = exitpointer->dst;
		}

	}


};


#endif //_PLAYER_H_