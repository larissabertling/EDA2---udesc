#include <stdio.h>
#include <stdlib.h>

int maxSoma(v* int, int n)){

    int *v, n;
    
    if (n==1){
    	return v[0];
	}
	
	v[0][0] = 0;
	v[0][1] = v[0];
	
	for (i =1; i<n; i++){
		v[i][1] = v[i-1][0] + v[i];
		v[i][0] = max(v[i-1][1], v[i-1][0]);
	}
	
	return max(v[n-1][0], v[n-1][1]);
}

int main{
	
		v* = {5,8,10,100,10,5};
		int n = v.tam();
		
		printf("MaxSoma: %n");
		return 0;

}
