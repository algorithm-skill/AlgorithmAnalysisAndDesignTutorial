#include <stdio.h>


//上楼梯
int up(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;
    
    return up(n-1) + up(n-2);
}

void main()
{
    int n;
    scanf("%d", &n);
    printf("上%d层楼梯有%d种方法\n", n, up(n));
}           
