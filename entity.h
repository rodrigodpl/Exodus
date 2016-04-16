#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "Data.h"
#include "String.h"
#include "Dyn_Array.h"
#include <cstdio>

class string;

class entity{

public:

	dyn_array<entity*>* content;
	string* name;
	string* desc;

public:

	void getitem(entity* old_container, string& itemname);
	entity* searchitem(string& itemname);

};




#endif
