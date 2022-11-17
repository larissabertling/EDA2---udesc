//ÁRVORES BINÁRIAS:

typedef struct no {
struct no* pai; //ponteiro para o nó pai
struct no* esquerda; //ponteiro para o nó filho a esquerda
struct no* direita; //ponteiro para o nó filho a direita
float v; //conteúdo de um nó arbitrário da árvore
} No;
typedef struct arvore {
struct no* raiz;
} Arvore;


// criar:

Arvore* cria() {
Arvore *arvore;
arvore = malloc(sizeof(Arvore));
arvore->raiz = NULL;

return arvore;
}

int vazia(Arvore* arvore) {
return (arvore->raiz == NULL);
}

// adicionar elemento:
No* adiciona(Arvore* arvore, No* pai, float valor) {
No *no = malloc(sizeof(No));
no->pai = pai;
no->esquerda = NULL;
no->direita = NULL;
no->valor = valor;

if (pai == NULL) {
arvore->raiz = no;
}
return no;
}

//remover elemento:
void remove(Arvore* arvore, No* no) {
 if (no->esquerda != NULL)
 remove(arvore, no->esquerda);

 if (no->direita != NULL)
 remove(arvore, no->direita);

 if (no->pai == NULL) {
 arvore->raiz = NULL;
 } else {
 if (no->pai->esquerda == no)
 no->pai->esquerda = NULL;
 else
 no->pai->direita = NULL;
 }
 free(no);
}

// percorrer:
void percorrer(No* no) {
 if (no != NULL) {
 printf("%f", no->valor);
 percorrer(no->esquerda);
 percorrer(no->direita);
 }
}

// BINÁRIA GENÉRICA:

typedef struct no {
struct no* pai; //ponteiro para o nó pai
struct no* esquerda; //ponteiro para o nó filho a esquerda
struct no* direita; //ponteiro para o nó filho a direita
void* valor; //conteúdo genérico do nó
} No;
typedef struct arvore {
struct no* raiz; //raiz da árvore
int tamanho; //tamanho do valor dos nós (em bytes)
} Arvore;

//CALLBACK
void percorrer(No* no, void (callback)(void*)) {
 if (no != NULL) {
 callback(no->v);
 percorrer(no->esquerda);
 percorrer(no->direita);
 }
}

void exibe(void* v) {
 float *f = (float*) f;
 printf("%f\n", v);
}
int main(int argc, char *argv[]){
 Arvore *a = cria();
 //insere valores na árvore...
 percorre(a->raiz, exibe); //passando a função como parâmetro
}




