//˼·�ο���https://blog.csdn.net/qq_29617037/article/details/51371460

//����ο���https://blog.csdn.net/bajinbajin/article/details/13616059
#include <iostream>
 
using namespace std;
 
/*D(1),��,D(n)������ֵ��n��1����ҵ�Ѱ�p1��p2�ݡ���pn��˳������
J(i)�����Ž��еĵ�i����ҵ��1��i��k��
��ֹʱ�� D(J(i))��D(J(i��1))�� 1��i��k
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