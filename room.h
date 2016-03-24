#ifndef __ROOM_H__
#define __ROOM_H__

#include "globals.h"
#include "exit.h"

class room: public entity{

public:

	exit* roomexitp = new exit[MAX_EXIT_NUM];




};

#endif //_ROOM_H_