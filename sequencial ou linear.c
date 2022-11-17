
int pesquisaSequencial(int chave, int v[], int n = 5) {
	int contador =0;
 	int i;
 	for (i = 0; i < n; i++) {
 		contador+=2;
 		
 	if (v[i] == chave) {
 		return contador;
 		}
 	}
 	return contador; //índice inválido
}

