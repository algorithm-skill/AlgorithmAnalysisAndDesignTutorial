#include <stdio.h>

//����װ�뱳������Ʒ
typedef struct {
    double v, m;            //��Ʒ�ļ�ֵ������
    double vm;              //��Ʒ��Ч��������
    int id;                 //��Ʒ�ı��
} Goods;

Goods goods[1000];          //��Ʒ����
double numberGoods[1000];    //��Ʒ�ķݶ��Ӧ��������

void swap(Goods goods[], int index1, int index2)
{
    Goods tempGoods = goods[index1];
    goods[index1] = goods[index2];
    goods[index2] = tempGoods;
}

int partition(Goods goods[], int low, int high)
{
    Goods pivot = goods[low];
    while(low < high){
        while((low < high) && (pivot.vm <= goods[high].vm))
            high--;
        swap(goods, low, high);
        while((low < high) && (pivot.vm >= goods[low].vm))
            low++;
        swap(goods, low, high);
    }
    return low;
}

void quickSort(Goods goods[], int low, int high)
{
    if (low < high) {
        int part = partition(goods, low, high);
        quickSort(goods, low, part-1);
        quickSort(goods, part+1, high);
    }
}

void main()
{
    double M;
    printf("�����뱳���ĳ��أ�");
    scanf("%lf", &M);

    int n;
    printf("��������Ʒ��������");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("��������Ʒ%d�������ͼ�ֵ��", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
        goods[i].vm = goods[i].v / goods[i].m;
        goods[i].id = i;                            //��¼���
    }

    quickSort(goods, 1, n);
    // for(int i = 1; i <= n; i++)
    //     printf("%lf\t", goods[i].vm);
    
    int cm = M;     //��¼������ǰʣ�����
    double cv = 0;  //��¼������ǰ��ֵ
    for(int i = n; i >= 1 && cm > 0; i--)
    {
        if(cm > goods[i].m)
        {
            numberGoods[i] = 1;
            cm -= goods[i].m;
            cv += goods[i].v;
        }
        else{
            numberGoods[i] = (cm / goods[i].m);
            cv += numberGoods[i] * goods[i].v;
            cm = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if (numberGoods[i] != 0) {
            printf("��Ʒ%d�ķݶ�Ϊ��%lf\n", goods[i].id, numberGoods[i]);
        }
    }
}