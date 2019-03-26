#include <stdio.h>

//定义装入背包的物品
typedef struct {
    double v, m;            //物品的价值，质量
    double vm;              //物品的效益质量比
    int id;                 //物品的编号
} Goods;

Goods goods[1000];          //物品集合
double numberGoods[1000];    //物品的份额对应的向量解

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
    printf("请输入背包的承重：");
    scanf("%lf", &M);

    int n;
    printf("请输入物品的数量：");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("请输入物品%d的重量和价值：", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
        goods[i].vm = goods[i].v / goods[i].m;
        goods[i].id = i;                            //记录编号
    }

    quickSort(goods, 1, n);
    // for(int i = 1; i <= n; i++)
    //     printf("%lf\t", goods[i].vm);
    
    int cm = M;     //记录背包当前剩余承重
    double cv = 0;  //记录背包当前价值
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
            printf("物品%d的份额为：%lf\n", goods[i].id, numberGoods[i]);
        }
    }
}