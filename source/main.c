#include "archive.h"
#include "hash.h"
#include <time.h>

int main(){

    double time = 0;
    
    GetDic();

    time = clock() - time;
    
    //Diagnose();
/*
    if(Find("encorrelhar"))
		puts("1/5 pass");
	
	if(Find("lentilhao"))
		puts("2/5 pass");

	if(Find("lentilhas-do-campo"))
		puts("3/5 pass");
	
	if(Find("presidente-castelo-branquense"))
		puts("4/5 pass");

	if(Find("simpiezometrico"))
		puts("5/5 pass");*/

    
    CmpFile();
    printf("Número total de palavras no texto: %lu\n", totalPalavras);
    printf("Tempo total da verificação: %lfms\n", (time/CLOCKS_PER_SEC)/1000);
    printf("Número de palavras que falharam no spell check: %lu\n", failed);

    return 0;
}
