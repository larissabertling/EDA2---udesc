#include <stdio.h>
#include <stdlib.h>

typedef estrutura não {
    struct no* pai; //ponteiro para o nó pai
    struct no* esquerda; //ponteiro para o nó filho a esquerda
    struct não* direita; //ponteiro para o nó filho a direita
    valor int; //conteúdo de um nó arbitrário da árvore
} Não;

typedef struct arvore {
    struct no* raiz;
} Árvore;

Arvore* criar() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    retornar um;
}

No* adicionar(Arvore* arvore, No* pai, int valor) {
    Não *não = (Não*) malloc(sizeof(No));

    não->pai = pai;
    não->valor = valor;

    não->esquerda = NULL;
    não->direita = NULL;
  
    if (pai == NULL) {
        arvore->raiz = não;
    }

    retornar não;
}

int unival(Não *não, int *contador) {
    int esq = 1,dir = 1;
    
    if (não->esquerda != NULL) {
        esq = unival(no->esquerda, contador);

        if (não->esquerda->valor != não->valor)
            eq = 0;
    }

    if (não->direita != NULL) {
        dir = unival(no->direita, contador);

        if (não->direita->valor != não->valor)
            dir = 0;
    }

    if (esq && dir)
        (*contador)++;

    return esq && dir;
}

int main(){
    Arvore *a = criar();

    Não *no1 = adicionar(a,NULL,0);
    
    Não *no2 = adicionar(a,no1,1);
    Não *no3 = adicionar(a,no1,1);
    
    no1->esquerda = no2;
    no1->direita = no3;

    Não *no4 = adicionar(a,no3,1);
    Não *no5 = adicionar(a,no3,1);

    no3->esquerda = no4;
    no3->direita = no5;

    Não *no6 = adicionar(a,no4,1);
    Não *no7 = adicionar(a,no4,1);

    no4->esquerda = no6;
    no4->direita = no7;

    contador = 0;
    unival(no1, &contador);
    printf("Contador: %d\n", contador);
}
