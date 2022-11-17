#include <stdio.h>

int tamanhoLuvas(int tam[], int n){
	 int cont = 0;
	 
	  ordena(tam, tam + n);
	  
	   for (int i = 0; i< n-1; i++) {
	   	if (tam[i] == tam[i + 1]) {
            cont++;
            i = i + 2;
        }
    
        else {
            i++;
	 	}
	
	 return cont;
	}
}

int main()
{
    int tam[] = {2,5,7,6,4,5,7,2};
    int n = sizeof(tam) / sizeof(tam[0]);
    tamanhoLuvas(tam, n);
 
 	printf("Quantidade de pares de luvas é %d com tamanho %d e %d. \n", n, tam, tam);
 
    return 0;
}
