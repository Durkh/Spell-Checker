#pragma once

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define NUM_BUCKS 300000

typedef struct tmp {
	char palavra[50];
	struct tmp* next;
}node;

unsigned long Key(char* str);
void Insert(char* palavra);
int Find(char* palavra);
void Diagnose();
