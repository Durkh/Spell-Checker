//
// Created by iogos on 05/04/2020.
//

#include "archive.h"

/*
void write(char str[]){
    FILE *file;

    file = fopen("C:\\Users\\iogos\\Desktop\\Str.txt", "w");

    fprintf(file, "%s", str);

    fclose(file);
}*/

void GetDic(){
    FILE *file;
    char str[30];

    file = fopen("ascii_noaccent_noduplicates_FIXED_v2", "r");

    if(file == NULL){
        strcpy(string, "NULL");
    }

    while (fgets(str, sizeof(str), file) != NULL){
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == '\n')
                str[i] = '\0';
        }
        Insert(str);
    }

    fclose(file);
}
