//POJ 1390
//https://blog.csdn.net/PKU_ZZY/article/details/51442591
#define MAX_N 200

#include<stdio.h>
#include<memory.h>

int cases,n,m;
int color[MAX_N+1];
int num[MAX_N+1],c[MAX_N+1];
int max[MAX_N+1][MAX_N+1][MAX_N+1];

int f(int l,int r,int len)
{ 
    if (l==r)
        return max[l][r][len]=(num[r]+len)*(num[r]+len);
    if (max[l][r][len])
        return max[l][r][len];
    int temp=f(l,r-1,0)+(len+num[r])*(len+num[r]);
    for (int k=l;k<r;k++)
        if (c[k]==c[r]) 
            if (f(l,k,num[r]+len)+f(k+1,r-1,0)>temp)
                temp=f(l,k,num[r]+len)+f(k+1,r-1,0);
    return max[l][r][len]=temp;
}

int main()
{
    scanf("%d",&cases);
    color[0]=0;
    for (int loop=1;loop<=cases;loop++)
    {
        memset(max,0,sizeof(max));
        scanf("%d",&n);
        m=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&color[i]);
            if (color[i]==color[i-1])
                num[m]++;
            else
            {
                m++;
                c[m]=color[i];
                num[m]=1;
            }
        }
        printf("Case %d: %d\n",loop,f(1,m,0));
    }
    return 0;
}