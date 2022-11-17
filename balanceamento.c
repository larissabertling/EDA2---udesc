//BALANCEAMENTO RUBRO - NEGRA

void balancear(Arvore* arvore, No* no) {
 while (no->pai->cor == Vermelho) { //Garante que todos os n�veis foram balanceados
 if (no->pai == no->pai->pai->esquerda) {
 No *tio = no->pai->pai->direita;

 if (tio->cor == Vermelho) {
 tio->cor = Preto; //Resolve caso 2
 no->pai->cor = Preto;
 no->pai->pai->cor = Vermelho;
 no = no->pai->pai; //Vai para o n�vel anterior
 } else {
 if (no == no->pai->direita) {
 no = no->pai; //Vai para o n�vel anterior
 rotacionarEsquerda(arvore, no); //Resolve caso 3
 } else {
 no->pai->cor = Preto; //Resolve caso 4
 no->pai->pai->cor = Vermelho;
 rotacionarDireita(arvore, no->pai->pai);
 }
 }
 } else {
 //Repete o mesmo c�digo do bloco if, invertendo o lado dos direita e esquerda
 }
 }
 arvore->raiz->cor = Preto; //Resolve caso 1
}


// ROTA��O � ESQUERDA

void rotacionarEsquerda(Arvore* arvore, No* no) {
 No* direita = no->direita;
 no->direita = direita->esquerda;
 if (direita->esquerda != arvore->nulo)
 direita->esquerda->pai = no; //Se houver filho � esquerda em direita, ele ser� pai do n�
 direita->pai = no->pai; //Ajusta no pai do n� � direita

 if (no->pai == arvore->nulo)
 arvore->raiz = direita; //Se n� for raiz, o n� direita ser� a nova raiz da �rvore
 else if (no == no->pai->esquerda)
 no->pai->esquerda = direita; //Corrige rela��o pai-filho do novo pai (esquerda)
 else
 no->pai->direita = direita; //Corrige rela��o pai-filho do novo pai (direita)
 direita->esquerda = no; //Corrige rela��o pai-filho entre o n� piv� e o n� � direita
 no->pai = direita;
}

// ROTA��O � DIREITA

void rotacionarDireita(Arvore* arvore, No* no) {
 No* esquerda = no->esquerda;
 no->esquerda = esquerda>direita;
 if (esquerda->direita != arvore->nulo)
 esquerda->direita->pai = no; //Se houver filho � direita em esquerda, ele ser� pai do n�
 esquerda->pai = no->pai; //Ajusta no pai do n� � esquerda

 if (no->pai == arvore->nulo)
 arvore->raiz = esquerda; //Se n� for raiz, o n� esquerda ser� a nova raiz da �rvore
 else if (no == no->pai->esquerda)
 no->pai->esquerda = esquerda; //Corrige rela��o pai-filho do novo pai (esquerda)
 else
 no->pai->direita = esquerda; //Corrige rela��o pai-filho do novo pai (direita)
 esquerda>direita = no; //Corrige rela��o pai-filho entre o n� piv� e o n� � esquerda
 no->pai = esquerda;
}
