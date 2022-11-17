//FATOR DE BALANCEAMENTO


int fb(No* no) {
 	int esquerda = 0,direita = 0;

 	if (no->esquerda != NULL) {
 		esquerda = altura(no->esquerda) + 1;
	}
	
 	if (no->direita != NULL) {
 		direita = altura(no->direita) + 1;
	}

 	return esquerda - direita;
}
