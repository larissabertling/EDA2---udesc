#include <stdio.h>
#include <string.h>

int main(void){
    char str1[20], str2[20]; 
    int i, cont = 0;

    scanf(" %s", str1);
    scanf(" %s", str2);

    if(strlen(str1) > strlen(str2)){
        for(i = 0; i < strlen(str1); i++){
            if(i < strlen(str2)){
                if(str1[i] != str2[i])
                    cont++;
            }else{
                cont++;
            }
        }  
    }
    else{
        for(int i = 0; i < strlen(str2); i++){
            if(i < strlen(str1)){
                if(str1[i] != str2[i])
                    cont++;
            }else{
                cont++;
            }
        }
    }

    printf("%i\n", cont);

    return 0;
}