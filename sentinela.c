
int pesquisaSequencialSentinela(int chave, int v[], int n) {
	
	int i = 0, contador=0;
 	v[n] = chave; //A �ltima posi��o do vetor possui o sentinela
 
 	while (v[i] != chave) {
 		contador++;
 		i++;
 	
	}
 	
	 if (i < n) {
	 	
	 	return i;
 	}
	 
	return contador; 
}
