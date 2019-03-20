//版本1： 
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



/*版本二：
#include <stdio.h>
#include <string.h>
typedef struct{
    double m, v;        //定义商品的质量和效益
} Goods;
Goods goods[1000];
int x[1000];            //对应的解向量
double bestv, cw, cv;   //对应的最大效益，商品剩余的质量，商品剩余的效益，目前的效益
int n;                  //对应商品个数
double W;               //背包承重

//当序号为i及以后的物品装入背包，计算剩下所有物品装入背包可以产生的最大收益
double Bounds(int i)
{
    double temp = cv;
    for(int j = i; j <= n; j++)
        temp += goods[j].v;
    return temp;
}

void Backtrack(int t)           //开始遍历解空间树的第t层，从第1层开始算起
{
    if(t > n)
    {
        bestv = cv;
        return;
    }

    if (t <= n) {       //这个if不需要，如果这个if都有，且后面没加return将不会结束调用
        if (goods[t].m <= cw) {     //左子树
            cv += goods[t].v;
            cw -= goods[t].m;
            x[t] = 1;
            Backtrack(t+1);
            cv -= goods[t].v;
            cw += goods[t].m;
        }
                                        //右子树
        if (Bounds(t+1) > bestv) {      //如果上界大于后面的最优值
            x[t] = 0;
            Backtrack(t+1);
        }
    }
}

void Knapsack(double w, int n)
{
    cw = w, cv = 0, bestv = 0;
    memset(x, 0, n * sizeof(int));
    double sumv = 0, sumw = 0;
    for(int i = 1; i <= n; i++)
    {
        sumw += goods[i].m;
        sumv += goods[i].v;
    }

    if (sumw <= w) {
        printf("放入购物车的物品所产生的最大效益为：%lf", sumv);
        printf("此时所有物品均放入购物车！\n");
    }
    Backtrack(1);
    printf("放入购物车的物品所产生的最大效益为：%.2lf\n", bestv);
    printf("放入的物品为:\n");
    for(int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d\t", i);
}

void main()
{
    printf("请输入商品个数：");
    scanf("%d", &n);    

    printf("请输入背包承重：");
    scanf("%lf", &W);

    for(int i = 1; i <= n; i++)
    {
        printf("请输入商品%d的质量和效益：", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
    }

    
    Knapsack(W, n);   
}

          


*/
