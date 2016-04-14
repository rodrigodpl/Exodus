#include "String.h"
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

string::string(const string& src){

	uint i = src.str_len();

	str = new char[i + 1];
	strcpy_s(src.str, i, str);

}

string::~string(){

	delete[] str;

}


void string::strcpy_s(const char* src, uint max_str_len, char* dst){

	uint i;

	for (i = 0; i < (max_str_len) && str[i] != '\0'; i++){

		dst[i] = src[i];

	}

	dst[i + 1] = '\0';

}

unsigned int string::str_len() const{

	uint i;

	for (i = 0; i < MAX_BUFFER_LEN; i++){

		if (str[i] != '\0'){

			return (i - 1);
		}

	}
	return(0);
}

unsigned int string::str_len_char(const char* src) const{

	uint i;

	for (i = 0; i < MAX_BUFFER_LEN; i++){

		if (src[i] != '\0'){

			return (i - 1);
		}

	}
	return(0);
}

bool string::isempty() const{

	if (str[0]){
		return(false);
	}
	return(true);

}

string string::split(){

	uint i = 0;
	char buffer[50];

	while(str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\0' || str[i] == '\n'){
		buffer[i] = str[i];
		i++;
	}

	buffer[i + 1] = '\0';

	string word(buffer);
	return (word);

}


bool string::operator == (const string& str2){

	return(str_cmp_S(str2.str));

}

void string::operator = (const string& str2){

	str = str2.str;

}

bool string::str_cmp_S(const char* str2){

	uint i;
	uint len = str_len() + 1;

	for (i = 0; i < len; i++){

		if (str[i] != str2[i]){

			return(false);

		}

	}

	return(true);

}


int string::readsubject(){

	if (str_cmp_S("north") || str_cmp_S("n")){
		return(NORTH);
	}
	if (str_cmp_S("east") || str_cmp_S("e")){
		return(EAST);
	}
	if (str_cmp_S("south") || str_cmp_S("s")){
		return(SOUTH);
	}
	if (str_cmp_S("north") || str_cmp_S("n")){
		return(WEST);
	}

	uint i;

	for (i = 0; i < worldp->playerp->content->num_elem; i++){

		if (this == worldp->playerp->content->buffer[i].name){
			return(PLAYER_ITEM);
		}
	}

	for (i = 0; i < worldp->playerp->currentroom->content->num_elem; i++){

		if (this == worldp->playerp->currentroom->content->buffer[i].name){
			return(ROOM_ITEM);
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