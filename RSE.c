// ROTAÇÃO SIMPLES A ESQUERDA RSE

No* rse(No* no) {
 	No* pai = no->pai;
 	No* direita = no->direita;

 	no->direita = direita->esquerda;
 	no->pai = direita;
 	direita->esquerda = no;
 	direita->pai = pai;

 	return direita;
}
