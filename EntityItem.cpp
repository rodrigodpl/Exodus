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

	nature = ITEM;

	itemslot = itemslotarray[index];
	iscontainer = itemiscontarray[index];

	if (iscontainer){
		content = new dyn_array<entity>(ITEM_INV_SIZE);
	}
}
