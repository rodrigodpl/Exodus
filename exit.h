#ifndef __EXIT_H__
#define __EXIT_H__

#include "globals.h"




class exit : public entity{

public:

	room* src;
	room* dst;
	bool isopen;
	int dir;

	exit(){

		this->iscontainer = false;
		this->content = NULL;

		exitnameindex = (stringmanager.getline(EXIT_NAMES, this->name, NEWLINE, exitnameindex) + 1);
		exitdescindex = (stringmanager.getline(EXIT_DESC, this->desc, NEWLINE, exitdescindex) + 1);
		
		this->isopen = exitisopenarray[exitdataindex];
		this->dir = exitdirarray[exitdataindex];

		this->src = &(roomp[(exitsrcarray[exitdataindex])]);
		this->dst = &(roomp[(exitdstarray[exitdataindex])]);

		exitdataindex++;

	}

	~exit(){

		delete[] name;
		delete[] desc;


	}



public:

	exit* searchexit(room* currentroom, int dir){

		int i;

		for (i = 0; i < EXIT_NUM; i++){

			if (currentroom == this[i].src){

				if (dir == this[i].dir){

					return(this + i);

				}

			}

		}

		return(NULL);

	}


};

#endif // _EXIT_H_