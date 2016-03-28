#ifndef __ROOM_H__
#define __ROOM_H__


#include "globals.h"
#include "entity.h"
#include "string.h"

class item;

class room : public entity{

public:

	int containerlen;


	room(){

		name = new char[NAME_LEN];
		desc = new char[DESCRIPTION_LEN];

		roomnameindex = (stringmanager.getline(ROOM_NAMES, name, NEWLINE, roomnameindex) + 1);
		roomdescindex = (stringmanager.getline(ROOM_DESC, desc, NEWLINE, roomdescindex) + 1);


		int i;

		iscontainer = true;
		containerlen = ROOM_CONTAINER_LEN;
		content = new item*[ROOM_CONTAINER_LEN];

		for (i = 0; i < ROOM_CONTAINER_LEN; i++){

			content[i] = NULL;

		}

		

	}

	~room(){

		delete[] name;
		delete[] desc;
		delete[] content;
		

	}


};

#endif //_ROOM_H_