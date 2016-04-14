#ifndef _ENTITYROOM_H_
#define _ENTITYROOM_H_

#include "Data.h"
#include "Entity.h"


class room : public entity{

public:

	~room();
	void Init(uint index);

};


#endif