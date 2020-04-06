#pragma once

#include <stdlib.h>
#include <string.h>

#define NUM_BUCKS 5000

typedef struct tmp {
	const char palavra[50];
	struct tmp* next;
}node;

int Key(char* str);
void Insert(char* palavra);
int Find(char* palavra);
