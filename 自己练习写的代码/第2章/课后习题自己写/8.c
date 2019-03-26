#include <stdio.h>

void swap(int arr[], int low, int high)
{
    int temp = arr[low];
    arr[low] = arr[high];
    arr[high] = temp;
}

//枢纽划分一次完成
int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    while(low < high)
    {
        while((low < high) && (arr[high] > pivot))
            high--;
        swap(arr, low, high);
        printf("交换%d与%d后：\t", arr[low], arr[high]);
        print(arr, 10);
        while((low < high) && (arr[low] < pivot))
            low++;
        swap(arr, low, high);
        printf("交换%d与%d后：\t", arr[low], arr[high]);
        print(arr, 10);
    }
    return low;
}

//n表示元素个数
void print(int arr[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d\t", arr[i]);
    printf("\n");
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int par = partition(arr, low, high);
        quickSort(arr, low, par-1);
        quickSort(arr, par+1, high);
    }
}

void main()
{
    int arr[] = {100, 300, 20, 99, 85, 66, 879, 489, 512, 31};
    printf("原始数据：\t");
    for(int i = 0; i <= 9; i++)
        printf("%d\t",arr[i]);
    printf("\n");
    quickSort(arr, 0, 9);
    for(int i = 0; i <= 9; i++)
        printf("%d\t",arr[i]);

}