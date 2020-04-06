//
// Created by iogos on 05/04/2020.
//

#include "archive.h"

unsigned long int totalPalavras = 0;
unsigned long int failed = 0;
unsigned long int palavrasDic = 0;

void CmpFile(){
    FILE *file;
    char str[40];

    file = fopen("constituicao_final_lindinha_e_bem_tratada.txt", "r");

     if(file == NULL){
        printf("error file 2");
        return;
    }
    while (fscanf(file,"%s", str) != EOF){
        if(str[0] == '-') continue;
        totalPalavras++;
        if(!Find(str)){
            failed++;
        }
    }

    fclose(file);
}

void GetDic(){
    FILE *file;
    char str[40];

    file = fopen("ascii_noaccent_noduplicates_FIXED_v2.txt", "r");

    if(file == NULL){
        strcpy(str, "NULL");
    }
    while (fgets(str, sizeof(str), file) != NULL){
    	palavrasDic++;
        for(int i = 0; i < strlen(str); i++){
        	if(str[i] == '\r')
            str[i] = '\0';
        }
    	/*if(palavrasDic == 178059)
    		puts("a");*/
        Insert(str);
    }

    printf("Número de palavras carregadas no Dicionário: %lu\n", palavrasDic);
    fclose(file);
}
