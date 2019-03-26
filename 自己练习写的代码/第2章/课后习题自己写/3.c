#include <stdio.h>

int Fibonacci(int n)
{
    if(n < 0)
        return -1;
    if (n == 0 || n == 1)
        return n;
    else
        return Fibonacci(n-1) + Fibonacci(n-2);
    
    
}

// 0 1 1 2 3 5 8
void main()
{
    printf("%d\n", Fibonacci(5));
}