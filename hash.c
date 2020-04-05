#include "hash.h"

node* Hash[NUM_BUCKS];

int Key(char* str){
	
	return ((~(strlen(str) >= 4? (str[0] & str[strlen(str)-1]) ^ str[1]: (str[0] & str[strlen(str)-1]) )) * strlen(str)) % NUM_BUCKS;
}

void Insert(char* palavra){
	
	int key = Key(palavra);

	if(Hash[key] == NULL){
		Hash[key] = malloc(sizeof(node));
		strcpy(Hash[key]->palavra, palavra);
	}else{
		node* p = Hash[key]->next;
		
		while(1){
			if(p == NULL){
				p = malloc(sizeof(node));
				strcpy(p->palavra, palavra);
				return;
			}
			p = p->next;
		}
	}
}

int Find(char* palavra){

	int key = Key(palavra);

	if(Hash[key] == NULL)
		return 0;
	else{
		if(!strcmp(Hash[key]->palavra, palavra))
			return 1;
		else{
			node* p = Hash[key]->next;
			while(p != NULL){
				if(!strcmp(p->palavra, palavra))
					return 1;

				p = p->next;
			}

		}
	}
	return 0;
}