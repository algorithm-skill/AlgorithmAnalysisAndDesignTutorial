#include <stdio.h>


//��¥��
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
    printf("��%d��¥����%d�ַ���\n", n, up(n));
}           
