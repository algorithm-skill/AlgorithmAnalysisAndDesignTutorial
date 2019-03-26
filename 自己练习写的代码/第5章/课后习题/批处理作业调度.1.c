#include <stdio.h>
typedef struct {
    int x, y;       //�ֱ��ʾ��ҵ�ڵ�1�������ļӹ�ʱ�䣬�͵�2�������ļӹ�ʱ��
} Work;
int best[10000], bestf = 65535;  //�ֱ��¼���ŵ���ҵ���,  Ŀǰ��С���ʱ��
int n = 0, f1 = 0, f2 = 0;         //��¼��ҵ�������ֱ��¼����1�����ʱ��ͻ���2�����ʱ��
Work workList[10000];
int x[10000];
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
        for(int i = 1; i <= n; i++)
            best[i] = x[i];
        bestf = f2;
        return;
    }

    for(int i = t; i <= n; i++)
    {
        f1 += workList[x[i]].x;
        int temp = f2;
        f2 = max(f1 + workList[x[i]].x, f2) + workList[i].y;
        if (f2 < bestf) {
            swap(x, i, t);
            backtrack(t+1);
            swap(x, i, t);
        }
        f1 -= workList[x[i]].x;
        f2 = temp;
    }
}

void main()
{
    printf("��������ҵ�ĸ�����");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        best[i] = i;
        printf("��������ҵ%d�ڻ���1�ӹ��ͻ���2�ӹ������ʱ�䣺", i);
        scanf("%d %d", &workList[i].x, &workList[i].y);
    }
    
    backtrack(1);

    printf("�������żӹ�ʱ��Ϊ��");
    for(int i = 1; i <= n; i++)
        printf("%d ", x[i]);
    printf("\n���żӹ�ʱ��Ϊ%d\n", bestf);
    
    
}