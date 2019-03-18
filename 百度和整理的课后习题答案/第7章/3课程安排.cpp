//参考https://blog.csdn.net/greatjames/article/details/75668477
//【二分图】poj 1469 COURSES




#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#define eps 1e-8
#define INF 0x7fffffff
#define maxn 100005
#define PI acos(-1.0)
using namespace std;
typedef long long LL;
const int N = 302;
/*变种1：二分图的最小顶点覆盖：
假如选了一个点就相当于覆盖了以它为端点的所有边，
你需要选择最少的点来覆盖所有的边
二分图的最小顶点覆盖数 = 二分图的最大匹配数
变种2：DAG图（无回路有向图）的最小路径覆盖
路径覆盖就是在图中找一些路经，使之覆盖了图中的所有顶点，
且任何一个顶点有且只有一条路径与之关联，
如果把这些路径中的每条路径从它的起始点走到它的终点，
那么恰好可以经过图中的每个顶点一次且仅一次
DAG图的最小路径覆盖数 = 节点数（n）- 最大匹配数（m）
变种3: 二分图的最大独立集：在图中选取最多的点，使任意所选两点均不相连
二分图的最大独立集数 = 节点数（n）- 最大匹配数（m）
*/
 
 
/*=***************************************************
二分图匹配（匈牙利算法的DFS实现）
INIT：g[][]两边定点划分的情况
CALL:res=hungary();输出最大匹配数
优点：适于稠密图，DFS找增广路快，实现简洁易于理解
时间复杂度:O(VE);
***************************************************=*/
const int MAXN = 1000;
int uN, vN; //u,v数目
int g[MAXN][MAXN];//编号是0~n-1的
int linker[MAXN];
bool used[MAXN];
 
bool dfs(int u)
{
    for (int v = 0; v < vN; v++)
        if (g[u][v] && !used[v])
        {
            used[v] = true;
            if (linker[v] == -1 || dfs(linker[v]))
            {
                linker[v] = u;
                return true;
            }
        }
    return false;
}
int hungary()
{
    int res = 0;
    memset(linker, -1, sizeof(linker));
    for (int u = 0; u < uN; u++)
    {
        memset(used, 0, sizeof(used));
        if (dfs(u))
        {
            res++;
        }
    }
    return res;
}
 
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(g, 0, sizeof(g));
        scanf("%d %d", &uN, &vN);
 
        int ct, xx;
        for (int i = 0; i < uN; i++)
        {
            scanf("%d", &ct);
            while (ct--)
            {
                scanf("%d", &xx);
                g[i][xx - 1] = 1;
            }
        }
        int ans = hungary();
        if (ans == uN)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}