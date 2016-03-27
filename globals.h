#ifndef __GLOBALS_H__
#define __GLOBALS_H__

//defines:
#define NAME_LEN 50
#define DESCRIPTION_LEN 200
#define MAX_BUFFER_LEN 200
#define VERB_AND_NOUN_BUFFER_LEN 30
#define CONTAINER_LEN 10
#define HALF_BUFFER_LEN 15

#define MAX_EXIT_NUM 4
#define ROOM_NUM 16
#define EXIT_NUM 22
#define ITEM_NUM 15

#define NULL 0
#define ERROR 0
#define SUCCESS 1
#define NEWLINE 10
#define SPACE_KEY 32


//player data:
#define MAX_EQUIP_SLOTS 8
enum equip_slots{

	HEAD_SLOT,
	SHOULDER_SLOT,
	RIGHT_HAND_SLOT,
	LEFT_HAND_SLOT,
	CHEST_SLOT,
	BELT_SLOT,
	LEG_SLOT,
	FOOT_SLOT
};



//room data:
static int roomnameindex, roomdescindex;

#define ROOM_NAMES "asdasdaf \nasdasdas\nassad"
#define ROOM_DESC "asdasdasdasdasd"



//exit data:
static int exitnameindex, exitdescindex, exitdataindex;

#define EXIT_NAMES "asdasda"
#define EXIT_DESC "asdasd"

const bool exitisopenarray[EXIT_NUM] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
const int exitsrcarray[EXIT_NUM] = { 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5 };
const int exitdstarray[EXIT_NUM] = { 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5 };
const int exitdirarray[EXIT_NUM] = { 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2 };



//item data:
static int itemnameindex, itemdescindex, itemdataindex;

#define ITEM_NAMES "asdasd"
#define ITEM_DESC "adasd"

const bool itemiscontarray[ITEM_NUM] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };



//logic actions enums:
enum directions{

	NORTH,
	EAST, 
	SOUTH,
	WEST

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
