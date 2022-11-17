// DUPLA ESQUERDA RDE

No* rde(No* no) {
 	no->direita = rsd(no->direita);
 	return rse(no);
}

