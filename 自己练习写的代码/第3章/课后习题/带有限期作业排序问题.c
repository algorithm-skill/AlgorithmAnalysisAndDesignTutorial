//���Ž��Ӧ��̰�Ĳ��ԣ�����Ч��ֵ�Ӵ�С��������ѡ����ҵ

#include <stdio.h>

typedef struct {
    double d;           //��ҵ�Ľ�ֹ���ʱ��
    double p;           //��ҵ�ڽ�ֹʱ�������������Ч��
} Work;

Work workList[1000];    //��ҵ�б�
int x[1000];            //��Ӧ�Ľ�����

void swap(Work workList[], int index1, int index2)
{
    Work temp = workList[index1];
    workList[index1] = workList[index2];
    workList[index2] = temp;
}

int partition(Work workList[], int low, int high)
{
    Work pivot = workList[low];
    while(low < high)
    {
        while((low < high) && (pivot.p <= workList[high].p))
            high--;
        swap(workList, low, high);
        while((low < high) && (pivot.p >= workList[low].p))
            low++;
        swap(workList, low, high);
    }

    return low;
}

void quickSort(Work workList[], int low, int high)
{
    printf("%d\n", high);
    if (low < high) {
        int part = partition(workList, low, high);
        quickSort(workList, low, part-1);
        quickSort(workList, part+1, high);
    }
}

void main()
{
    int n;
    printf("��������ҵ�ĸ�����");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("��������ҵ%d�Ľ�ֹʱ���Լ�Ч�棺", i);
        scanf("%lf %lf", &workList[i].d, &workList[i].p);
    }
    //����ҵ����Ч��ֵ��С�����������
    quickSort(workList, 1, n);

    for(int i = 1; i <= n; i++)
        printf("%lf\t", workList[i].p);
    
    x[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        while(x[i] == 1 && ){
            
        }
           
    }
    
    
}