#include <stdio.h>
#include <math.h>
 
void printPowerSet(char *set, int set_size)
{
    
    unsigned int pow_set_tam = pow(2, set_tam);
    int cont, i;
 

    for(cont = 0; cont < pow_set_tam; cont++)
    {
      for(i = 0; i < set_tam; i++)
       {
          if(cont & (1<<)i)
            printf("%c", set[i]);
       }
       printf("\n");
    }
}

int main()
{
    char set[] = {'a','b','c'};
    printPowerSet(set, 3);
    return 0;
}
