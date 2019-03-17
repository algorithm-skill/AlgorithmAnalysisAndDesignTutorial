#include <stdio.h>
#include <string.h>
#define N 100
int a[N][N], n, e;            //将图用邻接矩阵表示出来， 顶点数，边数
int x[N], sum;                //解向量，总人数
int bestn;                    //最优总人数

//约束函数
int Constr(int t)
{
    int tmp = 1;
    for(int i = 1; i < t; i++)
    {
        if (x[i] && a[t][i] == 0) {                 //先找已经加入集合的顶点，并且判断边是否存在
        // if (x[i] != 1 || a[i][t] != 1) {         //这个限界函数有问题
            tmp = 0;
            break;
        }
    }
    printf("Constr: %d\n", tmp);
    return tmp;
}

void Backtrack(int i)
{
    if (i > n) {
        bestn = sum;
        return;
    }
    if (Constr(i)) {            // 满足约束条件
        sum += 1;
        x[i] = 1;
        Backtrack(i+1);
        sum -= 1;
        // x[i] = 0;            //不能放在这里，因为这里是遍历该节点的左子树，并且包括该节点，此时该节点还是可选的
    }
    if((n - i + sum) > bestn)   //如果满足限界条件，扩展右子树，那么此时该节点就没用了
    {
        x[i] = 0;
        Backtrack(i+1);
    }
}



void main()
{
    printf("请输入结点个数：");
    scanf("%d", &n);

    printf("请输入边数：");
    scanf("%d", &e);

    int u, v;                   //临时建立图中两个结点的对应关系

    //初始化
    sum = 0, bestn = 0;
    memset(x, 0, 100 * sizeof(int));
    memset(a, 0, 100 * sizeof(int));


    for(int i = 1; i <= e; i++)
    {
        printf("请输入第%d条边的两个端点：", i);
        scanf("%d %d", &u, &v);
        a[u][v] = 1, a[v][u] = 1; 
    }

    printf("邻接矩阵为：\n");
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    

    for(int i = 1; i <= n; i++)
        printf("%d\t", x[i]);
    printf("\n");
    Backtrack(1);

    for(int i = 1; i <= n; i++)
        printf("%d\t", x[i]);

    printf("国王护卫队的总人数为：%d\n", bestn);
    printf("成员为：\n");
    for(int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d\t", i);
    for(int i = 1; i <= n; i++)
        printf("\n%d\t", x[i]);
    
}