/**
 * 题目：计算π值问题，试使用数值概率算法计算圆周率π的近似值
 * 思路：用随机投点法计算π值
 * 
 * 通过一半径为r的圆及其外切四边形，向该正方形随机投掷n个点，设落入圆内的点数为k，由于投入的点在正方形上
 * 均匀分布，因而投入的点落入圆内的概率为π * r * r / (4 * r * r) = π / 4，所以当n足够大的时候，
 * k与n之比就逼近这一概率，即π/4，从而π = 4 * k / n ，具体实现只要在第一象限进行计算
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
double darts(int n)
{
    //用随机投点法进行计算π值
    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        double x = random();            //random随机产生0-1之间的实数
        double y = random();
        if((x * x + y * y) <= 1)
            k++;
    }
    return 4 * k / (double) n;
}
*/
int main()
{
    double x, y;
    long dnode = 0, n = 0, scale;
    printf("Please input scale: ");
    scanf("%d", &scale);
    srandom((unsigned)time(NULL));
    while(n++ < scale)
    {
        x = random() / (double)RAND_MAX;
        y = random() / (double)RAND_MAX;
        if(x*x + y*y <= 1)
            dnode += 1;
    }
    printf("%f\n", 4.0 * dnode / scale);
    return 0;
}