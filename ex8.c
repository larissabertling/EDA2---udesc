#include <stdio.h>


int main(){
	
	int sequencia(char s[]) {
	int t, i, n;
    char pilha[n]; 

    t = 0;
    
    for (i = 0; s[i] != '\0'; ++i) {
      switch (s[i]) {
         case ')': if (t == 0) {
					return true;
		}	
		break;
		}
        if (pilha[--t] != '('){
            return false;
		}
            	break;
	
        case ']': if (t == 0) {
			return true;
			}break;
		 }
        if (pilha[--t] != '[') {
            return false; 	
             break;
			}
         default:  pilha[t++] = s[i];
      }
   }
   return t == 0;
}

	
