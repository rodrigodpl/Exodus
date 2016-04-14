#include "EntityExit.h"
#include "Entity.h"
#include "World.h"
#include "Data.h"


exit::~exit(){

	delete name;
	delete desc;

}

void exit::Init(uint index){

	name = new string(exitnamearray[index]);
	desc = new string(exitdescarray[index]);

	nature = EXIT;

	src = &(worldp->map[exitsrcarray[index]]);
	dst = &(worldp->map[exitdstarray[index]]);

	isopen = exitisopenarray[index];
	islocked = exitislockedarray[index];

	dir = exitdirarray[index];

	content = NULL;

}