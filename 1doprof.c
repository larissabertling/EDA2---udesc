#include <stdio.h>

int main(){
	
   int v[] = {10,15,3,7};
   int k =17;
   int n = 4;
   
   
   Dict* dict = cria();
   
   for (int i=0; i<n; i++){ //N
   	put(dict,v[i], i);
   }
   
   
	for(int i = 0; i < n -1; i++){ //N -> sequencial
		int vj = k- v[i];
		
		int j = get(dict,vj); //1 -> direto
		
		if (j < n && v[j] == vj){
			printf("%d %d\n", i,j);
			printf("true\n");
			return 0;
		}
	}

		printf("false\n");
}
