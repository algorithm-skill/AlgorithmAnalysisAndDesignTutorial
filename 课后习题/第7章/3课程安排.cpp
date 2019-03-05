//�ο�https://blog.csdn.net/greatjames/article/details/75668477
//������ͼ��poj 1469 COURSES

/* ***********************************************
��  �������������� ��
�������ߩ��������ߩ� ��
�������������������� ��
�������������������� ��
�������ש������ס��� ��
�������������������� ��
�����������ߡ������� ��
������������������ ��
�����������ա���������������������
�����������ꡡ���������� ��
�����������ڡ����������ǩ���
�����������Ĳ�������������
�����������������ש����� ��
�����������ϩϡ����ϩ� ��
�����������ߩ������ߩ� ��
************************************************ */
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <cmath>
#include <queue>
#include <cstdio>
#include <bitset>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <functional>
#define PI acos(-1)
#define eps 1e-8
#define inf 0x3f3f3f3f
#define debug(x) cout<<"---"<<x<<"---"<<endl
typedef long long ll;
using namespace std;
 
ll a[110];
ll b[110];
set<long long> p, q;
set<long long>:: iterator piter;
set<long long>:: iterator qiter;
 
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        p.clear();
        q.clear();
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &b[i]);
        }
 
        sort(a, a + n);
        sort(b, b + n);
        for (int i = 0; i < n; i++)
        {
            p.insert(a[i]);
            q.insert(b[i]);
        }
        if (p.size() != q.size())
        {
            printf("NO\n");
            continue;
        }
        int flag = 1;
        for (piter = p.begin(), qiter = q.begin(); piter != p.end(), qiter != q.end(); piter++, qiter++)
        {
            if (*piter != *qiter)
            {
                flag = 0;
                break;
            }
        }
        if (flag)
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