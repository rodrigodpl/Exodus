#ifndef __ROOM_H__
#define __ROOM_H__

#include "globals.h"
#include "exit.h"

class room: public entity{

public:

	exit* roomexitp;

	room(){

		roomexitp = new exit[MAX_EXIT_NUM];

	}

	~room(){

		delete[] roomexitp;

	}

};

#endif //_ROOM_H_