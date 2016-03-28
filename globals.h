#ifndef __GLOBALS_H__
#define __GLOBALS_H__

//defines:
#define NAME_LEN 50
#define DESCRIPTION_LEN 200
#define MAX_BUFFER_LEN 200
#define VERB_AND_NOUN_BUFFER_LEN 30
#define HALF_BUFFER_LEN 15

#define ROOM_NUM 16
#define PASSAGE_NUM 22
#define ITEM_NUM 15

#define NULL 0
#define ERROR 0
#define SUCCESS 1
#define NEWLINE 10
#define SPACE_KEY 32

#define ROOM_CONTAINER_LEN 10
#define PLAYER_INIT_INVSIZE 10


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
static int passagenameindex, passagedescindex, passagedataindex;

#define PASSAGE_NAMES "asdasda"
#define PASSAGE_DESC "asdasd"

const bool passageisopenarray[PASSAGE_NUM] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
const int passagesrcarray[PASSAGE_NUM] = { 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5 };
const int passagedstarray[PASSAGE_NUM] = { 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5 };
const int passagedirarray[PASSAGE_NUM] = { 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2, 1, 3, 1, 0, 2 };



//item data:
static int itemnameindex, itemdescindex, itemdataindex;

#define ITEM_NAMES "asdasd"
#define ITEM_DESC "adasd"

const bool itemiscontarray[ITEM_NUM] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
const int itemcontainerlen[ITEM_NUM] = { 0, 0, 0, 0, 10, 0, 0, 0, 0, 5, 0, 0, 0, 0, 10 };
const bool itemisequiparray[ITEM_NUM] = { 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0 };
const int itemequipslotarray[ITEM_NUM] = { 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1, 2, 3, 5, 1 };


//logic actions enums:
enum directions{

	NORTH,
	EAST, 
	SOUTH,
	WEST

};

enum actions{

	MOVE,
	LOOK,





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
