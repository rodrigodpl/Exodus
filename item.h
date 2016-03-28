#ifndef __ITEM_H__
#define __ITEM_H__

#include "entity.h"
#include "globals.h"

class item : public entity{

public:

	bool isequipable;
	int equipslot;
	

	item(){

		name = new char[NAME_LEN];
		desc = new char[DESCRIPTION_LEN];

		itemnameindex = (stringmanager.getline(ITEM_NAMES, name, NEWLINE, itemnameindex) + 1);
		itemdescindex = (stringmanager.getline(ITEM_DESC, desc, NEWLINE, itemdescindex) + 1);

		iscontainer = itemiscontarray[itemdataindex];
		isequipable = itemisequiparray[itemdataindex];

		if (iscontainer){

			containerlen = itemcontainerlen[itemdataindex];
			content = new item*[containerlen];

			int i;
			for (i = 0; i < containerlen; i++){

				content[i] = NULL;

			}
			
		}
		else{
			content = NULL;
		}
			
	


		if (isequipable){

			equipslot = itemequipslotarray[itemdataindex];

		}
		else{

			equipslot = -1;
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