#include <stdio.h>
#include <string.h>
#define N 100
int a[N][N], n, e;            //��ͼ���ڽӾ����ʾ������ ������������
int x[N], sum;                //��������������
int bestn;                    //����������

//Լ������
int Constr(int t)
{
    int tmp = 1;
    for(int i = 1; i < t; i++)
    {
        if (x[i] && a[t][i] == 0) {                 //�����Ѿ����뼯�ϵĶ��㣬�����жϱ��Ƿ����
        // if (x[i] != 1 || a[i][t] != 1) {         //����޽纯��������
            tmp = 0;
            break;
        }
    }
    printf("Constr: %d\n", tmp);
    return tmp;
}

void Backtrack(int i)
{
    if (i > n) {
        bestn = sum;
        return;
    }
    if (Constr(i)) {            // ����Լ������
        sum += 1;
        x[i] = 1;
        Backtrack(i+1);
        sum -= 1;
        // x[i] = 0;            //���ܷ��������Ϊ�����Ǳ����ýڵ�������������Ұ����ýڵ㣬��ʱ�ýڵ㻹�ǿ�ѡ��
    }
    if((n - i + sum) > bestn)   //��������޽���������չ����������ô��ʱ�ýڵ��û����
    {
        x[i] = 0;
        Backtrack(i+1);
    }
}



void main()
{
    printf("�������������");
    scanf("%d", &n);

    printf("�����������");
    scanf("%d", &e);

    int u, v;                   //��ʱ����ͼ���������Ķ�Ӧ��ϵ

    //��ʼ��
    sum = 0, bestn = 0;
    memset(x, 0, 100 * sizeof(int));
    memset(a, 0, 100 * sizeof(int));


    for(int i = 1; i <= e; i++)
    {
        printf("�������%d���ߵ������˵㣺", i);
        scanf("%d %d", &u, &v);
        a[u][v] = 1, a[v][u] = 1; 
    }

    printf("�ڽӾ���Ϊ��\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    

    for(int i = 1; i <= n; i++)
        printf("%d\t", x[i]);
    printf("\n");
    Backtrack(1);

    for(int i = 1; i <= n; i++)
        printf("%d\t", x[i]);

    printf("���������ӵ�������Ϊ��%d\n", bestn);
    printf("��ԱΪ��\n");
    for(int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d\t", i);
    for(int i = 1; i <= n; i++)
        printf("\n%d\t", x[i]);
}