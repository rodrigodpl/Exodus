#ifndef _ENTITYPLAYER_H_
#define _ENTITYPLAYER_H_

#include "Entity.h"

class room;
class world;
class exit;
class item;

class player : public entity{

public:

	room* currentroom;
	item* equippeditems[MAX_EQUIP_SLOTS];

public:


	~player();
	void Init();
	void move(exit* direction);
	void insert(char* second_subject, int subject, string subject_str, world* this_world);
	void extract(char* second_subject, string subject_str, world* this_world);
	void equip(string& subject_str, int origin);
	void unequip(string& item);

};


#endif