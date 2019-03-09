//https://blog.csdn.net/chenguolinblog/article/details/7882316
//https://www.cnblogs.com/Draymonder/p/7215230.html

//https://wenku.baidu.com/view/2717698379563c1ec4da7133.html PPT 10页附近
/*
    两种方式：
        方法一：连接法，将间距较小的相邻区间连接成一个大的新区间
        ，然后将所得的几个新区间的距离相加继而求得最小长度

        方法二：裁剪法：将较大的空白区域裁掉，也就是将整个区间分解成n个不相连的区间，然后求最小距离
*/


//下面的代码参考：https://blog.csdn.net/weixin_37605770/article/details/70160342 
#include<stdio.h>
#define N 230
void sort(int value[],int n)
{
    int i,j ,t;
    for(i = 0;i<n;i++)
    {
        for(j = 0;j<n-1-i;j++)
        {
            if(value[j]<value[j+1])
            {
                t = value[j];
                value[j] = value[j+1];
                value[j+1] = t;
            }
        }
    }
}
int main()
{
    int n ,m ,i;
    int nline ,devide,totall;
    int position[N];//保存区间数
    int distance [N-1];//区间间隔
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i = 0;i<n;i++)
        scanf("%d",&position[i]);
        sort(position,n);//将区间逆序排序
        for(i = 0;i<n-1;i++)
        distance[i] = position[i]-position[i+1]-1;//求区间间隔
        sort(distance,n-1);//区间间隔逆序排序
        //两种情况
       if(n<=m)
       printf("%d\n",n);
       else
       {
           nline = 1;//假设区间被一整条直线覆盖然后再自选区间隔中最大的一一删除
           totall = position[0]-position[n-1]+1;//总区间长度
           devide = 0;//间隔下标的表示
           while(nline <m&&distance[devide]>0)//总条数要小于直线数   而且间隔元素不能为零 间隔为零就不需要去掉了
          {
             nline++;
             totall -=distance[devide];
            devide++;
          }
          printf("%d\n",totall);
       }
    }
    return 0;
}
