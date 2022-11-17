
int pesquisaBinaria(int chave, int v[], int n) {
	int inicio = 0, meio, fim = n – 1;
	int contador = 0;
 	
	 while (inicio <= fim) {
	 	contador++;
 		meio = (inicio + fim) / 2;
 
 	if (chave < v[meio]) {
 		fim = meio - 1;
 
 	} else if (chave > v[meio]) {
 		inicio = meio + 1;
 	
	} else {
 		return contador;
 	}
 	}
 
 	return -1; //Índice impossível
}

