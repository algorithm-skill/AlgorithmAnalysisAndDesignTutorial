//https://blog.csdn.net/chenguolinblog/article/details/7882316
//https://www.cnblogs.com/Draymonder/p/7215230.html

//https://wenku.baidu.com/view/2717698379563c1ec4da7133.html PPT 10ҳ����
/*
    ���ַ�ʽ��
        ����һ�����ӷ���������С�������������ӳ�һ�����������
        ��Ȼ�����õļ���������ľ�����Ӽ̶������С����

        ���������ü��������ϴ�Ŀհ�����õ���Ҳ���ǽ���������ֽ��n�������������䣬Ȼ������С����
*/


//����Ĵ���ο���https://blog.csdn.net/weixin_37605770/article/details/70160342 
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
    int position[N];//����������
    int distance [N-1];//������
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i = 0;i<n;i++)
        scanf("%d",&position[i]);
        sort(position,n);//��������������
        for(i = 0;i<n-1;i++)
        distance[i] = position[i]-position[i+1]-1;//��������
        sort(distance,n-1);//��������������
        //�������
       if(n<=m)
       printf("%d\n",n);
       else
       {
           nline = 1;//�������䱻һ����ֱ�߸���Ȼ������ѡ�����������һһɾ��
           totall = position[0]-position[n-1]+1;//�����䳤��
           devide = 0;//����±�ı�ʾ
           while(nline <m&&distance[devide]>0)//������ҪС��ֱ����   ���Ҽ��Ԫ�ز���Ϊ�� ���Ϊ��Ͳ���Ҫȥ����
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
