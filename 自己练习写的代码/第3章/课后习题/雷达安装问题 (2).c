#include <stdio.h>
#include <math.h>
typedef struct {
    double x, y;
    double o;           //存放该岛屿位置为圆心，雷达为半径的圆与x轴交点的横坐标
} Island;

Island island[1000];

void sort(Island island[], int n)
{
    Island temp;
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= n - i; i++)
        {
            if (island[j].o > island[j+1].o) {
                temp = island[j];
                island[j] = island[i];
                island[i] = temp;
            }
        }
    }
}

//给定海中某个岛屿的位置，以及雷达的扫描范围，求解所需最小的雷达个数
int main()
{
    double scan;            //定义雷达的扫描范围
    printf("请输入雷达的扫描范围：");
    scanf("%lf", &scan);

    int n;
    int cout = 1;                   //雷达的个数
    printf("请输入岛屿的个数：");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        printf("请输入岛屿%d的坐标：", i);
        scanf("%lf %lf", &island[i].x, &island[i].y);
        if (fabs(island[i].y) > scan) {
            return -1;                      //此时无解，因为雷达扫描半径最远距离都够不到岛屿
        }
        island[i].o = sqrt(scan * scan - island[i].y * island[i].y) + island[i].x;      //与x轴交点的横坐标
    }
    for(int i = 1; i <= n; i++)
        printf("%lf\t" ,island[i].o);
    sort(island, n);
    for(int i = 1; i <= n; i++)
        printf("%lf\t" ,island[i].o);
    double dist = island[1].o;            //定义交点的横坐标到其他顶点的距离
    for(int i = 2; i <= n; i++)
    {
        if ((pow(fabs(dist - island[i].x * island[i].x), 2) + pow(fabs(island[i].y), 2)) >= (scan * scan)) 
        {
            cout++;
            dist = island[i].o;
        }
    }
    printf("\n%d\n", cout);
    return 0;
}