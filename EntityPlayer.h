#ifndef _ENTITYPLAYER_H_
#define _ENTITYPLAYER_H_

#include "Entity.h"

class room;
class exit;
class item;


class player : public entity{

public:

	room* currentroom;

public:


	~player();
	void Init();
	void move(exit* direction);
	void insert(string player_input, int subject, string subject_str);
	void extract(string player_input, string subject_str);

};


#endif