<<<<<<< HEAD
#include "archive.h"

int main() {

	/*
	char arr[][50] = { "Egidio", "egidio", "a", "arr", "teste", "test", "achar" };

	puts("keys: ");
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		printf("key = %d\n", Key(arr[i]));
	}
	puts("-------------------------------------------------------------------------");

	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
		Insert(arr[i]);
	}


	if (Find(arr[0]))
		puts("1/5 pass");

	if (!Find("rik"))
		puts("2/5 pass");

	if (Find(arr[2]))
		puts("3/5 pass");

	if (Find(arr[6]))
		puts("4/5 pass");

	if (!Find("YTPBR"))
		puts("5/5 pass"); */

	GetDic();

}
=======
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define NUM_BUCKS 500

typedef struct tmp{
    const char palavra[50];
    struct tmp* next;
}node;

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

int main(){

    double time = 0;
    char arr[][50] = {"Egidio", "egidio", "a", "arr", "teste", "test", "achar" };


    time = clock();
    puts("keys: ");
    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        printf("key = %d\n", Key(arr[i]));
    }
    puts("-------------------------------------------------------------------------");

    for(int i=0; i< sizeof(arr)/sizeof(arr[0]); i++){
        Insert(arr[i]);
    }


    if(Find(arr[0]))
        puts("1/5 pass");

    if(!Find("rik"))
        puts("2/5 pass");

    if(Find(arr[2]))
        puts("3/5 pass");

    if(Find(arr[6]))
        puts("4/5 pass");

    if(!Find("YTPBR"))
        puts("5/5 pass");

    time = clock() - time;

    printf("%lf SECONDS", time/CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 301a0399adbd89ac91e50667eb98b353f390dec7
