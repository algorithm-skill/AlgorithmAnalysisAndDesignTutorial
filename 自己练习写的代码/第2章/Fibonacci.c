#include <stdio.h>


//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233……（OEIS中的数列A000045）
int Fibonacci(int i)
{
    if(i < 0)
        return -1;
    if(i <= 1)
        return i;
    else
        return Fibonacci(i-1) + Fibonacci(i-2);
}


void main()
{
    printf("%d\n", Fibonacci(5));
}