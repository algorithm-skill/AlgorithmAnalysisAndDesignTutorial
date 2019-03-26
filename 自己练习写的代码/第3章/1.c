/*̰�ķ���ⱳ������*/
#include <stdio.h>
#include <malloc.h>

typedef struct {
    int m, v, count;           //����������Լ�Ч��,�Ŷ��ٻ���
    double vm;          //�����Ч���Լ�������
} Goods;

//����Ԫ��
void swap(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

//���������һ�λ���
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

//��������
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
    printf("��������Ʒ������");
    scanf("%d", &n);
    Goods *goods = (Goods *)malloc(n * sizeof(Goods));
    for(int i = 0; i < n; i++)
    {
        /* code */
        printf("�������%d����Ʒ��������Ч�棺", i+1);
        scanf("%d %d", &goods[i].m, &goods[i].v);
        goods[i].vm = (double)goods[i].v / goods[i].m;
        printf("\n");
    }
}