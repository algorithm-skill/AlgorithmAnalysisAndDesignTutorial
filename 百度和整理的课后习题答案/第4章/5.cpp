//参考：https://www.cnblogs.com/L-Arikes/p/5099270.html
#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int main()
{   
   int cost[100][101];
   int mincost[101];
   int n;
   memset(cost,0,sizeof(cost));
   cin >> n;

   for(int i = 0;i < n; i++)
      for(int j = i + 1; j <= n; j++)
       cin >> cost[i][j];

   mincost[0] = 0;
   for(int i = 1; i < n+1; i++)
       mincost[i] = LONG_MAX;

   for(int i=1;i<=n;i++)
       for(int j=0;j<i;j++)
           if(mincost[j]+cost[j][i]<mincost[i])
               mincost[i]=mincost[j]+cost[j][i];
   cout << endl << mincost[n];
}
/*
#include <iostream>
#include <stdio.h>
#include <algorithm>
 
#define maxn 100
 
using namespace std;
int f[maxn][maxn],a[maxn][maxn];//f[i][j]表示从i到j的租船费用，a[i][j]表示i到j的最少游船费用
int main(void)
{
    int n;
    int i,j,k;
    int num = 1;
    while(cin>>n)
    {
        //int num = 1;
 
 
        for(i = 0; i < n; i++)
        {
          for(j = i+1; j <= n; j++)
          {
              cin>>f[i][j];
              a[i][j] = f[i][j];//顺便初始化a[i][j]数组。
          }
        }
        for(i = 0; i < n; i++)
        {
            for(k = i+1; k < n-1; k++)
            for(j = k+1; j <= n; j++)
            {
                a[i][j] = min((f[i][k]+f[k][j]),f[i][j]);
            }
        }
        cout<<"Case "<<num<<":"<<endl;
        num++;
        cout<<a[0][n]<<endl;
    }
 
 
    //cout << "Hello world!" << endl;
    return 0;
}
*/