/**
 * ��Ŀ�������ֵ���⣬��ʹ����ֵ�����㷨����Բ���ʦеĽ���ֵ
 * ˼·�������Ͷ�㷨�����ֵ
 * 
 * ͨ��һ�뾶Ϊr��Բ���������ı��Σ�������������Ͷ��n���㣬������Բ�ڵĵ���Ϊk������Ͷ��ĵ�����������
 * ���ȷֲ������Ͷ��ĵ�����Բ�ڵĸ���Ϊ�� * r * r / (4 * r * r) = �� / 4�����Ե�n�㹻���ʱ��
 * k��n֮�Ⱦͱƽ���һ���ʣ�����/4���Ӷ��� = 4 * k / n ������ʵ��ֻҪ�ڵ�һ���޽��м���
 **/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
double darts(int n)
{
    //�����Ͷ�㷨���м����ֵ
    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        double x = random();            //random�������0-1֮���ʵ��
        double y = random();
        if((x * x + y * y) <= 1)
            k++;
    }
    return 4 * k / (double) n;
}
*/
int main()
{
    double x, y;
    long dnode = 0, n = 0, scale;
    printf("Please input scale: ");
    scanf("%d", &scale);
    srandom((unsigned)time(NULL));
    while(n++ < scale)
    {
        x = random() / (double)RAND_MAX;
        y = random() / (double)RAND_MAX;
        if(x*x + y*y <= 1)
            dnode += 1;
    }
    printf("%f\n", 4.0 * dnode / scale);
    return 0;
}