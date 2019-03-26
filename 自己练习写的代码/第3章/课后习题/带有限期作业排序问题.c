//最优解对应的贪心策略：按照效益值从大到小进行排序选择作业

#include <stdio.h>

typedef struct {
    double d;           //作业的截止完成时间
    double p;           //作业在截止时间完成所产生的效益
} Work;

Work workList[1000];    //作业列表
int x[1000];            //对应的解向量

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
    printf("请输入作业的个数：");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("请输入作业%d的截止时间以及效益：", i);
        scanf("%lf %lf", &workList[i].d, &workList[i].p);
    }
    //对作业按照效益值从小到大进行排序
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