#ifndef __ITEM_H__
#define __ITEM_H__


#include "globals.h"


class item : public entity{

public:

	bool iscontainer;

public:

	void insert(item* obj, entity* oldcontainer, int objcode){

		if (this->safeput(obj, searchemptyspace())){

			if (oldcontainer->safeerase(objcode)){

				printf("\nitem inserted!");
				return;
			}

			printf("Error erasing item!");

		}

		printf("\nFull container! Try extracting something before");
		return;

	}

	

};


#endif //_ITEM_H_