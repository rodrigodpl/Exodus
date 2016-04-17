#ifndef _STRING_H_
#define _STRING_H_

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
	uint str_len() const;
	bool str_cmp_S(const char* str2) const;
	int readsubject(world* worldp) const;
	int readaction() const;
	dyn_array<string*>* string::tokenize();
	uint str_len_char(const char* src) const;

};








#endif
