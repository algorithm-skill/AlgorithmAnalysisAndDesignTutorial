#include <stdio.h>

int stairsKind(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    else
        return stairsKind(n-1) + stairsKind(n-2);
}

int main()
{
    printf("��%d�ַ�����¥��\n", stairsKind(6));
}