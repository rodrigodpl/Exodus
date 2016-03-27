#ifndef __ROOM_H__
#define __ROOM_H__

#include "globals.h"
#include "exit.h"
#include "string.h"

class room: public entity{

public:


	room(){

		this->iscontainer = true;
		this->content = new entity[CONTAINER_LEN];

		roomnameindex = (stringmanager.getline(ROOM_NAMES, this->name, NEWLINE, roomnameindex) + 1);
		roomdescindex = (stringmanager.getline(ROOM_DESC, this->desc, NEWLINE, roomdescindex) + 1);
		

	}

	~room(){

		delete[] name;
		delete[] desc;
		delete[] content;
		

	}

};

#endif //_ROOM_H_