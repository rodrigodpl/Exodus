#ifndef __ENTITYITEM_H__
#define __ENTITYITEM_H__

#include "Entity.h"
#include "Data.h"

class item : public entity{

public:

	int itemslot;
	bool iscontainer;
	uint initial_location;

public:

	~item();
	void Init(uint index);

};


#endif