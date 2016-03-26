#ifndef __STRING_H__
#define __STRING_H__


#include "globals.h"
#include <stdio.h>

class string{

public:

	void strcpy(char* src, char* dst){

		while (*(src + 1) != 0){
			*dst = *src;
			dst++, src++;
		}

		*(dst + 1) = 0;

	}


	bool strcmp(char* str1, char* str2, int len){

		int i;

		for (i = 0; i < len; i++){

			if (str1[i] != str2[i]){

				return(0);
			}

		}

		return(1);

	}


	char* stringsplit(char* nounbuffer){

		int i, j, k, z = 0;
		char* auxbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];



		for (i = 0; i < VERB_AND_NOUN_BUFFER_LEN; i++){


			//extract the first word
			if (nounbuffer[i + 1] == EOF){

				return(ERROR);
			}

			else if (nounbuffer[i + 1] == SPACE_KEY){

				nounbuffer[i + 1] = EOF;


				//ignore the preposition
				for (j = i; j < VERB_AND_NOUN_BUFFER_LEN; j++){

					if (nounbuffer[j + 1] == EOF){

						return(ERROR);
					}

					else if (nounbuffer[j + 1] == SPACE_KEY){

						//exctract the second word
						for (k = j; k < VERB_AND_NOUN_BUFFER_LEN && nounbuffer[k] != EOF; k++){

							auxbuffer[z] = nounbuffer[k];
							z++;

						}

						return(auxbuffer);

					}
				}




			}
		}

		return(ERROR);

	}



	int readcommand(char* command){

		char* verbbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		verbbuffer[0] = EOF;
		char* nounbuffer = new char[VERB_AND_NOUN_BUFFER_LEN];
		nounbuffer[0] = EOF;

		int i = 0, j = 0;

		while (command[i + 1] != EOF){

			verbbuffer[i] = command[i];

			if (command[i + 1] != SPACE_KEY){

				i += 2;

				while (command[i + 1] != EOF){

					nounbuffer[j] = command[i];
					i++, j++;
				}
				j++;
				nounbuffer[j] = 0;
			}

			i++;
		}

		i++;
		verbbuffer[i] = 0;

	}








};



#endif //__STRING_H__