#include <stdio.h>

//��A�ƶ���B
void move(char A, char B)
{
    printf("%c-->%c\n", A, B);
}

//n�����ӣ���A�ƶ���B������C
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