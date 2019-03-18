//�ο�https://blog.csdn.net/greatjames/article/details/75668477
//������ͼ��poj 1469 COURSES




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
/*����1������ͼ����С���㸲�ǣ�
����ѡ��һ������൱�ڸ���������Ϊ�˵�����бߣ�
����Ҫѡ�����ٵĵ����������еı�
����ͼ����С���㸲���� = ����ͼ�����ƥ����
����2��DAGͼ���޻�·����ͼ������С·������
·�����Ǿ�����ͼ����һЩ·����ʹ֮������ͼ�е����ж��㣬
���κ�һ����������ֻ��һ��·����֮������
�������Щ·���е�ÿ��·����������ʼ���ߵ������յ㣬
��ôǡ�ÿ��Ծ���ͼ�е�ÿ������һ���ҽ�һ��
DAGͼ����С·�������� = �ڵ�����n��- ���ƥ������m��
����3: ����ͼ��������������ͼ��ѡȡ���ĵ㣬ʹ������ѡ�����������
����ͼ������������ = �ڵ�����n��- ���ƥ������m��
*/
 
 
/*=***************************************************
����ͼƥ�䣨�������㷨��DFSʵ�֣�
INIT��g[][]���߶��㻮�ֵ����
CALL:res=hungary();������ƥ����
�ŵ㣺���ڳ���ͼ��DFS������·�죬ʵ�ּ���������
ʱ�临�Ӷ�:O(VE);
***************************************************=*/
const int MAXN = 1000;
int uN, vN; //u,v��Ŀ
int g[MAXN][MAXN];//�����0~n-1��
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