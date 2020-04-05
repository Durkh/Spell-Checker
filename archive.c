//
// Created by iogos on 05/04/2020.
//

#include "archive.h"

void write(char str[]){
    FILE *file;

    file = fopen("C:\\Users\\iogos\\Desktop\\Str.txt", "w");

    fprintf(file, "%s", str);

    fclose(file);
}

void read(char* string){
    FILE *file;
    char str[sizeof(string)];

    file = fopen("C:\\Users\\iogos\\Desktop\\Str.txt", "r");

    if(file == NULL){
        strcpy(string, "NULL");
    }

    while(fgets(str, sizeof(str), file) != NULL)
        strcat(string, str);

    fclose(file);
}
