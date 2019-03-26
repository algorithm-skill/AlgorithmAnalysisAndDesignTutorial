#include <stdio.h>
#include <string.h>
typedef struct {
    double m, v;
} Goods;

Goods goods[1000];
int n;                  //商品个数
double W;               //背包承重
int x[1000];            //对应商品的解向量
double bestv;           //记录最大收益
double cm, cv;          //剩余物品的质量，目前所产生的最大收益


double Bounds(int t)
{
    double temp = cv;
    for(int i = t; i <= n; i++)
        temp += goods[i].v;
    return temp;
}

void Backtrack(int t)
{
    if(t > n)
    {
        bestv = cv;
        return;
    }

    if(goods[t].m <= cm)
    {
        cm -= goods[t].m;
        cv += goods[t].v;
        x[t] = 1;
        Backtrack(t+1);
        cm += goods[t].m;
        cv -= goods[t].v;
        // x[t] = 0;       //这个为什么不能放在这里
    }

    if(Bounds(t+1) > bestv)
    {
        x[t] == 0;         //这个为什么要放在这里
        Backtrack(t+1);
    }
}


void Knapsack(double w, int n)
{
    double sumv = 0, sumw = 0;
    bestv = 0, cm = w, cv = 0;
    memset(x, 0, 1000 * sizeof(int));
    for(int i = 1; i <= n; i++)
    {
        sumw += goods[i].m;
        sumv += goods[i].v;
    }

    if (sumw <= w) {
        printf("装入物品所产生的最大收益为：%.2lf\n", sumv);
        printf("此时所有物品均装入购物车\n");
    }

    Backtrack(1);

    printf("装入物品所产生的最大收益为：%.2lf\n", bestv);
    printf("此时装入物品的序号为：\n");
    for(int i = 1; i <= n; i++)
        if(x[i] == 1)
            printf("%d\t", i);
}

void main()
{
    printf("请输入背包承重：");
    scanf("%lf", &W);

    printf("请输入商品个数：");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("请输入商品%d的质量和效益: ", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
    }
    Knapsack(W, n);

}