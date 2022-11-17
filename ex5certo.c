#include <stdio.h>
#include <stdlib.h>

typedef estrutura n�o {
    struct no* pai; //ponteiro para o n� pai
    struct no* esquerda; //ponteiro para o n� filho a esquerda
    struct n�o* direita; //ponteiro para o n� filho a direita
    valor int; //conte�do de um n� arbitr�rio da �rvore
} N�o;

typedef struct arvore {
    struct no* raiz;
} �rvore;

Arvore* criar() {
    Arvore *a = (Arvore*) malloc(sizeof(Arvore));
    a->raiz = NULL;
    retornar um;
}

No* adicionar(Arvore* arvore, No* pai, int valor) {
    N�o *n�o = (N�o*) malloc(sizeof(No));

    n�o->pai = pai;
    n�o->valor = valor;

    n�o->esquerda = NULL;
    n�o->direita = NULL;
  
    if (pai == NULL) {
        arvore->raiz = n�o;
    }

    retornar n�o;
}

int unival(N�o *n�o, int *contador) {
    int esq = 1,dir = 1;
    
    if (n�o->esquerda != NULL) {
        esq = unival(no->esquerda, contador);

        if (n�o->esquerda->valor != n�o->valor)
            eq = 0;
    }

    if (n�o->direita != NULL) {
        dir = unival(no->direita, contador);

        if (n�o->direita->valor != n�o->valor)
            dir = 0;
    }

    if (esq && dir)
        (*contador)++;

    return esq && dir;
}

int main(){
    Arvore *a = criar();

    N�o *no1 = adicionar(a,NULL,0);
    
    N�o *no2 = adicionar(a,no1,1);
    N�o *no3 = adicionar(a,no1,1);
    
    no1->esquerda = no2;
    no1->direita = no3;

    N�o *no4 = adicionar(a,no3,1);
    N�o *no5 = adicionar(a,no3,1);

    no3->esquerda = no4;
    no3->direita = no5;

    N�o *no6 = adicionar(a,no4,1);
    N�o *no7 = adicionar(a,no4,1);

    no4->esquerda = no6;
    no4->direita = no7;

    contador = 0;
    unival(no1, &contador);
    printf("Contador: %d\n", contador);
}
