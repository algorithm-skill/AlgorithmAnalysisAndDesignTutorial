//²Î¿¼£ºhttps://blog.csdn.net/u014141559/article/details/43709481?utm_source=blogxgwz7

//´úÂë²Î¿¼£ºhttps://blog.csdn.net/qq_37685156/article/details/78652193

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#define INF 0x3f3f3f3f
 
using namespace std;
 
const int maxe=220;
const int maxv=220;
 
int M,N;
struct edge
{
    int to,w,next;
}e[maxe<<1];
int head[maxv<<1],cnt;
int depth[maxv];
 
void init()
{
    memset(head,-1,sizeof(head));
    cnt=-1;
}
void add_edge(int u,int v,int w)
{
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
void _add(int u,int v,int w)
{
    add_edge(u,v,w);
    add_edge(v,u,0);
}
bool bfs()
{
    memset(depth,0,sizeof(depth));
    queue<int> que;
    while(!que.empty()) que.pop();
    depth[1]=1;
    que.push(1);
 
    while(!que.empty())
    {
        int u=que.front();que.pop();
        for(int i=head[u];i!=-1;i=e[i].next)
        {
            if(!depth[e[i].to] && e[i].w>0)
            {
                depth[e[i].to]=depth[u]+1;
                que.push(e[i].to);
            }
        }
    }
 
    if(!depth[N]) return false;
    return true;
}
int dfs(int u,int flow)
{
    if(u==N) return flow;
    int ret=0;
    for(int i=head[u];i!=-1 && flow;i=e[i].next)
    {
        if(depth[u]+1==depth[e[i].to] && e[i].w>0)
        {
            int tmp=dfs(e[i].to,min(flow,e[i].w));
            if(tmp>0)
            {
                flow-=tmp;
                ret+=tmp;
                e[i].w-=tmp;
                e[i^1].w+=tmp;
            }
        }
    }
    return ret;
}
void Dinic()
{
    int ans=0;
    while(bfs())
        ans+=dfs(1,INF);
    cout<<ans<<endl;
}
 
int main()
{
    ios::sync_with_stdio(false);
    while(cin>>M>>N)
    {
        init();
        for(int i=1;i<=M;i++)
        {
            int u,v,w;
            cin>>u>>v>>w;
            _add(u,v,w);
        }
        Dinic();
    }
    return 0;
}