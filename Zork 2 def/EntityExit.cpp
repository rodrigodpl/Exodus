#include "EntityExit.h"
#include "Entity.h"
#include "World.h"
#include "Data.h"


exit::~exit(){

	delete name;
	delete desc;

}

void exit::Init(uint index, room* map){

	name = new string(exitnamearray[index]);
	desc = new string(exitdescarray[index]);


	src = &(map[exitsrcarray[index]]);
	dst = &(map[exitdstarray[index]]);

	isopen = exitisopenarray[index];
	islocked = exitislockedarray[index];

	dir = exitdirarray[index];

	content = NULL;

}


void exit::open(){

	if (!isopen){
		if (!islocked){
			isopen = true;
		}
		else{
			printf("\ndoor locked!\n");
		}
	}
	else{
		printf("\nalready open!\n");
	}
}


void exit::close(){

	if (isopen){
		isopen = false;
	}
	else{
		printf("\nalready closed!\n");
	}



}

