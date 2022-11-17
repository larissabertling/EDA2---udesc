#include <stdio.h>
 
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
 

int numEscadas(int s)
{
    return fib(s + 1);
}
 

int main()
{
    int s = 4;
    printf("Qntd de maneiras = %d", numEscadas(s));
    getchar();
    return 0;
}


