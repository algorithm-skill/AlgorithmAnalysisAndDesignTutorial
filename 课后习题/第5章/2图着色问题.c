//�ο���https://wenku.baidu.com/view/7193073c7fd5360cba1adb85.html
#include <stdio.h>
#include <string.h>
#define N 3 //ͼ�н�����
int a[N+1][N+1] = {
    0,0,0,0,
    0,1,1,1,
    0,1,1,1,
    0,1,1,1
};  //�ڽӾ���
int x[N+1];     //��¼��ɫ
int sum = 0;
int OK(int t, int i)    //�жϺ���
{
    int j;
    for(j = 1; j < t; j++)
    {
        if(a[t][j]&&x[j]==i)
            return 0;
    }
    return 1;
}

void Backtrace(int t, int m)
{
    int i;
    if(t > N)   //�㷨������Ҷ�ӽ��
    {
        sum++;
        printf("��%d�ַ�����\n", sum);
        for(i = 1; i <= N; i++)
            printf("%d ", x[i]);
        printf("\n");
    }
    else
    {
        for(i = 1; i <= m; i++)
        {
            if(OK(t, i))
            {
                x[t] = i;
                Backtrace(t+1, m);
            }
        }   
    }
}

void main()
{
    int m, i;
    printf("��������ɫ���ࣺ\n");
    scanf("%d", &m);
    for(i = 1; i <= m; i++) //��ʼ��
        x[i] = 0;
    Backtrace(1, m);
    if(sum == 0)
        printf("����%d����ɫ��!\n", m);
}