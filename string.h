#ifndef __STRING_H__
#define __STRING_H__


#include "globals.h"
#include <stdio.h>




class string{

public:

	char* verbbuffer;
	char* nounbuffer;
	

	string(){

		verbbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		nounbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];

	}

	~string(){

		delete[] verbbuffer;
		delete[] nounbuffer;


	}

	friend class entity;
	friend class room;
	friend class passage;
	friend class item;
	friend class player;
	friend class world;


public:


	void strcpy(char* src, char* dst){

		while (*(src) != EOF){
			*dst = *src;
			dst++, src++;
		}

		*(dst + 1) = EOF;

	}



	int getline(char* src, char* dst, char delim, int index){

		int i, j = index;

		for (i = 0; i < MAX_BUFFER_LEN; i++) {

			src[index] = dst[i];
			index++;
			
			if (*(src) != delim && *(src) != EOF){
				dst[i] = EOF;
				return(i);

			}

		}

		printf("EOF or delim character not found!");
		return(0);
		
	}


	bool strcmp(char* str1, char* str2){

		int i;

		for (i = 0; i < MAX_BUFFER_LEN; i++){

			if (str1[i] != str2[i]){

				return(0);
			}

			if (str1[i] == EOF || str2[i] == EOF){

				break;
			}

		}

		return(1);

	}


	char* stringsplit(char* buffer){

		int i, j, k, z = 0;
		char* auxbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];



		for (i = 0; i < VERB_AND_NOUN_BUFFER_LEN; i++){


			//extract the first word
			if (buffer[i + 1] == EOF){

				return(ERROR);
			}

			else if (buffer[i + 1] == SPACE_KEY){

				buffer[i + 1] = EOF;


				//ignore the preposition
				for (j = i; j < VERB_AND_NOUN_BUFFER_LEN; j++){

					if (buffer[j + 1] == EOF){

						return(ERROR);
					}

					else if (buffer[j + 1] == SPACE_KEY){

						//exctract the second word
						for (k = j; k < VERB_AND_NOUN_BUFFER_LEN && buffer[k] != EOF; k++){

							auxbuffer[z] = buffer[k];
							z++;

						}

						return(auxbuffer);

					}
				}




			}
		}

		return(ERROR);

	}



	void readcommand(char* command){

		char* verbbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		verbbuffer[0] = EOF;
		char* nounbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		nounbuffer[0] = EOF;

		int i = 0, j = 0, k;

		while (command[i + 1] != EOF){

			verbbuffer[i] = command[i];

			if (command[i + 1] != SPACE_KEY){

				k = i + 1;
				i += 2;

				while (command[i + 1] != EOF){

					nounbuffer[j] = command[i];
					i++, j++;
				}
				
				nounbuffer[j + 1] = 0;
			}

			
		}
		
		verbbuffer[k] = 0;

	}








}stringmanager;



#endif //__STRING_H__