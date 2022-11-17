// ROTAÇÃO SIMPLES A DIREITA

No* rsd(No* no) {
 	No* pai = no->pai;
 	No* esquerda = no->esquerda;

 	no->esquerda = esquerda->direita;
 	no->pai = esquerda;

 	esquerda->direita = no;
 	esquerda->pai = pai;

 	return esquerda;
}
