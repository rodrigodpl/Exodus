#ifndef __PASSAGE_H__
#define __PASSAGE_H__

#include "globals.h"
#include "entity.h"

class room;

class passage : public entity{

public:

	room* src;
	room* dst;
	bool isopen;
	int dir;

	passage(){

		iscontainer = false;

		content = NULL;

		name = new char[NAME_LEN];
		desc = new char[DESCRIPTION_LEN];

		passagenameindex = (stringmanager.getline(PASSAGE_NAMES, name, NEWLINE, passagenameindex) + 1);
		passagedescindex = (stringmanager.getline(PASSAGE_DESC, desc, NEWLINE, passagedescindex) + 1);
		
		isopen = passageisopenarray[passagedataindex];
		dir = passagedirarray[passagedataindex];


		passagedataindex++;

	}

	~passage(){

		delete[] name;
		delete[] desc;


	}



public:

	passage* searchpassage(room* currentroom, int dir){

		int i;

		for (i = 0; i < PASSAGE_NUM; i++){

			if (currentroom == this[i].src){

				if (dir == this[i].dir){

					return(&this[i]);

				}

			}

		}

		return(NULL);

	}

	void initpassages(room* roomp, int n){

		src = &(roomp[(passagesrcarray[n])]);
		dst = &(roomp[(passagedstarray[n])]);



	}


};

#endif // _EXIT_H_