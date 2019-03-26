#include <stdio.h>
typedef struct {
    int x, y;       //�ֱ��ʾ��ҵ�ڵ�1�������ļӹ�ʱ�䣬�͵�2�������ļӹ�ʱ��
} Work;

int best[10000], bestf = 65535;  //�ֱ��¼���ŵ���ҵ���,  Ŀǰ��С���ʱ��
int n, f1 = 0, f2 = 0;         //��¼��ҵ�������ֱ��¼����1�����ʱ��ͻ���2�����ʱ��
Work workList[10000];

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void backtrack(int t)
{
    //�����������ҵ����ֱ�����
    if(t > n)
    {
        for(int i = 1; i <= n; i++)         //�����������
            printf("%d \t", best[i]);
        printf("\n");
    }

    for(int i = t; i <= n; i++)
    {
        if ((max(f1 + workList[i].x, f2) + workList[i].y) < best) {
            swap(best, i, t);
            backtrack(t+1);
            swap(best, i, t);
        }
    }
}

void main()
{
    int n;
    printf("��������ҵ�ĸ�����");
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        printf("��������ҵ%d�ڻ���1�ӹ��ͻ���2�ӹ������ʱ�䣺", i);
        scanf("%d %d", &workList[i].x, &workList[i].y);
    }
    
    backtrack(1);
}