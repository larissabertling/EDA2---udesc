#include <stdio.h>

 
void printRLE(string str){
    int n = str.length();
    for (int i = 0; i < n; i++) {
 
        int cont = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            cont++;
            i++;
        }
 
 		printf("str %s: ");
    }
}
 
int main(){
    string str = "wwwwaaadexxxxxxywww";
    printRLE(str);
    return 0;
}


