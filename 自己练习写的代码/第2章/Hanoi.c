#include <stdio.h>

//从A移动到B
void move(char A, char B)
{
    printf("%c-->%c\n", A, B);
}

//n个盘子，从A移动到B，借助C
void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
        move(A, B);
    else
    {
        hanoi(n-1, A, C, B);
        move(A, B);
        hanoi(n-1, C, B, A);
    }
}


void main()
{
    hanoi(3, 'A', 'B', 'C');
}