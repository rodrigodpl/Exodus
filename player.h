#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "globals.h"


class player : public entity{

public:

	room* currentroom;

	player(){

		

	}

	~player(){

		delete currentroom;

	}

public:


	void move(exit* dir){

		if (dir != NULL){

			this->currentroom = dir->dst;
		}
		else{
			printf("\nthere's no exit in that direction");
		}

	}


};


#endif //_PLAYER_H_