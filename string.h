#ifndef _STRING_H_
#define _STRING_H_

#define MAX_BUFFER_LEN 50

#include "Data.h"


class string{

public:

	char* str;

public:


	string(const char* src);
	string(const string& src);
	~string();
	void strcpy_s(const char* src, uint max_str_len, char* dst);
	unsigned int str_len() const;
	bool isempty() const;
	bool operator == (const string& str2);
	string split();
	void operator = (const string& str2);
	bool str_cmp_S(const char* str2);
	int readsubject();
	int readaction();
	uint str_len_char(const char* src) const;


};








#endif
