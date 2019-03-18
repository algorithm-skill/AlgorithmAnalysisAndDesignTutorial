//参考：https://wenku.baidu.com/view/7193073c7fd5360cba1adb85.html
#include <stdio.h>
#include <string.h>
#define N 3 //图中结点个数
int a[N+1][N+1] = {
    0,0,0,0,
    0,1,1,1,
    0,1,1,1,
    0,1,1,1
};  //邻接矩阵
int x[N+1];     //记录颜色
int sum = 0;
int OK(int t, int i)    //判断函数
{
    int j;
    for(j = 1; j < t; j++)
    {
        if(a[t][j]&&x[j]==i)
            return 0;
    }
    return 1;
}

void Backtrace(int t, int m)
{
    int i;
    if(t > N)   //算法搜索至叶子结点
    {
        sum++;
        printf("第%d种方案：\n", sum);
        for(i = 1; i <= N; i++)
            printf("%d ", x[i]);
        printf("\n");
    }
    else
    {
        for(i = 1; i <= m; i++)
        {
            if(OK(t, i))
            {
                x[t] = i;
                Backtrace(t+1, m);
            }
        }   
    }
}

void main()
{
    int m, i;
    printf("请输入颜色种类：\n");
    scanf("%d", &m);
    for(i = 1; i <= m; i++) //初始化
        x[i] = 0;
    Backtrace(1, m);
    if(sum == 0)
        printf("不是%d可着色的!\n", m);
}
