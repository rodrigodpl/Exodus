#include "EntityItem.h"
#include "Entity.h"
#include "Data.h"


item::~item(){

	delete name;
	delete desc;

	if (content != NULL){
		delete content;
	}

}

void item::Init(uint index){

	name = new string(itemnamearray[index]);
	desc = new string(itemdescarray[index]);

	itemslot = itemslotarray[index];
	iscontainer = itemiscontarray[index];
	initial_location = itemlocarray[index];

	if (iscontainer){
		content = new dyn_array<entity*>(INIT_CONTENT_SIZE);
	}
	else{
		content = NULL;
	}
}
