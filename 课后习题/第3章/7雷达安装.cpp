//�ο���https://blog.csdn.net/cax1165/article/details/52563947


#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct node
{
    int x;
    int y;
    double z;
    bool operator < (node tmp)const
    {
        return tmp.z>z;
    }
}a[maxn];
int n,d,ans=1;
int main()
{
    cin>>n>>d;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].y;
        if(a[i].y>d)//�ж�-1���
        {
            cout<<-1;
            return 0;
        }
        a[i].z=double(a[i].x)+sqrt(double(d*d)-double(a[i].y*a[i].y));//������x�ύ������
    }
    sort(a+1,a+n+1);//����
    double tmp=a[1].z;
    for(int i=2;i<=n;i++)//ͳ���״����
    if((a[i].x-tmp)*(a[i].x-tmp)+a[i].y*a[i].y>d*d)
    ans++,tmp=a[i].z;
    cout<<ans;//���
    return 0;
}