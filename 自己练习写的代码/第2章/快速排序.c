#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int arr[], int n)
{
    int low = 0, high = n - 1;
    arr[0] = arr[1];
    while(low < high){
        while( (low < high) && (arr[0] <= arr[high]) )
            high--;
        swap(&arr[low], &arr[high]);
        while( (low < high) && (arr[0] >= arr [low]) )
            low++;
        swap(&arr[low], &arr[high]);
    }  
}

void main()
{
    int arr[] = { 0, 34, 33, 34, 45, 23, 23, 34, 23 };
    quickSort(arr, 9);          //多创建一个可以存储临时变量
    for(int i = 1; i < 9; i++)
        printf("%d\t", arr[i]);
}




