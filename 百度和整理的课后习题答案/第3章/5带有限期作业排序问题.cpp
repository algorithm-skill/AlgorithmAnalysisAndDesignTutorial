//思路参考：https://blog.csdn.net/qq_29617037/article/details/51371460

//代码参考：https://blog.csdn.net/bajinbajin/article/details/13616059
#include <iostream>
 
using namespace std;
 
/*D(1),…,D(n)是期限值。n≥1。作业已按p1≥p2≥…≥pn的顺序排序。
J(i)是最优解中的第i个作业，1≤i≤k。
终止时， D(J(i))≤D(J(i＋1))， 1≤i＜k
*/
void JS(int d[], int J[], int n, int &k)
{
    int i,j,r;
    d[0] = J[0] = 0;
    k = 1;
    J[1] = 1;
    for(i=2; i<=n; i++)
    {
        r = k;
        while(d[J[r]] > d[i] && d[J[r]] != r)
            r--;
        if(d[J[r]] <= d[i] && d[i]>r)
        {
            for(j=k; j>r; j--)
                J[i+1] = J[i];
            J[r+1] = i;
            k++;
        }
    }
}
int main()
{
    int d[5] = {0,2,1,2,1};
    int p[5] = {0,100,20,15,10};
    int J[5] = {0};
    int k;
    JS(d,J,4,k);
    for(int i=1; i<=k; i++)
        printf("%d-%d-%d  ", p[J[i]], d[J[i]], J[i]);
    return 0;
}