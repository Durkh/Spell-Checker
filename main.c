#include "archive.h"
#include <time.h>

int main(){

    double time = 0;
    /*
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
        puts("5/5 pass"); */
    
    GetDic();

    time = clock() - time;

    printf("%lf SECONDS", time/CLOCKS_PER_SEC);
    return 0;
}
