#ifndef _DATA_H_
#define _DATA_H_

//defines:


#define ROOM_NUM 16
#define EXIT_NUM 22
#define ITEM_NUM 15

#define NULL 0
#define ERROR 0
#define SUCCESS 1
#define NEWLINE 10
#define SPACE_KEY 32

#define ROOM_INV_SIZE 10
#define ITEM_INV_SIZE 10
#define PLAYER_INIT_INVSIZE 10
#define INITIAL_ROOM 6

typedef unsigned int uint;


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

const char roomnamearray[ROOM_NUM][50]
{ "\0", "Security Dormitory", "Security Storage", "Right Engine Room", "West Main Room", "East Main Room",
  "Cryogenesis Deposit", "Machinery Room", "Oxygen Production", "Command Booth", "\0", "Left Engine Room", "Laboratory",
  "Laboratory Deposit", "\0", "\0"};

const char roomdescarray[ROOM_NUM][120] 
{ "\0", "You are in a big room with series of bunk beds.",
  "You are in a small cabinet with army supplies. \nIn a desk rests a hand gun.",
  "A huge nuclear reactor occupies almost the \ntotality of the great room you are in. ",
  "You are in the west side of what looks like \nthe main room of the spaceship.",
  "You are in the east side of what looks like \nthe main room of the spaceship.",
  "You are in a great room full of human-sized \ncapsules stored in long rows that get into the sides of the ship. ",
  "What looks like two great electricty cables \ncommute in greater even space-bounding engine. ",
  "All the walls of the room are covered in cristal \ngreenhouses full of whats looks like a green moss. ",
  "A transparent panel would allow you to see in \nfront of the ship.",
  "\0", "A huge nuclear reactor occupies almost \nthe totality of the great room you are in. However, it looks like it broken.",
  "You are in a scientific laboratory. Lots of \ntest tubes filled with multi-colored substances decorate the room.",
 "You are in a smaller room than the main laboratory, \nmostly filled with barrels with toxic signs on them.", "\0", "\0"};



//exit data:

const char exitnamearray[EXIT_NUM][50]
{ "Security Storage", "Security Dormitory", "Security Dormitory", "East Main Room", "Right Engine Room",
  "Machinery Room", "West Main Room", "East Main Room", "East Main Room", "Cryogenesis Deposit",
  "Cryogenesis Deposit", "Machinery Room", "Oxygen Production", "West Main Room", "Command Booth",
  "East Main Room", "Left Engine Room","Machinery Room", "Laboratory", "Oxygen Production", 
  "Laboratory Basement", "Laboratory"};

const char exitdescarray[EXIT_NUM][120]
{ "A broken door leads to what seems military supplies", "A room where the security personal sleep and train",
  "A room where the security personal sleep and train", "The east zone of the great room you are in", "The right piece of the ship engine glows from here",
  "The room from where the ship was propulsed", "The west zone of the great room you are in", "The east zone of the great room you are in",
  "The east zone of the great room you are in", "A very cold room where people were stored in cryogenesis", "A very cold room where people were stored in cryogenesis",
  "The room from where the ship was propulsed", "A room full of vegetation to produce the vital oxygen", "the west zone of the great room you are in",
  "The zone where the captain of the ship would have commanded the machine", "The east zone of the great room you are in", "The room where the left engine should be, but it's mute",
  "The room from where the ship was propulsed", "The laboratory of the ship, full of chemicals and toxins", "A room full of vegetation to produce the vital oxygen",
  "The deposit of the laboratory, where the necessary materials are stored", "The laboratory of the ship, full of chemicals and toxins"};

const bool exitisopenarray[EXIT_NUM] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
const bool exitislockedarray[EXIT_NUM] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
const uint exitsrcarray[EXIT_NUM] = { 1, 2, 5, 1, 7, 3, 5, 4, 6, 5, 7, 6, 4, 8, 5, 9, 7, 11, 8, 12, 12, 13 };
const uint exitdstarray[EXIT_NUM] = { 2, 1, 1, 5, 3, 7, 4, 5, 5, 6, 6, 7, 8, 4, 9, 5, 11, 7, 12, 8, 13, 12 };
const uint exitdirarray[EXIT_NUM] = { 1, 3, 0, 2, 0, 2, 3, 1, 3, 1, 3, 1, 2, 0, 2, 0, 2, 0, 2, 0, 1, 3 };



//item data:

const char itemnamearray[ITEM_NUM][50]
{ "Security Storage", "Security Dormitory", "Security Dormitory", "East Main Room", "Right Engine Room",
"Machinery Room", "West Main Room", "East Main Room", "East Main Room", "Cryogenesis Deposit",
"Cryogenesis Deposit", "Machinery Room", "Oxygen Production", "West Main Room", "Command Booth"}; //insert data//
const char itemdescarray[ITEM_NUM][120]
{ "A broken door leads to what seems military supplies", "A room where the security personal sleep and train",
"A room where the security personal sleep and train", "The east zone of the great room you are in", "The right piece of the ship engine glows from here",
"The room from where the ship was propulsed", "The west zone of the great room you are in", "The east zone of the great room you are in",
"The east zone of the great room you are in", "A very cold room where people were stored in cryogenesis", "A very cold room where people were stored in cryogenesis",
"The room from where the ship was propulsed", "A room full of vegetation to produce the vital oxygen", "the west zone of the great room you are in",
"The zone where the captain of the ship would have commanded the machine"};

const bool itemiscontarray[ITEM_NUM] = { 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };
const int itemslotarray[ITEM_NUM] = { 3, -1, -1, -1, -1, -1, -1, -1, -1, 2, -1, -1, -1, 5, -1 };
// -1 if not equipable

//logic actions enums:
enum subjects{

	NORTH,
	EAST,
	SOUTH,
	WEST,
	PLAYER_ITEM,
	ROOM_ITEM,
	CURRENT_ROOM

};


enum natureclasses{

	ITEM,
	ROOM,
	PLAYER,
	EXIT

};

enum actions{

	MOVE, 
	LOOK,
	PICK,
	DROP,
	HELP,
	QUIT,
	INSERT,
	EXTRACT,
	EQUIP,
	UNEQUIP


};


#endif