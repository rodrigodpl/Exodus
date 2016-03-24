#ifndef __WORLD_H__
#define __WORLD_H__


#include "entity.h"
#include "string.h"


class world{

public:


	player* playerp = new player;
	room* map = new room[ROOM_NUM];
	exit* exitp = new exit[EXIT_NUM];



};

#endif //_WORLD_H_