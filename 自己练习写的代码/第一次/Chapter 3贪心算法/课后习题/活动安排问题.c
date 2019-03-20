#include <stdio.h>
typedef struct 
{
    double s, f;                //��Ŀ�ʼʱ��ͽ���ʱ��
} Activity;

Activity activity[10000];
int x[10000];                   //������

void swap(Activity activity[], int index1, int index2)
{
    Activity act = activity[index1];
    activity[index1] = activity[index2];
    activity[index2] = act;
}

int partition(Activity activity[], int low, int high)
{
    Activity pivot = activity[low];
    while(low < high){
        while((low < high) && (pivot.f <= activity[high].f))
            high--;
        swap(activity, low, high);
        while((low < high) && (pivot.f >= activity[low].f))
            low++;
        swap(activity, low, high);
    }
    return low;
}

void quickSort(Activity activity[], int low , int high)
{
    if (low < high) {
        int actNum = partition(activity, low, high);
        quickSort(activity, low, actNum-1);
        quickSort(activity, actNum+1, high);
    }
}

void main()
{
    int n;
    printf("�������ĸ�����");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        printf("������%d�Ŀ�ʼʱ��ͽ���ʱ�䣺", i);
        scanf("%lf %lf", &activity[i].s,  &activity[i].f);
    }

    //���ջ����ʱ��Ի��������
    quickSort(activity, 1, n);
    x[1] = 1;
    int temp = activity[1].f;           //�洢��һ��ѡ�������ʱ��
    for(int i = 2; i <= n; i++)
    {
        if (activity[i].s >= temp) {
            x[i] = 1;
            temp = activity[i].f;
        }
        else
            x[i] = 0;
    }

    printf("ѡ��Ļ�����У�");
    for(int i = 1; i <= n; i++)
    {
        if (x[i] == 1) 
            printf("%d\t", i); 
    }
}