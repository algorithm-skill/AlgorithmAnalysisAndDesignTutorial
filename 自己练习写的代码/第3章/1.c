/*贪心法求解背包问题*/
#include <stdio.h>
#include <malloc.h>

typedef struct {
    int m, v, count;           //货物的质量以及效益,放多少货物
    double vm;          //货物的效益以及质量比
} Goods;

//交换元素
void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

//快速排序的一次划分
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while(low < high){
        while((low < high) && arr[high] > pivot)
            high--;
        swap(arr, low, high);
        while((low < high) && (arr[low] < pivot))
            low++;
        swap(arr, low, high);
    }

    return low;
}

//快速排序
void quickSort(int arr[], int low ,int high)
{
    if(low < high)
    {
        int par = partition(arr, low, high);
        quickSort(arr, low, par);
        quickSort(arr, par+1, high);
    }
    else
        return;
}

void main()
{
    int n;
    printf("请输入物品个数：");
    scanf("%d", &n);
    Goods *goods = (Goods *)malloc(n * sizeof(Goods));
    for(int i = 0; i < n; i++)
    {
        /* code */
        printf("请输入第%d个物品的质量，效益：", i+1);
        scanf("%d %d", &goods[i].m, &goods[i].v);
        goods[i].vm = (double)goods[i].v / goods[i].m;
        printf("\n");
    }
}