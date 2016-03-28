#ifndef __ENTITY_H__
#define __ENTITY_H__


#include "globals.h"
#include "string.h"
#include <stdio.h>

class item;

class entity{

public:

	char* name;
	char* desc;
	item** content;
	bool iscontainer;
	int containerlen;


public:



	void look(){


		printf("\n%s, %s", name, desc);

	}


	int getobjectcode(char* objname){

		int i;

		for (i = 0; i < containerlen && content[i] != NULL; i++){

			if (stringmanager.strcmp(content[i]->name, objname)){

				return(i);

			}
		}

		return(-1);
	}


	bool put(item* object){

		int i;

		for (i = 0; i < containerlen; i++){

			if (content[i] == NULL){

				content[i] = object;
				return(SUCCESS);
			}
		}

		return(ERROR);

	}

	bool erase(int objcode){

		if (objcode != -1){

			content[objcode] = NULL;


			return(SUCCESS);
		}
		else{

			return(ERROR);
		}

	}



	void moveitem(item* obj, entity* oldcontainer, int objcode){

		if (put(obj)){

			if (oldcontainer->erase(objcode)){

				printf("\nOperation done!");
				return;
			}

			printf("Error erasing item!");
			return;

		}

		printf("\nFull container! Try emptying it before");
		return;

	}

}


#endif //_ENTITY_H_