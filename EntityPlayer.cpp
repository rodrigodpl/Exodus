#include "EntityPlayer.h"
#include "EntityRoom.h"
#include "EntityItem.h"
#include "EntityExit.h"



void player::Init(){

	name = NULL;
	desc = NULL;

	content = new dyn_array<entity*>(PLAYER_INIT_INVSIZE);

	uint i;
	for (i = 0; i < MAX_EQUIP_SLOTS; i++){
		equippeditems[i] = NULL;
	}

}

player::~player(){


	delete content;

}

void player::move(exit* direction){

	if (direction != NULL){
		if (direction->isopen){
			currentroom = direction->dst;
		}
		else{
			printf("\ndoor closed!\n");
		}
	}
	else{
		printf("\nno exit in that direction!\n");
	}

}

void player::equip(string itemname, int origin){

	item* item_to_equip;
	uint i;
	entity* origin_ent;
	
	if (origin == PLAYER_ITEM){
		origin_ent = this;
	}
	else{
		origin_ent = currentroom;
	}

	item_to_equip = (item*)origin_ent->searchitem(itemname);

	if (item_to_equip != NULL){
		equippeditems[item_to_equip->itemslot] = item_to_equip;

		for (i = 0; i < origin_ent->content->num_elem; i++){

			if (itemname.str_cmp_S(origin_ent->content->buffer[i]->name->str)){
				origin_ent->content->erase(i);
				return;
			}
		}
	}

}

void player::unequip(string itemname){

	uint i;

	for (i = 0; i < MAX_EQUIP_SLOTS; i++){
		if (equippeditems[i] != NULL){
			if (itemname.str_cmp_S(equippeditems[i]->name->str)){
				content->pushback(equippeditems[i]);
				equippeditems[i] = NULL;
			}
		}
	}


}

void player::extract(char* second_subject, string subject_str, world* this_world){

	// Discard preposition//
	string old_container_str(second_subject);
	int old_container_class = old_container_str.readsubject(this_world);

	if (old_container_class != -1){
		if (old_container_class == PLAYER_ITEM){
			currentroom->getitem(searchitem(old_container_str), subject_str);
		}
		else if (old_container_class == ROOM_ITEM){
			currentroom->getitem(currentroom->searchitem(old_container_str), subject_str);
		}
	}
	else{
		printf("I just understood you as far as you want to extract %s from something", subject_str);
	}
}

void player::insert(char* second_subject, int subject, string subject_str, world* this_world){

	 // Discard preposition//
	string new_container_str(second_subject);
	int new_container_class = new_container_str.readsubject(this_world);
	entity* new_container;


	if (new_container_class != -1){
		if (subject == PLAYER_ITEM){
			if (new_container_class == PLAYER_ITEM){
				new_container = searchitem(new_container_str);
				new_container->getitem(this, subject_str);
			}
			else if ((new_container_class == ROOM_ITEM)){
				new_container = currentroom->searchitem(new_container_str);
				new_container->getitem(this, subject_str);
			}

		}
		else if (subject == ROOM_ITEM){
			if (new_container_class == PLAYER_ITEM){
				new_container = searchitem(new_container_str);
				new_container->getitem(currentroom, subject_str);
			}
			else if ((new_container_class == ROOM_ITEM)){
				new_container = currentroom->searchitem(new_container_str);
				new_container->getitem(currentroom, subject_str);
			}
		}
	}
	else{
		printf("I just understood you as far as you want to insert %s into something", subject_str);
	}

}
