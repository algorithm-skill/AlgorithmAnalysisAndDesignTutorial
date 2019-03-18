//参考：https://blog.csdn.net/forpro_yang/article/details/6650838

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
 
int map[505][505];
int vis[1001];
int flag[1001];    //flag[i]记录与i相连的边。
int n,m;
 
bool dfs(int s)  //一般也写作find（int s）
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        if(!vis[i] && map[s][i])
        {
            vis[i]=1;
            if(flag[i]==0 || dfs(flag[i]))   //若i没有于别的边相连，或者与i相连的那条边于变得边相连。
            {
                flag[i]=s;
                return true;
            }
        }
    }
    return false;
}
 
int main()
{
    int k,x,y,i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        memset(map,0,sizeof(map));
        memset(flag,0,sizeof(flag));
        for(i=0;i<k;i++)
        {
            scanf("%d%d",&x,&y);
            map[x][y]=1;
        }
        int result=0;
        for(i=1;i<=n;i++)
        {
            memset(vis,0,sizeof(vis));
            if(dfs(i))   result++;
        }
        cout<<result<<endl;
    }
    return 0;
}