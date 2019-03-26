/*注意：N皇后求解方案个数，只是求出所有可行解，因此不需要写最优解对应的限界函数*/
#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 1000
int x[N];           //定义第N行的放到第X[N]列
int n, cnt;         //定义实际的皇后个数，方案个数

int Constr(int t)
{
    int status = 1;
    for(int i = 1; i < t; i++)
    {
        if(x[t] == x[i] || fabs(x[t] - x[i]) == (t -i))
            status = 0;
    }
    return status;
}


//回溯算法
void Backtrack(int t)
{
    if (t > n) {
        cnt += 1;
        printf("方案%d：\n\t\t", cnt);
        for(int i = 1; i <= n; i++)
            printf("%d\t", x[i]);
    }
    for(int i = 1; i <= n; i++)
    {
        x[t] = i;                   //假定先放在第i列
        if (Constr(t))              //如果符合约束条件
            Backtrack(t+1);
    }
}


void main()
{
    cnt = 0;
    printf("请输入皇后个数：");
    scanf("%d", &n);            
    memset(x, 0, N * sizeof(int));
    Backtrack(1);
    printf("有%d种方案：\n", cnt);
}