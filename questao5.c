#include <stdio.h>

int main(){
	
	int tam[A], tam [B];
	int M[m,n] = 0;
	int custo;
	
	for(int i=0; i<m; i++){
		M[i,0] =i;
	}
	
	for(int j=0; j<n; j++){
		M[0,j]=j;
	}
	for(i=1;i<m;i++){
		for(j=1;j<n;j++){
			if(A[i] == B[j]){
				custo =0;
			}else{
				custo =1;
			}
			M[i,j] == menor(M[i-1,j] +1, 
							M[i-1, j-1] + custo, 
								M[i,j-1] +1);
		}
	}
	return [m-1, n-1];
}
