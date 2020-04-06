#include "hash.h"

node* Hash[NUM_BUCKS];

unsigned long Key(char* str){

	//return ((~(strlen(str) >= 4? (str[0] & str[strlen(str)-1]) ^ str[1]: (str[0] & str[strlen(str)-1]) )) * strlen(str)) % NUM_BUCKS;
	
	unsigned long hash = 5381;
	int c;

	while (c = *str++)
		hash = ((hash << 5) + hash) + c;

	return hash % NUM_BUCKS;
}

void Insert(char* palavra){
	
	int key = Key(palavra);

	if(Hash[key] == NULL){
		Hash[key] = malloc(sizeof(node));
		strcpy(Hash[key]->palavra, palavra);
	}else{
		node** p = &Hash[key]->next;
		
		while(1){
			if(*p == NULL){
				*p = malloc(sizeof(node));
				strcpy((*p)->palavra, palavra);
				return;
			}else
			p = &(*p)->next;
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
			node** p = &Hash[key]->next;
			while(*p != NULL){
				if(!strcmp((*p)->palavra, palavra))
					return 1;
				p = &(*p)->next;
			}

		}
	}
	return 0;
}

void Diagnose(){
 
    unsigned long int f0 = 0;
    unsigned long int f1 = 0;
    unsigned long int f2 = 0;
    unsigned long int f5 = 0;
    unsigned long int f10= 0;
    unsigned long int f50= 0;
    unsigned long int f100= 0;
    unsigned long int f4= 0;
    unsigned long int f3= 0;

    
    for(unsigned int i = 0; i < NUM_BUCKS; i++){
        
        if(Hash[i] == NULL) f0++;
        
        else if(Hash[i]->next == NULL) f1++;
        
        else {
            unsigned long int j = 1;
            node* p = Hash[i];
            while(p != NULL){
                p = p->next;
                j++;
            }


            if(j>=100) f100++;
            else if(j>=50) f50++;
            else if(j>=10) f10++;
            else if(j>=5) f5++;
            else if(j>=4) f4++;
            else if(j>=3) f3++;
            else if(j>=2) f2++;
        }
    
    }
    
    puts("Diagnóstico:\n\nBuckets: ");
    printf("Zero: %lu\nUm: %lu\nDois: %lu\nTres: %lu\nQuatro: %lu\nCinc: %lu\nDez: %lu\n\n", f0,f1,f2,f3,f4,f5,f10);
    
    puts("Porcentagens:");
    printf("zero%%: %.2lf\num%%: %.2lf\ndois%%: %.2lf\ntres%%: %.2lf\nquatro%%: %.2lf\ncinco%%: %.2lf\n", ((double)f0*100)/307856, ((double)f1*100)/307856, ((double)f2*100)/307856, ((double)f3*100)/307856, ((double)f4*100)/307856, ((double)f5*100)/307856 );
}
