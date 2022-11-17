#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Codificação de comprimento de execução) é uma forma simples de R de textos (texto). UMA
 * ideia desta técnica é representar sucessivamente com um caracteres
 * seguido contador pelo caractere. Dada uma string, rendimentos o texto resultante
 * da aplicação da técnica RLE.
 * Exemplo, dado uma string "AAAABBBCCDAA", uma saída compactada deve ser "4A3B2C1D2A"
 */

char* rle(char* s) {
   	char *r = malloc(sizeof(char) * 50);

    caractere u = s[0];
    intc = 1;
    int = 0;

    int tamanho = strlen(s);
    
    for (int j = 1; j < tamanho; j++) {
        if (s[j] == u) {
            c++;
        } senão {
            char cc[50];
            sprintf(cc, "%d", c);

            int num = strlen(cc);

            for (int k = 0; k < num; k++) {
                r[i++] = cc[k];
            }
            
            r[i++] = u;
            
            u = s[j];
            c = 1;
        }
    }

    char cc[50];
    sprintf(cc, "%d", c);

    int num = strlen(cc);

    for (int k = 0; k < num; k++) {
        r[i++] = cc[k];
    }
    
    r[i++] = u;
 
    retornar r;
}

int main(){
	char* s = "AAAABBBCCDAA";
	
    printf("%s\n",s);
    printf("%s\n",rle(s));
}
