#include "EntityRoom.h"
#include "Data.h"
#include "Entity.h"

room::~room(){

	delete name;
	delete desc;

	delete content;

}

void room::Init(uint index){

	name = new string(roomnamearray[index]);
	desc = new string(roomdescarray[index]);

	nature = ROOM;

	content = new dyn_array<entity>(ROOM_INV_SIZE);
}