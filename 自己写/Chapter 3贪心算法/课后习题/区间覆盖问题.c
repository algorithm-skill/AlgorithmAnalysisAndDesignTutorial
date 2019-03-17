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

//��С����Ŀ�������
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
    printf("���������������");
    scanf("%d", &m);

    int n;
    printf("�������߶�������");
    scanf("%d", &n);

    for(int i = 1; i <= m; i++)
    {
        printf("����������%d���Ҷ˵㣺", i);
        scanf("%d", &M[i]);
    }
    //�������Ҷ˵��������,��С����
    quickSort(M, 1, m);

    //������
    for(int i = 1; i <= m-1; i++)
        //��i�����䵽��i+1������ľ���
        dist[i] = M[i+1] - 1 - M[i]; 

    quickSort(dist, 1, m-1);

    int sum =  M[m] - M[1] + 1;        //�������㸲�Ǻ����̾����
    for(int i = m; i > m-n+1; i--)
        sum -= dist[i-1];
    
    printf("��С���Ⱥ�Ϊ��%d\n", sum);
}