#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *v, k, n;

    printf("\nTamanho do vetor: ");
    scanf("%i", &n);

    v = malloc(sizeof(int)*n);

    printf("\n\nDigite os valores: \n");

    for(int i = 0; i < n; i++){
        printf("%i: ", i);
        scanf("%i", &v[i]);
    }

    printf("\nDigite o valor para k: ");
    scanf("%i", &k);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(v[i] + v[j] == k){
                printf("True\n");
                return 0;
            }
        }
    }

    printf("False");

    return 0;
}