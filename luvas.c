#include <stdio.h>

int main(void){

    int n, i, cont = 0, aux = 0, aux2 = 0, pares, qtd_pares = 0;

    printf("Quantidade de luvas: ");
    scanf("%i", &n);

    int luvas[n], tam[n];

    for(int m = 0; m < n; m++){//ler tamanhos das luvas
        printf("- ");
        scanf("%i", &luvas[m]);
    }

    for(i = 0; i < n; i++){
        cont = 0;
        aux = 0;

        for(int j = i; j < n; j++){
            if(luvas[i] == luvas[j]){//achar as repetições
                cont++;
            }
        }

        for(int k = 0;k < i; k++){
            if(luvas[k]==luvas[i]){
                aux++;
            }
        }

        if (aux == 0){
            pares = cont/2;
            qtd_pares += pares;
            if(pares != 0){
                tam[aux2] = luvas[i];
                aux2++;
            }
        }
    }

    if (qtd_pares !=0){
        printf("%i par(es), tamanho(s) ",  qtd_pares);
        for(int l = 0; l < aux2; l++){
            printf(" %i -", tam[l]);
        }
        printf("\n");     
    }

    return 0;
}