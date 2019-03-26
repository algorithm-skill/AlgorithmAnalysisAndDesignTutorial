/*ע�⣺N�ʺ���ⷽ��������ֻ��������п��н⣬��˲���Ҫд���Ž��Ӧ���޽纯��*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000
int x[N];           //�����N�еķŵ���X[N]��
int n, cnt;         //����ʵ�ʵĻʺ��������������

int Constr(int t)
{
    int status = 1;
    for(int i = 1; i < t; i++)
    {
        if(x[t] == x[i] || fabs(x[t] - x[i]) == (t -i))
            status = 0;
    }
    return status;
}


//�����㷨
void Backtrack(int t)
{
    if (t > n) {
        cnt += 1;
        printf("����%d��\n\t\t", cnt);
        for(int i = 1; i <= n; i++)
            printf("%d\t", x[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        x[t] = i;                   //�ٶ��ȷ��ڵ�i��
        if (Constr(t))              //�������Լ������
            Backtrack(t+1);
    }
}


void main()
{
    cnt = 0;
    printf("������ʺ������");
    scanf("%d", &n);            
    memset(x, 0, N * sizeof(int));
    Backtrack(1);
    printf("��%d�ַ�����\n", cnt);
}