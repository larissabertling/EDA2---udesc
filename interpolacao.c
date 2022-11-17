
int pesquisaInterpolacao(int chave, int v[], int n) {
 
 	int inicio = 0, meio, fim = n – 1;
 	int contador=0;
 
 	while (ini <= fim) {
 		meio = ini + ((fim - ini) * (chave - v[ini])) / (v[fim] - v[ini]);
 
 	if (chave < v[meio]) {
 		fim = meio - 1;
 
 	} else if (chave > v[meio]) {
 		ini = meio + 1;
 	
	 } else {
 		return meio;
 	}
 	}
 	return -1; //Índice impossível
}

