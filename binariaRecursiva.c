
int pesquisaBinariaRecursiva(int chave, int v[], int ini, int fim) {
	
	int meio = (ini + fim) / 2;
 
 	if (ini > fim){
 		return -1;
 	}
 	
	 if (chave == v[meio]){
	 	 return meio;
	}
 
 	else if (chave < v[meio]){
	 	return pesquisaBinariaRecursiva(chave, v, ini, meio - 1);
 	
	 }else{
 		return pesquisaBinariaRecursiva(chave, v, meio + 1, fim);	
	}
}
