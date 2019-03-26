#include <stdio.h>
#include <string.h>
typedef struct{
    double m, v;        //������Ʒ��������Ч��
} Goods;
Goods goods[1000];
int x[1000];            //��Ӧ�Ľ�����
double bestv, cw, cv;   //��Ӧ�����Ч�棬��Ʒʣ�����������Ʒʣ���Ч�棬Ŀǰ��Ч��
int n;                  //��Ӧ��Ʒ����
double W;               //��������

//�����Ϊi���Ժ����Ʒװ�뱳��������ʣ��������Ʒװ�뱳�����Բ������������
double Bounds(int i)
{
    double temp = cv;
    for(int j = i; j <= n; j++)
        temp += goods[j].v;
    return temp;
}

void Backtrack(int t)           //��ʼ������ռ����ĵ�t�㣬�ӵ�1�㿪ʼ����
{
    if(t > n)
    {
        bestv = cv;
        return;
    }

    if (t <= n) {       //���if����Ҫ��������if���У��Һ���û��return�������������
        if (goods[t].m <= cw) {     //������
            cv += goods[t].v;
            cw -= goods[t].m;
            x[t] = 1;
            Backtrack(t+1);
            cv -= goods[t].v;
            cw += goods[t].m;
        }
                                        //������
        if (Bounds(t+1) > bestv) {      //����Ͻ���ں��������ֵ
            x[t] = 0;
            Backtrack(t+1);
        }
    }
}

void Knapsack(double w, int n)
{
    cw = w, cv = 0, bestv = 0;
    memset(x, 0, n * sizeof(int));
    double sumv = 0, sumw = 0;
    for(int i = 1; i <= n; i++)
    {
        sumw += goods[i].m;
        sumv += goods[i].v;
    }

    if (sumw <= w) {
        printf("���빺�ﳵ����Ʒ�����������Ч��Ϊ��%lf", sumv);
        printf("��ʱ������Ʒ�����빺�ﳵ��\n");
    }
    Backtrack(1);
    printf("���빺�ﳵ����Ʒ�����������Ч��Ϊ��%.2lf\n", bestv);
    printf("�������ƷΪ:\n");
    for(int i = 1; i <= n; i++)
        if (x[i] == 1)
            printf("%d\t", i);
}

void main()
{
    printf("��������Ʒ������");
    scanf("%d", &n);    

    printf("�����뱳�����أ�");
    scanf("%lf", &W);

    for(int i = 1; i <= n; i++)
    {
        printf("��������Ʒ%d��������Ч�棺", i);
        scanf("%lf %lf", &goods[i].m, &goods[i].v);
    }

    
    Knapsack(W, n);   
}

         