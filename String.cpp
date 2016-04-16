#include "String.h"
#include "Dyn_Array.h"
#include "World.h"
#include "Data.h"


string::string(const char* src){

	if (!src){
		str = NULL;
	}
	else{

		uint i = str_len_char(src);

		str = new char[i + 1];
		strcpy_s(src, i, str);
	}


}


string::~string(){

	uint i;

	for (i = 0; i > str_len(); i++){
		delete str;
		str++;
	}

}

dyn_array<string*>* string::tokenize(){

	uint i = 0, j = 0;
	

	dyn_array<string*>*array_pointer = new dyn_array<string*>(5);

	while (str[i] != '\0'){

		char* word_buffer = new char[50];;
		while (str[i] != ' ' && str[i] != ',' && str[i] != '.' && str[i] != '\0' && str[i] != '\n'){
			word_buffer[j] = str[i];
			i++;
			j++;
		}

		word_buffer[j] = '\0';

		string* word = new string(word_buffer);
		array_pointer->pushback(word);
		i++;
		delete[] word_buffer;
		j = 0;
	}
	return (array_pointer);

}


void string::strcpy_s(const char* src, uint max_str_len, char* dst){

	uint i;

	for (i = 0; i <= (max_str_len) && src[i] != '\0'; i++){

		dst[i] = src[i];

	}

	dst[i] = '\0';

}

unsigned int string::str_len() const{

	uint i;

	for (i = 0; i < MAX_BUFFER_LEN; i++){

		if (str[i] != '\0'){

			return (i);
		}

	}
	return(0);
}

unsigned int string::str_len_char(const char* src) const{

	uint i;

	for (i = 0; i < MAX_BUFFER_LEN; i++){

		if (src[i] == '\0'){

			return (i);
		}

	}
	return(0);
}

bool string::str_cmp_S(const char* str2){

	uint i;

	for (i = 0; str[i - 1] != '\0' || str[i - 1] != '\0'; i++){

		if (str[i] != str2[i]){

			return(false);

		}

	}

	return(true);

}


int string::readsubject(world* worldp){

	if (str_cmp_S("north") || str_cmp_S("n")){
		return(NORTH);
	}
	if (str_cmp_S("east") || str_cmp_S("e")){
		return(EAST);
	}
	if (str_cmp_S("south") || str_cmp_S("s")){
		return(SOUTH);
	}
	if (str_cmp_S("west") || str_cmp_S("w")){
		return(WEST);
	}
	if (str_cmp_S("inventory")){
		return(INVENTORY);
	}
	if (str_cmp_S("equip")){
		return(EQUIP);
	}
	uint i;

	for (i = 0; i < worldp->playerp->content->num_elem; i++){

		if (str_cmp_S(worldp->playerp->content->buffer[i]->name->str)){
			return(PLAYER_ITEM);
		}
	}

	for (i = 0; i < worldp->playerp->currentroom->content->num_elem; i++){

		if (str_cmp_S(worldp->playerp->currentroom->content->buffer[i]->name->str)){
			return(ROOM_ITEM);
		}
	}

	for (i = 0; i < MAX_EQUIP_SLOTS; i++){

		if (worldp->playerp->equippeditems[i] != NULL){
			if (str_cmp_S(worldp->playerp->equippeditems[i]->name->str)){
				return(PLAYER_EQUIPPED_ITEM);
			}
		}
	}



	if (str_cmp_S("around")){
		return(CURRENT_ROOM);
	}

	return(-1);
}


int string::readaction(){

	if (str_cmp_S("move")){
		return(MOVE);
	}
	if (str_cmp_S("help")){
		return(HELP);
	}
	if (str_cmp_S("look")){
		return(LOOK);
	}
	if (str_cmp_S("open")){
		return(OPEN);
	}
	if (str_cmp_S("close")){
		return(CLOSE);
	}
	if (str_cmp_S("quit")){
		return(QUIT);
	}
	if (str_cmp_S("pick")){
		return(PICK);
	}
	if (str_cmp_S("drop")){
		return(DROP);
	}
	if (str_cmp_S("insert")){
		return(INSERT);
	}
	if (str_cmp_S("extract")){
		return(EXTRACT);
	}
	if (str_cmp_S("equip")){
		return(EQUIP);
	}
	if (str_cmp_S("unequip")){
		return(UNEQUIP);
	}

	return(-1);
}