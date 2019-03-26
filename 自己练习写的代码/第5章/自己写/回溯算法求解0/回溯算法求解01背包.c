#include <stdio.h>
#include <string.h>
typedef struct {
    double m, v;
} Goods;

Goods goods[1000];
int n;                  //��Ʒ����
double W;               //��������
int x[1000];            //��Ӧ��Ʒ�Ľ�����
double bestv;           //��¼�������
double cm, cv;          //ʣ����Ʒ��������Ŀǰ���������������


double Bounds(int t)
{
    double temp = cv;
    for(int i = t; i <= n; i++)
        temp += goods[i].v;
    return temp;
}

void Backtrack(int t)
{
    if(t > n)
    {
        bestv = cv;
        return;
    }

    if(goods[t].m <= cm)
    {
        cm -= goods[t].m;
        cv += goods[t].v;
        x[t] = 1;
        Backtrack(t+1);
        cm += goods[t].m;
        cv -= goods[t].v;
        // x[t] = 0;       //���Ϊʲô���ܷ�������
    }

    if(Bounds(t+1) > bestv)
    {
        x[t] == 0;         //���ΪʲôҪ��������
        Backtrack(t+1);
    }
}


void Knapsack(double w, int n)
{
    double sumv = 0, sumw = 0;
    bestv = 0, cm = w, cv = 0;
    memset(x, 0, 1000 * sizeof(int));
    for(int i = 1; i <= n; i++)
    {
        sumw += goods[i].m;
        sumv += goods[i].v;
    }

    if (sumw <= w) {
        printf("װ����Ʒ���������������Ϊ��%.2lf\n", sumv);
        printf("��ʱ������Ʒ��װ�빺�ﳵ\n");
    }

    Backtrack(1);

    printf("װ����Ʒ���������������Ϊ��%.2lf\n", bestv);
    printf("��ʱװ����Ʒ�����Ϊ��\n");
    for(int i = 1; i <= n; i++)
        if(x[i] == 1)
            printf("%d\t", i);
}

void main()
{
    printf("�����뱳�����أ�");
    scanf("%lf", &W);

    printf("��������Ʒ������");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        printf("��������Ʒ%d��������Ч��: ", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
    }
    Knapsack(W, n);

}