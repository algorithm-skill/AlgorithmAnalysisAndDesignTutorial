#include <stdio.h>


//将盘子从A移动到B
void move(char A, char B)
{
    printf("%c---->%c\n", A, B);
}

//将n个盘子从A移动到C 借助B
void hanoi(int n, char A, char B, char C)
{
    if(n == 1)
        move(A, C);
    else
    {
        hanoi(n-1, A, C, B);
        move(A, C);
        hanoi(n-1, B, A, C);
    }
}


void main()
{
    hanoi(3, 'A', 'B', 'C');
}