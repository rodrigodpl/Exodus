#ifndef _STRING_H_
#define _STRING_H_

#define MAX_BUFFER_LEN 250

#include "Data.h"
#include "Dyn_Array.h"

class world;

class string{

public:

	char* str;

public:


	string(const char* src);
	~string();
	void strcpy_s(const char* src, uint max_str_len, char* dst);
	unsigned int str_len() const;
	bool str_cmp_S(const char* str2);
	int readsubject(world* worldp);
	int readaction();
	dyn_array<string*>* string::tokenize();
	uint str_len_char(const char* src) const;


};








#endif
