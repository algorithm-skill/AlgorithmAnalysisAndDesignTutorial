#include <stdio.h>
int M[10000];
int dist[10000];

void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    
    while(low < high){
        while((low < high) && (pivot <= arr[high]))
            high--;
        swap(arr, low, high);
        while((low < high) && (pivot >= arr[low]))
            low++;
        swap(arr, low, high);
    }
    return low;
}

//从小到大的快速排序
void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int part = partition(arr, low, high);
        quickSort(arr, low, part-1);
        quickSort(arr, part+1, high);
    }
}

void main()
{
    int m;
    printf("请输入区间个数：");
    scanf("%d", &m);

    int n;
    printf("请输入线段条数：");
    scanf("%d", &n);

    for(int i = 1; i <= m; i++)
    {
        printf("请输入区间%d的右端点：", i);
        scanf("%d", &M[i]);
    }
    //对区间右端点进行排序,从小到大
    quickSort(M, 1, m);

    //计算间距
    for(int i = 1; i <= m-1; i++)
        //第i个区间到第i+1个区间的距离
        dist[i] = M[i+1] - 1 - M[i]; 

    quickSort(dist, 1, m-1);

    int sum =  M[m] - M[1] + 1;        //用来计算覆盖后的最短距离和
    for(int i = m; i > m-n+1; i--)
        sum -= dist[i-1];
    
    printf("最小长度和为：%d\n", sum);
}