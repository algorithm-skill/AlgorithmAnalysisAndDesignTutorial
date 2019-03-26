/*整数x的n次幂*/
#include <stdio.h>

int power (int x, int n)
{
    if(n == 0)
        return 1;
    else
    {
        int y = power(x, n / 2);
        y = y * y;
        if(n % 2 == 1)
            y = y * x;
        return y;
    }
}

void main()
{
    printf("%d\n", power(2,20));
}