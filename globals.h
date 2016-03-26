#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define NAME_LEN 50
#define DESCRIPTION_LEN 200
#define MAX_BUFFER_LEN 200
#define SPACE_KEY 32
#define VERB_AND_NOUN_BUFFER_LEN 30
#define CONTAINER_LEN 10
#define MAX_EXIT_NUM 4
#define ROOM_NUM 16
#define EXIT_NUM 22
#define NULL 0
#define HALF_BUFFER_LEN 15
#define ERROR 0
#define SUCCESS 1
#define NEWLINE 10
#define DATA_LEN 8000


enum directions{

	NORTH,
	EAST, 
	SOUTH,
	WEST

	
};

enum parameters{

	NAME_OR_DESC,
	ROOM_SRC_OR_DST,
	EXITS_OPEN,



};

enum OBJ_OUTPUTS{

	DIR_OUTPUT,
	ROOM_OUTPUT,
	ITEM_FROMPLAYER_OUTPUT,
	ITEM_FROMROOM_OUTPUT,
	ERROR_OUTPUT, 
	NULL_OUTPUT

};


#endif //_GLOBALS_H_
