#include "EntityRoom.h"
#include "Data.h"
#include "Entity.h"
#include "EntityItem.h"

room::~room(){

	delete name;
	delete desc;

	delete content;

}

void room::Init(uint index, item* item_list){

	name = new string(roomnamearray[index]);
	desc = new string(roomdescarray[index]);

	content = new dyn_array<entity*>(ROOM_INV_SIZE);

	uint i;
	for (i = 0; i < ITEM_NUM; i++){

		if (item_list[i].initial_location == index){
			content->pushback(&(item_list[i]));
		}
	}
}