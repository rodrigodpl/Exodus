#ifndef __WORLD_H__
#define __WORLD_H__

#include "EntityRoom.h"
#include "EntityPlayer.h"
#include "EntityItem.h"
#include "EntityExit.h"
#include "Data.h"
#include "string.h"

class world{

public:

	player* playerp;
	room* map;
	exit* exitp;
	item* itemp;
	

public:

	~world();
	void Init();
	bool executecommand(string& player_input);
	exit* searchexit(room* src, int direction);
	void look(int origin, string lookat);
	void recurrent_look();


};


#endif