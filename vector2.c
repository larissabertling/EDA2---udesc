#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *v, *nv, n, prod = 1;

    printf("\nTamanho do vetor: ");
    scanf("%i", &n);

    v = malloc(sizeof(int)*n);
    nv = malloc(sizeof(int)*n);

    printf("\n\nDigite os valores: \n");

    for(int i = 0; i < n; i++){
        printf("%i: ", i);
        scanf("%i", &v[i]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                prod *= v[j];
            }
        }
        nv[i] = prod;
        prod = 1;
    }

    printf("\n[");
    for(int i = 0; i < n; i++){
        printf("%i, ", nv[i]);
    }
    printf("]\n\n");

    return 0;
}