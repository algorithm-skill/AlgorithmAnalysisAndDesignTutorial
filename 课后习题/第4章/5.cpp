//²Î¿¼£ºhttps://www.cnblogs.com/L-Arikes/p/5099270.html
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