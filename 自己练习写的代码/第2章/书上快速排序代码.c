#include <stdio.h>

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivotkey;
    pivotkey = arr[low];
    while(low < high){
        while((low < high) && (arr[high] >= pivotkey))
            high--;
        swap(arr, low, high);
        while((low < high) && (arr[low] <= pivotkey))
            low++;
        swap(arr, low, high);
    }
    
    return low;
}

void main()
{
    int arr[] = { 0, 34, 33, 34, 45, 23, 23, 34, 23 };
    partition(arr, 1, 8);          //多创建一个可以存储临时变量
    for(int i = 1; i < 9; i++)
        printf("%d\t", arr[i]);
}