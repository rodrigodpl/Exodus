#ifndef _DATA_H_
#define _DATA_H_

//defines:

#define DYN_ARR_BUFFER_BLOCK 3
#define MAX_BUFFER_LEN 200

#define ERROR -1

#define CONTINUE 1
#define QUIT_GAME 0

#define ROOM_NUM 16
#define EXIT_NUM 22
#define ITEM_NUM 15

#define INIT_CONTENT_SIZE 3
#define MAX_CONTENT_SIZE 15
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
	FEET_SLOT

};



//room data:

const char roomnamearray[ROOM_NUM][20]
{ "\0", "Security Dormitory", "Security Storage", "Right Engine Room", "West Main Room", "East Main Room",
  "Cryogenesis Deposit", "Machinery Room", "Oxygen Production", "Command Booth", "\0", "Left Engine Room", "Laboratory",
  "Laboratory Deposit", "\0", "\0"};

const char roomdescarray[ROOM_NUM][117] 
{ "\0", "You are in a big room with series of bunk beds.",
  "You are in a small cabinet with army supplies. \nIn a desk rests a hand gun.",
  "A huge nuclear reactor occupies almost the \ntotality of the great room you are in. ",
  "You are in the west side of what looks like \nthe main room of the spaceship.",
  "You are in the east side of what looks like \nthe main room of the spaceship.",
  "You are in a great room full of human-sized \ncapsules stored in long rows that get into the sides of the ship. ",
  "What looks like two great electricty cables \ncommute in greater even space-bounding engine. ",
  "All the walls of the room are covered in cristal \ngreenhouses full of whats looks like a green moss. ",
  "A transparent panel would allow you to see in \nfront of the ship.",
  "\0", "A huge nuclear reactor occupies almost \nthe totality of the great room you are in. However, it looks like it broke.",
  "You are in a scientific laboratory. Lots of \ntest tubes filled with multi-colored substances decorate the room.",
 "You are in a smaller room than the main laboratory, \nmostly filled with barrels with toxic signs on them.", "\0", "\0"};



//exit data:

const char exitnamearray[EXIT_NUM][20]
{ "Security Storage", "Security Dormitory", "Security Dormitory", "East Main Room", "Right Engine Room",
  "Machinery Room", "West Main Room", "East Main Room", "East Main Room", "Cryogenesis Deposit",
  "Cryogenesis Deposit", "Machinery Room", "Oxygen Production", "West Main Room", "Command Booth",
  "East Main Room", "Left Engine Room","Machinery Room", "Laboratory", "Oxygen Production", 
  "Laboratory Basement", "Laboratory"};

const char exitdescarray[EXIT_NUM][72]
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

const char itemnamearray[ITEM_NUM][12]
{ "knife", "gun", "key", "vest", "food",
"health pack", "boots", "tools", "backpack", "helmet",
"crowbar", "poison", "belt", "pants", "flashlight"}; //insert data//
const char itemdescarray[ITEM_NUM][79]
{ "a sharp knife mostly used in the kitchen, although it can be used as a weapon", "a small caliber handgun used by the security crew",
"an electronic key used to open locked door. Which one will open with this key?", "a bulletproof vest worn by the security crew", 
"some dehydrated food supplies, enough to feed few mouths some days", "a small box containing some items for health restoration",
"two leather boots, very worn, but better than barefeet", "some utility tools like a hammer or a screwdriver", 
"a small backpack, with enough space to contain some items inside", "a security chief helmet, very hard and heavy",
"an iron crowbar. Could be used as a weapon or to force some door", "a green bottle full of what looks like rat poison, enough to kill a human",
"A worker tool-belt with a lot of pockets and holders", "A worn and dirty jeans, probably from one of the civilians of the ship", 
"A small battery powered by a dynamo, weak but enough to light dark areas"};

const bool itemiscontarray[ITEM_NUM] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 };
const int itemslotarray[ITEM_NUM] = 
{ RIGHT_HAND_SLOT, RIGHT_HAND_SLOT, -1, CHEST_SLOT, -1, -1, FEET_SLOT,
-1, SHOULDER_SLOT, HEAD_SLOT, RIGHT_HAND_SLOT, -1, BELT_SLOT, LEG_SLOT, LEFT_HAND_SLOT }; // -1 if not equipable
const uint itemlocarray[ITEM_NUM] = { 1, 2, 4, 3, 5, 13, 11, 13, 9, 11, 7, 8, 7, 4, 6};



//string data:

enum words_tokenize{

	VERB,
	SUBJECT,
	PREPOSITION,
	SECOND_SUBJECT

};



//logic actions enums:

enum subjects{

	NORTH,
	EAST,
	SOUTH,
	WEST,
	PLAYER_ITEM,
	ROOM_ITEM,
	CURRENT_ROOM,
	INVENTORY, 
	PLAYER_EQUIP,
	PLAYER_EQUIPPED_ITEM
};


enum actions{

	MOVE, 
	LOOK,
	PICK,
	DROP,
	OPEN,
	CLOSE,
	HELP,
	QUIT,
	INSERT,
	EXTRACT,
	EQUIP,
	UNEQUIP


};



//help text:

const char help_text [702] = 
{ "\nActions:\nMOVE: allows the player to move between rooms. Type <move> and a direction\n(north, east, south, west) to use.\nLOOK: shows further details about an item, exit, inventory... Type <look>\nfollowed with what you want to look to use.\nOPEN/CLOSE: open or closes the related door. type<open/close> and a \ndirection to use.\nPICK/DROP: picks an item from the room or drop an item from the inventory.\nType <pick/drop> and the item name to use.\nEXCTRACT/INSERT: inserts or extracts an item from a container. Type <insert>, \nthe item name, <into/from> and the container name to use.\nEQUIP/UNEQUIP: equips or unequips the related item. Type <equip/unequip>\nand the item name to use.QUIT: exits the game.\n" };

#endif