#include <stdio.h>
typedef struct {
    int x, y;       //分别表示作业在第1个机器的加工时间，和第2个机器的加工时间
} Work;

int best[10000], bestf = 65535;  //分别记录最优的作业序号,  目前最小完成时间
int n, f1 = 0, f2 = 0;         //记录作业个数，分别记录机器1的完成时间和机器2的完成时间
Work workList[10000];

int max(int num1, int num2)
{
    return num1 > num2 ? num1 : num2;
}

int swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void backtrack(int t)
{
    //如果超过了作业个数直接输出
    if(t > n)
    {
        for(int i = 1; i <= n; i++)         //输出最优排列
            printf("%d \t", best[i]);
        printf("\n");
    }

    for(int i = t; i <= n; i++)
    {
        if ((max(f1 + workList[i].x, f2) + workList[i].y) < best) {
            swap(best, i, t);
            backtrack(t+1);
            swap(best, i, t);
        }
    }
}

void main()
{
    int n;
    printf("请输入作业的个数：");
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        printf("请输入作业%d在机器1加工和机器2加工所需的时间：", i);
        scanf("%d %d", &workList[i].x, &workList[i].y);
    }
    
    backtrack(1);
}