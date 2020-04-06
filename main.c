#include "archive.h"
#include <time.h>

int main(){

    double time = 0;
    
    GetDic();

    time = clock() - time;

    cmpFile();
    printf("Número total de palavras no texto: %lu", totalPalavras);
    printf("Tempo total da verificação: %lfms", (time/CLOCKS_PER_SEC)/1000);
    printf("Número de palavras que falharam no spell check: %lu", failed);
    
    return 0;
}
