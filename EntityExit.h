#ifndef _ENTITYEXIT_H_
#define _ENTITYEXIT_H_

#include "Entity.h"
#include "Data.h"

class room;


class exit : public entity{

public:

	room* src;
	room* dst;
	bool isopen;
	bool islocked;
	uint dir;

public:


	~exit();
	void Init(uint index);


};


#endif