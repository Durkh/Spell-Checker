#include <stdio.h>

int main(){

    FILE *fp;
    FILE *otp;
    int k;

    fp = fopen("constituicao_compilada_noaccent_nosymbols_nonumbers_nonewlines.txt", "r");
    otp = fopen("constituicao_final_lindinha_e_bem_tratada.txt", "w+");

    if( !fp && !otp){
        puts("file error");
        return -1;
    }

    char str[1025];
    char aux[1025];

    while(fgets(str, 1024, fp) != NULL){

        k = 0;

        for(int i = 0; str[i] != '\0'; i++){
            if(str[i] == ' '){
            	aux[k] = '\n';
            	k++;
            	while(str[i] == ' ')
            		i++;
            }
            aux[k] = str[i];
            k++;
        }
        aux[k] = '\0';
        if(!fprintf(otp, "%s", aux)){
            return -1;
        }
    }

    fclose(fp);
    fclose(otp);

}
