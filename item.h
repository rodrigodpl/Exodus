#ifndef __ITEM_H__
#define __ITEM_H__


#include "globals.h"


class item : public entity{

public:


	item(){

		this->content = new entity[CONTAINER_LEN];

		itemnameindex = (stringmanager.getline(ITEM_NAMES, this->name, NEWLINE, itemnameindex) + 1);
		itemdescindex = (stringmanager.getline(ITEM_DESC, this->desc, NEWLINE, itemdescindex) + 1);

		this->iscontainer = itemiscontarray[itemdataindex];
		
		if (this->iscontainer){


		}
		else{

			this->content = NULL;
		}

		itemdataindex++;

	}

	~item(){

		delete[] name;
		delete[] desc;
		delete[] content;


	}

public:



	

};


#endif //_ITEM_H_