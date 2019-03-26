#include <stdio.h>
#include <math.h>
typedef struct {
    double x, y;
    double o;           //��Ÿõ���λ��ΪԲ�ģ��״�Ϊ�뾶��Բ��x�ύ��ĺ�����
} Island;

Island island[1000];

void sort(Island island[], int n)
{
    Island temp;
    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= n - i; i++)
        {
            if (island[j].o > island[j+1].o) {
                temp = island[j];
                island[j] = island[i];
                island[i] = temp;
            }
        }
    }
}

//��������ĳ�������λ�ã��Լ��״��ɨ�跶Χ�����������С���״����
int main()
{
    double scan;            //�����״��ɨ�跶Χ
    printf("�������״��ɨ�跶Χ��");
    scanf("%lf", &scan);

    int n;
    int cout = 1;                   //�״�ĸ���
    printf("�����뵺��ĸ�����");
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        printf("�����뵺��%d�����꣺", i);
        scanf("%lf %lf", &island[i].x, &island[i].y);
        if (fabs(island[i].y) > scan) {
            return -1;                      //��ʱ�޽⣬��Ϊ�״�ɨ��뾶��Զ���붼����������
        }
        island[i].o = sqrt(scan * scan - island[i].y * island[i].y) + island[i].x;      //��x�ύ��ĺ�����
    }
    for(int i = 1; i <= n; i++)
        printf("%lf\t" ,island[i].o);
    sort(island, n);
    for(int i = 1; i <= n; i++)
        printf("%lf\t" ,island[i].o);
    double dist = island[1].o;            //���彻��ĺ����굽��������ľ���
    for(int i = 2; i <= n; i++)
    {
        if ((pow(fabs(dist - island[i].x * island[i].x), 2) + pow(fabs(island[i].y), 2)) >= (scan * scan)) 
        {
            cout++;
            dist = island[i].o;
        }
    }
    printf("\n%d\n", cout);
    return 0;
}