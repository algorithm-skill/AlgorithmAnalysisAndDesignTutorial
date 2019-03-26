

/*Çó½×³Ë*/
#include <stdio.h>

int fact(int n)
{
    if(n == 0)
        return 1;
    else
        return n * fact(n-1);
}

void main()
{
    printf("5µÄ½×³ËÊÇ%d\n", fact(5));
}